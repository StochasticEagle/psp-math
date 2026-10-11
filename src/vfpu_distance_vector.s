#include "vfpu_macros.inc"


gfunc vfpu_Vec2Distance_U
    ulv.q C000, 0($a0)
    ulv.q C010, 0($a1)
    vsub.p C020, C000, C010
    svp S020, S021, $a2, 0
    jr $ra
    nop

gfunc vfpu_Vec3Distance_U
    ulv.q C000, 0($a0)
    ulv.q C010, 0($a1)
    vsub.t C020, C000, C010
    svt S020, S021, S022, $a2, 0
    jr $ra
    nop

gfunc vfpu_Vec4Distance_U
    ulv.q C000, 0($a0)
    ulv.q C010, 0($a1)
    vsub.q C020, C000, C010
    usv.q C020, 0($a2)
    jr $ra
    nop

gfunc vfpu_Vec2pDistance
gfunc vfpu_Vec4Distance
    lv.q      C000, 0($a0)
    lv.q      C010, 0($a1)
    vsub.q    C020, C000, C010
    vabs.q    C020, C020
    sv.q      C020, 0($a2)
    jr $ra
    nop
