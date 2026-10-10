/* vfpu_
* A VFPU accelerated linear algebra &amp; quaternion library for the PlayStation Portable.
*
* MIT License
*
* Copyright (c) 2024 Jayanky
*/

#include "pspmath.h"

void vfpu_QuatInverse_U(float *q1, float *qout)
{
    float conjugate[4] PSPMATH_ALIGN;
    vfpu_QuatConjugate_U(q1, conjugate);
    float norm = vfpu_Vec4Magnitude_U(q1);
    vfpu_Vec4Scale_U(conjugate, 1.0f / (norm * norm), qout);
}

void vfpu_QuatInverse(float *q1, float *qout)
{
    float conjugate[4] PSPMATH_ALIGN;
    vfpu_QuatConjugate(q1, conjugate);
    float norm = vfpu_Vec4Magnitude(q1);
    vfpu_Vec4Scale(conjugate, 1.0f / (norm * norm), qout);
}
