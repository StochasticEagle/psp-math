/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Subtract_U
    singleOpVec2_U vsub.p
    jr $ra
    nop

gfunc vfpu_Vec3Subtract_U
    singleOpVec3_U vsub.t
    jr $ra
    nop

gfunc vfpu_Mat2Subtract_U
gfunc vfpu_Vec4Subtract_U
    singleOpVec4_U vsub.q
    jr $ra
    nop

gfunc vfpu_Mat2Subtract
gfunc vfpu_Vec2pSubtract
gfunc vfpu_Vec4Subtract
    singleOpVecV vsub.q
    jr $ra
    nop


gfunc vfpu_Mat3Subtract_U
    singleOpMat3_U vsub
    jr $ra
    nop

gfunc vfpu_Mat4Subtract_U
    singleOpMat4_U vsub
    jr $ra
    nop

gfunc vfpu_Mat3Subtract
    singleOpMat3 vsub
    jr $ra
    nop

gfunc vfpu_Mat4Subtract
    singleOpMat4 vsub
    jr $ra
    nop
