/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_quaternion_identity_U
    vidt.q r000
    usv.q r000, 0($a0)
    jr $ra

gfunc vfpu_quaternion_identity
    vidt.q r000
    sv.q r000, 0($a0)
    jr $ra
