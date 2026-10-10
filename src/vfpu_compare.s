/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Equals_U
    comparisonOpVec_U vcmp.p, eq
    jr $ra

gfunc vfpu_Vec3Equals_U
    comparisonOpVec_U vcmp.t, eq
    jr $ra

gfunc vfpu_Vec4Equals_U
    comparisonOpVec_U vcmp.q, eq
    jr $ra

gfunc vfpu_Vec2Equals
    comparisonOpVec vcmp.p, eq
    jr $ra

gfunc vfpu_Vec3Equals
    comparisonOpVec vcmp.t, eq
    jr $ra

gfunc vfpu_Vec2pEquals
gfunc vfpu_Vec4Equals
    comparisonOpVec vcmp.q, eq
    jr $ra

gfunc vfpu_Vec2LessThan_U
    comparisonOpVec_U vcmp.p, lt
    jr $ra

gfunc vfpu_Vec3LessThan_U
    comparisonOpVec_U vcmp.t, lt
    jr $ra

gfunc vfpu_Vec4LessThan_U
    comparisonOpVec_U vcmp.q, lt
    jr $ra

gfunc vfpu_Vec2LessThan
    comparisonOpVec vcmp.p, lt
    jr $ra

gfunc vfpu_Vec3LessThan
    comparisonOpVec vcmp.t, lt
    jr $ra

gfunc vfpu_Vec2pLessThan
gfunc vfpu_Vec4LessThan
    comparisonOpVec vcmp.q, lt
    jr $ra

gfunc vfpu_Vec2LessThanEqual_U
    comparisonOpVec_U vcmp.p, le
    jr $ra

gfunc vfpu_Vec3LessThanEqual_U
    comparisonOpVec_U vcmp.t, le
    jr $ra

gfunc vfpu_Vec4LessThanEqual_U
    comparisonOpVec_U vcmp.q, le
    jr $ra

gfunc vfpu_Vec2LessThanEqual
    comparisonOpVec vcmp.p, le
    jr $ra

gfunc vfpu_Vec3LessThanEqual
    comparisonOpVec vcmp.t, le
    jr $ra

gfunc vfpu_Vec2pLessThanEqual
gfunc vfpu_Vec4LessThanEqual
    comparisonOpVec vcmp.q, le
    jr $ra

gfunc vfpu_Vec2GreaterThan_U
    comparisonOpVec_U vcmp.p, gt
    jr $ra

gfunc vfpu_Vec3GreaterThan_U
    comparisonOpVec_U vcmp.t, gt
    jr $ra

gfunc vfpu_Vec4GreaterThan_U
    comparisonOpVec_U vcmp.q, gt
    jr $ra

gfunc vfpu_Vec2GreaterThan
    comparisonOpVec vcmp.p, gt
    jr $ra

gfunc vfpu_Vec3GreaterThan
    comparisonOpVec vcmp.t, gt
    jr $ra

gfunc vfpu_Vec2pGreaterThan
gfunc vfpu_Vec4GreaterThan
    comparisonOpVec vcmp.q, gt
    jr $ra

gfunc vfpu_Vec2GreaterThanEqual_U
    comparisonOpVec_U vcmp.p, ge
    jr $ra

gfunc vfpu_Vec3GreaterThanEqual_U
    comparisonOpVec_U vcmp.t, ge
    jr $ra

gfunc vfpu_Vec4GreaterThanEqual_U
    comparisonOpVec_U vcmp.q, ge
    jr $ra

gfunc vfpu_Vec2GreaterThanEqual
    comparisonOpVec vcmp.p, ge
    jr $ra

gfunc vfpu_Vec3GreaterThanEqual
    comparisonOpVec vcmp.t, ge
    jr $ra

gfunc vfpu_Vec2pGreaterThanEqual
gfunc vfpu_Vec4GreaterThanEqual
    comparisonOpVec vcmp.q, ge
    jr $ra

gfunc vfpu_Vec2Compare_U
    singleOpVec2_U vscmp.p
    jr $ra

gfunc vfpu_Vec3Compare_U
    singleOpVec3_U vscmp.t
    jr $ra

gfunc vfpu_Vec4Compare_U
    singleOpVec4_U vscmp.q
    jr $ra

gfunc vfpu_Vec2pCompare_U
gfunc vfpu_Vec4Compare
    singleOpVecV vscmp.q
    jr $ra
