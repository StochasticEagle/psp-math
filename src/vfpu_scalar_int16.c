#include <stdint.h>
#include <limits.h>
#include "pspmath.h"

// Signed Q14 adapters for existing VFPU scalar operations.
// Q14 has the representable range [-2.0, 1.99993896484375].
static int16_t vfpu_q14_from_float(float x)
{
    if (x != x) return 0;
    if (x >= 32767.0f / 16384.0f) return INT16_MAX;
    if (x <= -2.0f) return INT16_MIN;
    float y = x * 16384.0f;
    return (int16_t)(y >= 0.0f ? (int32_t)(y + 0.5f) : (int32_t)(y - 0.5f));
}
static float vfpu_q14_to_float(int16_t x) { return (float)x * (1.0f / 16384.0f); }

int16_t vfpu_sinf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_sinf(vfpu_q14_to_float(x))); }
int16_t vfpu_cosf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_cosf(vfpu_q14_to_float(x))); }
int16_t vfpu_tanf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_tanf(vfpu_q14_to_float(x))); }
int16_t vfpu_asinf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_asinf(vfpu_q14_to_float(x))); }
int16_t vfpu_acosf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_acosf(vfpu_q14_to_float(x))); }
int16_t vfpu_atanf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_atanf(vfpu_q14_to_float(x))); }
int16_t vfpu_sinhf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_sinhf(vfpu_q14_to_float(x))); }
int16_t vfpu_coshf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_coshf(vfpu_q14_to_float(x))); }
int16_t vfpu_tanhf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_tanhf(vfpu_q14_to_float(x))); }
int16_t vfpu_expf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_expf(vfpu_q14_to_float(x))); }
int16_t vfpu_logf_int16(int16_t x) { return vfpu_q14_from_float(vfpu_logf(vfpu_q14_to_float(x))); }
int16_t vfpu_EaseInOut_int16(int16_t x) { return vfpu_q14_from_float(vfpu_EaseInOut(vfpu_q14_to_float(x))); }
int16_t vfpu_AbsoluteValue_int16(int16_t x) { return vfpu_q14_from_float(vfpu_AbsoluteValue(vfpu_q14_to_float(x))); }
int16_t vfpu_SquareRoot_int16(int16_t x) { return vfpu_q14_from_float(vfpu_SquareRoot(vfpu_q14_to_float(x))); }
int16_t vfpu_atan2f_int16(int16_t x, int16_t y) { return vfpu_q14_from_float(vfpu_atan2f(vfpu_q14_to_float(x), vfpu_q14_to_float(y))); }
int16_t vfpu_powf_int16(int16_t x, int16_t y) { return vfpu_q14_from_float(vfpu_powf(vfpu_q14_to_float(x), vfpu_q14_to_float(y))); }
int16_t vfpu_fmodf_int16(int16_t x, int16_t y) { return vfpu_q14_from_float(vfpu_fmodf(vfpu_q14_to_float(x), vfpu_q14_to_float(y))); }
void vfpu_sincos_int16(int16_t radians, int16_t *s, int16_t *c)
{
    float sf, cf;
    vfpu_sincos(vfpu_q14_to_float(radians), &sf, &cf);
    if (s) *s = vfpu_q14_from_float(sf);
    if (c) *c = vfpu_q14_from_float(cf);
}
int16_t vfpu_random_int16(void) { return vfpu_q14_from_float(vfpu_Random()); }
int16_t vfpu_sinf_scaled_int16(int16_t radians, int16_t scale) { return vfpu_q14_from_float(vfpu_sinf_scaled(vfpu_q14_to_float(radians), vfpu_q14_to_float(scale))); }
int16_t vfpu_cosf_scaled_int16(int16_t radians, int16_t scale) { return vfpu_q14_from_float(vfpu_cosf_scaled(vfpu_q14_to_float(radians), vfpu_q14_to_float(scale))); }
int16_t vfpu_sind_scaled_int16(int degrees, int16_t scale) { return vfpu_q14_from_float(vfpu_sind_scaled((float)degrees, vfpu_q14_to_float(scale))); }
int16_t vfpu_cosd_scaled_int16(int degrees, int16_t scale) { return vfpu_q14_from_float(vfpu_cosd_scaled((float)degrees, vfpu_q14_to_float(scale))); }
int16_t vfpu_tand_scaled_int16(int degrees, int16_t scale) { return vfpu_q14_from_float(vfpu_tand_scaled((float)degrees, vfpu_q14_to_float(scale))); }
