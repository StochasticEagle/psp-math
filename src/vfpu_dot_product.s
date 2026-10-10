/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2DotProduct_U
    singleOpScaDV_U vdot.p
    jr $ra
    nop

gfunc vfpu_Vec3DotProduct_U
    singleOpScaDV_U vdot.t
    jr $ra
    nop

gfunc vfpu_Vec4DotProduct_U
    singleOpScaDV_U vdot.q
    jr $ra
    nop

gfunc vfpu_Vec2DotProduct
    singleOpScaDV vdot.p
    jr $ra
    nop

gfunc vfpu_Vec2pDotProduct
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vdot.p s200, r000, r001
    vmov.q r002, r000[z,w,z,w]
    vmov.q r003, r001[z,w,z,w]
    vdot.p s210, r002, r003
    sv.s s200, 0($a2)
    sv.s s210, 4($a2)
    jr $ra
    nop

gfunc vfpu_Vec3DotProduct
    singleOpScaDV vdot.t
    jr $ra
    nop

gfunc vfpu_Vec4DotProduct
    singleOpScaDV vdot.q
    jr $ra
    nop
