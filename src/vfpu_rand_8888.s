#include "vfpu_macros.inc"

gfunc vfpu_rand_8888
    mtv      $a0, S020
    mtv      $a1, S021
    vmov.t   C000, C020[x, x, x]
    vmov.t   C010, C020[y, y, y]
    vi2f.t   C000, C000, 0
    vi2f.t   C010, C010, 0
    vsub.t   C010, C010, C000
    vrndf1.t C020
    vsub.t   C020, C020, C020[1, 1, 1]
    vmul.t   C020, C020, C010
    vadd.t   C020, C020, C000
    vf2iz.t  C020, C020, 23
    viim.s   S023, 255
    vf2iz.s  S023, S023, 23
    vi2uc.q  S000, C020
    mfv      $v0, S000
    jr $ra
    nop
