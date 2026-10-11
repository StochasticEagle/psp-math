
/* pspla
 * A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
 *
 * MIT License
 *
 * Copyright (c) 2024 Jayanky
 */

#include "vfpu_macros.inc"

gfunc vfpu_Vec2Magnitude_U
    ulv.q r000, 0($a0)
    vdot.p s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop

gfunc vfpu_Vec3Magnitude_U
    ulv.q r000, 0($a0)
    vdot.t s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop

gfunc vfpu_QuatMagnitude_U
gfunc vfpu_Vec4Magnitude_U
    ulv.q r000, 0($a0)
    vdot.q s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop

gfunc vfpu_Vec2Magnitude
    lv.q r000, 0($a0)
    vdot.p s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop

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
    nop

gfunc vfpu_Vec3Magnitude
    lv.q r000, 0($a0)
    vdot.t s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop

gfunc vfpu_QuatMagnitude
gfunc vfpu_Vec4Magnitude
    lv.q r000, 0($a0)
    vdot.q s002, r000, r000
    vsqrt.s s002, s002
    mfv $t0, s002
    mtc1 $t0, $f0
    jr $ra
    nop
