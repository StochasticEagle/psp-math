#include "pspmath.h"


void vfpu_Vec2Zero_U(ScePspFVector2 *v)
{
    __asm__ volatile (
        "vzero.p C000\n"
        "sv.s    S000, 0(%0)\n"
        "sv.s    S001, 4(%0)\n"
        : : "r"(v) : "memory");
}

void vfpu_Vec3Zero_U(ScePspFVector3 *v)
{
    __asm__ volatile (
        "vzero.t C000\n"
        "sv.s    S000, 0(%0)\n"
        "sv.s    S001, 4(%0)\n"
        "sv.s    S002, 8(%0)\n"
        : : "r"(v) : "memory");
}

void vfpu_Vec2pZero(ScePspFVector4 *v) __attribute__((alias("vfpu_Vec4Zero")));

void vfpu_Vec4Zero(ScePspFVector4 *v)
{
   __asm__ volatile (
       "vzero.t C000\n"
       "sv.q    C000, %0\n"
       : "+m"(*v));
}
