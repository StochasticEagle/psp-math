/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Round_U
    truncateOpVec2_U vf2in.p
    jr $ra
    nop

gfunc vfpu_Vec3Round_U
    truncateOpVec3_U vf2in.t
    jr $ra
    nop

gfunc vfpu_Vec4Round_U
    truncateOpVec4_U vf2in.q
    jr $ra
    nop

gfunc vfpu_Vec2pRound_U
    truncateOpVec4_U vf2in.q
    jr $ra
    nop

gfunc vfpu_Vec4Round
    truncateOpVecV vf2in.q
    jr $ra
    nop

gfunc vfpu_Vec2Floor_U
    truncateOpVec2_U vf2iz.p
    jr $ra
    nop

gfunc vfpu_Vec3Floor_U
    truncateOpVec3_U vf2iz.t
    jr $ra
    nop

gfunc vfpu_Vec4Floor_U
    truncateOpVec4_U vf2iz.q
    jr $ra
    nop

gfunc vfpu_Vec2pFloor_U
    truncateOpVec4_U vf2iz.q
    jr $ra
    nop

gfunc vfpu_Vec4Floor
    truncateOpVecV vf2iz.q
    jr $ra
    nop

gfunc vfpu_Vec2Ceiling_U
    truncateOpVec2_U vf2iu.p
    jr $ra
    nop

gfunc vfpu_Vec3Ceiling_U
    truncateOpVec3_U vf2iu.t
    jr $ra
    nop

gfunc vfpu_Vec4Ceiling_U
    truncateOpVec4_U vf2iu.q
    jr $ra
    nop

gfunc vfpu_Vec2pCeiling_U
    truncateOpVec4_U vf2iu.q
    jr $ra
    nop

gfunc vfpu_Vec4Ceiling
    truncateOpVecV vf2iu.q
    jr $ra
    nop
