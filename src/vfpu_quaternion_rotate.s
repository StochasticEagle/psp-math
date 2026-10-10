#include "vfpu_macros.inc"

# Inputs: q1 in $a0, q2 in $a1, destination in $a2.
# Compute q2 * q1 * conjugate(q2), preserving the original operation order.
# Scratch: conjugate at 0($sp), first product at 16($sp).
.macro quat_rotate suffix
    addiu $sp, $sp, -80
    sw $ra, 76($sp)
    sw $s0, 72($sp)
    sw $s1, 68($sp)
    sw $s2, 64($sp)
    move $s0, $a0
    move $s1, $a1
    move $s2, $a2

    move $a0, $s1
    move $a1, $sp
    jal vfpu_QuatConjugate\suffix
    nop

    move $a0, $s1
    move $a1, $s0
    addiu $a2, $sp, 16
    jal vfpu_QuatMultiply\suffix
    nop

    addiu $a0, $sp, 16
    move $a1, $sp
    move $a2, $s2
    jal vfpu_QuatMultiply\suffix
    nop

    lw $s2, 64($sp)
    lw $s1, 68($sp)
    lw $s0, 72($sp)
    lw $ra, 76($sp)
    jr $ra
    addiu $sp, $sp, 80
.endm

gfunc vfpu_QuatRotate_U
    quat_rotate _U

gfunc vfpu_QuatRotate
    quat_rotate
