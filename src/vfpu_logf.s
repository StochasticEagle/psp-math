#include "vfpu_macros.inc"

gfunc vfpu_logf
    mfc1 $t0, $f12
    mtv     $t0, S000
    vcst.s  S001, VFPU_LN2
    vlog2.s S000, S000
    vmul.s  S000, S000, S001
    mfv     $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
