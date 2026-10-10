#!/usr/bin/env python3
"""Read-only PSP-Math archive/API audit. Run from psp-math repository root."""
import argparse
import csv
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path


def run(argv, output, allow_failure=False):
    proc = subprocess.run(argv, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    output.write_text('$ ' + ' '.join(map(str, argv)) + '\n' + proc.stdout)
    if proc.returncode and not allow_failure:
        raise RuntimeError(f"Command failed ({proc.returncode}): {' '.join(map(str, argv))}; see {output}")
    return proc.returncode


def symbols_from_header(header):
    text = re.sub(r'/\*.*?\*/|//[^\n]*', '', header, flags=re.S)
    symbols = []
    for statement in text.split(';'):
        if re.search(r'^\s*#', statement):
            # Ignore preprocessor lines while preserving code that follows them.
            statement = re.sub(r'^\s*#.*$', '', statement, flags=re.M)
        hits = re.findall(r'\b((?:vfpu_[A-Za-z0-9_]+|print[A-Za-z0-9_]+))\s*\(', statement)
        if hits and '(' in statement and ')' in statement:
            symbols.append(hits[-1])
    return sorted(set(symbols))


def archive_symbols(nm, archive, raw_path):
    run([nm, '-A', '-g', '--defined-only', str(archive)], raw_path)
    items = []
    for line in raw_path.read_text().splitlines():
        match = re.match(r'^(.+):(?:\s*)([0-9a-fA-F]+)\s+([A-Za-z])\s+(\S+)\s*$', line)
        if match:
            origin, _, typ, name = match.groups()
            items.append((name, typ, origin))
    if not items:
        raise RuntimeError('No symbols parsed from nm output; check nm-inventory.txt syntax.')
    return items


def color_status(status):
    if not sys.stdout.isatty() or 'NO_COLOR' in os.environ:
        return status
    colors = {'PASS': '32', 'FAIL': '31', 'NOT ATTEMPTED': '33'}
    return f'\033[{colors[status]}m{status}\033[0m'


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--repo', type=Path, default=Path('.'))
    ap.add_argument('--out', type=Path, default=Path('build/api-audit'))
    ap.add_argument('--archive', type=Path, default=Path('bin/psp-math.a'))
    ap.add_argument('--cc', default='psp-gcc')
    ap.add_argument('--nm', default='psp-nm')
    args = ap.parse_args()
    repo = args.repo.resolve()
    out = (repo / args.out).resolve()
    archive = (repo / args.archive).resolve()
    out.mkdir(parents=True, exist_ok=True)
    header = repo / 'include/pspmath.h'
    for dep in (header, archive):
        if not dep.is_file():
            sys.exit(f'Missing {dep}; build psp-math first')
    for command in (args.cc, args.nm):
        if not shutil.which(command):
            sys.exit(f'Missing tool: {command}')

    public = symbols_from_header(header.read_text())
    if len(public) < 250:
        sys.exit(f'Parser found only {len(public)} functions; inspect header before trusting results')
    defined = archive_symbols(args.nm, archive, out / 'nm-inventory.txt')
    with (out / 'symbols.csv').open('w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['symbol', 'type', 'archive_member'])
        writer.writerows(sorted(defined))
    defined_set = {name for name, typ, _ in defined if typ.upper() in ('T', 'W')}
    missing = sorted(set(public) - defined_set)
    excess = sorted(name for name in defined_set if (name.startswith('vfpu_') or name.startswith('print')) and name not in public)
    (out / 'missing-public-symbols.txt').write_text('\n'.join(missing) + ('\n' if missing else ''))
    (out / 'undeclared-exported-functions.txt').write_text('\n'.join(excess) + ('\n' if excess else ''))
    (out / 'public-declarations.txt').write_text('\n'.join(public) + '\n')
    run([args.nm, '-A', '-u', str(archive)], out / 'undefined-archive-symbols.txt', allow_failure=True)

    lines = ['#include "pspmath.h"', '', '/* Volatile pointers force one relocation per declared public function. */',
             'static void (* volatile api_references[])(void) = {']
    lines.extend(f'    (void (*)(void)){name},' for name in public)
    lines.extend(['};', 'int main(void) {', '    unsigned int i;', '    unsigned int count = 0;',
                  '    for (i = 0; i < sizeof(api_references) / sizeof(api_references[0]); ++i)',
                  '        if (api_references[i] != 0) ++count;',
                  f'    return count == {len(public)} ? 0 : 1;', '}', ''])
    source = out / 'api-coverage.c'
    source.write_text('\n'.join(lines))
    obj = out / 'api-coverage.o'
    cc_result = run([args.cc, '-O0', '-G0', '-I' + str(repo / 'include'), '-c', str(source), '-o', str(obj)], out / 'compile.log', allow_failure=True)
    link_result = None
    if cc_result == 0:
        link_result = run([args.cc, '-o', str(out / 'api-coverage.elf'), str(obj), str(archive), '-lm'], out / 'link.log', allow_failure=True)
    print(f'Public declarations: {len(public)}; defined function symbols: {len(defined_set)}; missing: {len(missing)}; undeclared exported vfpu/print functions: {len(excess)}')
    compile_status = "PASS" if cc_result == 0 else "FAIL"
    link_status = "NOT ATTEMPTED" if link_result is None else "PASS" if link_result == 0 else "FAIL"
    print(f"Compile: {color_status(compile_status)}; link: {color_status(link_status)}")
    print(f'Reports: {out}')
    if missing:
        print('Missing declarations in archive (first 30): ' + ', '.join(missing[:30]))
    return int(bool(missing) or cc_result != 0 or link_result != 0)


if __name__ == '__main__':
    sys.exit(main())
