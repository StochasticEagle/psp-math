#include "vfpu_macros.inc"

gfunc vfpu_rand_565
    lui $t0, %hi(.Lrgb565_pack)
    addiu $t0, $t0, %lo(.Lrgb565_pack)
    mtv      $a0, S020
    mtv      $a1, S021
    mtv      $a2, S022
    mtv      $a3, S023
    vi2f.q   C020, C020, 0
    vmov.t   C000, C020[x, y, x]
    vmov.q   C010, C020[z, w, z, w]
    vsub.t   C010, C010, C000
    vrndf1.t C020
    vmul.t   C020, C020, C010
    vadd.t   C020, C020, C000
    vf2iz.t  C020, C020, 0
    vi2f.t   C020, C020, 0
    lv.q     C030, 0($t0)
    vdot.t   S020, C020, C030
    vf2iz.s  S020, S020, 0
    mfv      $v0, S020
    jr $ra
    nop

    .section .rodata
    .align 4
.Lrgb565_pack:
    .float 2048,32,1,0
    .text
