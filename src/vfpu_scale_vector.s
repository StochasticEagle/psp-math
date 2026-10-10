/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Scale_U
    singleOpVec2Sca_U vscl.p
    jr $ra

gfunc vfpu_Vec3Scale_U
    singleOpVec3Sca_U vscl.t
    jr $ra

gfunc vfpu_Mat2Scale_U
gfunc vfpu_Vec4Scale_U
    singleOpVec4Sca_U vscl.q
    jr $ra

gfunc vfpu_Mat2Scale
gfunc vfpu_Vec2pScale_U
gfunc vfpu_Vec4Scale
    singleOpVecVSca vscl.q
    jr $ra
