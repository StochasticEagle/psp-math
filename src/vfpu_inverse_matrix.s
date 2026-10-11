/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Mat2Inverse_U
    mfc1 $t0, $f12
    mtv $t0, s100
    ulv.q r101, 0($a0)
    vrcp.s s120, s100
    vscl.q r101, r101, s120
    vmov.q r101, r101[w,-y,-z,x]
    usv.q r101, 0($a1)
    jr $ra
    nop

gfunc vfpu_Mat3Inverse_U
    pushf28_31
    lm3_u 7, $a0
    popf28_31
    # Produce the signed adjugate directly in M200.
    # Reversing determinant operands encodes the alternating cofactor sign.
    mat2Determinant 11, 21, 12, 22, s200
    mat2Determinant 02, 22, 01, 21, s201
    mat2Determinant 01, 11, 02, 12, s202
    mat2Determinant 12, 22, 10, 20, s210
    mat2Determinant 00, 20, 02, 22, s211
    mat2Determinant 02, 12, 00, 10, s212
    mat2Determinant 10, 20, 11, 21, s220
    mat2Determinant 01, 21, 00, 20, s221
    mat2Determinant 00, 10, 01, 11, s222
    mfc1 $t0, $f12
    mtv $t0, s300
    vrcp.s s320, s300
    vmscl.t m200, m200, s320
    sm3 2, $a1
    jr $ra
    nop

gfunc vfpu_Mat4Inverse_U
    pushf28_31
    lm4_u 7, $a0
    popf28_31
    mat4Minors 02, 12, 22, 32, 03, 13, 23, 33
    # Emit the signed adjugate in M300 and avoid four matrix shuffles.
    mat4Cofactors 01, s300, s310, s320, s330, 0, 1, 0, 1
    mat4Cofactors 00, s301, s311, s321, s331, 1, 0, 1, 0
    mat4Minors 01, 11, 21, 31, 03, 13, 23, 33
    mat4Cofactors 00, s302, s312, s322, s332, 0, 1, 0, 1
    mat4Minors 01, 11, 21, 31, 02, 12, 22, 32
    mat4Cofactors 00, s303, s313, s323, s333, 1, 0, 1, 0
    mfc1 $t0, $f12
    mtv $t0, s400
    vrcp.s s420, s400
    vmscl.q m300, m300, s420
    usv.q r300, 0($a1)
    usv.q r301, 16($a1)
    usv.q r302, 32($a1)
    usv.q r303, 48($a1)
    jr $ra
    nop

gfunc vfpu_Mat2Inverse
    mfc1 $t0, $f12
    mtv $t0, s100
    lv.q r101, 0($a0)
    vrcp.s s120, s100
    vscl.q r101, r101, s120
    vmov.q r101, r101[w,-y,-z,x]
    sv.q r101, 0($a1)
    jr $ra
    nop

gfunc vfpu_Mat3Inverse
    lm3_a 7, $a0
    # Produce the signed adjugate directly in M200.
    # Reversing determinant operands encodes the alternating cofactor sign.
    mat2Determinant 11, 21, 12, 22, s200
    mat2Determinant 02, 22, 01, 21, s201
    mat2Determinant 01, 11, 02, 12, s202
    mat2Determinant 12, 22, 10, 20, s210
    mat2Determinant 00, 20, 02, 22, s211
    mat2Determinant 02, 12, 00, 10, s212
    mat2Determinant 10, 20, 11, 21, s220
    mat2Determinant 01, 21, 00, 20, s221
    mat2Determinant 00, 10, 01, 11, s222
    mfc1 $t0, $f12
    mtv $t0, s300
    vrcp.s s320, s300
    vmscl.t m200, m200, s320
    sv.q r200, 0($a1)
    usv.q r201, 12($a1)
    svt s202, s212, s222, $a1, 24
    jr $ra
    nop

gfunc vfpu_Mat4Inverse
    lm4_a 7, $a0
    mat4Minors 02, 12, 22, 32, 03, 13, 23, 33
    # Emit the signed adjugate in M300 and avoid four matrix shuffles.
    mat4Cofactors 01, s300, s310, s320, s330, 0, 1, 0, 1
    mat4Cofactors 00, s301, s311, s321, s331, 1, 0, 1, 0
    mat4Minors 01, 11, 21, 31, 03, 13, 23, 33
    mat4Cofactors 00, s302, s312, s322, s332, 0, 1, 0, 1
    mat4Minors 01, 11, 21, 31, 02, 12, 22, 32
    mat4Cofactors 00, s303, s313, s323, s333, 1, 0, 1, 0
    mfc1 $t0, $f12
    mtv $t0, s400
    vrcp.s s420, s400
    vmscl.q m300, m300, s420
    sv.q r300, 0($a1)
    sv.q r301, 16($a1)
    sv.q r302, 32($a1)
    sv.q r303, 48($a1)
    jr $ra
    nop
