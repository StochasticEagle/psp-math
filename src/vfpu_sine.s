/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Sine_U
    singleOpSVec2_U vsin.p
    jr $ra
    nop

gfunc vfpu_Vec3Sine_U
    singleOpSVec3_U vsin.t
    jr $ra
    nop

gfunc vfpu_Vec4Sine_U
    singleOpSVec4_U vsin.q
    jr $ra
    nop

gfunc vfpu_Vec2Sine
    singleOpSVec2 vsin.p
    jr $ra
    nop

gfunc vfpu_Vec3Sine
    singleOpSVec3 vsin.t
    jr $ra
    nop

gfunc vfpu_Vec2pSine
gfunc vfpu_Vec4Sine
    singleOpSVecV vsin.q
    jr $ra
    nop
