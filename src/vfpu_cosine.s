/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Cosine
    singleOpSca2Sca vcos.s
    jr $ra



gfunc vfpu_Vec2Cosine_U
    singleOpSVec2_U vcos.p
    jr $ra

gfunc vfpu_Vec3Cosine_U
    singleOpSVec3_U vcos.t
    jr $ra

gfunc vfpu_Vec4Cosine_U
    singleOpSVec4_U vcos.q
    jr $ra

gfunc vfpu_Vec2Cosine
    singleOpsVecV vcos.p
    jr $ra

gfunc vfpu_Vec3Cosine
    singleOpsVecV vcos.t
    jr $ra

gfunc vfpu_Vec4Cosine
    singleOpsVecV vcos.q
    jr $ra
