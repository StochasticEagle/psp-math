/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Mat2ToMat3_U
    pushf $f0
    lm2_u 0, $a0
    popf $f0
    vidt.q c020
    vidt.q r002
    usv.q r000, 0($a1)
    usv.q r001, 12($a1)
    svt s002, s012, s022, $a1, 24
    jr $ra
    nop

gfunc vfpu_Mat2ToMat3
    lm2_a 0, $a0
    vidt.q c020
    vidt.q r002
    sv.q r000, 0($a1)
    usv.q r001, 12($a1)
    svt s002, s012, s022, $a1, 24
    jr $ra
    nop

gfunc vfpu_Mat2ToMat4_U
    pushf $f0
    lm2_u 0, $a0
    popf $f0
    vidt.q c020
    vidt.q r002
    vidt.q c030
    vidt.q r003
    usv.q r000, 0($a1)
    usv.q r001, 16($a1)
    usv.q r002, 32($a1)
    usv.q r003, 48($a1)
    jr $ra
    nop

gfunc vfpu_Mat2ToMat4
    lm2_a 0, $a0
    vidt.q c020
    vidt.q r002
    vidt.q c030
    vidt.q r003
    sv.q r000, 0($a1)
    sv.q r001, 16($a1)
    sv.q r002, 32($a1)
    sv.q r003, 48($a1)
    jr $ra
    nop

gfunc vfpu_Mat3ToMat4_U
    pushf $f0
    lm3_u 0, $a0
    popf $f0
    vidt.q c030
    vidt.q r003
    usv.q r000, 0($a1)
    usv.q r001, 16($a1)
    usv.q r002, 32($a1)
    usv.q r003, 48($a1)
    jr $ra
    nop

gfunc vfpu_Mat3ToMat4
    lm3_a 0, $a0
    vidt.q c030
    vidt.q r003
    sv.q r000, 0($a1)
    sv.q r001, 16($a1)
    sv.q r002, 32($a1)
    sv.q r003, 48($a1)
    jr $ra
    nop


