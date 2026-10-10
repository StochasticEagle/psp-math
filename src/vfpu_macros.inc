/* pspla
 * A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
 *
 * MIT License
 *
 * Copyright (c) 2024 Jayanky
 */


# Unaligned and aligned loads for matrices
# Figured that splitting these up better allows for choosing between speed and flexibility
# Imported from pspla
# September 2026

#ifndef _vfpu_macros_inc_
#define _vfpu_macros_inc_

.macro lm2_u mat, src
    ulv.q r\mat\()00, 0(\src\())
    ulv.q r\mat\()01, 8(\src\())
.endm

.macro lm3_u mat, src
    ulv.q r\mat\()00, 0(\src\())
    ulv.q r\mat\()01, 12(\src\())
    ulv.q r\mat\()02, 24(\src\())
.endm

.macro lm4_u mat, src
    ulv.q r\mat\()00, 0(\src\())
    ulv.q r\mat\()01, 16(\src\())
    ulv.q r\mat\()02, 32(\src\())
    ulv.q r\mat\()03, 48(\src\())
.endm

.macro lm2_a mat, src
    lv.q r\mat\()00, 0(\src\())
    vmov.p r\mat\()01, r\mat\()20
.endm

.macro lm3_a mat, src
    lv.q r\mat\()00, 0(\src\())
    lv.q r\mat\()01, 16(\src\())
    lv.s s\mat\()22, 32(\src\())
    vmov.p r\mat\()02, r\mat\()21
    vmov.t r\mat\()11, r\mat\()01
    vmov.s s\mat\()01, s\mat\()30
.endm

.macro lm4_a mat, src
    lv.q r\mat\()00, 0(\src\())
    lv.q r\mat\()01, 16(\src\())
    lv.q r\mat\()02, 32(\src\())
    lv.q r\mat\()03, 48(\src\())
.endm



# Reduce function header redundancy
.macro gfunc name
    .globl \name
    \name\():
.endm



# Slightly compact saving for Vec2 and Vec3 unaligned functions
.macro svp reg1, reg2, dest, off
    sv.s \reg1\(), (\off\() + 0)(\dest\())
    sv.s \reg2\(), (\off\() + 4)(\dest\())
.endm

.macro svt reg1, reg2, reg3, dest, off
    svp \reg1\(), \reg2\(), \dest\(), \off\()
    sv.s \reg3\(), (\off\() + 8)(\dest\())
.endm



# Pushing and popping corrupted registers to and from the stack
.macro pushf reg
    sub $sp, $sp, 4
    s.s \reg\(), 0($sp)
.endm

.macro popf reg
    l.s \reg\(), 0($sp)
    add $sp, $sp, 4
.endm



# For functions that take two vectors and output a vector
.macro singleOpVec_U op
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    \op\() r002, r000, r001
.endm

.macro singleOpVec2_U op
    singleOpVec_U \op\()
    svp s002, s012, $a2, 0
.endm

.macro singleOpVec3_U op
    singleOpVec_U \op\()
    svt s002, s012, s022, $a2, 0
.endm

.macro singleOpVec4_U op
    singleOpVec_U \op\()
    usv.q r002, 0($a2)
.endm

.macro singleOpVecV op
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    \op\() r002, r000, r001
    sv.q r002, 0($a2)
.endm



# For functions that take a single vector and output a scalar
.macro singleOpScaV_U op
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    \op\() s001, r000
    mfv $t0, s001
    mtc1 $t0, $f0
.endm

.macro singleOpScaV op
    lv.q r000, 0($a0)
    \op\() s001, r000
    mfv $t0, s001
    mtc1 $t0, $f0
.endm



# For functions that take two vectors and output a scalar
.macro singleOpScaDV_U op
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    \op\() s002, r000, r001
    mfv $t0, s002
    mtc1 $t0, $f0
.endm

.macro singleOpScaDV op
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    \op\() s002, r000, r001
    mfv $t0, s002
    mtc1 $t0, $f0
.endm



# For functions that take a single vector and return a single vector
.macro singleOpSVec_U op
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    \op\() r002, r000
.endm

.macro singleOpSVec2_U op
    singleOpSVec_U \op\()
    svp s002, s012, $a1, 0
.endm

.macro singleOpSVec3_U op
    singleOpSVec_U \op\()
    svt s002, s012, s022, $a1, 0
.endm

.macro singleOpSVec4_U op
    singleOpSVec_U \op\()
    usv.q r002, 0($a1)
.endm

.macro singleOpSVecV op
    lv.q r000, 0($a0)
    \op\() r002, r000
    sv.q r002, 0($a1)
.endm



# For functions that take a vector and scalar as arguments, and return a vector
.macro singleOpVecSca_U op
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    mfc1 $t0, $f12
    mtv $t0, s001
    \op\() r002, r000, s001
.endm

.macro singleOpVec2Sca_U op
    singleOpVecSca_U \op\()
    svp s002, s012, $a1, 0
.endm

.macro singleOpVec3Sca_U op
    singleOpVecSca_U \op\()
    svt s002, s012, s022, $a1, 0
.endm

.macro singleOpVec4Sca_U op
    singleOpVecSca_U \op\()
    usv.q r002, 0($a1)
.endm

.macro singleOpVecVSca op
    lv.q r000, 0($a0)
    mfc1 $t0, $f12
    mtv $t0, s001
    \op\() r002, r000, s001
    sv.q r002, 0($a1)
.endm



# For functions that take a scalar and return a scalar
.macro singleOpSca2Sca op
    mfc1 $t0, $f12
    mtv $t0, s000
    \op\() s001, s000
    mfv $t0, s001
    mtc1 $t0, $f0
.endm


/* Two independent XY vectors in each aligned 128-bit quad. */
.macro pair_reduce op
    lv.q r000, 0($a0)
    \op\().p s200, r000
    vmov.q r001, r000[z,w,z,w]
    \op\().p s210, r001
    sv.s s200, 0($a1)
    sv.s s210, 4($a1)
.endm


# For Round, Floor, and Ceiling functions
.macro truncateOpVec_U op
    pushf $f0
    ulv.q r000, 0($a0)
    popf $f0
    \op\() r000, r000, 0
    vi2f.q r000, r000, 0
.endm

.macro truncateOpVec2_U op
    truncateOpVec_U \op\()
    svp s000, s010, $a1, 0
.endm

.macro truncateOpVec3_U op
    truncateOpVec_U \op\()
    svt s000, s010, s020, $a1, 0
.endm

.macro truncateOpVec4_U op
    truncateOpVec_U \op\()
    usv.q r000, 0($a1)
.endm

.macro truncateOpVecV op
    lv.q r000, 0($a0)
    \op\() r000, r000, 0
    vi2f.q r000, r000, 0
    sv.q r000, 0($a1)
.endm



# For comparison functions
.macro comparisonOpVec_U inst op
    pushf $f0
    ulv.q r000, 0($a0)
    ulv.q r001, 0($a1)
    popf $f0
    viim.s s003, 0
    vmtvc $131, s003
    \inst\() \op\(), r000, r001
    vnop
    mfvc $v0, $131
.endm

.macro comparisonOpVec inst op
    lv.q r000, 0($a0)
    lv.q r001, 0($a1)
    viim.s s003, 0
    vmtvc $131, s003
    \inst\() \op\(), r000, r001
    vnop
    mfvc $v0, $131
.endm



# For mat3 and mat4 element-wise functions
.macro singleOpMat3_U op
    sub $sp, $sp, 8
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm3_u 0, $a0
    lm3_u 1, $a1
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    add $sp, $sp, 8
    \op\().t r200, r000, r100
    \op\().t r201, r001, r101
    \op\().t r202, r002, r102
    usv.q r200, 0($a2)
    usv.q r201, 12($a2)
    svt s202, s212, s222, $a2, 24
.endm

.macro singleOpMat4_U op
    sub $sp, $sp, 8
    s.s $f0, 4($sp)
    s.s $f4, 0($sp)
    lm4_u 0, $a0
    lm4_u 1, $a1
    l.s $f4, 0($sp)
    l.s $f0, 4($sp)
    add $sp, $sp, 8
    \op\().q r200, r000, r100
    \op\().q r201, r001, r101
    \op\().q r202, r002, r102
    \op\().q r203, r003, r103
    usv.q r200, 0($a2)
    usv.q r201, 16($a2)
    usv.q r202, 32($a2)
    usv.q r203, 48($a2)
.endm

.macro singleOpMat3 op
    lm3_a 0, $a0
    lm3_a 1, $a1
    \op\().t r200, r000, r100
    \op\().t r201, r001, r101
    \op\().t r202, r002, r102
    sv.q r200, 0($a2)
    usv.q r201, 12($a2)
    usv.q r202, 24($a2)
.endm

.macro singleOpMat4 op
    lm4_a 0, $a0
    lm4_a 1, $a1
    \op\().q r200, r000, r100
    \op\().q r201, r001, r101
    \op\().q r202, r002, r102
    \op\().q r203, r003, r103
    sv.q r200, 0($a2)
    sv.q r201, 16($a2)
    sv.q r202, 32($a2)
    sv.q r203, 48($a2)
.endm



# For determinant and inverse functions
.macro mat2Determinant a, b, c, d, out
    vmov.s s000, s7\a
    vmov.s s010, s7\d
    vmov.s s001, s7\b
    vmov.s s011, s7\c
    vmul.p c020, c000, c010
    vfad.p \out, c020[x,-y]
.endm

.macro mat3Determinant d, e, f, g, h, i, j, k, l, mlt, out
    mat2Determinant \e, \f, \h, \i, s100
    mat2Determinant \d, \f, \g, \i, s101
    mat2Determinant \d, \e, \g, \h, s102
    vmov.q c110, r7\mlt\()[\j,\k,\l,0]
    vmul.t c120, c110, c100
    vfad.t \out, c120[x,-y,z]
.endm

.macro mat4Determinant e, f, g, h, i, j, k, l, out
    mat3Determinant \f, \g, \h, \j, \k, \l, y, z, w, 01, s200
    mat3Determinant \e, \g, \h, \i, \k, \l, x, z, w, 01, s201
    mat3Determinant \e, \f, \h, \i, \j, \l, x, y, w, 01, s202
    mat3Determinant \e, \f, \g, \i, \j, \k, x, y, z, 01, s203
    vmov.q c210, r700
    vmul.q c220, c210, c200
    vfad.q \out, c220[x,-y,z,-w]
.endm

#endif
