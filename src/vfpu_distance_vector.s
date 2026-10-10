#include "vfpu_macros.inc"


gfunc vfpu_Vec2Distance_U
    lv.s      S000, 0($a0)
    lv.s      S001, 4($a0)
    lv.s      S010, 0($a1)
    lv.s      S011, 4($a1)
    vsub.p    C020, C000, C010
    sv.s      S020, 0($a2)
    sv.s      S021, 4($a2)
    jr $ra
    nop

gfunc vfpu_Vec3Distance_U
    lv.s      S000, 0($a0)
    lv.s      S001, 4($a0)
    lv.s      S002, 8($a0)
    lv.s      S010, 0($a1)
    lv.s      S011, 4($a1)
    lv.s      S012, 8($a1)
    vsub.t    C020, C000, C010
    sv.s      S020, 0($a2)
    sv.s      S021, 4($a2)
    sv.s      S022, 8($a2)
    jr $ra
    nop

gfunc vfpu_Vec4Distance_U
    lv.s      S000,  0($a0)
    lv.s      S001,  4($a0)
    lv.s      S002,  8($a0)
    lv.s      S003, 12($a0)
    lv.s      S010,  0($a1)
    lv.s      S011,  4($a1)
    lv.s      S012,  8($a1)
    lv.s      S013, 12($a1)
    vsub.q    C020, C000, C010
    sv.s      S020,  0($a2)
    sv.s      S021,  4($a2)
    sv.s      S022,  8($a2)
    sv.s      S023, 12($a2)
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
