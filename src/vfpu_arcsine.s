/* pspla
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"

gfunc vfpu_Arcsine
    mfc1 $t0, $f12
    mtv $t0, s000
    vfim.s s001, 0
    vfim.s s002, 0
    vfim.s s003, 30
    vfim.s s020, 1
Arcsine_loop:
    vcmp.s lt, s002, s003
    vadd.s s002, s002, s020
    vsin.s s010, s001
    vsub.s s010, s010, s000
    vcos.s s011, s001
    vdiv.s s012, s010, s011
    vsub.s s001, s001, s012
    bvtl 0, Arcsine_loop
    mfv $t0, s001
    mtc1 $t0, $f0
    jr $ra
