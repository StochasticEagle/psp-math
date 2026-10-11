#include "vfpu_macros.inc"

gfunc vfpu_Vec3SetPosition
    lv.q C000, 0($a0)
    vone.s S003
    sv.q C000, 0($a1)
    jr $ra
    nop

gfunc vfpu_Vec3SetDirection
    lv.q C000, 0($a0)
    vzero.s S003
    sv.q C000, 0($a1)
    jr $ra
    nop
