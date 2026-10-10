#include "vfpu_macros.inc"

gfunc vfpu_Mat4LookAt_U
    vmidt.q   M000
    lv.s      S100, 0($a0)
    lv.s      S101, 4($a0)
    lv.s      S102, 8($a0)
    lv.s      S110, 0($a1)
    lv.s      S111, 4($a1)
    lv.s      S112, 8($a1)
    lv.s      S120, 0($a2)
    lv.s      S121, 4($a2)
    lv.s      S122, 8($a2)
    vsub.t    C130, C110, C100
    vdot.t    S200, C130, C130
    vrsq.s    S200, S200
    vscl.t    C130, C130, S200
    vcrs.t    C000, C130, C120
    vdot.t    S200, C000, C000
    vrsq.s    S200, S200
    vscl.t    C000, C000, S200
    vcrs.t    C010, C000, C130
    vneg.t    C020, C130
    sv.q      C000, 0($a3)
    sv.q      C010, 16($a3)
    sv.q      C020, 32($a3)
    sv.q      C030, 48($a3)
    jr $ra
    nop

gfunc vfpu_Mat4LookAt
    vmidt.q   M000
    lv.q      C100, 0($a0)
    lv.q      C110, 0($a1)
    lv.q      C120, 0($a2)
    vsub.t    C130, C110, C100
    vdot.t    S200, C130, C130
    vrsq.s    S200, S200
    vscl.t    C130, C130, S200
    vcrs.t    C000, C130, C120
    vdot.t    S200, C000, C000
    vrsq.s    S200, S200
    vscl.t    C000, C000, S200
    vcrs.t    C010, C000, C130
    vneg.t    C020, C130
    sv.q      C000, 0($a3)
    sv.q      C010, 16($a3)
    sv.q      C020, 32($a3)
    sv.q      C030, 48($a3)
    jr $ra
    nop
