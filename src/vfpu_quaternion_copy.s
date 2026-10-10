#include "vfpu_macros.inc"

gfunc vfpu_QuatCopy
    lv.q C000, 0($a0)
    sv.q C000, 0($a1)
    jr $ra
    nop
