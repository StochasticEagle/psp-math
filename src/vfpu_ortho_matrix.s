#include "vfpu_macros.inc"

gfunc vfpu_Mat4Orthographic
    lw $t0, 16($sp)
    lw $t1, 20($sp)
    lw $t2, 24($sp)
    vmidt.q M100
    mtv     $a2, S000
    mtv     $t0, S001
    mtv     $t2, S002
    mtv     $a1, S010
    mtv     $a3, S011
    mtv     $t1, S012
    vsub.t  C020, C000, C010
    vrcp.t  C020, C020
    vmul.s  S100, S100[2], S020
    vmul.s  S111, S111[2], S021
    vmul.s  S122, S122[2], S022[-x]
    vsub.t  C130, C000[-x,-y,-z], C010
    vmul.t  C130, C130, C020
    sv.q    C100, 0($a0)
    sv.q    C110, 16($a0)
    sv.q    C120, 32($a0)
    sv.q    C130, 48($a0)
    jr $ra
    nop

gfunc vfpu_Mat4TransformVec4
    lv.q    C000, 0($a0)
    lv.q    C010, 16($a0)
    lv.q    C020, 32($a0)
    lv.q    C030, 48($a0)
    lv.q    C100, 0($a1)
    vtfm4.q C110, M000, C100
    sv.q    C110, 0($a2)
    jr $ra
    nop
