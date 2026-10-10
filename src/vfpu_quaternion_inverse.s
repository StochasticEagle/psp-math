#include "vfpu_macros.inc"

gfunc vfpu_QuatInverse_U
    lv.s S000, 0($a0)
    lv.s S010, 4($a0)
    lv.s S020, 8($a0)
    lv.s S030, 12($a0)
    vdot.q S100, C000, C000
    vrcp.s S100, S100
    vneg.t C000, C000
    vscl.q C000, C000, S100
    sv.s S000, 0($a1)
    sv.s S010, 4($a1)
    sv.s S020, 8($a1)
    sv.s S030, 12($a1)
    jr $ra
    nop

gfunc vfpu_QuatInverse
    lv.q C000, 0($a0)
    vdot.q S100, C000, C000
    vrcp.s S100, S100
    vneg.t C000, C000
    vscl.q C000, C000, S100
    sv.q C000, 0($a1)
    jr $ra
    nop
