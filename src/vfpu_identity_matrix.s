/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Mat2Identity_U
    vmidt.p m000
    vmov.p r020, r001
    usv.q r000, 0($a0)
    jr $ra
    nop

gfunc vfpu_Mat3Identity_U
    vmidt.t m000
    usv.q r000, 0($a0)
    usv.q r001, 12($a0)
    svt s002, s012, s022, $a0, 24
    jr $ra
    nop

gfunc vfpu_Mat4Identity_U
    vmidt.q m000
    usv.q r000, 0($a0)
    usv.q r001, 16($a0)
    usv.q r002, 32($a0)
    usv.q r003, 48($a0)
    jr $ra
    nop

gfunc vfpu_Mat2Identity
    vmidt.p m000
    vmov.p r020, r001
    sv.q r000, 0($a0)
    jr $ra
    nop

gfunc vfpu_Mat3Identity
    vmidt.t m000
    sv.q r000, 0($a0)
    usv.q r001, 12($a0)
    usv.q r002, 24($a0)
    jr $ra
    nop

gfunc vfpu_Mat4Identity
    vmidt.q m000
    sv.q r000, 0($a0)
    sv.q r001, 16($a0)
    sv.q r002, 32($a0)
    sv.q r003, 48($a0)
    jr $ra
    nop
