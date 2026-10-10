/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Mat3Copy_U
    pushf $f0
    lm3_u 0, $a0
    popf $f0
    usv.q r000, 0($a1)
    usv.q r001, 12($a1)
    svt s002, s012, s022, $a1, 24
    jr $ra

gfunc vfpu_Mat4Copy_U
    pushf $f0
    lm4_u 0, $a0
    popf $f0
    usv.q r000, 0($a1)
    usv.q r001, 16($a1)
    usv.q r002, 32($a1)
    usv.q r003, 48($a1)
    jr $ra

gfunc vfpu_Mat3Copy
    lm3_a 0, $a0
    sv.q r000, 0($a1)
    usv.q r001, 12($a1)
    usv.q r002, 24($a1)
    jr $ra

gfunc vfpu_Mat4Copy
    lm4_a 0, $a0
    sv.q r000, 0($a1)
    sv.q r001, 16($a1)
    sv.q r002, 32($a1)
    sv.q r003, 48($a1)
    jr $ra

gfunc vfpu_Vec2Copy_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    svp s000, s010, $a1, 0
    jr $ra

gfunc vfpu_Vec3Copy_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    svt s000, s010, s020, $a1, 0
    jr $ra

gfunc vfpu_Mat2Copy_U
gfunc vfpu_Vec4Copy_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    usv.q r000, 0($a1)
    jr $ra

gfunc vfpu_Mat2Copy
gfunc vfpu_VecVCopy
    lv.q r000, 0($a0)
    sv.q r000, 0($a1)
    jr $ra
