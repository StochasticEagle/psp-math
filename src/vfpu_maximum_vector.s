#include "vfpu_macros.inc"


gfunc vfpu_Vec2Maximum_U
    singleOpVec2_U vmax.p
    jr $ra

gfunc vfpu_Vec3Maximum_U
    singleOpVec3_U vmax.t
    jr $ra

gfunc vfpu_Vec4Maximum_U
    singleOpVec4_U vmax.q
    jr $ra

gfunc vfpu_VecVMaximum
    singleOpVecV vmax.q
    jr $ra
