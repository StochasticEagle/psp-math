/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Negate_U
    singleOpSVec2_U vneg.p
    jr $ra

gfunc vfpu_Vec3Negate_U
    singleOpSVec3_U vneg.t
    jr $ra

gfunc vfpu_Vec4Negate_U
    singleOpSVec4_U vneg.q
    jr $ra

gfunc vfpu_Vec4Negate
    singleOpSVecV vneg.q
    jr $ra
