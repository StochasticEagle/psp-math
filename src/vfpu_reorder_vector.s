/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Reorder_U
    vfim.s s003, 4
    pushf $f0
    ulv.q r000, 0($a1)
    popf $f0
    vscl.p r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    svp s001, s011, $a2, 0
    jr $ra

gfunc vfpu_Vec3Reorder_U
    vfim.s s003, 4
    pushf $f0
    ulv.q r000, 0($a1)
    popf $f0
    vscl.t r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    mfv $t2, s020
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    add $t2, $t2, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    lv.s s021, 0($t2)
    svt s001, s011, s021, $a2, 0
    jr $ra

gfunc vfpu_Vec4Reorder_U
    vfim.s s003, 4
    pushf $f0
    ulv.q r000, 0($a1)
    popf $f0
    vscl.q r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    mfv $t2, s020
    mfv $t3, s030
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    add $t2, $t2, $a0
    add $t3, $t3, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    lv.s s021, 0($t2)
    lv.s s031, 0($t3)
    usv.q r001, 0($a2)
    jr $ra

gfunc vfpu_Vec2Reorder
    vfim.s s003, 4
    lv.q r000, 0($a1)
    vscl.p r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    sv.q r001, 0($a2)
    jr $ra

gfunc vfpu_Vec3Reorder
    vfim.s s003, 4
    lv.q r000, 0($a1)
    vscl.t r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    mfv $t2, s020
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    add $t2, $t2, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    lv.s s021, 0($t2)
    sv.q r001, 0($a2)
    jr $ra

gfunc vfpu_Vec4Reorder
    vfim.s s003, 4
    lv.q r000, 0($a1)
    vscl.q r000, r000, s003
    mfv $t0, s000
    mfv $t1, s010
    mfv $t2, s020
    mfv $t3, s030
    add $t0, $t0, $a0
    add $t1, $t1, $a0
    add $t2, $t2, $a0
    add $t3, $t3, $a0
    lv.s s001, 0($t0)
    lv.s s011, 0($t1)
    lv.s s021, 0($t2)
    lv.s s031, 0($t3)
    sv.q r001, 0($a2)
    jr $ra


/* Indices 0 and 1 are local to each independent packed vec2. */
gfunc vfpu_Vec2pReorder
    lw $t0, 0($a1)
    lw $t1, 4($a1)
    lw $t2, 8($a1)
    lw $t3, 12($a1)
    andi $t0, $t0, 1
    andi $t1, $t1, 1
    andi $t2, $t2, 1
    andi $t3, $t3, 1
    sll $t0, $t0, 2
    sll $t1, $t1, 2
    sll $t2, $t2, 2
    sll $t3, $t3, 2
    addu $t0, $a0, $t0
    addu $t1, $a0, $t1
    addu $t2, $a0, $t2
    addu $t3, $a0, $t3
    lw $t0, 0($t0)
    lw $t1, 0($t1)
    lw $t2, 8($t2)
    lw $t3, 8($t3)
    sw $t0, 0($a2)
    sw $t1, 4($a2)
    sw $t2, 8($a2)
    sw $t3, 12($a2)
    jr $ra
