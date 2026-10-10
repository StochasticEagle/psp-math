/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"



gfunc vfpu_Vec2Divide_U
    singleOpVec2_U vdiv.p
    jr $ra

gfunc vfpu_Vec3Divide_U
    singleOpVec3_U vdiv.t
    jr $ra

gfunc vfpu_Vec4Divide_U
    singleOpVec4_U vdiv.q
    jr $ra

gfunc vfpu_Vec2Divide
    singleOpVecV vdiv.p
    jr $ra

gfunc vfpu_Vec3Divide
    singleOpVecV vdiv.t
    jr $ra

gfunc vfpu_Vec2pDivide
gfunc vfpu_Vec4Divide
    singleOpVecV vdiv.q
    jr $ra
