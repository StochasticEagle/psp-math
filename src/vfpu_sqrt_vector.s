/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
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
    singleOpSVecV vsqrt.p
    jr $ra

gfunc vfpu_Vec3SquareRoot
    singleOpSVecV vsqrt.t
    jr $ra

gfunc vfpu_Vec2pSquareRoot
gfunc vfpu_Vec4SquareRoot
    singleOpSVecV vsqrt.q
    jr $ra
