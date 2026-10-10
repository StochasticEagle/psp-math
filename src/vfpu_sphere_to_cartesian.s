#include "vfpu_macros.inc"

gfunc vfpu_Vec3FromSpherical
    mfc1 $t3, $f12
    mfc1 $t4, $f14
    lw $t1, 16($sp)
    lw $t2, 20($sp)
    mtv      $t3, S000
    mtv      $t4, S001
    mtv      $a2, S002
    vcst.s   S003, VFPU_2_PI
    vscl.p   C000, C000, S003
    vrot.p   C010, S000, [s, c]
    vrot.p   C012, S001, [s, c]
    vmul.q   C020, C010[y, 1, x, 0], C010[z, w, z, 0]
    vscl.t   C020, C020, S002
    sv.q     C020, 0($a3)
    sv.s     S020, 0($a3)
    sv.s     S021, 0($t1)
    sv.s     S022, 0($t2)
    jr $ra
    nop
