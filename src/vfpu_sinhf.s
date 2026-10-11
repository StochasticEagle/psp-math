#include "vfpu_macros.inc"

gfunc vfpu_sinhf
    mfc1 $t0, $f12
    mtv      $t0, S000
    vcst.s   S001, VFPU_LOG2E
    vmov.s   S002, S000[|x|]
    vcmp.s   NE, S000, S002
    vmul.s   S002, S001, S002
    vexp2.s  S002, S002
    vrcp.s   S003, S002
    vsub.s   S002, S002, S003
    vmul.s   S002, S002, S002[1/2]
    vcmov.s  S002, S002[-x], 0
    mfv      $t0, S002
    mtc1 $t0, $f0
    jr $ra
    nop
