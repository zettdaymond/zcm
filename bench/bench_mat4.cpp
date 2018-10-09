#include "config.h"

#include VEC2_INCLUDE
#include VEC3_INCLUDE
#include VEC4_INCLUDE

#include MAT3_INCLUDE
#include MAT4_INCLUDE
#include MATRIX_OPS_INCLUDE
#include MATRIX_TRANSFORM_INCLUDE

#include COMMON_INCLIDE

#include <vector>

template <typename matType, typename vecType>
static int test_operators()
{
	int Error = 0;

	matType const M(2.0f);
	matType const N(1.0f);
	vecType const U(2.0f);

	{
		matType const P = N * (2.0f);

		matType const Q = M / (2.0f);
	}

	{
		vecType const V = M * U;

		vecType const W = U / M;
	}

	{
		matType const O = M * N;
	}

	return Error;
}

template <typename matType>
static int test_inverse()
{

	int Error = 0;

	matType const Identity(1.0f);
	matType const Matrix(
		NAMESPACE::vec4(0.6f, 0.2f, 0.3f, 0.4f),
		NAMESPACE::vec4(0.2f, 0.7f, 0.5f, 0.3f),
		NAMESPACE::vec4(0.3f, 0.5f, 0.7f, 0.2f),
		NAMESPACE::vec4(0.4f, 0.3f, 0.2f, 0.6f));
	matType const Inverse = Identity / Matrix;
	matType const Result = Matrix * Inverse;

	return Error;
}

template int test_operators<NAMESPACE::mat4, NAMESPACE::vec4>();
template int test_operators<NAMESPACE::mat3, NAMESPACE::vec3>();
template int test_inverse<NAMESPACE::mat4>();


int test_transpose()
{
	int Error(0);

	{
		NAMESPACE::mat3 m(NAMESPACE::vec3{0, 1, 2}, NAMESPACE::vec3{3, 4, 5}, NAMESPACE::vec3{6, 7, 8});
		NAMESPACE::mat3 t = transpose(m);
		NAMESPACE::mat3 const expected = NAMESPACE::mat3(NAMESPACE::vec3{0, 3, 6}, NAMESPACE::vec3{1, 4, 7}, NAMESPACE::vec3{2, 5, 8});
	}


	{
		NAMESPACE::mat4 m(NAMESPACE::vec4{0, 1, 2, 3}, NAMESPACE::vec4{4, 5, 6, 7}, NAMESPACE::vec4{8, 9, 10, 11}, NAMESPACE::vec4{12, 13, 14, 15});
		NAMESPACE::mat4 t = transpose(m);
		NAMESPACE::mat4 const expected = NAMESPACE::mat4(NAMESPACE::vec4{0, 4, 8, 12},
		                                                 NAMESPACE::vec4{1, 5, 9, 13},
		                                                 NAMESPACE::vec4{2, 6, 10, 14},
		                                                 NAMESPACE::vec4{3, 7, 11, 15});
	}

	return Error;
}


int test_inverse()
{
	int Error = 0;

	{
		NAMESPACE::mat4 A4x4(
			NAMESPACE::vec4(1, 0, 1, 0),
			NAMESPACE::vec4(0, 1, 0, 0),
			NAMESPACE::vec4(0, 0, 1, 0),
			NAMESPACE::vec4(0, 0, 0, 1));
		NAMESPACE::mat4 B4x4 = inverse(A4x4);
		NAMESPACE::mat4 I4x4 = A4x4 * B4x4;
		NAMESPACE::mat4 Identity(1);
	}

	{
		NAMESPACE::mat3 A3x3(
			NAMESPACE::vec3(1, 0, 1),
			NAMESPACE::vec3(0, 1, 0),
			NAMESPACE::vec3(0, 0, 1));
		NAMESPACE::mat3 B3x3 = NAMESPACE::inverse(A3x3);
		NAMESPACE::mat3 I3x3 = A3x3 * B3x3;
		NAMESPACE::mat3 Identity(1);
	}


	return Error;
}


