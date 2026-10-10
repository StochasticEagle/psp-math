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
    vfpu_VecVScale(conjugate, 1.0f / (norm * norm), qout);
}
/**
 *  Get the norm of a quaternion - Unaligned
 *  @param q1 input quaternion
 *  @return The quaternion norm
 **/
float vfpu_QuatMagnitude_U(float* q1);

/**
 *  Get the norm of a quaternion - Aligned
 *  @param q1 input quaternion
 *  @return The quaternion norm
 **/
void vfpu_QuatMagnitude(const float *q1, float *qout);

/**
 *  Get the normalized of a quaternion - Unaligned
 *  @param q1 input quaternion
 *  @return The quaternion with magnitude = 1
 **/
float vfpu_QuatNormalize_U(float* q1);

/**
 *  Get the normalized quaternion - Aligned
 *  @param q1 input quaternion
 *  @return The quaternion with magnitude = 1
 **/
float vfpu_QuatNormalize(float* q1);
