#include <stdio.h>
#include "pspmath.h"


void vfpu_PrintMatrix(const int matId)
{
	float m[16] PSPMATH_ALIGN;

	#define SV(N)									\
	asm volatile   ("usv.q	R"#N"00,  0 + %0\n"	\
	"usv.q	R"#N"01, 16 + %0\n"	\
	"usv.q	R"#N"02, 32 + %0\n"	\
	"usv.q	R"#N"03, 48 + %0\n"	\
	: "=m"(m))

	switch (matId) {
		case 0:		SV(0); break;
		case 1:		SV(1); break;
		case 2:		SV(2); break;
		case 3:		SV(3); break;
		case 4:		SV(4); break;
		case 5:		SV(5); break;
		case 6:		SV(6); break;
		case 7:		SV(7); break;
		default:
			return;
	}

	printf("\n\n");
	printf("      C%d00    C%d10    C%d20    C%d30\n", matId, matId, matId, matId);
	printf("R%d00: %0.6f %0.6f %0.6f %0.6f\n", matId, m[0], m[1], m[2], m[3]);
	printf("R%d01: %0.6f %0.6f %0.6f %0.6f\n", matId, m[4], m[5], m[6], m[7]);
	printf("R%d02: %0.6f %0.6f %0.6f %0.6f\n", matId, m[8], m[9], m[10], m[11]);
	printf("R%d03: %0.6f %0.6f %0.6f %0.6f\n", matId, m[12], m[13], m[14], m[15]);

	#undef SV
}


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


void vfpu_PrintRegisters(const int blockid)
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
