#include "vfpu_macros.inc"


gfunc vfpu_QuatConjugate_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vneg.t r010, r010
    usv.q r000, 0($a1)

gfunc vfpu_QuatConjugate
    lv.q r000, 0($a0)
    vneg.t r010, r010
    sv.q r000, 0($a1)
    jr $ra
