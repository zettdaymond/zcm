#include <gtest/gtest.h>

#include <zcm/ivec2.hpp>

using namespace zcm;

const auto first = ivec2(2, 4);
const auto second = ivec2(-4, 5);
const auto scalar = 5;

TEST(ivec2, element_access)
{
    ASSERT_EQ(first.x,   2);
    ASSERT_EQ(first.y,   4);
}

TEST(ivec2, vector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_EQ(result.x, 10);
    ASSERT_EQ(result.y, 20);
}

TEST(ivec2, scalar_vector_multiplication)
{
    auto result = scalar * first;

    ASSERT_EQ(result.x, 10);
    ASSERT_EQ(result.y, 20);
}

TEST(ivec2, vector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_EQ(result.x,  0);
    ASSERT_EQ(result.y,  0);
}

TEST(ivec2, scalar_vector_devision)
{
    auto result = scalar / first;

    ASSERT_EQ(result.x,  2);
    ASSERT_EQ(result.y,  1);
}

TEST(ivec2, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_EQ(result.x, 7);
    ASSERT_EQ(result.y, 9);
}

TEST(ivec2, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_EQ(result.x, -3);
    ASSERT_EQ(result.y, -1);
}

TEST(ivec2, vector_addition)
{
    auto result = first + second;

    ASSERT_EQ(result.x, -2);
    ASSERT_EQ(result.y,  9);
}

TEST(ivec2, vector_substraction)
{
    auto result = first - second;

    ASSERT_EQ(result.x,  6);
    ASSERT_EQ(result.y, -1);
}

TEST(ivec2, vector_unar_substraction)
{
    auto result = -first;

    ASSERT_EQ(result.x,  -first.x);
    ASSERT_EQ(result.y,  -first.y);
}

TEST(ivec2, vector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_EQ(result.x, -8);
    ASSERT_EQ(result.y,  20);
}

TEST(ivec2, vector_access)
{
    auto result = first;

    result[0] = 1;
    result[1] = 1;

    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
}

TEST(ivec2, vector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  2);
    ASSERT_EQ(result[1],  4);
}

#ifndef ZCM_DISABLE_SWIZZLE
TEST(ivec2, shuffle)
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
}
#endif

TEST(ivec2, make) {
    int d[] = {0, 1};
    auto result = zcm::make_ivec2(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
}

////TODO: test - faceforward, reflect, refract
