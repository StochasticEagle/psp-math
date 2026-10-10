/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Random
    vrndf1.s s000
    vsub.s s000, s000, s000[1]
    mfv $t0, s000
    mtc1 $t0, $f0
    jr $ra
    nop

gfunc vfpu_srand
    mtv $a0, s000
    vrnds.s s000
    jr $ra
    nop




gfunc vfpu_Vec2Random_U
    vrndf1.p r000
    vsub.p r000, r000, r000[1,1]
    svp s000, s010, $a0, 0
    jr $ra
    nop

gfunc vfpu_Vec3Random_U
    vrndf1.t r000
    vsub.t r000, r000, r000[1,1,1]
    svt s000, s010, s020, $a0, 0
    jr $ra
    nop

gfunc vfpu_Vec4Random_U
    vrndf1.q r000
    vsub.q r000, r000, r000[1,1,1,1]
    usv.q r000, 0($a0)
    jr $ra
    nop

gfunc vfpu_Vec2Random
    vrndf1.p r000
    vsub.p r000, r000, r000[1,1]
    sv.q r000, 0($a0)
    jr $ra
    nop

gfunc vfpu_Vec3Random
    vrndf1.t r000
    vsub.t r000, r000, r000[1,1,1]
    sv.q r000, 0($a0)
    jr $ra
    nop

gfunc vfpu_Vec2pRandom
gfunc vfpu_Vec4Random
    vrndf1.q r000
    vsub.q r000, r000, r000[1,1,1,1]
    sv.q r000, 0($a0)
    jr $ra
    nop

