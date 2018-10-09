#include "config.h"

#include VEC2_INCLUDE
#include VEC3_INCLUDE
#include VEC4_INCLUDE

#include MAT3_INCLUDE
#include MAT4_INCLUDE

#include COMMON_INCLIDE


#include <cstdio>
#include <ctime>
#include <vector>

static NAMESPACE::vec3 g1;
static NAMESPACE::vec3 g2(1);
static NAMESPACE::vec3 g3(1, 1, 1);

template <int Value>
struct mask
{
	enum{value = Value};
};

enum comp
{
	X,
	Y,
	Z,
	W
};

static int test_vec3_ctor()
{
	int Error = 0;


	{
		float R = 12012.f;
		float S = 23423;
		float T = 23;
		float U = 2e4;

		NAMESPACE::vec3 const O(1.0f, 2.0f, 3.0f);

		NAMESPACE::vec3 const A(R);
		NAMESPACE::vec3 const B(1.0f);

		NAMESPACE::vec3 const C(R, S, 54 );

		NAMESPACE::vec3 const D(R, 2.0f, 3.0f);

		NAMESPACE::vec3 const E(1.0f, S, 3.0f);

		NAMESPACE::vec3 const F(R, S, 3.0f);

		NAMESPACE::vec3 const G(1.0f, 2.0f, T);

		NAMESPACE::vec3 const H(R, 2.0f, T);

		NAMESPACE::vec3 const I(1.0f, S, T);

		NAMESPACE::vec3 const J(R, S, T);

		NAMESPACE::vec3 const K(R, 2.0f, 3.0f);

		NAMESPACE::vec3 const L(1.0f, S, 3.0f);

		NAMESPACE::vec3 const M(R, S, 3.0f);

		NAMESPACE::vec3 const N(1.0f, 2.0f, T);

		NAMESPACE::vec3 const P(R, 2.0f, T);

		NAMESPACE::vec3 const Q(1.0f, S, T);

		NAMESPACE::vec3 const V(R, S, T);
	}

	{
		float R = 12012.f;
		float S = 23423;
		float T = 23;
		float U = 2e4;
		NAMESPACE::vec3 const O(1.0f, 3.0f,54);

		NAMESPACE::vec3 const A(R);
		NAMESPACE::vec3 const B(1.0);

		NAMESPACE::vec3 const C(R, S, T);

		NAMESPACE::vec3 const D(R, 2.0f, 3.0);

		NAMESPACE::vec3 const E(1.0, S, 3.0f);

		NAMESPACE::vec3 const F(R, S, 3.0);

		NAMESPACE::vec3 const G(1.0f, 2.0, T);

		NAMESPACE::vec3 const H(R, 2.0, T);

		NAMESPACE::vec3 const I(1.0, S, T);

		NAMESPACE::vec3 const J(R, S, T);

		NAMESPACE::vec3 const K(R, 2.0f, 3.0);

		NAMESPACE::vec3 const L(1.0f, S, U);
		NAMESPACE::vec3 const M(R, S, 3.0);

		NAMESPACE::vec3 const N(1.0f, T, U);

		NAMESPACE::vec3 const P(R, T, U);

		NAMESPACE::vec3 const Q( S, T, U);

		NAMESPACE::vec3 const V(R, S, U);
	}

	{
		NAMESPACE::vec2 const v2_0(1.0f, 2.0f);
		NAMESPACE::vec2 const v2_1(2.0f, 3.0f);
		NAMESPACE::vec2 const v2_2(3.0f, 4.0f);

		NAMESPACE::vec3 const v3_0(1.0f, 2.0f, 3.0f);
		NAMESPACE::vec3 const v3_1(2.0f, 3.0f, 4.0f);

		NAMESPACE::vec3 const O(1.0f, 2.0, 4.0);

		NAMESPACE::vec3 const B(1.0f, v2_2);


		NAMESPACE::vec3 const H(v2_0, 4.0f);
	}

	{
		NAMESPACE::vec2 const v2(2.0f, 3.0f);

		NAMESPACE::vec3 const O( 2.0, 3.0f, 4.0);


		NAMESPACE::vec3 const D(1.0f, v2);

		NAMESPACE::vec3 const E( v2, 4.0f);
	}

	return Error;
}

static int test_operators()
{
	int Error = 0;



	{
		NAMESPACE::vec3 const A(1.0f, 2.0f, 3.0f);
		NAMESPACE::vec3 const B(4.0f, 5.0f, 6.0f);

		NAMESPACE::vec3 const C = A + B;

		NAMESPACE::vec3 const D = B - A;

		NAMESPACE::vec3 const E = A * B;

		NAMESPACE::vec3 const F = B / A;

		NAMESPACE::vec3 const G = A + 1.0f;

		NAMESPACE::vec3 const H = B - 1.0f;

		NAMESPACE::vec3 const I = A * 2.0f;

		NAMESPACE::vec3 const J = B / 2.0f;

		NAMESPACE::vec3 const K = 1.0f + A;

		NAMESPACE::vec3 const L = 1.0f - B;

		NAMESPACE::vec3 const M = 2.0f * A;

		NAMESPACE::vec3 const N = 2.0f / B;
	}

	return Error;
}


struct AoS
{
	NAMESPACE::vec3 A;
	NAMESPACE::vec3 B;
	NAMESPACE::vec3 C;
	NAMESPACE::vec2 D;
};

static int test_perf_AoS(std::size_t Size)
{
	int Error = 0;

	std::vector<AoS> In;
	std::vector<AoS> Out;
	In.resize(Size);
	Out.resize(Size);

	std::clock_t StartTime = std::clock();

	for(std::size_t i = 0; i < In.size(); ++i)
		Out[i] = In[i];

	std::clock_t EndTime = std::clock();

	std::printf("AoS: %d\n", static_cast<int>(EndTime - StartTime));

	return Error;
}

static int test_perf_SoA(std::size_t Size)
{
	int Error = 0;

	std::vector<NAMESPACE::vec3> InA;
	std::vector<NAMESPACE::vec3> InB;
	std::vector<NAMESPACE::vec3> InC;
	std::vector<NAMESPACE::vec2> InD;
	std::vector<NAMESPACE::vec3> OutA;
	std::vector<NAMESPACE::vec3> OutB;
	std::vector<NAMESPACE::vec3> OutC;
	std::vector<NAMESPACE::vec2> OutD;

	InA.resize(Size);
	InB.resize(Size);
	InC.resize(Size);
	InD.resize(Size);
	OutA.resize(Size);
	OutB.resize(Size);
	OutC.resize(Size);
	OutD.resize(Size);

	std::clock_t StartTime = std::clock();

	for(std::size_t i = 0; i < InA.size(); ++i)
	{
		OutA[i] = InA[i];
		OutB[i] = InB[i];
		OutC[i] = InC[i];
		OutD[i] = InD[i];
	}

	std::clock_t EndTime = std::clock();

	std::printf("SoA: %d\n", static_cast<int>(EndTime - StartTime));

	return Error;
}

