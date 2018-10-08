#include <gtest/gtest.h>

#include "zcm/vec3.h"
#include "zcm/geometric.h"

TEST(vec3, scalar_multiplication)
{
    using namespace zcm;

    auto sample = vec3(2.0f, 4.33, -5.56);
    auto result = sample * 5;

    ASSERT_FLOAT_EQ(result.x, 10.0f);
    ASSERT_FLOAT_EQ(result.y, 21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
}

TEST(vec3, scalar_devision)
{
    using namespace zcm;

    auto sample = vec3(2.0f, 4.33, -5.56);
    auto result = sample / 5;

    ASSERT_FLOAT_EQ(result.x,  0.4f);
    ASSERT_FLOAT_EQ(result.y,  0.866f);
    ASSERT_FLOAT_EQ(result.z, -1.112f);
}

TEST(vec3, scalar_addition)
{
    using namespace zcm;

    auto sample = vec3(2.0f, 4.33, -5.56);
    auto result = sample + 5;

    ASSERT_FLOAT_EQ(result.x, 7.0f);
    ASSERT_FLOAT_EQ(result.y, 9.33f);
    ASSERT_FLOAT_EQ(result.z, -0.56f);
}

TEST(vec3, scalar_substraction)
{
    using namespace zcm;

    auto sample = vec3(2.0f, 4.33, -5.56);
    auto result = sample - 5;

    ASSERT_FLOAT_EQ(result.x, -3.0f);
    ASSERT_FLOAT_EQ(result.y, -0.67f);
    ASSERT_FLOAT_EQ(result.z, -10.56f);
}

TEST(vec3, vector_addition)
{
    using namespace zcm;

    auto first = vec3(2.0f, 4.33, -5.56);
    auto second = vec3(-4.33, 5.4325, -1.0005);
    auto result = first + second;

    ASSERT_FLOAT_EQ(result.x, -2.33f);
    ASSERT_FLOAT_EQ(result.y,  9.7625f);
    ASSERT_FLOAT_EQ(result.z, -6.5605f);
}

TEST(vec3, vector_substraction)
{
    using namespace zcm;

    auto first = vec3(2.0f, 4.33, -5.56);
    auto second = vec3(-4.33, 5.4325, -1.0005);
    auto result = first - second;

    ASSERT_FLOAT_EQ(result.x,  6.33f);
    ASSERT_FLOAT_EQ(result.y, -1.1025f);
    ASSERT_FLOAT_EQ(result.z, -4.5595f);
}

TEST(vec3, vector_per_component_multiplication)
{
    using namespace zcm;

    auto first = vec3(2.0f, 4.33, -5.56);
    auto second = vec3(-4.33, 5.4325, -1.0005);
    auto result = first * second;

    ASSERT_FLOAT_EQ(result.x, -8.66f);
    ASSERT_FLOAT_EQ(result.y,  23.522725);
    ASSERT_FLOAT_EQ(result.z,  5.56278);
}


TEST(vec3, vector_dot)
{
    using namespace zcm;

    auto first = vec3(2.0f, 4.33, -5.56);
    auto second = vec3(-4.33, 5.4325, -1.0005);
    auto result = dot(first,second);

    ASSERT_FLOAT_EQ(result, 20.425505f);
}

TEST(vec3, vector_cross)
{
    using namespace zcm;

    auto first = vec3(2.0f, 4.33, -5.56);
    auto second = vec3(-4.33, 5.4325, -1.0005);
    auto result = cross(first,second);

    ASSERT_FLOAT_EQ(result.x,  25.872535);
    ASSERT_FLOAT_EQ(result.y,  26.0758);
    ASSERT_FLOAT_EQ(result.z,  29.6139);
}

//distance
//length
//faceforward
//normalize
//reflect
//refract
