#include "vfpu_macros.inc"


gfunc vfpu_Vec2Subtract_U
    singleOpVec2_U vsub.p
    jr $ra

gfunc vfpu_Vec3Subtract_U
    singleOpVec3_U vsub.t
    jr $ra

gfunc vfpu_Mat2Subtract_U
gfunc vfpu_Vec4Subtract_U
    singleOpVec4_U vsub.q
    jr $ra

gfunc vfpu_Mat2Subtract
gfunc vfpu_VecVSubtract
    singleOpVecV vsub.q
    jr $ra


gfunc vfpu_Mat3Subtract_U
    singleOpMat3_U vsub
    jr $ra

gfunc vfpu_Mat4Subtract_U
    singleOpMat4_U vsub
    jr $ra

gfunc vfpu_Mat3Subtract
    singleOpMat3 vsub
    jr $ra

gfunc vfpu_Mat4Subtract
    singleOpMat4 vsub
    jr $ra
