#include "vfpu_macros.inc"

gfunc vfpu_Mat3Scale_U
    pushf $f0
    lm3_u 0, $a0
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s200
    vmscl.t m100, m000, s200
    usv.q r100, 0($a1)
    usv.q r101, 12($a1)
    svt s102, s112, s122, $a1, 24
    jr $ra

gfunc vfpu_Mat4Scale_U
    pushf $f0
    lm4_u 0, $a0
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s200
    vmscl.q m100, m000, s200
    usv.q r100, 0($a1)
    usv.q r101, 16($a1)
    usv.q r102, 32($a1)
    usv.q r103, 48($a1)
    jr $ra

gfunc vfpu_Mat3Scale
    lm3_a 0, $a0
    mfc1 $t0, $f12
    mtv $t0, s200
    vmscl.t m100, m000, s200
    sv.q r100, 0($a1)
    usv.q r101, 12($a1)
    usv.q r102, 24($a1)
    jr $ra

gfunc vfpu_Mat4Scale
    lm4_a 0, $a0
    mfc1 $t0, $f12
    mtv $t0, s200
    vmscl.q m100, m000, s200
    sv.q r100, 0($a1)
    sv.q r101, 16($a1)
    sv.q r102, 32($a1)
    sv.q r103, 48($a1)
    jr $ra
