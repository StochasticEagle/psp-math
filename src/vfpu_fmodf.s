#include "vfpu_macros.inc"

gfunc vfpu_fmodf
    mfc1 $t0, $f12
    mfc1 $t1, $f14
    mtv       $t1, S001
    mtv       $t0, S000
    vrcp.s    S002, S001
    vmul.s    S003, S000, S002
    vf2iz.s   S002, S003, 0
    vi2f.s    S003, S002, 0
    vmul.s    S003, S003, S001
    vsub.s    S000, S000, S003
    mfv       $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
