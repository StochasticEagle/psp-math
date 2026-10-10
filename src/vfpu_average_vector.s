#include "vfpu_macros.inc"



gfunc vfpu_Vec2_Average_U
    singleOpScaV_U vavg.p
    jr $ra

gfunc vfpu_Vec3_Average_U
    singleOpScaV_U vavg.t
    jr $ra

gfunc vfpu_Vec4_Average_U
    singleOpScaV_U vavg.q
    jr $ra

gfunc vfpu_Vec2_Average
    singleOpScaV vavg.p
    jr $ra

gfunc vfpu_Vec3_Average
    singleOpScaV vavg.t
    jr $ra

gfunc vfpu_Vec4_Average
    singleOpScaV vavg.q
    jr $ra
