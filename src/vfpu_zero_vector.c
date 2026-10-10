#include "pspmath.h"


void vfpu_Vec2Zero(ScePspFVector2 *v)
{
    __asm__ volatile (
        "vzero.t C000\n"
        "sv.p    C000, %0\n"
        : "+m"(*v));
}



void vfpu_Vec3Zero(ScePspFVector3 *v)
{
    __asm__ volatile (
        "vzero.t C000\n"
        "sv.t    C000, %0\n"
        : "+m"(*v));
}


void vfpu_Vec2pZero(ScePspFVector4 *v)
void vfpu_Vec4Zero(ScePspFVector4 *v)
{
   __asm__ volatile (
       "vzero.t C000\n"
       "sv.q    C000, %0\n"
       : "+m"(*v));
}
