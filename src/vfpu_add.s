/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"



gfunc vfpu_Vec2_Add_U
    singleOpVec2_U vadd.p
    jr $ra

gfunc vfpu_Vec3_Add_U
    singleOpVec3_U vadd.t
    jr $ra

gfunc vfpu_Mat2Add_U
gfunc vfpu_Vec4_Add_U
    singleOpVec4_U vadd.q
    jr $ra

gfunc vfpu_Mat2Add
gfunc vfpu_VecVAdd
    singleOpVecV vadd.q
    jr $ra


gfunc vfpu_Mat3_Add_U
    singleOpMat3_U vadd
    jr $ra

gfunc vfpu_Mat4_Add_U
    singleOpMat4_U vadd
    jr $ra

gfunc vfpu_Mat3_Add
    singleOpMat3 vadd
    jr $ra

gfunc vfpu_Mat4_Add
    singleOpMat4 vadd
    jr $ra





gfunc vfpu_Vec2Sum_U
    singleOpScaV_U vfad.p
    jr $ra

gfunc vfpu_Vec3Sum_U
    singleOpScaV_U vfad.t
    jr $ra

gfunc vfpu_Vec4Sum_U
    singleOpScaV_U vfad.q
    jr $ra

gfunc vfpu_Vec2Sum
    singleOpScaV vfad.p
    jr $ra

gfunc vfpu_Vec3Sum
    singleOpScaV vfad.t
    jr $ra

gfunc vfpu_Vec4Sum
    singleOpScaV vfad.q
    jr $ra
