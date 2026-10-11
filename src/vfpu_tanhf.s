#include "vfpu_macros.inc"

gfunc vfpu_tanhf
    mfc1 $t0, $f12
    mtv      $t0, S000
    vadd.s   S000, S000, S000
    vcst.s   S001, VFPU_LOG2E
    vmul.s   S000, S000, S001
    vexp2.s  S000, S000
    vone.s   S001
    vbfy1.p  C002, C000
    vdiv.s   S000, S003, S002
    mfv      $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
