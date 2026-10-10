#include "vfpu_macros.inc"

gfunc vfpu_tanf
    mfc1 $t0, $f12
    mtv      $t0, S000
    vcst.s   S001, VFPU_2_PI
    vmul.s   S000, S000, S001
    vrot.p   C002, S000, [s, c]
    vdiv.s   S000, S002, S003
    mfv      $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
