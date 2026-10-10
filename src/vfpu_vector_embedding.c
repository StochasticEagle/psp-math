#include "pspmath.h"

void vfpu_Vec3SetPosition(const ScePspFVector3 *src, ScePspFVector4 *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = 1.0f;
}

void vfpu_Vec3SetDirection(const ScePspFVector3 *src, ScePspFVector4 *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = 0.0f;
}
