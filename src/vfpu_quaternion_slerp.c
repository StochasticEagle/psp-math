#include "pspmath.h"

/* Shortest-arc SLERP for unit quaternions.  Scalar coefficients are computed
 * before vector operations, so no VFPU register state spans a C call. */
static void quat_slerp(const float *q1, const float *q2, float t, float *out)
{
    float dot = q1[0]*q2[0] + q1[1]*q2[1] + q1[2]*q2[2] + q1[3]*q2[3];
    float sign = 1.0f;
    if (dot < 0.0f) { dot = -dot; sign = -1.0f; }
    if (dot > 1.0f) dot = 1.0f;

    float a, b;
    if (dot >= 0.9995f) {
        a = 1.0f - t;
        b = t * sign;
    } else {
        const float omega = vfpu_acosf(dot);
        const float sine = vfpu_sinf(omega);
        a = vfpu_sinf((1.0f - t) * omega) / sine;
        b = sign * vfpu_sinf(t * omega) / sine;
    }

    float x = a*q1[0] + b*q2[0];
    float y = a*q1[1] + b*q2[1];
    float z = a*q1[2] + b*q2[2];
    float w = a*q1[3] + b*q2[3];
    float n2 = x*x + y*y + z*z + w*w;
    if (n2 <= 1.0e-20f) {
        out[0] = 0.0f; out[1] = 0.0f; out[2] = 0.0f; out[3] = 1.0f;
    } else {
        float inv = 1.0f / vfpu_SquareRoot(n2);
        out[0] = x*inv; out[1] = y*inv; out[2] = z*inv; out[3] = w*inv;
    }
}

void vfpu_QuatSlerp_U(float *q1, float *q2, float t, float *qout)
{
    quat_slerp(q1, q2, t, qout);
}

void vfpu_QuatSlerp(float *q1, float *q2, float t, float *qout)
{
    quat_slerp(q1, q2, t, qout);
}
