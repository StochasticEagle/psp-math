#include "vfpu_macros.inc"

gfunc vfpu_Mat4Perspective
    lw $t0, 16($sp)
    vmzero.q M100
    mtv     $a1, S000
    viim.s  S001, 90
    vrcp.s  S001, S001
    vmul.s  S000, S000, S000[1/2]
    vmul.s  S000, S000, S001
    vrot.p  C002, S000, [c, s]
    vdiv.s  S100, S002, S003
    mtv     $a3, S001
    mtv     $t0, S002
    vsub.s  S003, S001, S002
    vrcp.s  S003, S003
    mtv     $a2, S000
    vmov.s  S111, S100
    vdiv.s  S100, S100, S000
    vadd.s  S122, S001, S002
    vmul.s  S122, S122, S003
    vmul.s  S132, S001, S002
    vmul.s  S132, S132, S132[2]
    vmul.s  S132, S132, S003
    vsub.s   S123, S123, S123[1]
    sv.q	 C100, 0($a0)
    sv.q	 C110, 16($a0)
    sv.q	 C120, 32($a0)
    sv.q	 C130, 48($a0)
    jr $ra
    nop
