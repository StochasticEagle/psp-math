/* pspla
* A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/


#include "vfpu_macros.inc"


gfunc vfpu_Vec3RotationMatrix_U
    pushf $f0
    ulv.q r001, 0($a0)
    popf $f0
    vsin.t r002, r001
    vcos.t r003, r001
    vmidt.q m100
    vmidt.q m200
    vmidt.q m300
    vmov.q c110[m, , ,m], c000[0,w,z,0]
    vmov.q c120[m, , ,m], c000[0,-z,w,0]
    vmov.q c200[ ,m, ,m], c010[w,0,-z,0]
    vmov.q c220[ ,m, ,m], c010[z,0,w,0]
    vmov.q c300[ , ,m,m], c020[w,z,0,0]
    vmov.q c310[ , ,m,m], c020[-z,w,0,0]
    vmmul.t m400, m100, m200
    vmmul.t m500, m400, m300
    sv.q r500, 0($a1)
    usv.q r501, 12($a1)
    svt s502, s512, s522, $a1, 24
    jr $ra
    nop

gfunc vfpu_Vec3RotationMatrix
    lv.q r001, 0($a0)
    vsin.t r002, r001
    vcos.t r003, r001
    vmidt.q m100
    vmidt.q m200
    vmidt.q m300
    vmov.q c110[m, , ,m], c000[0,w,z,0]
    vmov.q c120[m, , ,m], c000[0,-z,w,0]
    vmov.q c200[ ,m, ,m], c010[w,0,-z,0]
    vmov.q c220[ ,m, ,m], c010[z,0,w,0]
    vmov.q c300[ , ,m,m], c020[w,z,0,0]
    vmov.q c310[ , ,m,m], c020[-z,w,0,0]
    vmmul.t m400, m100, m200
    vmmul.t m500, m400, m300
    sv.q r500, 0($a1)
    usv.q r501, 12($a1)
    svt s502, s512, s522, $a1, 24
    jr $ra
    nop

gfunc vfpu_Vec3RotationQuaternion_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vfim.s s003, 0.5
    vscl.t r000, r000, s003
    vsin.t r001, r000
    vcos.t r002, r000
    vmov.q c100, c000[z,y,z,y]
    vmov.q c110, c010[z,z,y,y]
    vmov.q c120, c020[z,z,z,z]
    vmul.q c200, c100, c110
    vmul.q c200, c200, c120
    vmov.q c100, c000[y,z,y,z]
    vmov.q c110, c010[y,y,z,z]
    vmov.q c120, c020[y,y,y,y]
    vmul.q c210, c100, c110
    vmul.q c210, c210, c120
    vadd.q c220, c200, c210[-x,y,-z,w]
    usv.q c220, 0($a1)
    jr $ra
    nop

gfunc vfpu_Vec3RotationQuaternion
    lv.q r000, 0($a0)
    vfim.s s003, 0.5
    vscl.t r000, r000, s003
    vsin.t r001, r000
    vcos.t r002, r000
    vmov.q c100, c000[z,y,z,y]
    vmov.q c110, c010[z,z,y,y]
    vmov.q c120, c020[z,z,z,z]
    vmul.q c200, c100, c110
    vmul.q c200, c200, c120
    vmov.q c100, c000[y,z,y,z]
    vmov.q c110, c010[y,y,z,z]
    vmov.q c120, c020[y,y,y,y]
    vmul.q c210, c100, c110
    vmul.q c210, c210, c120
    vadd.q c220, c200, c210[-x,y,-z,w]
    sv.q c220, 0($a1)
    jr $ra
    nop



gfunc vfpu_QuatRotationMatrix_U
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    vfim.s s001, 2
    vfim.s s011, 1
    vmul.q r100, r000[x,y,y,0], r000[x,z,w,0]
    vmul.q r101, r000[y,x,x,0], r000[y,w,z,0]
    vmul.q r200, r000[y,x,z,0], r000[z,x,w,0]
    vmul.q r201, r000[x,z,x,0], r000[w,z,y,0]
    vmul.q r300, r000[y,z,x,0], r000[w,w,x,0]
    vmul.q r301, r000[x,x,w,0], r000[z,y,w,0]
    vadd.t r102, r100, r101[x,-y,z]
    vadd.t r202, r200, r201[x,y,-z]
    vadd.t r302, r300, r301[-x,y,z]
    vscl.t r102, r102, s001
    vscl.t r202, r202, s001
    vscl.t r302, r302, s001
    vsub.s s102, s102, s011
    vsub.s s212, s212, s011
    vsub.s s322, s322, s011
    usv.q r102, 0($a1)
    usv.q r202, 12($a1)
    svt s302, s312, s322, $a1, 24
    jr $ra
    nop

gfunc vfpu_QuatRotationMatrix
    lv.q r000, 0($a0)
    vfim.s s001, 2
    vfim.s s011, 1
    vmul.q r100, r000[x,y,y,0], r000[x,z,w,0]
    vmul.q r101, r000[y,x,x,0], r000[y,w,z,0]
    vmul.q r200, r000[y,x,z,0], r000[z,x,w,0]
    vmul.q r201, r000[x,z,x,0], r000[w,z,y,0]
    vmul.q r300, r000[y,z,x,0], r000[w,w,x,0]
    vmul.q r301, r000[x,x,w,0], r000[z,y,w,0]
    vadd.t r102, r100, r101[x,-y,z]
    vadd.t r202, r200, r201[x,y,-z]
    vadd.t r302, r300, r301[-x,y,z]
    vscl.t r102, r102, s001
    vscl.t r202, r202, s001
    vscl.t r302, r302, s001
    vsub.s s102, s102, s011
    vsub.s s212, s212, s011
    vsub.s s322, s322, s011
    sv.q r102, 0($a1)
    usv.q r202, 12($a1)
    svt s302, s312, s322, $a1, 24
    jr $ra
    nop



