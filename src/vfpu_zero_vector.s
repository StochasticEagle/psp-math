#include "vfpu_macros.inc"

gfunc vfpu_Vec2Zero_U
    sw $zero, 0($a0)
    sw $zero, 4($a0)
    jr $ra
    nop

gfunc vfpu_Vec3Zero_U
    sw $zero, 0($a0)
    sw $zero, 4($a0)
    sw $zero, 8($a0)
    jr $ra
    nop

gfunc vfpu_Vec2pZero
gfunc vfpu_Vec4Zero
    vzero.q C000
    sv.q C000, 0($a0)
    jr $ra
    nop
