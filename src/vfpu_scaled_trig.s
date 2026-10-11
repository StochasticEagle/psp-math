#include "vfpu_macros.inc"

// Scaled trigonometric functions use the PSP o32 hard-float arguments
// $f12 = angle, $f14 = scale. VFPU sin/cos inputs are multiples of pi/2.
gfunc vfpu_sinf_scaled
    mfc1    $t0, $f12
    mtv     $t0, S000
    vcst.s  S001, VFPU_2_PI
    vmul.s  S000, S000, S001
    vsin.s  S000, S000
    mfc1    $t0, $f14
    mtv     $t0, S002
    vmul.s  S000, S000, S002
    mfv     $t0, S000
    mtc1    $t0, $f0
    jr      $ra
    nop

gfunc vfpu_cosf_scaled
    mfc1    $t0, $f12
    mtv     $t0, S000
    vcst.s  S001, VFPU_2_PI
    vmul.s  S000, S000, S001
    vcos.s  S000, S000
    mfc1    $t0, $f14
    mtv     $t0, S002
    vmul.s  S000, S000, S002
    mfv     $t0, S000
    mtc1    $t0, $f0
    jr      $ra
    nop

gfunc vfpu_sind_scaled
    mfc1    $t0, $f12
    mtv     $t0, S000
    li      $t0, 0x3c360b61  // 1.0f / 90.0f
    mtv     $t0, S001
    vmul.s  S000, S000, S001
    vsin.s  S000, S000
    mfc1    $t0, $f14
    mtv     $t0, S002
    vmul.s  S000, S000, S002
    mfv     $t0, S000
    mtc1    $t0, $f0
    jr      $ra
    nop

gfunc vfpu_cosd_scaled
    mfc1    $t0, $f12
    mtv     $t0, S000
    li      $t0, 0x3c360b61  // 1.0f / 90.0f
    mtv     $t0, S001
    vmul.s  S000, S000, S001
    vcos.s  S000, S000
    mfc1    $t0, $f14
    mtv     $t0, S002
    vmul.s  S000, S000, S002
    mfv     $t0, S000
    mtc1    $t0, $f0
    jr      $ra
    nop

gfunc vfpu_tand_scaled
    mfc1    $t0, $f12
    mtv     $t0, S000
    li      $t0, 0x3c360b61  // 1.0f / 90.0f
    mtv     $t0, S001
    vmul.s  S000, S000, S001
    vrot.p  C002, S000, [s, c]
    vdiv.s  S000, S002, S003
    mfc1    $t0, $f14
    mtv     $t0, S002
    vmul.s  S000, S000, S002
    mfv     $t0, S000
    mtc1    $t0, $f0
    jr      $ra
    nop
