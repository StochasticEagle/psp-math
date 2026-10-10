#include "vfpu_macros.inc"

gfunc vfpu_Vec2Reflect_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    vfim.s s003, 2
    vdot.p s002, r000, r001
    vscl.p r001, r001, s002
    vscl.p r001, r001, s003
    vsub.p r000, r000, r001
    svp s000, s010, $a2, 0
    jr $ra

gfunc vfpu_Vec3Reflect_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    vfim.s s003, 2
    vdot.t s002, r000, r001
    vscl.t r001, r001, s002
    vscl.t r001, r001, s003
    vsub.t r000, r000, r001
    svt s000, s010, s020, $a2, 0
    jr $ra

gfunc vfpu_Vec4Reflect_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    vfim.s s003, 2
    vdot.q s002, r000, r001
    vscl.q r001, r001, s002
    vscl.q r001, r001, s003
    vsub.q r000, r000, r001
    usv.q r000, 0($a2)
    jr $ra

gfunc vfpu_Vec2Reflect
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vfim.s s003, 2
    vdot.p s002, r000, r001
    vscl.p r001, r001, s002
    vscl.p r001, r001, s003
    vsub.p r000, r000, r001
    sv.q r000, 0($a2)
    jr $ra

gfunc vfpu_Vec3Reflect
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vfim.s s003, 2
    vdot.t s002, r000, r001
    vscl.t r001, r001, s002
    vscl.t r001, r001, s003
    vsub.t r000, r000, r001
    sv.q r000, 0($a2)
    jr $ra

gfunc vfpu_Vec4Reflect
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vfim.s s003, 2
    vdot.q s002, r000, r001
    vscl.q r001, r001, s002
    vscl.q r001, r001, s003
    vsub.q r000, r000, r001
    sv.q r000, 0($a2)
    jr $ra
