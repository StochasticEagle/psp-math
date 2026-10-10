/* vfpu_
 * A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
 *
 * MIT License
 *
 * Copyright (c) 2024 Jayanky
 */

#include "pspmath.h"

void vfpu_QuatRotate_U(float *q1, float *q2, float *qout)
{
    float q2c[4] PSPMATH_ALIGN;
    float accumulator[4] PSPMATH_ALIGN;

    vfpu_QuatConjugate_U(q2, q2c);
    vfpu_QuatMultiply_U(q2, q1, accumulator);
    vfpu_QuatMultiply(accumulator, q2c, accumulator);
    vfpu_Vec4Copy_U(accumulator, qout);
}

void vfpu_QuatRotate(float *q1, float *q2, float *qout)
{
    float q2c[4] PSPMATH_ALIGN;
    float accumulator[4] PSPMATH_ALIGN;

    vfpu_QuatConjugate(q2, q2c);
    vfpu_QuatMultiply(q2, q1, accumulator);
    vfpu_QuatMultiply(accumulator, q2c, accumulator);
    vfpu_Vec4Copy(accumulator, qout);
}
