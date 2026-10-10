#include "vfpu_macros.inc"

gfunc vfpu_QuatExp
    # Input and output are [x,y,z,w]. Keep intermediates in VFPU registers.
    lv.q C000, 0($a0)
    vdot.t S100, C000, C000
    vsqrt.s S100, S100
    vcst.s S101, VFPU_2_PI
    vmul.s S102, S100, S101
    vrot.p C110, S102, [s, c]
    lui $t0, %hi(.Lexp_epsilon)
    lw $t0, %lo(.Lexp_epsilon)($t0)
    mtv $t0, S120
    vmax.s S112, S100, S120
    vdiv.s S110, S110, S112
    vcmp.s LE, S100, S120
    vone.s S113
    vcmovt.s S110, S113, 0
    vcmovt.s S111, S113, 0
    vcst.s S103, VFPU_LOG2E
    vmul.s S103, S030, S103
    vexp2.s S103, S103
    # [e^w*sin(r)/r, e^w*sin(r)/r, e^w*sin(r)/r, e^w*cos(r)]
    vmov.q C200, C110[x,x,x,y]
    vscl.q C200, C200, S103
    vmul.q C000, C000, C200
    sv.q C000, 0($a1)
    jr $ra
    nop

    .section .rodata
    .align 2
.Lexp_epsilon:
    .float 1.0e-5
    .text
