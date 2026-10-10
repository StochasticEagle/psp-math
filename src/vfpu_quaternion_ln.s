#include "vfpu_macros.inc"

gfunc vfpu_QuatLn
    lui $t2, %hi(.Lln_limits)
    addiu $t2, $t2, %lo(.Lln_limits)
    lw $t0, 0($t2)
    lw $t1, 4($t2)
    lv.q C000, 0($a0)
    mtv $t0, S120
    mtv $t1, S121
    vdot.t S110, C000, C000
    vdot.q S111, C000, C000
    vmax.s S111, S111, S121
    vsqrt.s S112, S110
    vsqrt.s S113, S111
    vdiv.s S122, S030, S113
    vone.s S123
    vneg.s S130, S123
    vmin.s S122, S122, S123
    vmax.s S122, S122, S130
    vasin.s S122, S122
    vocp.s S122, S122
    vcst.s S131, VFPU_PI_2
    vmul.s S122, S122, S131
    vmax.s S112, S112, S120
    vdiv.s S132, S122, S112
    vcmp.s LT, S110, S120
    vzero.s S133
    vcmovt.s S132, S133, 0
    vscl.t C000, C000, S132
    vlog2.s S130, S111
    vcst.s S131, VFPU_LN2
    vmul.s S130, S130, S131
    vfim.s S131, 0.5
    vmul.s S030, S130, S131
    sv.q C000, 0($a1)
    jr $ra
    nop

    .section .rodata
    .align 2
.Lln_limits:
    .float 1.1e-19
    .float 1.0e-20
    .text
