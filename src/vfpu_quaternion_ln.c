#include "pspmath.h"

/* Quaternion logarithm in native VFPU [x,y,z,w] order.
 * One VFPU block: no calls, register reloads, or division by zero.
 * For vanishing vector magnitude the direction is saturated to zero;
 * a zero-norm quaternion has its logarithmic magnitude saturated. */
void vfpu_QuatLn(ScePspQuatMatrix *qout, ScePspQuatMatrix *qin)
{
    const float epsilon = 1.0e-5f;
    const float epsilon2 = 1.0e-20f;
    __asm__ volatile (
        "lv.q C000, %1\n"
        "mtv %2, S020\n"
        "mtv %3, S021\n"
        "vdot.t S010, C000, C000\n"
        "vdot.q S011, C000, C000\n"
        "vmax.s S011, S011, S021\n"
        "vsqrt.s S012, S010\n"
        "vsqrt.s S013, S011\n"
        "vdiv.s S022, S003, S013\n"
        "vone.s S024\n"
        "vneg.s S025, S024\n"
        "vmin.s S022, S022, S024\n"
        "vmax.s S022, S022, S025\n"
        "vasin.s S022, S022\n"
        "vocp.s S022, S022\n"
        "vcst.s S023, VFPU_PI_2\n"
        "vmul.s S022, S022, S023\n"
        "vmax.s S020, S012, S020\n"
        "vdiv.s S020, S022, S020\n"
        "vmul.s S027, S020, S020\n"
        "vcmp.s LT, S010, S027\n"
        "vzero.s S024\n"
        "vcmovt.s S020, S024, 0\n"
        "vscl.t C000, C000, S020\n"
        "vlog2.s S025, S011\n"
        "vcst.s S026, VFPU_LN2\n"
        "vmul.s S025, S025, S026\n"
        "vfim.s S027, 0.5\n"
        "vmul.s S003, S025, S027\n"
        "sv.q C000, %0\n"
        : "=m"(*qout) : "m"(*qin), "r"(epsilon), "r"(epsilon2));
}
