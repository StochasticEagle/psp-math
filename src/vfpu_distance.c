#include "pspmath.h"

void vfpu_Vec2Distance_U(const ScePspFVector2 *va, const ScePspFVector2 *vb, ScePspFVector2 *vout)
{
    __asm__ volatile (
        // Load vector components into pair registers
        "lv.s      S000, 0(%1)\n"        // va.x
        "lv.s      S001, 4(%1)\n"        // va.y
        "lv.s      S010, 0(%2)\n"        // vb.x
        "lv.s      S011, 4(%2)\n"        // vb.y

        // Vector pair subtract: diff = va - vb
        "vsub.p    C020, C000, C010\n"

        // Store result components safely to avoid 16-byte quad buffer overflow
        "sv.s      S020, 0(%0)\n"        // vout->x
        "sv.s      S021, 4(%0)\n"        // vout->y
        : : "r"(vout), "r"(va), "r"(vb) : "memory"
    );
}


void vfpu_Vec3Distance_U(const ScePspFVector3 *va, const ScePspFVector3 *vb, ScePspFVector3 *vout)
{
    __asm__ volatile (
        // Load va components
        "lv.s      S000, 0(%1)\n"        // va.x
        "lv.s      S001, 4(%1)\n"        // va.y
        "lv.s      S002, 8(%1)\n"        // va.z

        // Load vb components
        "lv.s      S010, 0(%2)\n"        // vb.x
        "lv.s      S011, 4(%2)\n"        // vb.y
        "lv.s      S012, 8(%2)\n"        // vb.z

        // Vector triplet subtract: out_xyz = va_xyz - vb_xyz
        "vsub.t    C020, C000, C010\n"

        // Store results back to out pointer
        "sv.s      S020, 0(%0)\n"        // out.x
        "sv.s      S021, 4(%0)\n"        // out.y
        "sv.s      S022, 8(%0)\n"        // out.z
        : : "r"(vout), "r"(va), "r"(vb) : "memory"
    );
}


void vfpu_Vec4Distance_U(const ScePspFVector4Unaligned *va, const ScePspFVector4Unaligned *vb, ScePspFVector4Unaligned *vout)
{
    __asm__ volatile (
        // Safely load unaligned va components into a full quad register
        "lv.s      S000,  0(%1)\n"
        "lv.s      S001,  4(%1)\n"
        "lv.s      S002,  8(%1)\n"
        "lv.s      S003, 12(%1)\n"

        // Safely load unaligned vb components into a full quad register
        "lv.s      S010,  0(%2)\n"
        "lv.s      S011,  4(%2)\n"
        "lv.s      S012,  8(%2)\n"
        "lv.s      S013, 12(%2)\n"

        // Vector quad subtract: out_xyzw = va_xyzw - vb_xyzw
        "vsub.q    C020, C000, C010\n"

        // Safely store result components back to unaligned output struct
        "sv.s      S020,  0(%0)\n"
        "sv.s      S021,  4(%0)\n"
        "sv.s      S022,  8(%0)\n"
        "sv.s      S023, 12(%0)\n"
        : : "r"(vout), "r"(va), "r"(vb) : "memory"
    );
}


void vfpu_Vec4Distance_A(const ScePspFVector4 *va, const ScePspFVector4 *vb, ScePspFVector4 *vout)
{
    __asm__ volatile (
        // Load aligned 16-byte quads directly into VFPU matrix/vector columns
        "lv.q      C000, 0(%1)\n"        // Load va
        "lv.q      C010, 0(%2)\n"        // Load vb

        // Single quad vector subtraction (x, y, z, w concurrently)
        "vsub.q    C020, C000, C010\n"

        // Store aligned result directly back to memory
        "sv.q      C020, 0(%0)\n"        // Store vout
        : : "r"(vout), "r"(va), "r"(vb) : "memory"
    );
}
