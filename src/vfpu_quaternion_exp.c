#include "pspmath.h"

/* VFPU calculations are confined to this function; no live VFPU values
 * cross calls. Guard the removable sin(r)/r singularity explicitly. */
void vfpu_QuatExp(ScePspQuatMatrix *qout, ScePspQuatMatrix *qin)
{
    const float x = qin->a, y = qin->b, z = qin->c, w = qin->d;
    const float r2 = x*x + y*y + z*z;
    const float r = vfpu_SquareRoot(r2);
    const float ew = vfpu_expf(w);
    float ratio, cosine;

    if (r <= 1.0e-5f) {
        /* sin(r)/r -> 1, cos(r) -> 1. */
        ratio = 1.0f;
        cosine = 1.0f;
    } else {
        ratio = vfpu_sinf(r) / r;
        cosine = vfpu_cosf(r);
    }
    qout->a = ew * ratio * x;
    qout->b = ew * ratio * y;
    qout->c = ew * ratio * z;
    qout->d = ew * cosine;
}
