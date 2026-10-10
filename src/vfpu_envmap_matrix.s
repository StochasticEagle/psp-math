#include "vfpu_macros.inc"

gfunc vfpu_Vec4EnvironmentMap
    mtv $a1, S000
    vcst.s S001, VFPU_2_PI
    vmul.s S000, S000, S001
    vrot.q C010, S000, [c,s,0,0]
    vrot.q C020, S000, [-s,c,0,0]
    sv.q C010, 0($a0)
    sv.q C020, 16($a0)
    jr $ra
    nop
