#include "vfpu_macros.inc"

gfunc vfpu_QuatIdentity_U
    vidt.q r000
    usv.q r000, 0($a0)
    jr $ra

gfunc vfpu_QuatIdentity_A
    vidt.q r000
    sv.q r000, 0($a0)
    jr $ra
