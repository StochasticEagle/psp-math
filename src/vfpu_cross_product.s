/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec2Cross_U
    lw    $t0, 0($a0)                 # Load v1.x via GPR
    lw    $t1, 4($a0)                 # Load v1.y via GPR
    mtv   $t0, s000                   # Move to VFPU scalar
    mtv   $t1, s010                   # Move to VFPU scalar
    lw    $t0, 0($a1)                 # Load v2.x via GPR
    lw    $t1, 4($a1)                 # Load v2.y via GPR
    mtv   $t0, s001                   # Move to VFPU scalar
    mtv   $t1, s011                   # Move to VFPU scalar
    vmul.p r002, r000, r001[y,x]      # r002.x = x1*y2, r002.y = y1*x2
    vfad.p s003, r002[x,-y]           # s003 = x1*y2 - y1*x2
    mfv   $t0, s003                   # Move result to GPR
    jr    $ra
    mtc1  $t0, $f0                    # Optimized branch delay slot (moves to return float)

gfunc vfpu_Vec2Cross
    lv.q  r000, 0($a0)
    lv.q  r001, 0($a1)
    vmul.p r002, r000, r001[y,x]      # r002.x = x1*y2, r002.y = y1*x2
    vfad.p s003, r002[x,-y]           # s003 = x1*y2 - y1*x2
    mfv   $t0, s003                   # Move result to GPR
    jr    $ra
    mtc1  $t0, $f0                    # Optimized branch delay slot

gfunc vfpu_Vec2pCross
    lv.q   r000, 0($a0)              # Load v1 packed pairs [x1, y1, z1, w1]
    lv.q   r001, 0($a1)              # Load v2 packed pairs [x2, y2, z2, w2]
    vmul.p r002, r000, r001[y,x]     # Cross-multiply both pairs in parallel
    vsub.p r003, r002, r002[y,x]     # Subtract cross terms for both pairs simultaneously
    sv.s   s003, 0($a2)              # Store first result (x1*y2 - y1*x2)
    sv.s   s023, 4($a2)              # Store second result (z1*w2 - w1*z2)
    jr     $ra
    nop

gfunc vfpu_Vec3CrossProduct_U
    singleOpVec3_U vcrsp.t
    jr $ra
    nop

gfunc vfpu_Vec3CrossProduct
    singleOpVecV vcrsp.t
    jr $ra
    nop
