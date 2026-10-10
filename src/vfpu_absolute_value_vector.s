#include "vfpu_macros.inc"

gfunc vfpu_AbsoluteValue
    singleOpSca2Sca vabs.s
    jr $ra

gfunc vfpu_Vec2_AbsoluteValue_U
    singleOpSVec2_U vabs.p
    jr $ra

gfunc vfpu_Vec3_AbsoluteValue_U
    singleOpSVec3_U vabs.t
    jr $ra

gfunc vfpu_Vec4_AbsoluteValue_U
    singleOpSVec4_U vabs.q
    jr $ra

gfunc vfpu_VecVAbsoluteValue
    singleOpSVecV vabs.q
    jr $ra

