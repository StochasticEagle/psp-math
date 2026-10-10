#include "vfpu_macros.inc"

gfunc vfpu_Vec3SetPosition
    lw $t0, 0($a0)
    lw $t1, 4($a0)
    lw $t2, 8($a0)
    lui $t3, 0x3f80
    sw $t0, 0($a1)
    sw $t1, 4($a1)
    sw $t2, 8($a1)
    sw $t3, 12($a1)
    jr $ra
    nop

gfunc vfpu_Vec3SetDirection
    lw $t0, 0($a0)
    lw $t1, 4($a0)
    lw $t2, 8($a0)
    sw $t0, 0($a1)
    sw $t1, 4($a1)
    sw $t2, 8($a1)
    sw $zero, 12($a1)
    jr $ra
    nop
