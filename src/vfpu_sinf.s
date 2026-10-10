#include "vfpu_macros.inc"

gfunc vfpu_sinf
    mfc1 $t0, $f12
    mtv     $t0, S000
    vcst.s  S001, VFPU_2_PI
    vmul.s  S000, S000, S001
    vsin.s  S000, S000
    mfv     $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
