#include "vfpu_macros.inc"

gfunc vfpu_expf
    mfc1 $t0, $f12
    mtv     $t0, S000
    vcst.s  S001, VFPU_LN2
    vrcp.s  S001, S001
    vmul.s  S000, S000, S001
    vexp2.s S000, S000
    mfv     $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
