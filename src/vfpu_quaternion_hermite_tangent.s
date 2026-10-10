#include "vfpu_macros.inc"

gfunc vfpu_QuatHermiteTangent
    lv.q C000, 0($a0)
    lv.q C010, 0($a1)
    mtv $a2, S100
    vsub.q C020, C010, C000
    vscl.q C020, C020, S100
    sv.q C020, 0($a3)
    jr $ra
    nop
