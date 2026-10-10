#include "pspmath.h"

static const float rgb565_pack[4] __attribute__((aligned(16))) = { 2048.0f, 32.0f, 1.0f, 0.0f };


unsigned short vfpu_rand_565(int minS, int minL, int maxS, int maxL)
{
	unsigned int result;

	__asm__ volatile (
		"mtv      %1, S020\n"				/* minS */
		"mtv      %2, S021\n"				/* minL */
		"mtv      %3, S022\n"				/* maxS */
		"mtv      %4, S023\n"				/* maxL */

		"vi2f.q   C020, C020, 0\n"			/* Convert limits to float. */
		"vmov.t   C000, C020[x, y, x]\n"	/* C000 = [minS, minL, minS] */
        "vmov.q   C010, C020[z, w, z, w]\n"	/* C010 = [maxS, maxL, maxS] */
		"vsub.t   C010, C010, C000\n"		/* C010 = [rangeS, rangeL, rangeS] */

		"vrndf1.t C020\n"					/* Generate three random floats in [0, 1). */
		"vmul.t   C020, C020, C010\n"		/* Scale into requested ranges. */
		"vadd.t   C020, C020, C000\n"		/* Offset into requested ranges. */

		"vf2iz.t  C020, C020, 0\n"			/* Convert R/G/B to integers. */
		"vi2f.t   C020, C020, 0\n"			/* Convert back to float for vdot. */
        "lv.q     C030, 0(%5)\n"				/* Load the RGB565 packing coefficients: C021 = [2048, 32, 1, 0] */
        "vdot.t   S020, C020, C030\n"		/* Packed RGB565 value:  R * 2048 + G * 32 + B */
		"vf2iz.s  S020, S020, 0\n"			/* Convert packed float to integer. */
		"mfv      %0, S020\n"				/* Transfer result to CPU */

		: "=r"(result) : "r"(minS), "r"(minL), "r"(maxS), "r"(maxL), "r"(rgb565_pack)
	);

	return (unsigned short)result;
}
