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

static NAMESPACE::vec2 g1;
static NAMESPACE::vec2 g2(1);
static NAMESPACE::vec2 g3(1, 1);

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

static int test_vec2_ctor()
{
	int Error = 0;


	{
		float R = 12012.f;
		float S = 23423;
		float T = 23;
		float U = 2e4;

		NAMESPACE::vec2 const O(1.0f, 2.0f);

		NAMESPACE::vec2 const A(R);
		NAMESPACE::vec2 const B(1.0f);

		NAMESPACE::vec2 const C(R, 23.f );

		NAMESPACE::vec2 const D(R,  3.0f);

		NAMESPACE::vec2 const E(1.0f, S);


		NAMESPACE::vec2 const G(1.0f, 2.0f);



		NAMESPACE::vec2 const I(S, T);

		NAMESPACE::vec2 const J(R,T);

		NAMESPACE::vec2 const K(R, 2.0f );


		NAMESPACE::vec2 const M(R,  3.0f);

		NAMESPACE::vec2 const N(1.0f,  T);

		NAMESPACE::vec2 const P(R, 2.0f);

	}

	{
		float R = 12012.f;
		float S = 23423;
		float T = 23;
		float U = 2e4;
		NAMESPACE::vec2 const O(1.0f, 3.0f);

		NAMESPACE::vec2 const A(R);
		NAMESPACE::vec2 const B(1.0);

		NAMESPACE::vec2 const C(R, T);

		NAMESPACE::vec2 const D(R, 2.0f);

		NAMESPACE::vec2 const E(1.0, S);

		NAMESPACE::vec2 const L(S, U);


		NAMESPACE::vec2 const Q( S, U);

		NAMESPACE::vec2 const V(R, S);
	}

	{
		NAMESPACE::vec2 const v2_0(1.0f, 2.0f);
		NAMESPACE::vec2 const v2_1(2.0f, 3.0f);
		NAMESPACE::vec2 const v2_2(3.0f, 4.0f);

		NAMESPACE::vec2 const v3_0(1.0f, 3.0f);
		NAMESPACE::vec2 const v3_1(2.0f, 3.0f);

		NAMESPACE::vec2 const O(2.0, 4.0);

		NAMESPACE::vec2 const B(v2_2);


		NAMESPACE::vec2 const H(v2_0);
	}

	{
		NAMESPACE::vec2 const v2(2.0f);

		NAMESPACE::vec2 const O( 2.0, 4.0);


		NAMESPACE::vec2 const D(v2);

	}

	return Error;
}

static int test_operators()
{
	int Error = 0;



	{
		NAMESPACE::vec2 const A(1.0f, 3.0f);
		NAMESPACE::vec2 const B(4.0f, 5.0f);

		NAMESPACE::vec2 const C = A + B;

		NAMESPACE::vec2 const D = B - A;

		NAMESPACE::vec2 const E = A * B;

//		NAMESPACE::vec2 const F = B / A;

		NAMESPACE::vec2 const G = A + 1.0f;

		NAMESPACE::vec2 const H = B - 1.0f;

		NAMESPACE::vec2 const I = A * 2.0f;

		NAMESPACE::vec2 const J = B / 2.0f;

		NAMESPACE::vec2 const K = 1.0f + A;

		NAMESPACE::vec2 const L = 1.0f - B;

		NAMESPACE::vec2 const M = 2.0f * A;

		NAMESPACE::vec2 const N = 2.0f / B;
	}

	return Error;
}


struct AoS
{
	NAMESPACE::vec2 A;
	NAMESPACE::vec2 B;
	NAMESPACE::vec2 C;
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

	std::vector<NAMESPACE::vec2> InA;
	std::vector<NAMESPACE::vec2> InB;
	std::vector<NAMESPACE::vec2> InC;
	std::vector<NAMESPACE::vec2> InD;
	std::vector<NAMESPACE::vec2> OutA;
	std::vector<NAMESPACE::vec2> OutB;
	std::vector<NAMESPACE::vec2> OutC;
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
