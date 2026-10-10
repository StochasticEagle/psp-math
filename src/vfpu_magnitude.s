
/* pspla
 * A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
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
    vdot.p s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec3Magnitude_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vdot.t s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_QuatMagnitude_U
gfunc vfpu_Vec4Magnitude_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vdot.q s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec2Magnitude
    lv.q r000, 0($a0)
    vdot.p s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Vec3Magnitude
    lv.q r000, 0($a0)
    vdot.t s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_QuatMagnitude
gfunc vfpu_Vec4Magnitude
    lv.q r000, 0($a0)
    vdot.q s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
