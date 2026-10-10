/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_SquareRoot
    singleOpSca2Sca vsqrt.s
    jr $ra

gfunc vfpu_Vec2SquareRoot_U
    singleOpSVec2_U vsqrt.p
    jr $ra

gfunc vfpu_Vec3SquareRoot_U
    singleOpSVec3_U vsqrt.t
    jr $ra

gfunc vfpu_Vec4SquareRoot_U
    singleOpSVec4_U vsqrt.q
    jr $ra

gfunc vfpu_Vec2SquareRoot
    singleOpsVecV vsqrt.p
    jr $ra

gfunc vfpu_Vec3SquareRoot
    singleOpsVecV vsqrt.t
    jr $ra

gfunc vfpu_VecVSquareRoot
gfunc vfpu_Vec4SquareRoot
    singleOpsVecV vsqrt.q
    jr $ra
