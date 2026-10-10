/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"



gfunc vfpu_Vec2Average_U
    singleOpScaV_U vavg.p
    jr $ra

gfunc vfpu_Vec3Average_U
    singleOpScaV_U vavg.t
    jr $ra

gfunc vfpu_Vec4Average_U
    singleOpScaV_U vavg.q
    jr $ra

gfunc vfpu_Vec2Average
    singleOpScaV vavg.p
    jr $ra

gfunc vfpu_Vec3Average
    singleOpScaV vavg.t
    jr $ra

gfunc vfpu_Vec4Average
    singleOpScaV vavg.q
    jr $ra
