#include "vfpu_macros.inc"

# atan(x) = asin(x / sqrt(x*x + 1)); VFPU asin uses pi/2 units.
.macro atan_vfpu
    mtv     $t0, S000
    vmul.s  S001, S000, S000
    vadd.s  S001, S001, S001[1]
    vrsq.s  S001, S001
    vmul.s  S000, S000, S001
    vasin.s S000, S000
    vcst.s  S001, VFPU_PI_2
    vmul.s  S000, S000, S001
    mfv     $t0, S000
.endm

gfunc vfpu_atanf
    mfc1    $t0, $f12
    atan_vfpu
    mtc1    $t0, $f0
    jr      $ra
    nop

gfunc vfpu_atan2f
    # O32 hard-float: y in $f12, x in $f14.
    abs.s   $f4, $f14
    abs.s   $f6, $f12
    mtc1    $zero, $f8
    c.le.s  $f6, $f4
    bc1f    .Latan2_y_dominant
    nop

    # |x| >= |y|: atan(y/x), then +/- pi for negative x.
    div.s   $f10, $f12, $f14
    mfc1    $t0, $f10
    atan_vfpu
    mtc1    $t0, $f0
    c.lt.s  $f14, $f8
    bc1f    .Latan2_return
    nop
    c.lt.s  $f12, $f8
    bc1t    .Latan2_minus_pi
    nop
    lui     $t0, %hi(.Lpi)
    lwc1    $f10, %lo(.Lpi)($t0)
    add.s   $f0, $f0, $f10
    b       .Latan2_return
    nop
.Latan2_minus_pi:
    lui     $t0, %hi(.Lpi)
    lwc1    $f10, %lo(.Lpi)($t0)
    sub.s   $f0, $f0, $f10
    b       .Latan2_return
    nop

.Latan2_y_dominant:
    # |y| > |x|: -atan(x/y) plus signed pi/2.
    div.s   $f10, $f14, $f12
    mfc1    $t0, $f10
    atan_vfpu
    mtc1    $t0, $f0
    neg.s   $f0, $f0
    lui     $t0, %hi(.Lhalf_pi)
    lwc1    $f10, %lo(.Lhalf_pi)($t0)
    c.lt.s  $f12, $f8
    bc1t    .Latan2_minus_half_pi
    nop
    add.s   $f0, $f0, $f10
    b       .Latan2_return
    nop
.Latan2_minus_half_pi:
    sub.s   $f0, $f0, $f10
.Latan2_return:
    jr      $ra
    nop

    .section .rodata
    .align 2
.Lpi:
    .float 3.14159265358979
.Lhalf_pi:
    .float 1.57079632679489
    .text
