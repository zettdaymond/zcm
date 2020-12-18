#include <gtest/gtest.h>

#include <zcm/ivec3.hpp>
#include <zcm/ivec2.hpp>

using namespace zcm;

const auto first = ivec3(2, 4, -5);
const auto second = ivec3(-4, 5, -1);
const auto scalar = 5;

TEST(ivec3, element_access)
{
    ASSERT_EQ(first.x,   2);
    ASSERT_EQ(first.y,   4);
    ASSERT_EQ(first.z,  -5);
}

TEST(ivec3, vector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_EQ(result.x, 10);
    ASSERT_EQ(result.y, 20);
    ASSERT_EQ(result.z, -25);
}

TEST(ivec3, scalar_vector_multiplication)
{
    auto result = scalar * first;

    ASSERT_EQ(result.x, 10);
    ASSERT_EQ(result.y, 20);
    ASSERT_EQ(result.z, -25);
}

TEST(ivec3, vector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_EQ(result.x,  0);
    ASSERT_EQ(result.y,  0);
    ASSERT_EQ(result.z, -1);
}

TEST(ivec3, scalar_vector_devision)
{
    auto result = scalar / first;

    ASSERT_EQ(result.x,  2);
    ASSERT_EQ(result.y,  1);
    ASSERT_EQ(result.z,  -1);
}

TEST(ivec3, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_EQ(result.x, 7);
    ASSERT_EQ(result.y, 9);
    ASSERT_EQ(result.z, 0);
}

TEST(ivec3, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_EQ(result.x, -3);
    ASSERT_EQ(result.y, -1);
    ASSERT_EQ(result.z, -10);
}

TEST(ivec3, vector_addition)
{
    auto result = first + second;

    ASSERT_EQ(result.x, -2);
    ASSERT_EQ(result.y,  9);
    ASSERT_EQ(result.z, -6);
}

TEST(ivec3, vector_substraction)
{
    auto result = first - second;

    ASSERT_EQ(result.x,  6);
    ASSERT_EQ(result.y, -1);
    ASSERT_EQ(result.z, -4);
}

TEST(ivec3, vector_unar_substraction)
{
    auto result = -first;

    ASSERT_EQ(result.x,  -first.x);
    ASSERT_EQ(result.y,  -first.y);
    ASSERT_EQ(result.z,  -first.z);
}

TEST(ivec3, vector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_EQ(result.x, -8);
    ASSERT_EQ(result.y,  20);
    ASSERT_EQ(result.z,  5);
}

TEST(ivec3, vector_access)
{
    auto result = first;

    result[0] = 1;
    result[1] = 2;
    result[2] = 3;

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 2);
    ASSERT_EQ(result[2], 3);
}

TEST(ivec3, vector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  2);
    ASSERT_EQ(result[1],  4);
    ASSERT_EQ(result[2],  -5);
}

#ifndef ZCM_DISABLE_SWIZZLE
TEST(ivec3, shuffle)
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

}
#endif

TEST(ivec3, make) {
    int d[] = {0, 1, -1};
    auto result = zcm::make_ivec3(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
    ASSERT_EQ(result[2], d[2]);
}

//TODO: test - faceforward, reflect, refract
