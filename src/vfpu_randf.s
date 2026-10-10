#include "vfpu_macros.inc"

gfunc vfpu_randf
    mfc1 $t0, $f12
    mfc1 $t1, $f14
    mtv      $t0, S000
    mtv      $t1, S001
    vsub.s   S001, S001, S000
    vrndf1.s S002
    vone.s	  S003
    vsub.s   S002, S002, S003
    vmul.s   S001, S002, S001
    vadd.s   S000, S000, S001
    mfv      $t0, S000
    mtc1 $t0, $f0
    jr $ra
    nop
