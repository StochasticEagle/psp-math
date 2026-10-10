/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Mat2Determinant_U
    pushf $f28
    ulv.q r700, 0($a0)
    popf $f28
    mat2Determinant 00, 10, 20, 30, s100
    mfv $t0, s100
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Mat3Determinant_U
    pushf $f28
    lm3_u 7, $a0
    popf $f28
    mat3Determinant 01, 11, 21, 02, 12, 22, x, y, z, 00, s103
    mfv $t0, s103
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Mat4Determinant_U
    pushf $f28
    lm4_u 7, $a0
    popf $f28
    mat4Determinant 02, 12, 22, 32, 03, 13, 23, 33, s300
    mfv $t0, s300
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Mat2Determinant
    lv.q r700, 0($a0)
    mat2Determinant 00, 10, 20, 30, s100
    mfv $t0, s100
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Mat3Determinant
    lm3_a 7, $a0
    mat3Determinant 01, 11, 21, 02, 12, 22, x, y, z, 00, s103
    mfv $t0, s103
    mtc1 $t0, $f0
    jr $ra

gfunc vfpu_Mat4Determinant
    lm4_a 7, $a0
    mat4Determinant 02, 12, 22, 32, 03, 13, 23, 33, s300
    mfv $t0, s300
    mtc1 $t0, $f0
    jr $ra
