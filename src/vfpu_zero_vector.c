#include "pspmath.h"

void vfpu_Vec4Zero(ScePspFVector4 *v) {
   __asm__ volatile (
       "vzero.t C000\n"
       "sv.q    C000, %0\n"
       : "+m"(*v));
}
