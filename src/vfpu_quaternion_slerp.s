#include "vfpu_macros.inc"

# Shortest-arc quaternion SLERP; inputs [x,y,z,w], t in $a2.
# Both implementations are leaf functions and keep coefficients in VFPU.
gfunc vfpu_QuatSlerp_U
    lv.s S000, 0($a0)
    lv.s S001, 4($a0)
    lv.s S002, 8($a0)
    lv.s S003, 12($a0)
    lv.s S010, 0($a1)
    lv.s S011, 4($a1)
    lv.s S012, 8($a1)
    lv.s S013, 12($a1)
    mtv $a2, S102
    vone.s S101
    vsub.s S121, S101, S102

    # Select the shortest arc by negating q2 if the dot product is negative.
    vdot.q S100, C000, C010
    vzero.s S103
    vcmp.s LT, S100, S103
    vneg.q C020, C010
    vcmovt.q C010, C020, 0
    vabs.s S100, S100
    vmin.s S100, S100, S101

    # LERP if abs(dot) >= 0.9995; compare positive float bit patterns.
    mfv $t0, S100
    lui $t1, %hi(.Lslerp_threshold)
    lw $t1, %lo(.Lslerp_threshold)($t1)
    sltu $t2, $t0, $t1
    beq $t2, $zero, 1f
    nop

    # Acosine in half-pi units, which VFPU sine accepts directly.
    vasin.s S103, S100
    vocp.s S103, S103
    vsin.s S110, S103
    vmul.s S130, S121, S103
    vmul.s S131, S102, S103
    vsin.p C130, C130
    vrcp.s S132, S110
    vscl.p C130, C130, S132
    b 2f
    nop
1:
    vmov.s S130, S121
    vmov.s S131, S102
2:
    vscl.q C200, C000, S130
    vscl.q C210, C010, S131
    vadd.q C200, C200, C210

    # Normalize, substituting [0,0,0,1] if squared norm <= 1e-20.
    vdot.q S300, C200, C200
    lui $t1, %hi(.Lslerp_norm_min)
    lw $t1, %lo(.Lslerp_norm_min)($t1)
    mtv $t1, S301
    vcmp.s LE, S300, S301
    vmax.s S302, S300, S301
    vrsq.s S302, S302
    vscl.q C200, C200, S302
    vzero.q C220
    vone.s S223
    vcmovt.q C200, C220, 0
    sv.s S200, 0($a3)
    sv.s S201, 4($a3)
    sv.s S202, 8($a3)
    sv.s S203, 12($a3)
    jr $ra
    nop

gfunc vfpu_QuatSlerp
    lv.q C000, 0($a0)
    lv.q C010, 0($a1)
    mtv $a2, S102
    vone.s S101
    vsub.s S121, S101, S102

    # Select the shortest arc by negating q2 if the dot product is negative.
    vdot.q S100, C000, C010
    vzero.s S103
    vcmp.s LT, S100, S103
    vneg.q C020, C010
    vcmovt.q C010, C020, 0
    vabs.s S100, S100
    vmin.s S100, S100, S101

    # LERP if abs(dot) >= 0.9995; compare positive float bit patterns.
    mfv $t0, S100
    lui $t1, %hi(.Lslerp_threshold)
    lw $t1, %lo(.Lslerp_threshold)($t1)
    sltu $t2, $t0, $t1
    beq $t2, $zero, 1f
    nop

    # Acosine in half-pi units, which VFPU sine accepts directly.
    vasin.s S103, S100
    vocp.s S103, S103
    vsin.s S110, S103
    vmul.s S130, S121, S103
    vmul.s S131, S102, S103
    vsin.p C130, C130
    vrcp.s S132, S110
    vscl.p C130, C130, S132
    b 2f
    nop
1:
    vmov.s S130, S121
    vmov.s S131, S102
2:
    vscl.q C200, C000, S130
    vscl.q C210, C010, S131
    vadd.q C200, C200, C210

    # Normalize, substituting [0,0,0,1] if squared norm <= 1e-20.
    vdot.q S300, C200, C200
    lui $t1, %hi(.Lslerp_norm_min)
    lw $t1, %lo(.Lslerp_norm_min)($t1)
    mtv $t1, S301
    vcmp.s LE, S300, S301
    vmax.s S302, S300, S301
    vrsq.s S302, S302
    vscl.q C200, C200, S302
    vzero.q C220
    vone.s S223
    vcmovt.q C200, C220, 0
    sv.q C200, 0($a3)
    jr $ra
    nop

    .section .rodata
    .align 2
.Lslerp_threshold:
    .float 0.9995
.Lslerp_norm_min:
    .float 1.0e-20
    .text
