#include "vfpu_macros.inc"

gfunc vfpu_Mat2ToMatrix3_U
    pushf $f0
    lm2_u 0, $a0
    popf $f0
    vidt.q c020
    vidt.q r002
    usv.q r000, 0($a1)
    usv.q r001, 12($a1)
    svt s002, s012, s022, $a1, 24
    jr $ra

gfunc vfpu_Mat2ToMatrix3_A
    lm2_a 0, $a0
    vidt.q c020
    vidt.q r002
    sv.q r000, 0($a1)
    usv.q r001, 12($a1)
    usv.q r002, 24($a1)
    jr $ra

gfunc vfpu_Mat2ToMatrix4_U
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

gfunc vfpu_Mat2ToMatrix4_A
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

gfunc vfpu_Mat3ToMatrix4_U
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

gfunc vfpu_Mat3ToMatrix4_A
    lm3_a 0, $a0
    vidt.q c030
    vidt.q r003
    sv.q r000, 0($a1)
    sv.q r001, 16($a1)
    sv.q r002, 32($a1)
    sv.q r003, 48($a1)
    jr $ra


