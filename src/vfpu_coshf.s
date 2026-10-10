#include "vfpu_macros.inc"

gfunc vfpu_coshf
    mfc1 $t0, $f12
    mtv      $t0, S000
    vcst.s   S001, VFPU_LN2
    vrcp.s   S001, S001
    vmov.s   S002, S000[|x|]
    vmul.s   S002, S001, S002
    vexp2.s  S002, S002
    vrcp.s   S003, S002
    vadd.s   S002, S002, S003
    vmul.s   S002, S002, S002[1/2]
    mfv      $t0, S002
    mtc1 $t0, $f0
    jr $ra
    nop
