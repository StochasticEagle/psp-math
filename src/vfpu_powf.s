#include "vfpu_macros.inc"

gfunc vfpu_powf
    mfc1 $t0, $f12
    mfc1 $t1, $f14
    mtv      $t0, S000
    mtv      $t1, S001
    vlog2.s  S000, S000
    vmul.s   S000, S000, S001
    vexp2.s  S000, S000
    mfv      $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
