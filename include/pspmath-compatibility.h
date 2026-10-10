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

#ifndef _pspmath_compatibility_h_
#define _pspmath_compatibility_h_

#include <pspmath.h>

/* @defgroup VFPUMATH VFPU Math Library
 *
 **/

#if defined(__cplusplus)
extern "C" {
#endif

/*
    * pspla compatibility
    *
    * Legacy pspla names are mapped to the current vfpu API.
    *
    * Aligned operations:
    *     psplaFooA() -> vfpu_Foo()
    *
    * Unaligned operations:
    *     psplaFooU() -> vfpu_Foo_U()
    */


/* Scalar */

#define psplaAbsoluteValue             vfpu_AbsoluteValue
#define psplaArccosine                 vfpu_Arccosine
#define psplaArcsine                   vfpu_Arcsine
#define psplaCosine                    vfpu_Cosine
#define psplaRandom                    vfpu_Random
#define psplaSine                      vfpu_Sine
#define psplaSquareRoot                vfpu_SquareRoot


/* Vector 2 - reductions */

#define psplaVec2AverageA              vfpu_Vec2Average
#define psplaVec2AverageU              vfpu_Vec2Average_U
#define psplaVec2DotProductA           vfpu_Vec2DotProduct
#define psplaVec2DotProductU           vfpu_Vec2DotProduct_U
#define psplaVec2MagnitudeA            vfpu_Vec2Magnitude
#define psplaVec2MagnitudeU            vfpu_Vec2Magnitude_U
#define psplaVec2SumA                  vfpu_Vec2Sum
#define psplaVec2SumU                  vfpu_Vec2Sum_U


/* Vector 3 - reductions */

#define psplaVec3AverageA              vfpu_Vec3Average
#define psplaVec3AverageU              vfpu_Vec3Average_U
#define psplaVec3DotProductA           vfpu_Vec3DotProduct
#define psplaVec3DotProductU           vfpu_Vec3DotProduct_U
#define psplaVec3MagnitudeA            vfpu_Vec3Magnitude
#define psplaVec3MagnitudeU            vfpu_Vec3Magnitude_U
#define psplaVec3SumA                  vfpu_Vec3Sum
#define psplaVec3SumU                  vfpu_Vec3Sum_U


/* Vector 4 - reductions */

#define psplaVec4AverageA              vfpu_Vec4Average
#define psplaVec4AverageU              vfpu_Vec4Average_U
#define psplaVec4DotProductA           vfpu_Vec4DotProduct
#define psplaVec4DotProductU           vfpu_Vec4DotProduct_U
#define psplaVec4MagnitudeA            vfpu_Vec4Magnitude
#define psplaVec4MagnitudeU            vfpu_Vec4Magnitude_U
#define psplaVec4SumA                  vfpu_Vec4Sum
#define psplaVec4SumU                  vfpu_Vec4Sum_U


/* Vector 2 - comparison */

#define psplaVec2EqualsA               vfpu_Vec2Equals
#define psplaVec2EqualsU               vfpu_Vec2Equals_U
#define psplaVec2GreaterThanA          vfpu_Vec2GreaterThan
#define psplaVec2GreaterThanU          vfpu_Vec2GreaterThan_U
#define psplaVec2GreaterThanEqualA     vfpu_Vec2GreaterThanEqual
#define psplaVec2GreaterThanEqualU     vfpu_Vec2GreaterThanEqual_U
#define psplaVec2LessThanA             vfpu_Vec2LessThan
#define psplaVec2LessThanU             vfpu_Vec2LessThan_U
#define psplaVec2LessThanEqualA        vfpu_Vec2LessThanEqual
#define psplaVec2LessThanEqualU        vfpu_Vec2LessThanEqual_U


/* Vector 3 - comparison */

#define psplaVec3EqualsA               vfpu_Vec3Equals
#define psplaVec3EqualsU               vfpu_Vec3Equals_U
#define psplaVec3GreaterThanA          vfpu_Vec3GreaterThan
#define psplaVec3GreaterThanU          vfpu_Vec3GreaterThan_U
#define psplaVec3GreaterThanEqualA     vfpu_Vec3GreaterThanEqual
#define psplaVec3GreaterThanEqualU     vfpu_Vec3GreaterThanEqual_U
#define psplaVec3LessThanA             vfpu_Vec3LessThan
#define psplaVec3LessThanU             vfpu_Vec3LessThan_U
#define psplaVec3LessThanEqualA        vfpu_Vec3LessThanEqual
#define psplaVec3LessThanEqualU        vfpu_Vec3LessThanEqual_U


/* Vector 4 - comparison */

#define psplaVec4EqualsA               vfpu_Vec4Equals
#define psplaVec4EqualsU               vfpu_Vec4Equals_U
#define psplaVec4GreaterThanA          vfpu_Vec4GreaterThan
#define psplaVec4GreaterThanU          vfpu_Vec4GreaterThan_U
#define psplaVec4GreaterThanEqualA     vfpu_Vec4GreaterThanEqual
#define psplaVec4GreaterThanEqualU     vfpu_Vec4GreaterThanEqual_U
#define psplaVec4LessThanA             vfpu_Vec4LessThan
#define psplaVec4LessThanU             vfpu_Vec4LessThan_U
#define psplaVec4LessThanEqualA        vfpu_Vec4LessThanEqual
#define psplaVec4LessThanEqualU        vfpu_Vec4LessThanEqual_U


/* Matrix 2 */

#define psplaMat2DeterminantA          vfpu_Mat2Determinant
#define psplaMat2DeterminantU          vfpu_Mat2Determinant_U

#define psplaMat2AddA                  vfpu_Mat2Add
#define psplaMat2AddU                  vfpu_Mat2Add_U
#define psplaMat2CopyA                 vfpu_Mat2Copy
#define psplaMat2CopyU                 vfpu_Mat2Copy_U
#define psplaMat2IdentityA             vfpu_Mat2Identity
#define psplaMat2IdentityU             vfpu_Mat2Identity_U
#define psplaMat2InverseA              vfpu_Mat2Inverse
#define psplaMat2InverseU              vfpu_Mat2Inverse_U
#define psplaMat2MultiplyA             vfpu_Mat2Multiply
#define psplaMat2MultiplyU             vfpu_Mat2Multiply_U
#define psplaMat2ScaleA                vfpu_Mat2Scale
#define psplaMat2ScaleU                vfpu_Mat2Scale_U
#define psplaMat2SubtractA             vfpu_Mat2Subtract
#define psplaMat2SubtractU             vfpu_Mat2Subtract_U
#define psplaMat2ToMatrix3A            vfpu_Mat2ToMat3
#define psplaMat2ToMatrix3U            vfpu_Mat2ToMat3_U
#define psplaMat2ToMatrix4A            vfpu_Mat2ToMat4
#define psplaMat2ToMatrix4U            vfpu_Mat2ToMat4_U
#define psplaMat2TransposeU            vfpu_Mat2Transpose_U
#define psplaMat2Vector2MultiplyA      vfpu_Mat2Vector2Multiply
#define psplaMat2Vector2MultiplyU      vfpu_Mat2Vector2Multiply_U


/* Matrix 3 */

#define psplaMat3DeterminantA          vfpu_Mat3Determinant
#define psplaMat3DeterminantU          vfpu_Mat3Determinant_U

#define psplaMat3AddA                  vfpu_Mat3Add
#define psplaMat3AddU                  vfpu_Mat3Add_U
#define psplaMat3CopyA                 vfpu_Mat3Copy
#define psplaMat3CopyU                 vfpu_Mat3Copy_U
#define psplaMat3IdentityA             vfpu_Mat3Identity
#define psplaMat3IdentityU             vfpu_Mat3Identity_U
#define psplaMat3InverseA              vfpu_Mat3Inverse
#define psplaMat3InverseU              vfpu_Mat3Inverse_U
#define psplaMat3MultiplyA             vfpu_Mat3Multiply
#define psplaMat3MultiplyU             vfpu_Mat3Multiply_U
#define psplaMat3ScaleA                vfpu_Mat3Scale
#define psplaMat3ScaleU                vfpu_Mat3Scale_U
#define psplaMat3SubtractA             vfpu_Mat3Subtract
#define psplaMat3SubtractU             vfpu_Mat3Subtract_U
#define psplaMat3ToMatrix4A            vfpu_Mat3ToMat4
#define psplaMat3ToMatrix4U            vfpu_Mat3ToMat4_U
#define psplaMat3TransposeU            vfpu_Mat3Transpose_U
#define psplaMat3Vector3MultiplyA      vfpu_Mat3Vector3Multiply
#define psplaMat3Vector3MultiplyU      vfpu_Mat3Vector3Multiply_U


/* Matrix 4 */

#define psplaMat4DeterminantA          vfpu_Mat4Determinant
#define psplaMat4DeterminantU          vfpu_Mat4Determinant_U

#define psplaMat4AddA                  vfpu_Mat4Add
#define psplaMat4AddU                  vfpu_Mat4Add_U
#define psplaMat4CopyA                 vfpu_Mat4Copy
#define psplaMat4CopyU                 vfpu_Mat4Copy_U
#define psplaMat4IdentityA             vfpu_Mat4Identity
#define psplaMat4IdentityU             vfpu_Mat4Identity_U
#define psplaMat4InverseA              vfpu_Mat4Inverse
#define psplaMat4InverseU              vfpu_Mat4Inverse_U
#define psplaMat4MultiplyA             vfpu_Mat4Multiply
#define psplaMat4MultiplyU             vfpu_Mat4Multiply_U
#define psplaMat4ScaleA                vfpu_Mat4Scale
#define psplaMat4ScaleU                vfpu_Mat4Scale_U
#define psplaMat4SubtractA             vfpu_Mat4Subtract
#define psplaMat4SubtractU             vfpu_Mat4Subtract_U
#define psplaMat4TransposeU            vfpu_Mat4Transpose_U
#define psplaMat4Vector4MultiplyA      vfpu_Mat4Vector4Multiply
#define psplaMat4Vector4MultiplyU      vfpu_Mat4Vector4Multiply_U


/* Quaternion */

#define psplaQuatNormA                 vfpu_QuatMagnitude
#define psplaQuatNormU                 vfpu_QuatMagnitude_U

#define psplaQuatConjugateA            vfpu_QuatConjugate
#define psplaQuatConjugateU            vfpu_QuatConjugate_U
#define psplaQuatIdentityA             vfpu_QuatIdentity
#define psplaQuatIdentityU             vfpu_QuatIdentity_U
#define psplaQuatInverseA              vfpu_QuatInverse
#define psplaQuatInverseU              vfpu_QuatInverse_U
#define psplaQuatLerpA                 vfpu_QuatLerp
#define psplaQuatLerpU                 vfpu_QuatLerp_U
/* Legacy pspla uses scalar-first [w,x,y,z]; the native VFPU API uses
 * scalar-last [x,y,z,w]. Convert only at this compatibility boundary. */
static inline void psplaQuatMultiplyA(const float *a, const float *b, float *out)
{
    float aa[4] PSPMATH_ALIGN = {a[1], a[2], a[3], a[0]};
    float bb[4] PSPMATH_ALIGN = {b[1], b[2], b[3], b[0]};
    float rr[4] PSPMATH_ALIGN;
    vfpu_QuatMultiply(aa, bb, rr);
    out[0] = rr[3]; out[1] = rr[0]; out[2] = rr[1]; out[3] = rr[2];
}
static inline void psplaQuatMultiplyU(const float *a, const float *b, float *out)
{
    float aa[4] PSPMATH_ALIGN = {a[1], a[2], a[3], a[0]};
    float bb[4] PSPMATH_ALIGN = {b[1], b[2], b[3], b[0]};
    float rr[4] PSPMATH_ALIGN;
    vfpu_QuatMultiply(aa, bb, rr);
    out[0] = rr[3]; out[1] = rr[0]; out[2] = rr[1]; out[3] = rr[2];
}
#define psplaQuatRotateA               vfpu_QuatRotate
#define psplaQuatRotateU               vfpu_QuatRotate_U
#define psplaQuatRotationMatrixA       vfpu_QuatRotationMatrix
#define psplaQuatRotationMatrixU       vfpu_QuatRotationMatrix_U
#define psplaQuatSlerpA                vfpu_QuatSlerp
#define psplaQuatSlerpU                vfpu_QuatSlerp_U


/* Random */

#define psplaRandomSeed                vfpu_RandomSeed


/* Vector 2 */

#define psplaVec2AbsoluteValueU        vfpu_Vec2AbsoluteValue_U
#define psplaVec2AddU                  vfpu_Vec2Add_U
#define psplaVec2CeilingU              vfpu_Vec2Ceiling_U
#define psplaVec2ClampU                vfpu_Vec2Clamp_U
#define psplaVec2CompareU              vfpu_Vec2Compare_U
#define psplaVec2CopyU                 vfpu_Vec2Copy_U
#define psplaVec2CosineA               vfpu_Vec2Cosine
#define psplaVec2CosineU               vfpu_Vec2Cosine_U
#define psplaVec2DivideA               vfpu_Vec2Divide
#define psplaVec2DivideU               vfpu_Vec2Divide_U
#define psplaVec2FloorU                vfpu_Vec2Floor_U
#define psplaVec2LerpU                 vfpu_Vec2Lerp_U
#define psplaVec2MaximumU              vfpu_Vec2Maximum_U
#define psplaVec2MinimumU              vfpu_Vec2Minimum_U
#define psplaVec2MultiplyU              vfpu_Vec2Multiply_U
#define psplaVec2NegateU               vfpu_Vec2Negate_U
#define psplaVec2NormalizeA            vfpu_Vec2Normalize
#define psplaVec2NormalizeU            vfpu_Vec2Normalize_U
#define psplaVec2RandomA               vfpu_Vec2Random
#define psplaVec2RandomU               vfpu_Vec2Random_U
#define psplaVec2ReflectA              vfpu_Vec2Reflect
#define psplaVec2ReflectU              vfpu_Vec2Reflect_U
#define psplaVec2ReorderA              vfpu_Vec2Reorder
#define psplaVec2ReorderU              vfpu_Vec2Reorder_U
#define psplaVec2RoundU                vfpu_Vec2Round_U
#define psplaVec2ScaleU                vfpu_Vec2Scale_U
#define psplaVec2SineA                 vfpu_Vec2Sine
#define psplaVec2SineU                 vfpu_Vec2Sine_U
#define psplaVec2SquareRootA           vfpu_Vec2SquareRoot
#define psplaVec2SquareRootU           vfpu_Vec2SquareRoot_U
#define psplaVec2SubtractU             vfpu_Vec2Subtract_U


/* Vector 3 */

#define psplaVec3AbsoluteValueU        vfpu_Vec3AbsoluteValue_U
#define psplaVec3AddU                  vfpu_Vec3Add_U
#define psplaVec3CeilingU              vfpu_Vec3Ceiling_U
#define psplaVec3ClampU                vfpu_Vec3Clamp_U
#define psplaVec3CompareU              vfpu_Vec3Compare_U
#define psplaVec3CopyU                 vfpu_Vec3Copy_U
#define psplaVec3CosineA               vfpu_Vec3Cosine
#define psplaVec3CosineU               vfpu_Vec3Cosine_U
#define psplaVec3CrossProductA         vfpu_Vec3CrossProduct
#define psplaVec3CrossProductU         vfpu_Vec3CrossProduct_U
#define psplaVec3DivideA               vfpu_Vec3Divide
#define psplaVec3DivideU               vfpu_Vec3Divide_U
#define psplaVec3FloorU                vfpu_Vec3Floor_U
#define psplaVec3LerpU                 vfpu_Vec3Lerp_U
#define psplaVec3MaximumU              vfpu_Vec3Maximum_U
#define psplaVec3MinimumU              vfpu_Vec3Minimum_U
#define psplaVec3MultiplyU              vfpu_Vec3Multiply_U
#define psplaVec3NegateU               vfpu_Vec3Negate_U
#define psplaVec3NormalizeA            vfpu_Vec3Normalize
#define psplaVec3NormalizeU            vfpu_Vec3Normalize_U
#define psplaVec3RandomA               vfpu_Vec3Random
#define psplaVec3RandomU               vfpu_Vec3Random_U
#define psplaVec3ReflectA              vfpu_Vec3Reflect
#define psplaVec3ReflectU              vfpu_Vec3Reflect_U
#define psplaVec3ReorderA              vfpu_Vec3Reorder
#define psplaVec3ReorderU              vfpu_Vec3Reorder_U
#define psplaVec3RotationMatrixA       vfpu_Vec3RotationMatrix
#define psplaVec3RotationMatrixU       vfpu_Vec3RotationMatrix_U
#define psplaVec3RotationQuaternionA   vfpu_Vec3RotationQuaternion
#define psplaVec3RotationQuaternionU   vfpu_Vec3RotationQuaternion_U
#define psplaVec3RoundU                vfpu_Vec3Round_U
#define psplaVec3ScaleU                vfpu_Vec3Scale_U
#define psplaVec3SineA                 vfpu_Vec3Sine
#define psplaVec3SineU                 vfpu_Vec3Sine_U
#define psplaVec3SquareRootA           vfpu_Vec3SquareRoot
#define psplaVec3SquareRootU           vfpu_Vec3SquareRoot_U
#define psplaVec3SubtractU             vfpu_Vec3Subtract_U


/* Vector 4 */

#define psplaVec4AbsoluteValueU        vfpu_Vec4AbsoluteValue_U
#define psplaVec4AddU                  vfpu_Vec4Add_U
#define psplaVec4CeilingU              vfpu_Vec4Ceiling_U
#define psplaVec4ClampU                vfpu_Vec4Clamp_U
#define psplaVec4CompareU              vfpu_Vec4Compare_U
#define psplaVec4CopyU                 vfpu_Vec4Copy_U
#define psplaVec4CosineA               vfpu_Vec4Cosine
#define psplaVec4CosineU               vfpu_Vec4Cosine_U
#define psplaVec4DivideA               vfpu_Vec4Divide
#define psplaVec4DivideU               vfpu_Vec4Divide_U
#define psplaVec4FloorU                vfpu_Vec4Floor_U
#define psplaVec4LerpU                 vfpu_Vec4Lerp_U
#define psplaVec4MaximumU              vfpu_Vec4Maximum_U
#define psplaVec4MinimumU              vfpu_Vec4Minimum_U
#define psplaVec4MultiplyU              vfpu_Vec4Multiply_U
#define psplaVec4NegateU               vfpu_Vec4Negate_U
#define psplaVec4NormalizeA            vfpu_Vec4Normalize
#define psplaVec4NormalizeU            vfpu_Vec4Normalize_U
#define psplaVec4RandomA               vfpu_Vec4Random
#define psplaVec4RandomU               vfpu_Vec4Random_U
#define psplaVec4ReflectA              vfpu_Vec4Reflect
#define psplaVec4ReflectU              vfpu_Vec4Reflect_U
#define psplaVec4ReorderA              vfpu_Vec4Reorder
#define psplaVec4ReorderU              vfpu_Vec4Reorder_U
#define psplaVec4RoundU                vfpu_Vec4Round_U
#define psplaVec4ScaleU                vfpu_Vec4Scale_U
#define psplaVec4SineA                 vfpu_Vec4Sine
#define psplaVec4SineU                 vfpu_Vec4Sine_U
#define psplaVec4SquareRootA           vfpu_Vec4SquareRoot
#define psplaVec4SquareRootU           vfpu_Vec4SquareRoot_U
#define psplaVec4SubtractU             vfpu_Vec4Subtract_U


/* Generic vector operations */

#define psplaVecVAbsoluteValueA        vfpu_Vec4AbsoluteValue
#define psplaVecVAddA                  vfpu_Vec4Add
#define psplaVecVCeilingA              vfpu_Vec4Ceiling
#define psplaVecVClampA                vfpu_Vec4Clamp
#define psplaVecVCompareA              vfpu_Vec4Compare
#define psplaVecVCopyA                 vfpu_Vec4Copy
#define psplaVecVDivideA               vfpu_Vec4Divide
#define psplaVecVFloorA                vfpu_Vec4Floor
#define psplaVecVLerpA                 vfpu_Vec4Lerp
#define psplaVecVMaximumA              vfpu_Vec4Maximum
#define psplaVecVMinimumA              vfpu_Vec4Minimum
#define psplaVecVMultiplyA             vfpu_Vec4Multiply
#define psplaVecVNegateA               vfpu_Vec4Negate
#define psplaVecVRandomA               vfpu_Vec4Random
#define psplaVecVRoundA                vfpu_Vec4Round
#define psplaVecVScaleA                vfpu_Vec4Scale
#define psplaVecVSquareRootA           vfpu_Vec4SquareRoot
#define psplaVecVSubtractA             vfpu_Vec4Subtract


/* Additional canonical API aliases and former exported names. */
#define psplaPrintRegisters                     vfpu_PrintRegisters
#define printVFPURegisters                      vfpu_PrintRegisters
#define psplaPrintMatrix                        vfpu_PrintMatrix
#define printMatrixFloat                        vfpu_PrintMatrix
#define psplaPrintVector                        vfpu_PrintVector
#define printVectorFloat                        vfpu_PrintVector
#define psplaPrintQuaternion                    vfpu_PrintQuaternion
#define printQuaternionFloat                    vfpu_PrintQuaternion
#define psplaSrand                              vfpu_srand
#define psplaRandf                              vfpu_randf
#define psplaRand_8888                          vfpu_rand_8888
#define psplaRand_565                           vfpu_rand_565
#define psplaMat4TranslateA                     vfpu_Mat4Translate
#define vfpu_translate_matrix                   vfpu_Mat4Translate
#define psplaMat4PerspectiveA                   vfpu_Mat4Perspective
#define vfpu_perspective_matrix                 vfpu_Mat4Perspective
#define psplaMat4OrthographicA                  vfpu_Mat4Orthographic
#define vfpu_ortho_matrix                       vfpu_Mat4Orthographic
#define psplaSinf                               vfpu_sinf
#define psplaCosf                               vfpu_cosf
#define psplaTanf                               vfpu_tanf
#define psplaAsinf                              vfpu_asinf
#define psplaAcosf                              vfpu_acosf
#define psplaAtanf                              vfpu_atanf
#define psplaAtan2f                             vfpu_atan2f
#define psplaSinhf                              vfpu_sinhf
#define psplaCoshf                              vfpu_coshf
#define psplaTanhf                              vfpu_tanhf
#define psplaSincos                             vfpu_sincos
#define psplaExpf                               vfpu_expf
#define psplaLogf                               vfpu_logf
#define psplaPowf                               vfpu_powf
#define psplaFmodf                              vfpu_fmodf
#define psplaEaseInOut                          vfpu_EaseInOut
#define vfpu_ease_in_out                        vfpu_EaseInOut
#define psplaVec4ZeroA                          vfpu_Vec4Zero
#define vfpu_zero_vector                        vfpu_Vec4Zero
#define psplaVec4EnvironmentMapA                vfpu_Vec4EnvironmentMap
#define vfpu_envmap_matrix                      vfpu_Vec4EnvironmentMap
#define psplaMat4TransformVec4A                 vfpu_Mat4TransformVec4
#define vfpu_transform_vector                   vfpu_Mat4TransformVec4
#define psplaVec3FromSphericalA                 vfpu_Vec3FromSpherical
#define vfpu_sphere_to_cartesian                vfpu_Vec3FromSpherical
#define vfpu_quaternion_identity_U              vfpu_QuatIdentity_U
#define vfpu_quaternion_identity                vfpu_QuatIdentity
#define psplaQuatCopyA                          vfpu_QuatCopy
#define vfpu_quaternion_copy                    vfpu_QuatCopy
#define psplaQuatMultiplyOutFirstA              vfpu_QuatMultiplyOutFirst
#define vfpu_quaternion_multiply                vfpu_QuatMultiplyOutFirst
#define psplaQuatFromEulerA                     vfpu_QuatFromEuler
#define vfpu_quaternion_from_euler              vfpu_QuatFromEuler
#define psplaQuatExpA                           vfpu_QuatExp
#define vfpu_quaternion_exp                     vfpu_QuatExp
#define psplaQuatLnA                            vfpu_QuatLn
#define vfpu_quaternion_ln                      vfpu_QuatLn
#define psplaQuatSampleLinearA                  vfpu_QuatSampleLinear
#define vfpu_quaternion_sample_linear           vfpu_QuatSampleLinear
#define psplaQuatSampleHermiteA                 vfpu_QuatSampleHermite
#define vfpu_quaternion_sample_hermite          vfpu_QuatSampleHermite
#define psplaQuatHermiteTangentA                vfpu_QuatHermiteTangent
#define vfpu_quaternion_hermite_tangent         vfpu_QuatHermiteTangent
#define psplaQuatToMat4A                        vfpu_QuatToMat4
#define vfpu_quaternion_to_matrix               vfpu_QuatToMat4
#define psplaQuatNormalizeU                     vfpu_QuatNormalize_U
#define psplaQuatNormalizeA                     vfpu_QuatNormalize
#define vfpu_Mat2ToMatrix3_U                    vfpu_Mat2ToMat3_U
#define vfpu_Mat2ToMatrix3                      vfpu_Mat2ToMat3
#define vfpu_Mat2ToMatrix4_U                    vfpu_Mat2ToMat4_U
#define vfpu_Mat2ToMatrix4                      vfpu_Mat2ToMat4
#define vfpu_Mat3ToMatrix4_U                    vfpu_Mat3ToMat4_U
#define vfpu_Mat3ToMatrix4                      vfpu_Mat3ToMat4
#define psplaVec2DistanceU                      vfpu_Vec2Distance_U
#define psplaVec3DistanceU                      vfpu_Vec3Distance_U
#define psplaVec4DistanceU                      vfpu_Vec4Distance_U
#define psplaVec4DistanceA                      vfpu_Vec4Distance
#define psplaMat4LookAtU                        vfpu_Mat4LookAt_U
#define psplaMat4LookAtA                        vfpu_Mat4LookAt
#define psplaVec4CopyA                          vfpu_Vec4Copy
#define psplaVec4AddA                           vfpu_Vec4Add
#define psplaVec4SubtractA                      vfpu_Vec4Subtract
#define psplaVec4MultiplyA                      vfpu_Vec4Multiply
#define psplaVec4MinimumA                       vfpu_Vec4Minimum
#define psplaVec4MaximumA                       vfpu_Vec4Maximum
#define psplaVec4AbsoluteValueA                 vfpu_Vec4AbsoluteValue
#define psplaVec4ScaleA                         vfpu_Vec4Scale
#define psplaVec4RoundA                         vfpu_Vec4Round
#define psplaVec4FloorA                         vfpu_Vec4Floor
#define psplaVec4CeilingA                       vfpu_Vec4Ceiling
#define psplaVec4NegateA                        vfpu_Vec4Negate
#define psplaVec4CompareA                       vfpu_Vec4Compare
#define psplaVec4LerpA                          vfpu_Vec4Lerp
#define psplaVec4ClampA                         vfpu_Vec4Clamp
#define psplaQuatMagnitudeU                     vfpu_QuatMagnitude_U
#define psplaQuatMagnitudeA                     vfpu_QuatMagnitude
#define psplaMat2ToMat3U                        vfpu_Mat2ToMat3_U
#define psplaMat2ToMat3A                        vfpu_Mat2ToMat3
#define psplaMat2ToMat4U                        vfpu_Mat2ToMat4_U
#define psplaMat2ToMat4A                        vfpu_Mat2ToMat4
#define psplaMat3ToMat4U                        vfpu_Mat3ToMat4_U
#define psplaMat3ToMat4A                        vfpu_Mat3ToMat4

/* Original libpspmath and pre-normalization vfpu names. */
#define vfpu_VecVCopy                           vfpu_Vec4Copy
#define vfpu_VecVAdd                            vfpu_Vec4Add
#define vfpu_VecVSubtract                       vfpu_Vec4Subtract
#define vfpu_VecVMultiply                       vfpu_Vec4Multiply
#define vfpu_VecVDivide                         vfpu_Vec4Divide
#define vfpu_VecVMinimum                        vfpu_Vec4Minimum
#define vfpu_VecVMaximum                        vfpu_Vec4Maximum
#define vfpu_VecVAbsoluteValue                  vfpu_Vec4AbsoluteValue
#define vfpu_VecVSquareRoot                     vfpu_Vec4SquareRoot
#define vfpu_VecVRound                          vfpu_Vec4Round
#define vfpu_VecVFloor                          vfpu_Vec4Floor
#define vfpu_VecVCeiling                        vfpu_Vec4Ceiling
#define vfpu_VecVSine                           vfpu_Vec4Sine
#define vfpu_VecVCosine                         vfpu_Vec4Cosine
#define vfpu_VecVNegate                         vfpu_Vec4Negate
#define vfpu_VecVCompare                        vfpu_Vec4Compare
#define vfpu_VecVLerp                           vfpu_Vec4Lerp
#define vfpu_VecVClamp                          vfpu_Vec4Clamp
#define vfpu_VecVRandom                         vfpu_Vec4Random
#define vfpu_VecVScale                          vfpu_Vec4Scale

#if defined(__cplusplus)
}
#endif

#endif
