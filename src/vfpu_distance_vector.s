#include "vfpu_macros.inc"


gfunc vfpu_Vec2Distance_U
    lv.s      S000, 0(%1)
    lv.s      S001, 4(%1)
    lv.s      S010, 0(%2)
    lv.s      S011, 4(%2)
    vsub.p    C020, C000, C010
    sv.s      S020, 0(%0)
    sv.s      S021, 4(%0)
    jr $ra
    nop

gfunc vfpu_Vec3Distance_U
    lv.s      S000, 0(%1)
    lv.s      S001, 4(%1)
    lv.s      S002, 8(%1)
    lv.s      S010, 0(%2)
    lv.s      S011, 4(%2)
    lv.s      S012, 8(%2)
    vsub.t    C020, C000, C010
    sv.s      S020, 0(%0)
    sv.s      S021, 4(%0)
    sv.s      S022, 8(%0)
    jr $ra
    nop

gfunc vfpu_Vec4Distance_U
    lv.s      S000,  0(%1)
    lv.s      S001,  4(%1)
    lv.s      S002,  8(%1)
    lv.s      S003, 12(%1)
    lv.s      S010,  0(%2)
    lv.s      S011,  4(%2)
    lv.s      S012,  8(%2)
    lv.s      S013, 12(%2)
    vsub.q    C020, C000, C010
    sv.s      S020,  0(%0)
    sv.s      S021,  4(%0)
    sv.s      S022,  8(%0)
    sv.s      S023, 12(%0)
    jr $ra
    nop

gfunc vfpu_Vec2pDistance
gfunc vfpu_Vec4Distance
    lv.q      C000, 0(%1)
    lv.q      C010, 0(%2)
    vsub.q    C020, C000, C010
    vabs.q    C020, C020
    sv.q      C020, 0(%0)
    jr $ra
    nop
