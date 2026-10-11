/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Cosine_U
    singleOpSVec2_U vcos.p
    jr $ra
    nop

gfunc vfpu_Vec3Cosine_U
    singleOpSVec3_U vcos.t
    jr $ra
    nop

gfunc vfpu_Vec4Cosine_U
    singleOpSVec4_U vcos.q
    jr $ra
    nop

gfunc vfpu_Vec2Cosine
    singleOpSVec2 vcos.p
    jr $ra
    nop

gfunc vfpu_Vec3Cosine
    singleOpSVec3 vcos.t
    jr $ra
    nop

gfunc vfpu_Vec2pCosine
gfunc vfpu_Vec4Cosine
    singleOpSVecV vcos.q
    jr $ra
    nop
