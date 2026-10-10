#include "vfpu_macros.inc"

gfunc vfpu_QuatFromEuler
    lui $t0, %hi(.Ldeg_to_rad)
    addiu $t0, $t0, %lo(.Ldeg_to_rad)
    mtv	$a1, S000
    mtv	$a2, S001
    mtv	$a3, S002
    lv.s   S010, 0($t0)
    vscl.t C000, C000, S010
    vfim.s S010, 0.5
    vscl.t C000, C000, S010
    vcst.s S010, VFPU_2_PI
    vscl.t C000, C000, S010
    vrot.p C010, S000, [s, c]
    vrot.p C020, S001, [s, c]
    vrot.p C030, S002, [s, c]
    vmul.q R100, C010[x,y,y,x], C020[y,x,x,y]
    vmul.q R100, R100,          C030[y,x,y,x]
    vmul.q R101, C010[y,x,y,x], C020[y,x,y,x]
    vmul.q R101, R101,          C030[x,y,y,x]
    vadd.q C000, R100[x,z,0,0], R100[-y,w,0,0]
    vadd.q C000, C000, R101[0,0,x,z]
    vadd.q C000, C000, R101[0,0,-y,w]
    vdot.q S100, C000, C000
    vone.s S101
    vzero.s S102
    vcmp.s EQ, S100, S102
    vcmovt.s S100, S101, 0
    vrsq.s S100, S100
    vscl.q C000, C000, S100
    sv.q C000, 0($a0)
    jr $ra
    nop

    .section .rodata
    .align 2
.Ldeg_to_rad:
    .float 0.017453292519943295
    .text
