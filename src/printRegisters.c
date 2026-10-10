#include <stdio.h>
#include "pspmath.h"

void printVFPURegisters(const int blockid)
{
	float m[16] PSPMATH_ALIGN;

	#define SV(N)                             \
	asm volatile (                            \
		"sv.q R"#N"00,  0 + %0\n"             \
		"sv.q R"#N"01, 16 + %0\n"             \
		"sv.q R"#N"02, 32 + %0\n"             \
		"sv.q R"#N"03, 48 + %0\n"             \
	: "=m"(m))

	switch (blockid)
	{
		case 0: SV(0); break;
		case 1: SV(1); break;
		case 2: SV(2); break;
		case 3: SV(3); break;
		case 4: SV(4); break;
		case 5: SV(5); break;
		case 6: SV(6); break;
		case 7: SV(7); break;
		default: return;
	}

	#undef SV

	printf("\nVFPU Block %d\n", blockid);
	printf("                 Col 0                 Col 1                 Col 2                 Col 3\n");

	for (int row = 0; row < 4; row++)
	{
		printf("Row %d  ", row);

		for (int col = 0; col < 4; col++)
		{
			printf(" S%d%d%d:%12.6f", blockid, col, row, m[row * 4 + col]);
		}

		printf("\n");
	}
}
