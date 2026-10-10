/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Sine
    singleOpSca2Sca vsin.s
    jr $ra


gfunc vfpu_Vec2Sine_U
    singleOpSVec2_U vsin.p
    jr $ra

gfunc vfpu_Vec3Sine_U
    singleOpSVec3_U vsin.t
    jr $ra

gfunc vfpu_Vec4Sine_U
    singleOpSVec4_U vsin.q
    jr $ra

gfunc vfpu_Vec2Sine
    singleOpsVecV vsin.p
    jr $ra

gfunc vfpu_Vec3Sine
    singleOpsVecV vsin.t
    jr $ra

gfunc vfpu_Vec4Sine
    singleOpsVecV vsin.q
    jr $ra
