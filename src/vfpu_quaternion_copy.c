#include "pspmath.h"

void vfpu_QuatCopy(ScePspQuatMatrix *dst, ScePspQuatMatrix *src) {
	__asm__ volatile (
		"lv.q C000, %1\n"
		"sv.q C000, %0\n"
		:"+m"(*dst) : "m"(*src));
}
