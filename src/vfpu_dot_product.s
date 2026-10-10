#include "vfpu_macros.inc"


gfunc vfpu_Vec2DotProduct_U
    singleOpScaDV_U vdot.p
    jr $ra

gfunc vfpu_Vec3DotProduct_U
    singleOpScaDV_U vdot.t
    jr $ra

gfunc vfpu_Vec4DotProduct_U
    singleOpScaDV_U vdot.q
    jr $ra

gfunc vfpu_Vec2DotProduct
    singleOpScaDV vdot.p
    jr $ra

gfunc vfpu_Vec3DotProduct
    singleOpScaDV vdot.t
    jr $ra

gfunc vfpu_Vec4DotProduct
    singleOpScaDV vdot.q
    jr $ra
