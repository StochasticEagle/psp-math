#include "pspmath.h"

void vfpu_Mat4LookAt_U(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up, ScePspFMatrix4 *mout)
{
    __asm__ volatile (
        "vmidt.q   M000\n"              /* Start with the Identity matrix */

        /* Load eye */
        "lv.s      S100, 0(%1)\n"
        "lv.s      S101, 4(%1)\n"
        "lv.s      S102, 8(%1)\n"

        /* Load center */
        "lv.s      S110, 0(%2)\n"
        "lv.s      S111, 4(%2)\n"
        "lv.s      S112, 8(%2)\n"

        /* Load up */
        "lv.s      S120, 0(%3)\n"
        "lv.s      S121, 4(%3)\n"
        "lv.s      S122, 8(%3)\n"

        /* f */
        "vsub.t    C130, C110, C100\n"
        "vdot.t    S200, C130, C130\n"
        "vrsq.s    S200, S200\n"
        "vscl.t    C130, C130, S200\n"

        /* s */
        "vcrs.t    C000, C130, C120\n"
        "vdot.t    S200, C000, C000\n"
        "vrsq.s    S200, S200\n"
        "vscl.t    C000, C000, S200\n"

        "vcrs.t    C010, C000, C130\n"  /* u */
        "vneg.t    C020, C130\n"        /* -f */

        /* Store */
        "sv.q      C000, 0(%0)\n"
        "sv.q      C010, 16(%0)\n"
        "sv.q      C020, 32(%0)\n"
        "sv.q      C030, 48(%0)\n"

        : : "r"(mout), "r"(eye), "r"(center), "r"(up) : "memory"
    );
}


void vfpu_Mat4LookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up, ScePspFMatrix4 *mout)
{
    __asm__ volatile (
        "vmidt.q   M000\n"              /* Start with the Identity matrix */
        "lv.q      C100, 0(%1)\n"       /* Load eye */
        "lv.q      C110, 0(%2)\n"       /* Load center */
        "lv.q      C120, 0(%3)\n"       /* Load up */

        /* f */
        "vsub.t    C130, C110, C100\n"
        "vdot.t    S200, C130, C130\n"
        "vrsq.s    S200, S200\n"
        "vscl.t    C130, C130, S200\n"

        /* s */
        "vcrs.t    C000, C130, C120\n"
        "vdot.t    S200, C000, C000\n"
        "vrsq.s    S200, S200\n"
        "vscl.t    C000, C000, S200\n"

        "vcrs.t    C010, C000, C130\n"  /* u */
        "vneg.t    C020, C130\n"        /* -f */

        /* Store */
        "sv.q      C000, 0(%0)\n"
        "sv.q      C010, 16(%0)\n"
        "sv.q      C020, 32(%0)\n"
        "sv.q      C030, 48(%0)\n"

        : : "r"(mout), "r"(eye), "r"(center), "r"(up) : "memory"
    );
}

