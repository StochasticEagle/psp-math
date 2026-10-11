/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/

#include "vfpu_macros.inc"

gfunc vfpu_Mat2Transpose_U
    ulv.q r000, 0($a0)
    vmov.q r000, r000[x,z,y,w]
    usv.q r000, 0($a1)
    jr $ra
    nop

gfunc vfpu_Mat3Transpose_U
    lm3_u 0, $a0
    vmov.t c100, r000
    vmov.t c110, r001
    vmov.t c120, r002
    sm3 1, $a1
    jr $ra
    nop

gfunc vfpu_Mat4Transpose_U
    lm4_u 0, $a0
    vmov.q c100, r000
    vmov.q c110, r001
    vmov.q c120, r002
    vmov.q c130, r003
    usv.q r100, 0($a1)
    usv.q r101, 16($a1)
    usv.q r102, 32($a1)
    usv.q r103, 48($a1)
    jr $ra
    nop

gfunc vfpu_Mat4Transpose
    lv.q    c000, 0($a0)
    lv.q    c010, 16($a0)
    lv.q    c020, 32($a0)
    lv.q    c030, 48($a0)

    vmov.q  c100, r000
    vmov.q  c110, r001
    vmov.q  c120, r002
    vmov.q  c130, r003

    sv.q    r100, 0($a1)
    sv.q    r101, 16($a1)
    sv.q    r102, 32($a1)
    sv.q    r103, 48($a1)
    jr      $ra
    nop
