/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Magnitude_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vmul.p r001, r000, r000
    vfad.p s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec3Magnitude_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vmul.t r001, r000, r000
    vfad.t s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra



gfunc vfpu_QuatNorm_U
gfunc vfpu_Vec4Magnitude_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vmul.q r001, r000, r000
    vfad.q s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec2Magnitude
    lv.q r000, 0($a0)
    vmul.p r001, r000, r000
    vfad.p s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec3Magnitude
    lv.q r000, 0($a0)
    vmul.t r001, r000, r000
    vfad.t s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_QuatNorm
gfunc vfpu_Vec4Magnitude
    lv.q r000, 0($a0)
    vmul.q r001, r000, r000
    vfad.q s002, r001
    vsqrt.s s003, s002
    mfv $t0, s003
    mtc1 $t0, $f0
    jr $ra
