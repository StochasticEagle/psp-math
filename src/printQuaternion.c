#include <stdio.h>
#include "pspmath.h"

void vfpu_PrintQuaternion(const int quatId)
{
	float q[4] PSPMATH_ALIGN;

	#define SV(N) \
	asm volatile ( \
	"usv.q C"#N"00, 0 + %0\n" \
	: "=m"(q))

	switch (quatId) {
		case 0: SV(0); break;
		case 1: SV(1); break;
		case 2: SV(2); break;
		case 3: SV(3); break;
		case 4: SV(4); break;
		case 5: SV(5); break;
		case 6: SV(6); break;
		case 7: SV(7); break;
		default:
			return;
	}

	printf("R%d0: %0.6f %0.6fi %0.6fj %0.6fk\n", quatId, q[0], q[1], q[2], q[3]);

	#undef SV
}

