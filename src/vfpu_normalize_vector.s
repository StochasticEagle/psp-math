
/* pspla names but different, optimal functions.
 */

#include "vfpu_macros.inc"

gfunc vfpu_Vec2Normalize_U
    ulv.q r000, 0($a0)
    vdot.p s002, r000, r000
    vrsq.s s002, s002
    vscl.p r000, r000, s002
    svp s000, s010, $a1, 0
    jr $ra
    nop

gfunc vfpu_Vec3Normalize_U
    ulv.q r000, 0($a0)
    vdot.t s002, r000, r000
    vrsq.s s002, s002
    vscl.t r000, r000, s002
    svt s000, s010, s020, $a1, 0
    jr $ra
    nop

gfunc vfpu_QuatNormalize_U
gfunc vfpu_Vec4Normalize_U
    ulv.q r000, 0($a0)
    vdot.q s002, r000, r000
    vzero.s s003
    vcmp.s EQ, s002, s003
    vone.s s003
    vcmovt.s s002, s003, 0
    vrsq.s s002, s002
    vscl.q r000, r000, s002
    usv.q r000, 0($a1)
    jr $ra
    nop

gfunc vfpu_Vec2Normalize
    lv.q r000, 0($a0)
    vdot.p s002, r000, r000
    vrsq.s s002, s002
    vscl.p r000, r000, s002
    svp s000, s010, $a1, 0
    jr $ra
    nop

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
    nop

gfunc vfpu_Vec3Normalize
    lv.q r000, 0($a0)
    vdot.t s002, r000, r000
    vrsq.s s002, s002
    vscl.t r000, r000, s002
    svt s000, s010, s020, $a1, 0
    jr $ra
    nop

gfunc vfpu_QuatNormalize
gfunc vfpu_Vec4Normalize
    lv.q r000, 0($a0)
    vdot.q s002, r000, r000
    vzero.s s003
    vcmp.s EQ, s002, s003
    vone.s s003
    vcmovt.s s002, s003, 0
    vrsq.s s002, s002
    vscl.q r000, r000, s002
    sv.q r000, 0($a1)
    jr $ra
    nop
