#include "pspmath.h"

void vfpu_QuatCopy(ScePspQuatMatrix *src, ScePspQuatMatrix *dst) {
	__asm__ volatile (
		"lv.q C000, %1\n"
		"sv.q C000, %0\n"
		:"+m"(*dst) : "m"(*src));
}
