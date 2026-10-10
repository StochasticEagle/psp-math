#include "vfpu_macros.inc"

gfunc vfpu_sincos
    mfc1 $t0, $f12
    mtv $t0, S002
    vcst.s S003, VFPU_2_PI
    vmul.s S002, S002, S003
    vrot.p C000, S002, [s,c]
    mfv $t0, S000
    mfv $t1, S001
    sw $t0, 0($a1)
    sw $t1, 0($a2)
    jr $ra
    nop
