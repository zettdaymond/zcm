#include <gtest/gtest.h>

#include <zcm/vec2.hpp>
#include <zcm/geometric.hpp>

using namespace zcm;

const auto first = vec2(2.0, 4.33);
const auto second = vec2(-4.33, 5.4325);
const auto scalar = 5.0f;

TEST(vec2, element_access)
{
    ASSERT_FLOAT_EQ(first.x,   2.0f);
    ASSERT_FLOAT_EQ(first.y,   4.33f);
}

TEST(vec2, vector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_FLOAT_EQ(result.x, 10.0f);
    ASSERT_FLOAT_EQ(result.y, 21.65f);
}

TEST(vec2, scalar_vector_multiplication)
{
    auto result = scalar * first;

    ASSERT_FLOAT_EQ(result.x, 10.0f);
    ASSERT_FLOAT_EQ(result.y, 21.65f);
}

TEST(vec2, vector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_FLOAT_EQ(result.x,  0.4f);
    ASSERT_FLOAT_EQ(result.y,  0.866f);
}

TEST(vec2, scalar_vector_devision)
{
    auto result = scalar / first;

    ASSERT_FLOAT_EQ(result.x,  2.5f);
    ASSERT_FLOAT_EQ(result.y,  1.154734411f);
}

TEST(vec2, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_FLOAT_EQ(result.x, 7.0f);
    ASSERT_FLOAT_EQ(result.y, 9.33f);
}

TEST(vec2, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_FLOAT_EQ(result.x, -3.0f);
    ASSERT_FLOAT_EQ(result.y, -0.67f);
}

TEST(vec2, vector_addition)
{
    auto result = first + second;

    ASSERT_FLOAT_EQ(result.x, -2.33f);
    ASSERT_FLOAT_EQ(result.y,  9.7625f);
}

TEST(vec2, vector_substraction)
{
    auto result = first - second;

    ASSERT_FLOAT_EQ(result.x,  6.33f);
    ASSERT_FLOAT_EQ(result.y, -1.1025f);
}

TEST(vec2, vector_unar_substraction)
{
    auto result = -first;

    ASSERT_FLOAT_EQ(result.x,  -first.x);
    ASSERT_FLOAT_EQ(result.y,  -first.y);
}

TEST(vec2, vector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_FLOAT_EQ(result.x, -8.66f);
    ASSERT_FLOAT_EQ(result.y,  23.522725);
}

TEST(vec2, vector_access)
{
    auto result = first;

    result[0] = 1.0f;
    result[1] = 1.0f;

    ASSERT_FLOAT_EQ(result[0], 1.0f);
    ASSERT_FLOAT_EQ(result[1], 1.0f);
}

TEST(vec2, vector_const_access)
{
    const auto result = first;

    ASSERT_FLOAT_EQ(result[0],  2.0);
    ASSERT_FLOAT_EQ(result[1],  4.33);
}

//
// Vector operations
//

TEST(vec2, vector_dot)
{
    auto result = dot(first,second);

    ASSERT_FLOAT_EQ(result, 14.862725f);
}

TEST(vec2, vector_distance)
{
    auto result = distance(first,second);

    ASSERT_FLOAT_EQ(result,  6.425294253f);
}

TEST(vec2, vector_lenght)
{
    auto result = length(first);

    ASSERT_FLOAT_EQ(result,  4.76958f);
}

TEST(vec2, vector_normalize)
{
    auto result = normalize(first);

    ASSERT_FLOAT_EQ(result.x,  0.419324133f);
    ASSERT_FLOAT_EQ(result.y,  0.9078367f);
}

#ifndef ZCM_DISABLE_SWIZZLE
TEST(vec2, shuffle)
{
    zcm::vec2 result = first.yx;

    ASSERT_FLOAT_EQ(result.x,  first.y);
    ASSERT_FLOAT_EQ(result.y,  first.x);

    result = first.xx;

    ASSERT_FLOAT_EQ(result.x,  first.x);
    ASSERT_FLOAT_EQ(result.y,  first.x);

    result = first.yy;

    ASSERT_FLOAT_EQ(result.x,  first.y);
    ASSERT_FLOAT_EQ(result.y,  first.y);

    result = first.xy;

    ASSERT_FLOAT_EQ(result.x,  first.x);
    ASSERT_FLOAT_EQ(result.y,  first.y);
}
#endif

////TODO: test - faceforward, reflect, refract
