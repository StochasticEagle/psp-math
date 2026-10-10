#include "pspmath.h"

void vfpu_Vec3SetPosition(ScePspFVector4 *dst, const ScePspFVector3 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = 1.0f;
}

void vfpu_Vec3SetDirection(ScePspFVector4 *dst, const ScePspFVector3 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = 0.0f;
}
