/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"



gfunc vfpu_Vec2Add_U
    singleOpVec2_U vadd.p
    jr $ra

gfunc vfpu_Vec3Add_U
    singleOpVec3_U vadd.t
    jr $ra

gfunc vfpu_Mat2Add_U
gfunc vfpu_Vec4Add_U
    singleOpVec4_U vadd.q
    jr $ra

gfunc vfpu_Mat2Add
gfunc vfpu_Vec4Add
gfunc vfpu_VecVAdd
    singleOpVecV vadd.q
    jr $ra


gfunc vfpu_Mat3Add_U
    singleOpMat3_U vadd
    jr $ra

gfunc vfpu_Mat4Add_U
    singleOpMat4_U vadd
    jr $ra

gfunc vfpu_Mat3Add
    singleOpMat3 vadd
    jr $ra

gfunc vfpu_Mat4Add
    singleOpMat4 vadd
    jr $ra




