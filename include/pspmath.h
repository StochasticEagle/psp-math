/**
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * Copyright (c) 2007 Steve Galatis
 * Copyright (c) 2007 Christophe Avoinme
 *
 * General purpose math library using vfpu optimized instructions.
 * Most of the routines here run at least 5 to 20 times faster than the equivalent
 * routines in libm
 *
 **/

#ifndef _pspmath_h_
#define _pspmath_h_

#include <psptypes.h>

/** @defgroup VFPUMATH VFPU Math Library
  *
**/

#if defined(__cplusplus)
extern "C" {
#endif

/**
  * Aligns data to a 16-byte boundary
**/
#define PSPMATH_ALIGN __attribute__((aligned(16)))

typedef struct quat {
	float a, b, c, d;
} PSPMATH_ALIGN ScePspQuatMatrix;

/* @addtogroup VFPUMATH **/
/**@{**/

/**
  * Print a formatted block of 16 vfpu registers
  *
  * @param blockid - register block id (0 to 7)
  *
**/
void vfpu_PrintRegisters(int blockid);

/**
 * Print a formatted block of 16 vfpu registers
 *
 * @param matId - matrix id (0 to 7)
 *
 **/
void vfpu_PrintMatrix(int matId);

/**
 * Print a formatted block of 16 vfpu registers
 *
 * @param vecId - vector id (0 to 7)
 * @param vecSize - vector dimension (2 to 4)
 *
 **/
void vfpu_PrintVector(int vecId, int vecSize);

/**
 * Print a formatted quaternion
 *
 * @param quatId - quaternion id (0 to 7)
 *
 **/
void vfpu_PrintQuaternion(int quatId);


/**
  * Set vfpu random generator seed
  *
  * @param x - seed value
  *
**/
void vfpu_srand(unsigned int x);

/**
  * Return random float value
  *
  * @param min - minimum value to return
  * @param max - maximum value to return
  *
**/
float vfpu_randf(float min, float max);

/**
  * Return random color value in 8888 format
  * This always sets the alpha channel value to 0xFF
  *
  * @param min - minimum value for each color channel (0..255)
  * @param max - maximum value for each color channel (0..255)
  *
**/
unsigned int vfpu_rand_8888(int min, int max);

/**
 * Return random color value in 565 16-bit color format
 * The 5-bit channels use minS/maxS
 * The 6-bit channel uses minL/maxL
 *
 * @param minS Minimum value for the 5-bit channels (0..31).
 * @param minL Minimum value for the 6-bit channel (0..63).
 * @param maxS Maximum value for the 5-bit channels (0..31).
 * @param maxL Maximum value for the 6-bit channel (0..63).
 *
 **/
unsigned short vfpu_rand_565(int minS, int minL, int maxS, int maxL);

/**
  * Generate a translation matrix
  *
  * @param m - pointer to matrix
  * @param x - translation on x axis
  * @param y - translation on y axis
  * @param z - translation on z axis
  *
**/
void vfpu_Mat4Translate(ScePspFMatrix4 *m, float x, float y, float z);

/**
  * Generate a perspective projection matrix
  *
  * @param m      - pointer to matrix
  * @param fovy   - vertical field of view
  * @param aspect - aspect ratio of viewport
  * @param near   - near clipping plane
  * @param far    - far clipping plane
  *
**/
void vfpu_Mat4Perspective(ScePspFMatrix4 *m, float fovy, float aspect, float near, float far);

/**
  * Generate an orthogonal  projection matrix
  *
  * @param m      - pointer to matrix
  * @param left   - coordinate for left edge of viewport
  * @param right  - coordinate for right edge of viewport
  * @param bottom - coordinate for bottom edge of viewport
  * @param top    - coordinate for top edge of viewport
  * @param near   - near clipping plane
  * @param far    - far clipping plane
  *
**/
void vfpu_Mat4Orthographic(ScePspFMatrix4 *m, float left, float right, float bottom, float top, float near, float far);

/**
  * Calculate sine
  *
  * @param x - input in radians
  *
**/
float vfpu_sinf(float x);

/**
  * Calculate cosine
  *
  * @param x - input in radians
  *
**/
float vfpu_cosf(float x);

/**
  * Calculate tangent
  *
  * @param x - input in radians
  *
**/
float vfpu_tanf(float x);

/**
  * Calculate inverse sine (arcsin)
  *
  * @param x - input
  *
**/
float vfpu_asinf(float x);

/**
  * Calculate inverse cosine (arccos)
  *
  * @param x - input
  *
**/
float vfpu_acosf(float x);

/**
  * Calculate inverse tangent (arctan)
  *
  * @param x - input
  *
**/
float vfpu_atanf(float x);

/**
  * Calculate inverse tangent, with proper quadrant fixup
  *
  * @param x - input
  *
**/
float vfpu_atan2f(float x, float y);

/**
  * Calculate hyperbolic sine
  *
  * @param x - input
  *
**/
float vfpu_sinhf(float x);

/**
  * Calculate hyperbolic cosine
  *
  * @param x - input
  *
**/
float vfpu_coshf(float x);

/**
  * Calculate hyperbolic tangent
  *
  * @param x - input
  *
**/
float vfpu_tanhf(float x);

/**
  * Calculate sine and cosine
  *
  * @param r - input in radians
  * @param s - pointer to float for sin
  * @param c - pointer to float for cos
**/
void vfpu_sincos(float r, float *s, float *c);

/**
  * Calculate exponent of x
  *
  * @param x - input
  *
**/
float vfpu_expf(float x);

/**
  * Calculate logarithm of x
  *
  * @param x - input
  *
**/
float vfpu_logf(float x);

/**
  * Calculate x raised to the power of y
  *
  * @param x - number to raise power of
  * @param y - power to raise x by
  *
**/
float vfpu_powf(float x, float y);

/**
  * Calculate floating point remainder of x/y
  *
  * @param x - input
  * @param y - input
  *
**/
float vfpu_fmodf(float x, float y);

/**
  * Perform a smooth acceleration/deceleration curve based on the input time value
  * returns 0 to 1
  *
  * @param t - input (0 to 1 float)
  *
**/
float vfpu_EaseInOut(float t);

/**
  * Zero a 2d vector
  *
  * @param v - pointer to vector
  *
**/
void vfpu_Vec2Zero(ScePspFVector2 *v);

/**
  * Zero a 3d vector
  *
  * @param v - pointer to vector
  *
**/
void vfpu_Vec3Zero(ScePspFVector3 *v);

/**
  * Zero a 4d vector
  *
  * @param v - pointer to vector
  *
**/
void vfpu_Vec4Zero(ScePspFVector4 *v);

/**
  * Generate rotation matrix for environment map.
  *
  * @param envmat - pointer to array of 2 vectors to store envmap matrix
  * @param r      - angle to rotate in radians
**/
void vfpu_Vec4EnvironmentMap(ScePspFVector4 *envmat, float r);

/**
  * Transform 3d vector by 4x4 matrix
  *
  * @param m    - pointer to transformation matrix
  * @param vin  - pointer to vector to transform
  * @param vout - pointer to result vector
**/
void vfpu_Mat4TransformVec4(ScePspFMatrix4 *m, ScePspFVector4 *vin, ScePspFVector4 *vout);

/**
  * Convert input sphere coordinates to cartesian coordinates
  *
  * @param az  - azimuth angle (0 to PI*2)
  * @param ze  - zenith angle (0 to PI)
  * @param rad - sphere radius
  * @param x   - pointer to float for x coordinate
  * @param y   - pointer to float for y coordinate
  * @param z   - pointer to float for z coordinate
  *
**/
void vfpu_Vec3FromSpherical(float az, float ze, float rad, float *x, float *y, float *z);

/**
 * @brief Initialize a quaternion to the identity using unaligned access.
 *
 * Writes the quaternion components (0, 0, 0, 1).
 * The destination requires only normal float alignment.
 *
 * @param q Output quaternion (four floats).
 */
void vfpu_QuatIdentity_U(float *q);

/**
  * Generate an identity quaternion
  *
  * @param q - pointer to quaternion
  *
  * this will set the quaternion's components to 0,0,0,1
  *
**/
void vfpu_QuatIdentity(ScePspQuatMatrix *q);

/**
  * Copy a quaternion
  *
  * @param dst - pointer to quaternion to copy to
  * @param src - pointer to quaternion to copy from
  *
**/
void vfpu_QuatCopy(ScePspQuatMatrix *dst, ScePspQuatMatrix *src);

/**
  * Multiply 2 quaternions
  *
  * @param qout - pointer to result quaternion
  * @param a    - pointer to first quaternion to multiply
  * @param b    - pointer to second quaternion to multiply
  *
**/
void vfpu_QuatMultiplyOutFirst(ScePspQuatMatrix *qout, ScePspQuatMatrix *a, ScePspQuatMatrix *b);

/**
  * Make a quaternion from euler angles
  *
  * @param qout - pointer to output quaternion
  * @param rx   - rotation on x axis, in degrees
  * @param ry   - rotation on y axis, in degrees
  * @param rz   - rotation on z axis, in degrees
**/
void vfpu_QuatFromEuler(ScePspQuatMatrix *qout, float rx, float ry, float rz);

/**
  * Calculate exponent of a quaternion
  *
  * @param qout - pointer to output quaternion
  * @param qin  - pointer to input quaternion
  *
**/
void vfpu_QuatExp(ScePspQuatMatrix *qout, ScePspQuatMatrix *qin);

/**
  * Calculate logarithm of a quaternion
  *
  * @param qout - pointer to output quaternion
  * @param qin  - pointer to input quaternion
  *
**/
void vfpu_QuatLn(ScePspQuatMatrix *qout, ScePspQuatMatrix *qin);

/**
  * Return a sample from a linear interpolation of 2 quaternions
  *
  * @param qout - pointer to output quaternion
  * @param a    - pointer to starting quaternion
  * @param b    - pointer to ending quaternion
  * @param t    - time value to sample, from 0 to 1
  *
**/
void vfpu_QuatSampleLinear(ScePspQuatMatrix *qout, ScePspQuatMatrix *a, ScePspQuatMatrix *b, float t);

/**
  * Return a sample from a hermite spline interpolation
  *
  * @param qout - pointer to output quaternion
  * @param a    - pointer to start quaternion
  * @param b    - pointer to end quaternion
  * @param at   - pointer to tangent point for quaternion a
  * @param bt   - pointer to tangent point for quaternion b
  * @param t    - time value to sample, from 0 to 1
  *
**/
void vfpu_QuatSampleHermite(ScePspQuatMatrix *qout, ScePspQuatMatrix *a, ScePspQuatMatrix *b, ScePspQuatMatrix *at, ScePspQuatMatrix *bt, float t);

/**
  * Return a tangent point for hermite spline interpolation
  *
  * @param qout - pointer to output quaternion
  * @param p1   - pointer to p-1 on spline curve for tangent
  * @param p2   - pointer to p+1 on spline curve for tangent
  * @param bias - value to scale difference between endpoints.
  *              for example, 0.5 results in a catmull-rom spline tangent
  *
**/

void vfpu_QuatHermiteTangent(ScePspQuatMatrix *qout, ScePspQuatMatrix *p1, ScePspQuatMatrix *p2, float bias);

/**
  * Convert quaternion to rotation matrix
  *
  * @param q - pointer to input quaternion
  * @param m - pointer to output matrix
  *
**/
void vfpu_QuatToMat4(ScePspQuatMatrix *q, ScePspFMatrix4 *m);




















/************ Imported from pspla library ************/


/**
  *  Copy a matrix - Unaligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat2Copy_U(float *m1, float *mout);

/**
  *  Copy a matrix - Unaligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat3Copy_U(float *m1, float *mout);

/**
  *  Copy a matrix - Unaligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat4Copy_U(float *m1, float *mout);

/**
  *  Copy a matrix - Aligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat2Copy(float *m1, float *mout);

/**
  *  Copy a matrix - Aligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat3Copy(float *m1, float *mout);

/**
  *  Copy a matrix - Aligned
  *  @param m1 source matrix
  *  @param mout destination matrix
**/
void vfpu_Mat4Copy(float *m1, float *mout);

/**
  *  Copy a vector - Unaligned
  *  @param v1 source vector
  *  @param vout destination vector
**/
void vfpu_Vec2Copy_U(float *v1, float *vout);

/**
  *  Copy two vector - Aaligned
  *  @param v1 source vector
  *  @param vout destination vector
**/
void vfpu_Vec2pCopy(float *v1, float *vout);

/**
  *  Copy a vector - Unaligned
  *  @param v1 source vector
  *  @param vout destination vector
**/
void vfpu_Vec3Copy_U(float *v1, float *vout);

/**
  *  Copy a vector - Unaligned
  *  @param v1 source vector
  *  @param vout destination vector
**/
void vfpu_Vec4Copy_U(float *v1, float *vout);

/**
  *  Copy a vector - Aligned
  *  @param v1 source vector
  *  @param vout destination vector
**/
void vfpu_Vec4Copy(float *v1, float *vout);

/**
  *  Add two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2Add_U(float *v1, float *v2, float *vout);

/**
  *  Add two pairs of two packed vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2pAdd(float *v1, float *v2, float *vout);

/**
  *  Add two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec3Add_U(float *v1, float *v2, float *vout);

/**
  *  Add two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Add_U(float *v1, float *v2, float *vout);

/**
 *  Add two vectors - Unaligned
 *  @param v1 first vector
 *  @param v2 second vector
 *  @param vout result vector
 **/
void vfpu_Vec4Add(float *v1, float *v2, float *vout);


/**
  *  Subtract two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2Subtract_U(float *v1, float *v2, float *vout);

/**
  *  Subtract two pairs of packed vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2pSubtract(float *v1, float *v2, float *vout);

/**
  *  Subtract two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec3Subtract_U(float *v1, float *v2, float *vout);

/**
  *  Subtract two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Subtract_U(float *v1, float *v2, float *vout);

/**
  *  Subtract two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Subtract(float *v1, float *v2, float *vout);

/**
  *  Multiply two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2Multiply_U(float *v1, float *v2, float *vout);

/**
  *  Multiply two pairs of packed vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2pMultiply(float *v1, float *v2, float *vout);

/**
  *  Multiply two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec3Multiply_U(float *v1, float *v2, float *vout);

/**
  *  Multiply two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Multiply_U(float *v1, float *v2, float *vout);

/**
  *  Multiply two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Multiply(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2Divide_U(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec3Divide_U(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Divide_U(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2Divide(float *v1, float *v2, float *vout);

/**
  *  Divide two pairss of packed vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec2pDivide(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec3Divide(float *v1, float *v2, float *vout);

/**
  *  Divide two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout result vector
**/
void vfpu_Vec4Divide(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise minimum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec2Minimum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a pair packed of vectors from the the element-wise minimum of two pairs of packed vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec2pMinimum(float *v1, float *v2, float *vout);


/**
  *  Construct a vector from the the element-wise minimum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec3Minimum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise minimum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Minimum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise minimum of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Minimum(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise maximum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec2Maximum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise maximum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec3Maximum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise maximum of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Maximum_U(float *v1, float *v2, float *vout);

/**
  *  Construct a vector from the the element-wise maximum of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Maximum(float *v1, float *v2, float *vout);

/**
  *  Get the average of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec2Average_U(float *v1);

/**
  *  Get the average of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec3Average_U(float *v1);

/**
  *  Get the average of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec4Average_U(float *v1);

/**
  *  Get the average of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec2Average(float *v1);

/**
  *  Get the average of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec2pAverage(float *v1);

/**
  *  Get the average of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec3Average(float *v1);

/**
  *  Get the average of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The average of each element
**/
float vfpu_Vec4Average(float *v1);

/**
  *  Get the sum of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec2Sum_U(float *v1);

/**
  *  Get the sum of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec3Sum_U(float *v1);

/**
  *  Get the sum of the elements in a vector - Unaligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec4Sum_U(float *v1);

/**
  *  Get the sum of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec2Sum(float *v1);

/**
  *  Get the sum of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec2pSum(float *v1);

/**
  *  Get the sum of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec3Sum(float *v1);

/**
  *  Get the sum of the elements in a vector - Aligned
  *  @param v1 input vector
  *  @return The sum of the elements
**/
float vfpu_Vec4Sum(float *v1);

/**
  *  Get the absolute value of a scalar
  *  @param s1 input scalar
  *  @return The absolute value
**/
float vfpu_AbsoluteValue(float s1);

/**
  *  Get the absolute value of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2AbsoluteValue_U(float *v1, float *vout);

/**
  *  Get the absolute value of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2pAbsoluteValue(float *v1, float *vout);

/**
  *  Get the absolute value of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3AbsoluteValue_U(float *v1, float *vout);

/**
  *  Get the absolute value of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4AbsoluteValue_U(float *v1, float *vout);

/**
 * @brief Compute the component-wise absolute value of a Vec4.
 *
 * Both input and output must be 16-byte aligned.
 *
 * @param v1 Input vector (four floats).
 * @param vout Output vector containing the absolute values.
 */
void vfpu_Vec4AbsoluteValue(float *v1, float *vout);


/**
  *  Get the cross product of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout cross product
**/
void vfpu_Vec3CrossProduct_U(float *v1, float *v2, float *vout);

/**
  *  Get the cross product of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout cross product
**/
void vfpu_Vec3CrossProduct(float *v1, float *v2, float *vout);

/**
  *  Scale a vector by a scalar value - Unaligned
  *  @param v1 input vector
  *  @param s1 scale value
  *  @param vout output vector
**/
void vfpu_Vec2Scale_U(float *v1, float s1, float *vout);

/**
  *  Scale a vector by a scalar value - Unaligned
  *  @param v1 input vector
  *  @param s1 scale value
  *  @param vout output vector
**/
void vfpu_Vec2pScale_U(float *v1, float s1, float *vout);

/**
  *  Scale a vector by a scalar value - Unaligned
  *  @param v1 input vector
  *  @param s1 scale value
  *  @param vout output vector
**/
void vfpu_Vec3Scale_U(float *v1, float s1, float *vout);

/**
  *  Scale a vector by a scalar value - Unaligned
  *  @param v1 input vector
  *  @param s1 scale value
  *  @param vout output vector
**/
void vfpu_Vec4Scale_U(float *v1, float s1, float *vout);

/**
 *  Scale a vector by a scalar value - Unaligned
 *  @param v1 input vector
 *  @param s1 scale value
 *  @param vout output vector
 **/
void vfpu_Vec4Scale(float *v1, float s1, float *vout);


/**
  *  Get the dot product of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec2DotProduct_U(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec3DotProduct_U(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec4DotProduct_U(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec2DotProduct(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec2pDotProduct(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec3DotProduct(float *v1, float *v2);

/**
  *  Get the dot product of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return The dot product
**/
float vfpu_Vec4DotProduct(float *v1, float *v2);

/**
  *  Find the square root of a scalar
  *  @param s1 input scalar
  *  @return The square root
**/
float vfpu_SquareRoot(float s1);

/**
  *  Find the square roots of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2SquareRoot_U(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3SquareRoot_U(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4SquareRoot_U(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2SquareRoot(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2pSquareRoot(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3SquareRoot(float *v1, float *vout);

/**
  *  Find the square roots of each element in a vector - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4SquareRoot(float *v1, float *vout);


/**
  *  Get the magnitude of a vector - Unaligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec2Magnitude_U(float *v1);

/**
  *  Get the magnitude of a vector - Unaligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec3Magnitude_U(float *v1);

/**
  *  Get the magnitude of a vector - Unaligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec4Magnitude_U(float *v1);

/**
  *  Get the magnitude of a vector - Aligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec2Magnitude(float *v1);

/**
  *  Get the magnitude of a vector - Aligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec2pMagnitude(float *v1);

/**
  *  Get the magnitude of a vector - Aligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec3Magnitude(float *v1);

/**
  *  Get the magnitude of a vector - Aligned
  *  @param v1 input vector
  *  @return The magnitude
**/
float vfpu_Vec4Magnitude(float *v1);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Unaligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec2Normalize_U(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Unaligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec3Normalize_U(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Unaligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec4Normalize_U(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Aligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec2Normalize(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Aligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec2pNormalize(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Aligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec3Normalize(float *v1, float *vout);

/**
  *  Get a vector of the same direction but with a magnitude of 1 - Aligned
  *  @param v1 input vector
  *  @param vout normalized vector
**/
void vfpu_Vec4Normalize(float *v1, float *vout);

/**
  *  Round each element in a vector to the nearest whole number - Unaligned
  *  @param v1 input vector
  *  @param vout rounded vector
**/
void vfpu_Vec2Round_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the nearest whole number - Unaligned
  *  @param v1 input vector
  *  @param vout rounded vector
**/
void vfpu_Vec2pRound_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the nearest whole number - Unaligned
  *  @param v1 input vector
  *  @param vout rounded vector
**/
void vfpu_Vec3Round_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the nearest whole number - Unaligned
  *  @param v1 input vector
  *  @param vout rounded vector
**/
void vfpu_Vec4Round_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the nearest whole number - Aligned
  *  @param v1 input vector
  *  @param vout rounded vector
**/
void vfpu_Vec4Round(float *v1, float *vout);

/**
  *  Round each element in a vector to zero - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec2Floor_U(float *v1, float *vout);

/**
  *  Round each element in a vector to zero - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec2pFloor_U(float *v1, float *vout);

/**
  *  Round each element in a vector to zero - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec3Floor_U(float *v1, float *vout);

/**
  *  Round each element in a vector to zero - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec4Floor_U(float *v1, float *vout);

/**
  *  Round each element in a vector to zero - Aligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec4Floor(float *v1, float *vout);

/**
  *  Round each element in a vector to the next whole number - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec2Ceiling_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the next whole number - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec2pCeiling_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the next whole number - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec3Ceiling_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the next whole number - Unaligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec4Ceiling_U(float *v1, float *vout);

/**
  *  Round each element in a vector to the next whole number - Aligned
  *  @param v1 input vector
  *  @param vout truncated vector
**/
void vfpu_Vec4Ceiling(float *v1, float *vout);

/**
  *  Get the sine of a value in π/2 radians
  *  @param s1 input value
  *  @return The sine value
**/
float vfpu_Sine(float s1);

/**
  *  Get the cosine of a value in π/2 radians
  *  @param s1 input value
  *  @return The cosine value
**/
float vfpu_Cosine(float s1);

/**
  *  Get the sine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2Sine_U(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3Sine_U(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4Sine_U(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2Sine(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2pSine(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3Sine(float *v1, float *vout);

/**
  *  Get the sine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4Sine(float *v1, float *vout);


/**
  *  Get the cosine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2Cosine_U(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3Cosine_U(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4Cosine_U(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2Cosine(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec2pCosine(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec3Cosine(float *v1, float *vout);

/**
  *  Get the cosine of each element in a vector in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Vec4Cosine(float *v1, float *vout);


/**
  *  Get the arcsine of a value
  *  @param s1 input value
  *  @return The arcsine value in π/2 radians
**/
float vfpu_Arcsine(float s1);

/**
  *  Get the arccosine of a value
  *  @param s1 input value
  *  @return The arccosine value in π/2 radians
**/
float vfpu_Arccosine(float s1);

/**
  *  Negate a vector - Unaligned
  *  @param v1 input vector
  *  @param vout negated vector
**/
void vfpu_Vec2Negate_U(float *v1, float *vout);

/**
  *  Negate a vector - Unaligned
  *  @param v1 input vector
  *  @param vout negated vector
**/
void vfpu_Vec2pNegate_U(float *v1, float *vout);

/**
  *  Negate a vector - Unaligned
  *  @param v1 input vector
  *  @param vout negated vector
**/
void vfpu_Vec3Negate_U(float *v1, float *vout);

/**
  *  Negate a vector - Unaligned
  *  @param v1 input vector
  *  @param vout negated vector
**/
void vfpu_Vec4Negate_U(float *v1, float *vout);

/**
  *  Negate a vector - Aligned
  *  @param v1 input vector
  *  @param vout negated vector
**/
void vfpu_Vec4Negate(float *v1, float *vout);

/**
  *  Get the element-wise '==' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2Equals_U(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3Equals_U(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4Equals_U(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2Equals(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2pEquals(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3Equals(float *v1, float *v2);

/**
  *  Get the element-wise '==' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4Equals(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2LessThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3LessThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4LessThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2LessThan(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2pLessThan(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3LessThan(float *v1, float *v2);

/**
  *  Get the element-wise '<' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4LessThan(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2LessThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3LessThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4LessThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2LessThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2pLessThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3LessThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '<=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4LessThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2GreaterThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3GreaterThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4GreaterThan_U(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2GreaterThan(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2pGreaterThan(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3GreaterThan(float *v1, float *v2);

/**
  *  Get the element-wise '>' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4GreaterThan(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2GreaterThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3GreaterThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4GreaterThanEqual_U(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2GreaterThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-1 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec2pGreaterThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-2 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec3GreaterThanEqual(float *v1, float *v2);

/**
  *  Get the element-wise '>=' comparison of two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @return A bitfield of results. Bits 0-3 are the result of each comparison. Bits 4 and 5 are '||' and '&&' operations on the comparison bits.
**/
int vfpu_Vec4GreaterThanEqual(float *v1, float *v2);

/**
  *  Get the element wise comparison of two vectors (-1.0 for lt, 0.0 for eq, 1.0 for gt) - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec2Compare_U(float *v1, float *v2, float *vout);

/**
  *  Get the element wise comparison of two vectors (-1.0 for lt, 0.0 for eq, 1.0 for gt) - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec2pCompare_U(float *v1, float *v2, float *vout);

/**
  *  Get the element wise comparison of two vectors (-1.0 for lt, 0.0 for eq, 1.0 for gt) - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec3Compare_U(float *v1, float *v2, float *vout);

/**
  *  Get the element wise comparison of two vectors (-1.0 for lt, 0.0 for eq, 1.0 for gt) - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Compare_U(float *v1, float *v2, float *vout);

/**
  *  Get the element wise comparison of two vectors (-1.0 for lt, 0.0 for eq, 1.0 for gt) - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param vout output vector
**/
void vfpu_Vec4Compare(float *v1, float *v2, float *vout);

/**
  *  Get a linear interpolation between two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param s1 weight
  *  @param vout interpolated vector
**/
void vfpu_Vec2Lerp_U(float *v1, float *v2, float s1, float *vout);

/**
  *  Get a linear interpolation between two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param s1 weight
  *  @param vout interpolated vector
**/
void vfpu_Vec2pLerp(float *v1, float *v2, float s1, float *vout);

/**
  *  Get a linear interpolation between two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param s1 weight
  *  @param vout interpolated vector
**/
void vfpu_Vec3Lerp_U(float *v1, float *v2, float s1, float *vout);

/**
  *  Get a linear interpolation between two vectors - Unaligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param s1 weight
  *  @param vout interpolated vector
**/
void vfpu_Vec4Lerp_U(float *v1, float *v2, float s1, float *vout);

/**
  *  Get a linear interpolation between two vectors - Aligned
  *  @param v1 first vector
  *  @param v2 second vector
  *  @param s1 weight
  *  @param vout interpolated vector
**/
void vfpu_Vec4Lerp(float *v1, float *v2, float s1, float *vout);

/**
  *  Clamp each element in a vector to a specified range - Unaligned
  *  @param v1 input vector
  *  @param s1 minimum
  *  @param s2 maximum
  *  @param vout clamped vector
**/
void vfpu_Vec2Clamp_U(float *v1, float s1, float s2, float *vout);

/**
  *  Clamp each element in a vector to a specified range - Unaligned
  *  @param v1 input vector
  *  @param s1 minimum
  *  @param s2 maximum
  *  @param vout clamped vector
**/
void vfpu_Vec2pClamp(float *v1, float s1, float s2, float *vout);

/**
  *  Clamp each element in a vector to a specified range - Unaligned
  *  @param v1 input vector
  *  @param s1 minimum
  *  @param s2 maximum
  *  @param vout clamped vector
**/
void vfpu_Vec3Clamp_U(float *v1, float s1, float s2, float *vout);

/**
  *  Clamp each element in a vector to a specified range - Unaligned
  *  @param v1 input vector
  *  @param s1 minimum
  *  @param s2 maximum
  *  @param vout clamped vector
**/
void vfpu_Vec4Clamp_U(float *v1, float s1, float s2, float *vout);

/**
  *  Clamp each element in a vector to a specified range - Aligned
  *  @param v1 input vector
  *  @param s1 minimum
  *  @param s2 maximum
  *  @param vout clamped vector
**/
void vfpu_Vec4Clamp(float *v1, float s1, float s2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Unaligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-1
  *  @param vout reordered vector
**/
void vfpu_Vec2Reorder_U(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Unaligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-2
  *  @param vout reordered vector
**/
void vfpu_Vec3Reorder_U(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Unaligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-3
  *  @param vout reordered vector
**/
void vfpu_Vec4Reorder_U(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Aligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-1
  *  @param vout reordered vector
**/
void vfpu_Vec2Reorder(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Aligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-1
  *  @param vout reordered vector
**/
void vfpu_Vec2pReorder(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Aligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-2
  *  @param vout reordered vector
**/
void vfpu_Vec3Reorder(float *v1, int *v2, float *vout);

/**
  *  Create a new vector by reordering elements of the input vector - Aligned
  *  @param v1 vector to reorder
  *  @param v2 vector of element indices 0-3
  *  @param vout reordered vector
**/
void vfpu_Vec4Reorder(float *v1, int *v2, float *vout);

/**
  *  Generate a random floating pointer number
  *  @return A random number (0 <= x < 1)
**/
float vfpu_Random();

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Unaligned
  *  @param vout output vector
**/
void vfpu_Vec2Random_U(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Unaligned
  *  @param vout output vector
**/
void vfpu_Vec3Random_U(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Unaligned
  *  @param vout output vector
**/
void vfpu_Vec4Random_U(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Aligned
  *  @param vout output vector
**/
void vfpu_Vec2Random(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Aligned
  *  @param vout output vector
**/
void vfpu_Vec2pRandom(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Aligned
  *  @param vout output vector
**/
void vfpu_Vec3Random(float *vout);

/**
  *  Generate a vector of random floating point numbers (0 <= x < 1) - Aligned
  *  @param vout output vector
**/
void vfpu_Vec4Random(float *vout);


/**
  *  Set the VFPU's RNG seed
  *  @param s1 seed
**/
void vfpu_RandomSeed(int s1);

/**
  *  Get the reflection of a vector off of a surface normal - Unaligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec2Reflect_U(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Unaligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec3Reflect_U(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Unaligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec4Reflect_U(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Aligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec2Reflect(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Aligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec2pReflect(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Aligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec3Reflect(float *v1, float *v2, float *vout);

/**
  *  Get the reflection of a vector off of a surface normal - Aligned
  *  @param v1 input vector
  *  @param v2 normalized surface normal
  *  @param vout reflected vector
**/
void vfpu_Vec4Reflect(float *v1, float *v2, float *vout);

/**
  *  Get a rotation matrix from a set of euler angles in π/2 radians - Unaligned
  *  @param v1 input vector
  *  @param mout rotation matrix
**/
void vfpu_Vec3RotationMatrix_U(float *v1, float *mout);

/**
  *  Get a rotation matrix from a set of euler angles in π/2 radians - Aligned
  *  @param v1 input vector
  *  @param mout rotation matrix
**/
void vfpu_Vec3RotationMatrix(float *v1, float *mout);

/**
  *  Get a rotation quaternion from a set of euler angles in π/2 radians - Unaligned
  *  @param v1 input vector [x,y,z]
  *  @param qout output quaternion [w,x,y,z]
**/
void vfpu_Vec3RotationQuaternion_U(float *v1, float *qout);

/**
  *  Get a rotation quaternion from a set of euler angles in π/2 radians - Aligned
  *  @param v1 input vector [x,y,z]
  *  @param qout output quaternion [w,x,y,z]
**/
void vfpu_Vec3RotationQuaternion(float *v1, float *qout);

/**
  *  Multiply two quaternions - Unaligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param qout output quaternion
**/
void vfpu_QuatMultiply_U(float *q1, float *q2, float *qout);

/**
  *  Multiply two quaternions - Aligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param qout output quaternion
**/
void vfpu_QuatMultiply(float *q1, float *q2, float *qout);

/**
  *  Get the conjugate of a quaternion - Unaligned
  *  @param q1 input quaternion
  *  @param qout output quaternion
**/
void vfpu_QuatConjugate_U(float *q1, float *qout);

/**
  *  Get the conjugate of a quaternion - Aligned
  *  @param q1 input quaternion
  *  @param qout output quaternion
**/
void vfpu_QuatConjugate(float *q1, float *qout);


/**
 * @brief Calculate the magnitude of an unaligned quaternion.
 *
 * @param q1 Input quaternion.
 * @return Quaternion magnitude.
 */
float vfpu_QuatMagnitude_U(const float *q1);

/**
 * @brief Calculate the magnitude of an aligned quaternion.
 *
 * @param q1 Input quaternion, 16-byte aligned.
 * @return Quaternion magnitude.
 */
float vfpu_QuatMagnitude(const float *q1);

/**
 * @brief Normalize a quaternion using unaligned memory access.
 *
 * @param q1 Input quaternion.
 * @param qout Output unit quaternion.
 *
 * @note Input must have nonzero magnitude. In-place operation is supported.
 */
void vfpu_QuatNormalize_U(const float *q1, float *qout);

/**
 * @brief Normalize an aligned quaternion.
 *
 * @param q1 Input quaternion, 16-byte aligned.
 * @param qout Output unit quaternion, 16-byte aligned.
 *
 * @note Input must have nonzero magnitude. In-place operation is supported.
 */
void vfpu_QuatNormalize(const float *q1, float *qout);


/**
  *  Get the inverse of a quaternion - Unaligned
  *  @param q1 input quaternion
  *  @param qout inverse quaternion
**/
void vfpu_QuatInverse_U(float *q1, float *qout);

/**
  *  Get the inverse of a quaternion - Aligned
  *  @param q1 input quaternion
  *  @param qout inverse quaternion
**/
void vfpu_QuatInverse(float *q1, float *qout);

/**
  *  Get the linear interpolation of two quaternions based on a specified weight - Unaligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param s1 weight
  *  @param qout interpolated quaternion
**/
void vfpu_QuatLerp_U(float *q1, float *q2, float s1, float *qout);

/**
  *  Get the linear interpolation of two quaternions based on a specified weight - Aligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param s1 weight
  *  @param qout interpolated quaternion
**/
void vfpu_QuatLerp(float *q1, float *q2, float s1, float *qout);

/**
  *  Get the spherical linear interpolations of two quaternions based on a specified weight - Unaligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param s1 weight
  *  @param qout interpolated quaternion
**/
void vfpu_QuatSlerp_U(float *q1, float *q2, float s1, float *qout);

/**
  *  Get the spherical linear interpolations of two quaternions based on a specified weight - Aligned
  *  @param q1 first quaternion
  *  @param q2 second quaternion
  *  @param s1 weight
  *  @param qout interpolated quaternion
**/
void vfpu_QuatSlerp(float *q1, float *q2, float s1, float *qout);

/**
  *  Rotate a pure quaternion (0, Vec3) by a quaternion - Unaligned
  *  @param q1 pure input quaternion
  *  @param q2 rotation quaternion
  *  @param qout pure output quaternion
**/
void vfpu_QuatRotate_U(float *q1, float *q2, float *qout);

/**
  *  Rotate a pure quaternion (0, Vec3) by a quaternion - Aligned
  *  @param q1 pure input quaternion
  *  @param q2 rotation quaternion
  *  @param qout pure output quaternion
**/
void vfpu_QuatRotate(float *q1, float *q2, float *qout);

/**
  *  Get a rotation matrix from a quaternion - Unaligned
  *  @param q1 input quaternion
  *  @param mout output matrix
**/
void vfpu_QuatRotationMatrix_U(float *q1, float *mout);

/**
  *  Get a rotation matrix from a quaternion - Aligned
  *  @param q1 input quaternion
  *  @param mout output matrix
**/
void vfpu_QuatRotationMatrix(float *q1, float *mout);

/**
  *  Add two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Add_U(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Add_U(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Add_U(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Add(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2pAdd(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Add(float *m1, float *m2, float *mout);

/**
  *  Add two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Add(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Subtract_U(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Subtract_U(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Subtract_U(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Subtract(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2pSubtract(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Subtract(float *m1, float *m2, float *mout);

/**
  *  Subtract two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Subtract(float *m1, float *m2, float *mout);

/**
  *  Scale a matrix by a scalar value - Unaligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat2Scale_U(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Unaligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat3Scale_U(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Unaligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat4Scale_U(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Aligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat2Scale(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Aligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat2pScale(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Aligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat3Scale(float *m1, float s1, float *mout);

/**
  *  Scale a matrix by a scalar value - Aligned
  *  @param m1 input matrix
  *  @param s1 scale factor
  *  @param mout scaled matrix
**/
void vfpu_Mat4Scale(float *m1, float s1, float *mout);

/**
  *  Multiply two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Multiply_U(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Multiply_U(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Unaligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Multiply_U(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2Multiply(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat2pMultiply(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat3Multiply(float *m1, float *m2, float *mout);

/**
  *  Multiply two matrices - Aligned
  *  @param m1 first matrix
  *  @param m2 second matrix
  *  @param mout output matrix
**/
void vfpu_Mat4Multiply(float *m1, float *m2, float *mout);

/**
  *  Set a matrix to an identity matrix - Unaligned
  *  @param mout output matrix
**/
void vfpu_Mat2Identity_U(float *mout);

/**
  *  Set a matrix to an identity matrix - Unaligned
  *  @param mout output matrix
**/
void vfpu_Mat3Identity_U(float *mout);

/**
  *  Set a matrix to an identity matrix - Unaligned
  *  @param mout output matrix
**/
void vfpu_Mat4Identity_U(float *mout);

/**
  *  Set a matrix to an identity matrix - Aligned
  *  @param mout output matrix
**/
void vfpu_Mat2Identity(float *mout);

/**
  *  Set a matrix to an identity matrix - Aligned
  *  @param mout output matrix
**/
void vfpu_Mat2pIdentity(float *mout);

/**
  *  Set a matrix to an identity matrix - Aligned
  *  @param mout output matrix
**/
void vfpu_Mat3Identity(float *mout);

/**
  *  Set a matrix to an identity matrix - Aligned
  *  @param mout output matrix
**/
void vfpu_Mat4Identity(float *mout);

/**
  *  Transpose a matrix - Unaligned
  *  @param m1 input matrix
  *  @param mout transposed matrix
**/
void vfpu_Mat2Transpose_U(float *m1, float *mout);

/**
  *  Transpose a matrix - Unaligned
  *  @param m1 input matrix
  *  @param mout transposed matrix
**/
void vfpu_Mat3Transpose_U(float *m1, float *mout);

/**
  *  Transpose a matrix - Unaligned
  *  @param m1 input matrix
  *  @param mout transposed matrix
**/
void vfpu_Mat4Transpose_U(float *m1, float *mout);

/**
  *  Transpose a matrix - Unaligned
  *  @param m1 input matrix
  *  @param mout transposed matrix
**/
void vfpu_Mat2pTranspose(float *m1, float *mout);

/**
  *  Transpose a matrix - Unaligned
  *  @param m1 input matrix
  *  @param mout transposed matrix
**/
void vfpu_Mat4Transpose(float *m1, float *mout);

/**
  *  Get the determinant of a matrix - Unaligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat2Determinant_U(float *m1);

/**
  *  Get the determinant of a matrix - Unaligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat3Determinant_U(float *m1);

/**
  *  Get the determinant of a matrix - Unaligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat4Determinant_U(float *m1);

/**
  *  Get the determinant of a matrix - Aligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat2Determinant(float *m1);

/**
  *  Get the determinant of a matrix - Aligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat2pDeterminant(float *m1);

/**
  *  Get the determinant of a matrix - Aligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat3Determinant(float *m1);

/**
  *  Get the determinant of a matrix - Aligned
  *  @param m1 input matrix
  *  @return The determinant
**/
float vfpu_Mat4Determinant(float *m1);

/**
  *  Get the inverse of a matrix - Unaligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat2Inverse_U(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Unaligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat3Inverse_U(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Unaligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat4Inverse_U(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Aligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat2Inverse(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Aligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat2pInverse(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Aligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat3Inverse(float *m1, float s1, float *mout);

/**
  *  Get the inverse of a matrix - Aligned
  *  @param m1 input matrix
  *  @param s1 determinant
  *  @param mout inverse matrix
**/
void vfpu_Mat4Inverse(float *m1, float s1, float *mout);

/**
  *  Convert a matrix 2 to a matrix 3 - Unaligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat2ToMat3_U(float *m1, float *mout);

/**
  *  Convert a matrix 2 to a matrix 3 - Aligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat2ToMat3(float *m1, float *mout);

/**
  *  Convert a matrix 2 to a matrix 4 - Unaligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat2ToMat4_U(float *m1, float *mout);

/**
  *  Convert a matrix 2 to a matrix 4 - Aligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat2ToMat4(float *m1, float *mout);

/**
  *  Convert a matrix 3 to a matrix 4 - Unaligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat3ToMat4_U(float *m1, float *mout);

/**
  *  Convert a matrix 3 to a matrix 4 - Aligned
  *  @param m1 input matrix
  *  @param mout output matrix
**/
void vfpu_Mat3ToMat4(float *m1, float *mout);

/**
  *  Multiply a matrix by a vector - Unaligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat2Vector2Multiply_U(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Unaligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat3Vector3Multiply_U(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Unaligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat4Vector4Multiply_U(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Aligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat2Vector2Multiply(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Aligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat2pVector2pMultiply(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Aligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat3Vector3Multiply(float *m1, float *v1, float *vout);

/**
  *  Multiply a matrix by a vector - Aligned
  *  @param m1 input matrix
  *  @param v1 input vector
  *  @param vout output vector
**/
void vfpu_Mat4Vector4Multiply(float *m1, float *v1, float *vout);




















/************ New Library Functions ************/


/**
  *  Calculate a distance vector from a pair of vectors - Unaligned
  *  @param position 1
  *  @param position 2
**/
void vfpu_Vec2Distance_U(const ScePspFVector2 *va, const ScePspFVector2 *vb, ScePspFVector2 *vout);

/**
  *  Calculate a distance vector from a pair of vectors - Unaligned
  *  @param position 1
  *  @param position 2
**/
void vfpu_Vec2pDistance(const ScePspFVector2 *va, const ScePspFVector2 *vb, ScePspFVector2 *vout);

/**
  *  Calculate a distance vector from a pair of vectors - Unaligned
  *  @param position 1
  *  @param position 2
**/
void vfpu_Vec3Distance_U(const ScePspFVector3 *va, const ScePspFVector3 *vb, ScePspFVector3 *vout);

/**
  *  Calculate a distance vector from a pair of vectors - Unaligned
  *  @param position 1
  *  @param position 2
**/
void vfpu_Vec4Distance_U(const ScePspFVector4Unaligned *va, const ScePspFVector4Unaligned *vb, ScePspFVector4Unaligned *vout);

/**
  *  Calculate a distance vector from a pair of vectors - Unaligned
  *  @param position 1
  *  @param position 2
**/
void vfpu_Vec4Distance(const ScePspFVector4 *va, const ScePspFVector4 *vb, ScePspFVector4 *vout);


/**
  *  Create a "look at" matrix from a set of vectors - Unaligned
  *  @param eye input vector
  *  @param center input vector
  *  @param up input vector
  *  @param mout output matrix
**/
void vfpu_Mat4LookAt_U(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up, ScePspFMatrix4 *mout);

/**
  *  Create a "look at" matrix from a set of vectors - Aligned
  *  @param eye input vector
  *  @param center input vector
  *  @param up input vector
  *  @param mout output matrix
**/
void vfpu_Mat4LookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up, ScePspFMatrix4 *mout);


#if defined(__cplusplus)
}
#endif

#endif