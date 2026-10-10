#include "vfpu_macros.inc"

gfunc vfpu_QuatExp
    # Input and output are [x,y,z,w]. Keep intermediates in VFPU registers.
    lv.q C000, 0($a0)
    vdot.t S100, C000, C000
    vsqrt.s S100, S100
    vcst.s S101, VFPU_2_PI
    vmul.s S102, S100, S101
    vsin.s S110, S102
    vcos.s S111, S102
    lui $t0, %hi(.Lexp_epsilon)
    lw $t0, %lo(.Lexp_epsilon)($t0)
    mtv $t0, S120
    vmax.s S112, S100, S120
    vdiv.s S110, S110, S112
    vcmp.s LE, S100, S120
    vone.s S113
    vcmovt.s S110, S113, 0
    vcmovt.s S111, S113, 0
    vcst.s S114, VFPU_LOG2E
    vmul.s S114, S030, S114
    vexp2.s S114, S114
    vmul.s S110, S110, S114
    vscl.t C000, C000, S110
    vmul.s S030, S111, S114
    sv.q C000, 0($a1)
    jr $ra
    nop

    .section .rodata
    .align 2
.Lexp_epsilon:
    .float 1.0e-5
    .text
