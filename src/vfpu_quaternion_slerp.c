/* vfpu_
 * A VFPU accelerated linear algebra & quaternion library for the PlayStation Portable.
 *
 * MIT License
 *
 * Copyright (c) 2024 Jayanky
 */

#include "pspmath.h"

void vfpu_QuatSlerp_U(float *q1, float *q2, float s1, float *qout)
{
    float r1[4] PSPMATH_ALIGN;
    float r2[4] PSPMATH_ALIGN;

    float cosOmega = vfpu_Vec4DotProduct_U(q1, q2);

    if(vfpu_AbsoluteValue(cosOmega) >= 1.0)
    {
        vfpu_Vec4Copy_U(q1, qout);
        return;
    }

    float omega = vfpu_acosf(cosOmega);
    float sinOmega = vfpu_SquareRoot(1.0 - (cosOmega * cosOmega));

    float p1 = vfpu_sinf((1.0f - s1) * omega) / sinOmega;
    float p2 = vfpu_sinf(s1 * omega) / sinOmega;

    vfpu_Vec4Scale_U(q1, p1, r1);
    vfpu_Vec4Scale_U(q2, p2, r2);
    vfpu_Vec4Add_U(r1, r2, qout);
}

void vfpu_QuatSlerp(float *q1, float *q2, float s1, float *qout)
{
    float r1[4] PSPMATH_ALIGN;
    float r2[4] PSPMATH_ALIGN;

    float cosOmega = vfpu_Vec4DotProduct(q1, q2);

    if(vfpu_AbsoluteValue(cosOmega) >= 1.0)
    {
        vfpu_Vec4Copy(q1, qout);
        return;
    }

    float omega = vfpu_acosf(cosOmega);
    float sinOmega = vfpu_SquareRoot(1.0 - (cosOmega * cosOmega));

    float p1 = vfpu_sinf((1.0f - s1) * omega) / sinOmega;
    float p2 = vfpu_sinf(s1 * omega) / sinOmega;

    vfpu_Vec4Scale(q1, p1, r1);
    vfpu_Vec4Scale(q2, p2, r2);
    vfpu_Vec4Add(r1, r2, qout);
}
