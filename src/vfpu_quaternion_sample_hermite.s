#include "vfpu_macros.inc"

gfunc vfpu_QuatSampleHermite
    lw $t1, 16($sp)
    lw $t2, 20($sp)
    lui $t0, %hi(.Lhermite)
    addiu $t0, $t0, %lo(.Lhermite)
    lv.q    C000,  0($t0)
    lv.q    C010, 16($t0)
    lv.q    C020, 32($t0)
    lv.q    C030, 48($t0)
    lv.q    C100,  0($a0)
    lv.q    C110,  0($a1)
    lv.q    C120,  0($a2)
    lv.q    C130,  0($a3)
    mtv     $t1, S202
    vmul.s  S201, S202, S202
    vmul.s  S200, S202, S201
    vone.s  S203
    # Each coefficient is one dot product of a polynomial row with [t^3,t^2,t,1].
    vdot.q  S210, C000, C200
    vdot.q  S211, C010, C200
    vdot.q  S212, C020, C200
    vdot.q  S213, C030, C200
    vscl.q  C100, C100, S210
    vscl.q  C110, C110, S211
    vscl.q  C120, C120, S212
    vscl.q  C130, C130, S213
    vadd.q  C100, C100, C110
    vadd.q  C100, C100, C120
    vadd.q  C100, C100, C130
    sv.q    C100, 0($t2)
    jr $ra
    nop

    .section .rodata
    .align 4
.Lhermite:
    .float 2,-3,0,1,-2,3,0,0,1,-2,1,0,1,-1,0,0
    .text
