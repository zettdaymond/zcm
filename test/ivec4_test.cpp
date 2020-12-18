#include <gtest/gtest.h>
#include <zcm/ivec4.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/geometric.hpp>
#include <zcm/component_wise.hpp>

using namespace zcm;

const auto first = ivec4(2, 4, -5, 6);
const auto second = ivec4(-4, 5, -1, -2);
const auto scalar = 5;

TEST(ivec4, element_access)
{
    ASSERT_EQ(first.x,   2);
    ASSERT_EQ(first.y,   4);
    ASSERT_EQ(first.z,  -5);
    ASSERT_EQ(first.w,   6);
}

TEST(ivec4, ivector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_EQ(result.x,  10);
    ASSERT_EQ(result.y,  20);
    ASSERT_EQ(result.z, -25);
    ASSERT_EQ(result.w,  30);
}

TEST(ivec4, scalar_ivector_multiplication)
{
    auto result = scalar * first;

    ASSERT_EQ(result.x,  10);
    ASSERT_EQ(result.y,  20);
    ASSERT_EQ(result.z, -25);
    ASSERT_EQ(result.w,  30);
}

TEST(ivec4, ivector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_EQ(result.x,  0);
    ASSERT_EQ(result.y,  0);
    ASSERT_EQ(result.z, -1);
    ASSERT_EQ(result.w,  1);
}

TEST(ivec4, scalar_ivector_devision)
{
    auto result = scalar / first;

    ASSERT_EQ(result.x,  2);
    ASSERT_EQ(result.y,  1);
    ASSERT_EQ(result.z, -1);
    ASSERT_EQ(result.w,  0);
}

TEST(ivec4, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_EQ(result.x,   7);
    ASSERT_EQ(result.y,   9);
    ASSERT_EQ(result.z,  -0);
    ASSERT_EQ(result.w,  11);
}

TEST(ivec4, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_EQ(result.x,  -3);
    ASSERT_EQ(result.y,  -1);
    ASSERT_EQ(result.z, -10);
    ASSERT_EQ(result.w,  1);
}

TEST(ivec4, ivector_addition)
{
    auto result = first + second;

    ASSERT_EQ(result.x, -2);
    ASSERT_EQ(result.y,  9);
    ASSERT_EQ(result.z, -6);
    ASSERT_EQ(result.w,  4);
}

TEST(ivec4, ivector_substraction)
{
    auto result = first - second;

    ASSERT_EQ(result.x,  6);
    ASSERT_EQ(result.y, -1);
    ASSERT_EQ(result.z, -4);
    ASSERT_EQ(result.w,  8);
}

TEST(ivec4, ivector_unar_substraction)
{
    auto result = -first;

    ASSERT_EQ(result.x,  -first.x);
    ASSERT_EQ(result.y,  -first.y);
    ASSERT_EQ(result.z,  -first.z);
    ASSERT_EQ(result.w,  -first.w);
}

TEST(ivec4, ivector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_EQ(result.x,   -8);
    ASSERT_EQ(result.y,   20);
    ASSERT_EQ(result.z,    5);
    ASSERT_EQ(result.w,  -12);
}

TEST(ivec4, ivector_access)
{
    auto result = first;

    result[0] = 1;
    result[1] = 2;
    result[2] = 3;
    result[3] = 4;

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 2);
    ASSERT_EQ(result[2], 3);
    ASSERT_EQ(result[3], 4);
}

TEST(ivec4, ivector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  2);
    ASSERT_EQ(result[1],  4);
    ASSERT_EQ(result[2], -5);
    ASSERT_EQ(result[3],  6);
}

#ifndef ZCM_DISABLE_SWIZZLE
TEST(ivec4, shuffle)
{
    zcm::ivec2 result = first.yx;

    ASSERT_EQ(result.x,  first.y);
    ASSERT_EQ(result.y,  first.x);

    result = first.xx;

    ASSERT_EQ(result.x,  first.x);
    ASSERT_EQ(result.y,  first.x);

    result = first.yy;

    ASSERT_EQ(result.x,  first.y);
    ASSERT_EQ(result.y,  first.y);

    result = first.xy;

    ASSERT_EQ(result.x,  first.x);
    ASSERT_EQ(result.y,  first.y);

    result = first.xz;

    ASSERT_EQ(result.x,  first.x);
    ASSERT_EQ(result.y,  first.z);

    result = first.zy;

    ASSERT_EQ(result.x,  first.z);
    ASSERT_EQ(result.y,  first.y);

    zcm::ivec3 result3 = first.yxz;

    ASSERT_EQ(result3.x,  first.y);
    ASSERT_EQ(result3.y,  first.x);
    ASSERT_EQ(result3.z,  first.z);

    zcm::ivec4 result4 = first.wwxy;
    ASSERT_EQ(result4.x,  first.w);
    ASSERT_EQ(result4.y,  first.w);
    ASSERT_EQ(result4.z,  first.x);
    ASSERT_EQ(result4.w,  first.y);

}
#endif

TEST(ivec4, make) {
    int d[] = {0, 1, -1, 2};
    auto result = zcm::make_ivec4(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
    ASSERT_EQ(result[2], d[2]);
    ASSERT_EQ(result[3], d[3]);
}

//TODO: test - faceforward, reflect, refract
