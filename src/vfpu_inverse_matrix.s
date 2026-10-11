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
    pushf $f4
    ulv.q r101, 0($a0)
    popf $f4
    vfim.s s110, 1
    vdiv.s s120, s110, s100
    vscl.q r101, r101, s120
    vmov.q r101, r101[w,-y,-z,x]
    usv.q r101, 0($a1)
    jr $ra
    nop

gfunc vfpu_Mat3Inverse_U
    pushf28_31
    lm3_u 7, $a0
    popf28_31
    mat2Determinant 11, 21, 12, 22, s100
    mat2Determinant 01, 21, 02, 22, s110
    mat2Determinant 01, 11, 02, 12, s120
    mat2Determinant 10, 20, 12, 22, s101
    mat2Determinant 00, 20, 02, 22, s111
    mat2Determinant 00, 10, 02, 12, s121
    mat2Determinant 10, 20, 11, 21, s102
    mat2Determinant 00, 20, 01, 21, s112
    mat2Determinant 00, 10, 01, 11, s122
    vmov.t c200, r100[x,-y,z]
    vmov.t c210, r101[-x,y,-z]
    vmov.t c220, r102[x,-y,z]
    mfc1 $t0, $f12
    mtv $t0, s300
    vfim.s s310, 1
    vdiv.s s320, s310, s300
    vmscl.t m200, m200, s320
    usv.q r200, 0($a1)
    usv.q r201, 12($a1)
    svt s202, s212, s222, $a1, 24
    jr $ra
    nop

gfunc vfpu_Mat4Inverse_U
    pushf28_31
    lm4_u 7, $a0
    popf28_31
    mat4Minors 02, 12, 22, 32, 03, 13, 23, 33
    mat4Cofactors 01, s200, s210, s220, s230
    mat4Cofactors 00, s201, s211, s221, s231
    mat4Minors 01, 11, 21, 31, 03, 13, 23, 33
    mat4Cofactors 00, s202, s212, s222, s232
    mat4Minors 01, 11, 21, 31, 02, 12, 22, 32
    mat4Cofactors 00, s203, s213, s223, s233
    vmov.q c300, r200[x,-y,z,-w]
    vmov.q c310, r201[-x,y,-z,w]
    vmov.q c320, r202[x,-y,z,-w]
    vmov.q c330, r203[-x,y,-z,w]
    mfc1 $t0, $f12
    mtv $t0, s400
    vfim.s s410, 1
    vdiv.s s420, s410, s400
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
    vfim.s s110, 1
    vdiv.s s120, s110, s100
    vscl.q r101, r101, s120
    vmov.q r101, r101[w,-y,-z,x]
    sv.q r101, 0($a1)
    jr $ra
    nop

gfunc vfpu_Mat3Inverse
    lm3_a 7, $a0
    mat2Determinant 11, 21, 12, 22, s100
    mat2Determinant 01, 21, 02, 22, s110
    mat2Determinant 01, 11, 02, 12, s120
    mat2Determinant 10, 20, 12, 22, s101
    mat2Determinant 00, 20, 02, 22, s111
    mat2Determinant 00, 10, 02, 12, s121
    mat2Determinant 10, 20, 11, 21, s102
    mat2Determinant 00, 20, 01, 21, s112
    mat2Determinant 00, 10, 01, 11, s122
    vmov.t c200, r100[x,-y,z]
    vmov.t c210, r101[-x,y,-z]
    vmov.t c220, r102[x,-y,z]
    mfc1 $t0, $f12
    mtv $t0, s300
    vfim.s s310, 1
    vdiv.s s320, s310, s300
    vmscl.t m200, m200, s320
    sv.q r200, 0($a1)
    usv.q r201, 12($a1)
    svt s202, s212, s222, $a1, 24
    jr $ra
    nop

gfunc vfpu_Mat4Inverse
    lm4_a 7, $a0
    mat4Minors 02, 12, 22, 32, 03, 13, 23, 33
    mat4Cofactors 01, s200, s210, s220, s230
    mat4Cofactors 00, s201, s211, s221, s231
    mat4Minors 01, 11, 21, 31, 03, 13, 23, 33
    mat4Cofactors 00, s202, s212, s222, s232
    mat4Minors 01, 11, 21, 31, 02, 12, 22, 32
    mat4Cofactors 00, s203, s213, s223, s233
    vmov.q c300, r200[x,-y,z,-w]
    vmov.q c310, r201[-x,y,-z,w]
    vmov.q c320, r202[x,-y,z,-w]
    vmov.q c330, r203[-x,y,-z,w]
    mfc1 $t0, $f12
    mtv $t0, s400
    vfim.s s410, 1
    vdiv.s s420, s410, s400
    vmscl.q m300, m300, s420
    sv.q r300, 0($a1)
    sv.q r301, 16($a1)
    sv.q r302, 32($a1)
    sv.q r303, 48($a1)
    jr $ra
    nop
