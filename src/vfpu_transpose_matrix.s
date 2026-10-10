/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/

#include "vfpu_macros.inc"

gfunc vfpu_Mat2Transpose_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vmov.q r000, r000[x,z,y,w]
    usv.q r000, 0($a1)
    jr $ra

gfunc vfpu_Mat3Transpose_U
    pushf $f0
    lm3_u 0, $a0
    popf $f0
    vmov.t c100, r000
    vmov.t c110, r001
    vmov.t c120, r002
    usv.q r100, 0($a1)
    usv.q r101, 12($a1)
    svt s102, s112, s122, $a1, 24
    jr $ra

gfunc vfpu_Mat4Transpose_U
    pushf $f0
    lm4_u 0, $a0
    popf $f0
    vmov.q c100, r000
    vmov.q c110, r001
    vmov.q c120, r002
    vmov.q c130, r003
    usv.q r100, 0($a1)
    usv.q r101, 16($a1)
    usv.q r102, 32($a1)
    usv.q r103, 48($a1)
    jr $ra

gfunc vfpu_Mat4Transpose
    pushf   $f0
    lv.q    c000, 0($a0)
    lv.q    c010, 16($a0)
    lv.q    c020, 32($a0)
    lv.q    c030, 48($a0)
    popf    $f0

    vmov.q  c100, r000
    vmov.q  c110, r001
    vmov.q  c120, r002
    vmov.q  c130, r003

    sv.q    r100, 0($a1)
    sv.q    r101, 16($a1)
    sv.q    r102, 32($a1)
    sv.q    r103, 48($a1)
    jr      $ra
