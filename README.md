# PSP-Math

PSP-Math is a VFPU-accelerated scalar mathematics, vector, matrix and quaternion library for the PlayStation Portable. It consolidates the historical libpspmath and pspla implementations into one package. Performance depends on the operation, input sizes and calling overhead; older general-purpose speedup estimates are not guarantees.

## Build and link

Build with the PSP SDK installed and `psp-config` available:

```sh
make
make install
```

Include the canonical API and link against the installed static archive:

```c
#include <pspmath.h>
```

The installed library is `psp-math.a`. For a direct linker invocation use `-l:psp-math.a`, placed after the objects or static libraries that call it. Consumers of OSLib's math aliases also require PSP-Math; the OSLib CMake target declares this dependency.

The historical `pspmath-compatibility.h` provides legacy pspla names. New code should use `pspmath.h` directly.

## API conventions

- Canonical public operations use the `vfpu_` prefix; see [API declarations](api.md) for the current prototypes.
- Vector/matrix routines generally distinguish `_U` (unaligned) from aligned variants. Respect the alignment requirements documented in `pspmath.h`; `PSPMATH_ALIGN` requests 16-byte alignment.
- Scalar floating-point trig routines `vfpu_sinf`, `vfpu_cosf` and `vfpu_tanf` accept radians.
- `vfpu_sinf_scaled` and `vfpu_cosf_scaled` accept a radian angle and scale. `vfpu_sind_scaled`, `vfpu_cosd_scaled`, and `vfpu_tand_scaled` accept a degree angle and scale. They return `scale × trigonometric_value`.

## Integer and fixed-point operations

The integer-degree lookup API is:

```c
int16_t vfpu_sind_int16(int angle);
int16_t vfpu_cosd_int16(int angle);
int16_t vfpu_tan_int16(int angle);
```

These return **signed Q14** values (16384 represents 1.0), not rounded whole integers. Angles are integer degrees, normalized modulo 360. One read-only 450-entry sine table supplies sine and cosine (cosine uses an offset of 90); a separate 360-entry table supplies tangent. Total table storage is 1620 bytes with no runtime initialization or VFPU instruction on lookup. Tangent is undefined at 90° and 270°; these entries return `INT16_MAX`. Other nonrepresentable tangent results saturate to the 16-bit limits.

Additional scalar functions have `_int16` Q14 adapters, including inverse and hyperbolic trigonometry, exp/log/pow, square root, remainder, easing, random and scaled trig. Their fixed-point inputs and outputs are Q14 unless the degree-based scaled forms explicitly take an integer degree argument. Signed Q14 spans [-2, 32767/16384]; outputs saturate and NaN converts to zero. These adapters convert to float, invoke an existing VFPU routine and convert back; they are **not** native integer-VFPU kernels or necessarily faster than the float API. Consult the signatures and domain restrictions before use.

## Origin and licenses

Derived from historical libpspmath (including OSLibModV2) and pspla sources. See the repository license files and upstream copyright notices for applicable terms.

## AI-assisted contributions and licensing

This fork includes changes made with generative-AI assistance and integrated by the maintainer. To the extent the maintainer holds copyright in independently original AI-generated or AI-assisted contributions, those rights are dedicated to the public domain under [The Unlicense](https://unlicense.org/). Material that is not copyrightable requires no license.

This dedication applies only to rights controlled by the maintainer. Upstream and third-party code, derivative modifications, submodules and dependencies retain their applicable original licenses and attribution requirements, even when AI assisted in modifying them. Consult the existing license files and source notices.
