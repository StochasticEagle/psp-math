#include "vfpu_macros.inc"

gfunc vfpu_Mat4Translate
    vmidt.q M000
    mtv $a1, S030
    mtv $a2, S031
    mtv $a3, S032
    sv.q C000, 0($a0)
    sv.q C010, 16($a0)
    sv.q C020, 32($a0)
    sv.q C030, 48($a0)
    jr $ra
    nop
