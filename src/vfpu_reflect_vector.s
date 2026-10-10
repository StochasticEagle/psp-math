/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


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
    nop

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
    nop

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
    nop

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
    nop

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
    nop


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
    nop

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
    nop
