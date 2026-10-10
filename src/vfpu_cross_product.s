#include "vfpu_macros.inc"


gfunc vfpu_Vec3CrossProduct_U
    singleOpVec3_U vcrsp.t
    jr $ra

gfunc vfpu_Vec3CrossProduct
    singleOpVecV vcrsp.t
    jr $ra
