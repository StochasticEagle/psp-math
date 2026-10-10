/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


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

gfunc vfpu_Vec2pSum
    pair_reduce vfad
    jr $ra

gfunc vfpu_Vec3Sum
    singleOpScaV vfad.t
    jr $ra

gfunc vfpu_Vec4Sum
    singleOpScaV vfad.q
    jr $ra




