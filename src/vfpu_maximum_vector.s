/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Maximum_U
    singleOpVec2_U vmax.p
    jr $ra
    nop

gfunc vfpu_Vec3Maximum_U
    singleOpVec3_U vmax.t
    jr $ra
    nop

gfunc vfpu_Vec4Maximum_U
    singleOpVec4_U vmax.q
    jr $ra
    nop

gfunc vfpu_Vec4Maximum
    singleOpVecV vmax.q
    jr $ra
    nop
