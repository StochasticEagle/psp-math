#include "pspmath.h"

/* Native [x,y,z,w] quaternion logarithm, computed in one VFPU block.
 * C000 holds the input until the final output; all temporaries use matrix 1.
 * At vanishing vector magnitude, saturate the vector part to zero.
 * Clamp the squared norm to avoid log(0) and division by zero. */
void vfpu_QuatLn(ScePspQuatMatrix *qout, ScePspQuatMatrix *qin)
{
    const float epsilon2 = 1.1e-19f;  /* ( slightly greater than sqrt(FLT_MIN) ) */
    const float norm_min = 1.0e-20f;
    __asm__ volatile (
        "lv.q C000, %1\n"
        "mtv %2, S120\n"
        "mtv %3, S121\n"
        "vdot.t S110, C000, C000\n"
        "vdot.q S111, C000, C000\n"
        "vmax.s S111, S111, S121\n"
        "vsqrt.s S112, S110\n"
        "vsqrt.s S113, S111\n"
        "vdiv.s S122, S030, S113\n"
        "vone.s S123\n"
        "vneg.s S130, S123\n"
        "vmin.s S122, S122, S123\n"
        "vmax.s S122, S122, S130\n"
        "vasin.s S122, S122\n"
        "vocp.s S122, S122\n"
        "vcst.s S131, VFPU_PI_2\n"
        "vmul.s S122, S122, S131\n"
        "vmax.s S112, S112, S120\n"
        "vdiv.s S132, S122, S112\n"
        "vcmp.s LT, S110, S120\n"
        "vzero.s S133\n"
        "vcmovt.s S132, S133, 0\n"
        "vscl.t C000, C000, S132\n"
        "vlog2.s S130, S111\n"
        "vcst.s S131, VFPU_LN2\n"
        "vmul.s S130, S130, S131\n"
        "vfim.s S131, 0.5\n"
        "vmul.s S030, S130, S131\n"
        "sv.q C000, %0\n"
        : "=m"(*qout) : "m"(*qin), "r"(epsilon2), "r"(norm_min));
}
