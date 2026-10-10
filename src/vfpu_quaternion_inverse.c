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
    float norm PSPMATH_ALIGN = vfpu_QuatNorm_U(q1);

    norm = 1/(norm * norm);

    vfpu_Vec4Scale_U(conjugate, norm, qout);
}

void vfpu_QuatInverse(float *q1, float *qout)
{
    float conjugate[4] PSPMATH_ALIGN;
    vfpu_QuatConjugate(q1, conjugate);
    float norm PSPMATH_ALIGN = vfpu_QuatNorm(q1);

    norm = 1/(norm * norm);

    vfpu_VecVScale(conjugate, norm, qout);
}
