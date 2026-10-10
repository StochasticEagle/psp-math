#include "vfpu_macros.inc"

/* Two independent XY vectors in each aligned 128-bit quad. */
.macro pair_reduce op
    lv.q r000, 0($a0)
    \op\().p s200, r000
    vmov.q r001, r000[z,w,z,w]
    \op\().p s210, r001
    sv.s s200, 0($a1)
    sv.s s210, 4($a1)
.endm

gfunc vfpu_Vec2pSum
    pair_reduce vfad
    jr $ra

gfunc vfpu_Vec2pAverage
    pair_reduce vavg
    jr $ra

gfunc vfpu_Vec2pDotProduct
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vdot.p s200, r000, r001
    vmov.q r002, r000[z,w,z,w]
    vmov.q r003, r001[z,w,z,w]
    vdot.p s210, r002, r003
    sv.s s200, 0($a2)
    sv.s s210, 4($a2)
    jr $ra

gfunc vfpu_Vec2pMagnitude
    lv.q r000, 0($a0)
    vdot.p s200, r000, r000
    vmov.q r001, r000[z,w,z,w]
    vdot.p s210, r001, r001
    vsqrt.s s200, s200
    vsqrt.s s210, s210
    sv.s s200, 0($a1)
    sv.s s210, 4($a1)
    jr $ra

gfunc vfpu_Vec2pNormalize
    lv.q r000, 0($a0)
    vdot.p s200, r000, r000
    vmov.q r001, r000[z,w,z,w]
    vdot.p s210, r001, r001
    vrsq.s s200, s200
    vrsq.s s210, s210
    vscl.p r000, r000, s200
    vscl.p r001, r001, s210
    sv.s s000, 0($a1)
    sv.s s010, 4($a1)
    sv.s s001, 8($a1)
    sv.s s011, 12($a1)
    jr $ra

gfunc vfpu_Vec2pReflect
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vdot.p s200, r000, r001
    vmov.q r002, r000[z,w,z,w]
    vmov.q r003, r001[z,w,z,w]
    vdot.p s210, r002, r003
    vfim.s s220, 2
    vmul.s s200, s200, s220
    vmul.s s210, s210, s220
    vscl.p r001, r001, s200
    vsub.p r000, r000, r001
    vscl.p r003, r003, s210
    vsub.p r002, r002, r003
    sv.s s000, 0($a2)
    sv.s s010, 4($a2)
    sv.s s002, 8($a2)
    sv.s s012, 12($a2)
    jr $ra

