/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Clamp_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    mfc1 $t1, $f13
    mtv $t1, s003
    vmov.s s012, s002
    vmov.s s013, s003
    vcmp.p lt, r000, r002
    vcmovt.p r000, r002, 6
    vcmp.p gt, r000, r003
    vcmovt.p r000, r003, 6
    svp s000, s010, $a1, 0
    jr $ra

gfunc vfpu_Vec3Clamp_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    mfc1 $t1, $f13
    mtv $t1, s003
    vmov.t r002, r002[x,x,x]
    vmov.t r003, r003[x,x,x]
    vcmp.t lt, r000, r002
    vcmovt.t r000, r002, 6
    vcmp.t gt, r000, r003
    vcmovt.t r000, r003, 6
    svt s000, s010, s020, $a1, 0
    jr $ra

gfunc vfpu_Vec4Clamp_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    mfc1 $t1, $f13
    mtv $t1, s003
    vmov.q r002, r002[x,x,x,x]
    vmov.q r003, r003[x,x,x,x]
    vcmp.q lt, r000, r002
    vcmovt.q r000, r002, 6
    vcmp.q gt, r000, r003
    vcmovt.q r000, r003, 6
    usv.q r000, 0($a1)
    jr $ra

gfunc vfpu_Vec2pClamp
gfunc vfpu_Vec4Clamp
    lv.q r000, 0($a0)
    mfc1 $t0, $f12
    mtv $t0, s002
    mfc1 $t1, $f13
    mtv $t1, s003
    vmov.q r002, r002[x,x,x,x]
    vmov.q r003, r003[x,x,x,x]
    vcmp.q lt, r000, r002
    vcmovt.q r000, r002, 6
    vcmp.q gt, r000, r003
    vcmovt.q r000, r003, 6
    sv.q r000, 0($a1)
    jr $ra
