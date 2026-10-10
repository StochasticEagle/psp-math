/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Minimum_U
    singleOpVec2_U vmin.p
    jr $ra
    nop

gfunc vfpu_Vec3Minimum_U
    singleOpVec3_U vmin.t
    jr $ra
    nop

gfunc vfpu_Vec4Minimum_U
    singleOpVec4_U vmin.q
    jr $ra
    nop

gfunc vfpu_Vec2pMinimum
gfunc vfpu_Vec4Minimum
    singleOpVecV vmin.q
    jr $ra
    nop
