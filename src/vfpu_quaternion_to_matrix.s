#include "vfpu_macros.inc"

gfunc vfpu_QuatToMat4
    lv.q      C000, 0($a0)
    vmul.q    C010, C000, C000
    vcrs.t    C020, C000, C000
    vmul.q    C030, C000[x,y,z,1], C000[w,w,w,2]
    vadd.q    C100, C020[0,z,y,0], C030[0,z,-y,0]
    vadd.s    S100, S011, S012
    vadd.q    C110, C020[z,0,x,0], C030[-z,0,x,0]
    vadd.s    S111, S010, S012
    vadd.q    C120, C020[y,x,0,0], C030[y,-x,0,0]
    vadd.s    S122, S010, S011
    vmscl.t   M100, M100, S033
    vocp.s    S100, S100
    vocp.s    S111, S111
    vocp.s    S122, S122
    vidt.q    C130
    sv.q      R100, 0($a1)
    sv.q      R101, 16($a1)
    sv.q      R102, 32($a1)
    sv.q      R103, 48($a1)
    jr $ra
    nop
