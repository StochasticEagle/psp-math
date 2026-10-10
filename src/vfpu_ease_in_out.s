#include "vfpu_macros.inc"

gfunc vfpu_EaseInOut
    mfc1 $t0, $f12
    mtv     $t0, S000
    vmov.q  C000[0:1,,,], C000[x, 2, 1, 1/2]
    vmul.s  S000, S000, S001
    vsub.s  S000, S000, S002
    vsin.s  S000, S000
    vmul.s  S000, S000, S003
    vadd.s  S000, S000, S003
    mfv     $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
