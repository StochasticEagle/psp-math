/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_AbsoluteValue
    singleOpSca2Sca vabs.s
    jr $ra

gfunc vfpu_Vec2AbsoluteValue_U
    singleOpSVec2_U vabs.p
    jr $ra

gfunc vfpu_Vec3AbsoluteValue_U
    singleOpSVec3_U vabs.t
    jr $ra

gfunc vfpu_Vec4AbsoluteValue_U
    singleOpSVec4_U vabs.q
    jr $ra

gfunc vfpu_Vec2pAbsoluteValue
gfunc vfpu_Vec4AbsoluteValue
    singleOpSVecV vabs.q
    jr $ra

