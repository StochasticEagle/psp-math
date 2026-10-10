/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Lerp_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    vfim.s s012, 1
    vscl.p r001, r001, s002
    vsub.s s012, s012, s002
    vscl.p r000, r000, s012
    vadd.p r003, r000, r001
    svp s003, s013, $a2, 0
    jr $ra
    nop

gfunc vfpu_Vec3Lerp_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    vfim.s s012, 1
    vscl.t r001, r001, s002
    vsub.s s012, s012, s002
    vscl.t r000, r000, s012
    vadd.t r003, r000, r001
    svt s003, s013, s023, $a2, 0
    jr $ra
    nop

gfunc vfpu_QuatLerp_U
gfunc vfpu_Vec4Lerp_U
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s002
    vsub.q r001, r001, r000
    vscl.q r001, r001, s002
    vadd.q r003, r000, r001
    usv.q r003, 0($a2)
    jr $ra
    nop

gfunc vfpu_QuatLerp
gfunc vfpu_Vec2pLerp
gfunc vfpu_Vec4Lerp
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    mfc1 $t0, $f12
    mtv $t0, s002
    vsub.q r001, r001, r000
    vscl.q r001, r001, s002
    vadd.q r003, r000, r001
    sv.q r003, 0($a2)
    jr $ra
    nop



