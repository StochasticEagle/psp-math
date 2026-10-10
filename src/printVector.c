#include <stdio.h>
#include "pspmath.h"

void vfpu_PrintVector(const int vecId, const int vecSize)
{
	float v[4] PSPMATH_ALIGN;

	if (vecSize < 2 || vecSize > 4)
		return;

	#define SV(N) \
	asm volatile ( \
	"usv.q R"#N"00, 0(%0)\n" \
	: \
	: "r"(v) \
	: "memory")

	switch (vecId) {
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

	switch (vecSize) {
		case 2:
			printf("R%d0: %0.6f %0.6f\n", vecId, v[0], v[1]);
			break;
		case 3:
			printf("R%d0: %0.6f %0.6f %0.6f\n", vecId, v[0], v[1], v[2]);
			break;
		case 4:
			printf("R%d0: %0.6f %0.6f %0.6f %0.6f\n", vecId, v[0], v[1], v[2], v[3]);
			break;
		default:
			break;
	}

	#undef SV
}


