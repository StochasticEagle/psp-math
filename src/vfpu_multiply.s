/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Vec2Multiply_U
    singleOpVec2_U vmul.p
    jr $ra
    nop

gfunc vfpu_Vec3Multiply_U
    singleOpVec3_U vmul.t
    jr $ra
    nop

gfunc vfpu_Vec4Multiply_U
    singleOpVec4_U vmul.q
    jr $ra
    nop

gfunc vfpu_Vec2pMultiply
gfunc vfpu_Vec4Multiply
    singleOpVecV vmul.q
    jr $ra
    nop



gfunc vfpu_Mat2Multiply_U
    addiu $sp, $sp, -16
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm2_u 0, $a0
    lm2_u 1, $a1
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    addiu $sp, $sp, 16
    vmmul.p m200, m000, m100
    vmov.p r220, r201
    usv.q r200, 0($a2)
    jr $ra
    nop

gfunc vfpu_Mat3Multiply_U
    addiu $sp, $sp, -16
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm3_u 0, $a0
    lm3_u 1, $a1
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    addiu $sp, $sp, 16
    vmmul.t m200, m000, m100
    sm3 2, $a2
    jr $ra
    nop

gfunc vfpu_Mat4Multiply_U
    addiu $sp, $sp, -16
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm4_u 0, $a0
    lm4_u 1, $a1
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    addiu $sp, $sp, 16
    vmmul.q m200, m000, m100
    usv.q r200, 0($a2)
    usv.q r201, 16($a2)
    usv.q r202, 32($a2)
    usv.q r203, 48($a2)
    jr $ra
    nop

gfunc vfpu_Mat2Multiply
    lm2_a 0, $a0
    lm2_a 1, $a1
    vmmul.p m200, m000, m100
    vmov.p r220, r201
    sv.q r200, 0($a2)
    jr $ra
    nop

gfunc vfpu_Mat3Multiply
    lm3_a 0, $a0
    lm3_a 1, $a1
    vmmul.t m200, m000, m100
    sv.q r200, 0($a2)
    usv.q r201, 12($a2)
    svt s202, s212, s222, $a2, 24
    jr $ra
    nop

gfunc vfpu_Mat4Multiply
    lm4_a 0, $a0
    lm4_a 1, $a1
    vmmul.q m200, m000, m100
    sv.q r200, 0($a2)
    sv.q r201, 16($a2)
    sv.q r202, 32($a2)
    sv.q r203, 48($a2)
    jr $ra
    nop



gfunc vfpu_Mat2Vector2Multiply_U
    lm2_u 0, $a0
    ulv.q r002, 0($a1)
    vdot.p s100, r000, r002
    vdot.p s110, r001, r002
    svp s100, s110, $a2, 0
    jr $ra
    nop

gfunc vfpu_Mat3Vector3Multiply_U
    lm3_u 0, $a0
    ulv.q r003, 0($a1)
    vdot.t s100, r000, r003
    vdot.t s110, r001, r003
    vdot.t s120, r002, r003
    svt s100, s110, s120, $a2, 0
    jr $ra
    nop

gfunc vfpu_Mat4Vector4Multiply_U
    addiu $sp, $sp, -16
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm4_u 0, $a0
    ulv.q r100, 0($a1)
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    addiu $sp, $sp, 16
    vdot.q s101, r000, r100
    vdot.q s111, r001, r100
    vdot.q s121, r002, r100
    vdot.q s131, r003, r100
    usv.q r101, 0($a2)
    jr $ra
    nop

gfunc vfpu_Mat2Vector2Multiply
    lm2_a 0, $a0
    lv.q r002, 0($a1)
    vdot.p s100, r000, r002
    vdot.p s110, r001, r002
    sv.q r100, 0($a2)
    jr $ra
    nop

gfunc vfpu_Mat3Vector3Multiply
    lm3_a 0, $a0
    lv.q r003, 0($a1)
    vdot.t s100, r000, r003
    vdot.t s110, r001, r003
    vdot.t s120, r002, r003
    sv.q r100, 0($a2)
    jr $ra
    nop

gfunc vfpu_Mat4Vector4Multiply
    lm4_a 0, $a0
    lv.q r100, 0($a1)
    vdot.q s101, r000, r100
    vdot.q s111, r001, r100
    vdot.q s121, r002, r100
    vdot.q s131, r003, r100
    sv.q r101, 0($a2)
    jr $ra
    nop









gfunc vfpu_QuatMultiply_U
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    vqmul.q r201, r000, r001
    usv.q r201, 0($a2)
    jr $ra
    nop

gfunc vfpu_QuatMultiply
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    vqmul.q r201, r000, r001
    sv.q r201, 0($a2)
    jr $ra
    nop
