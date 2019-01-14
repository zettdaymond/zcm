#include <gtest/gtest.h>

#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/geometric.hpp>

using namespace zcm;

const auto first = vec3(2.0f, 4.33, -5.56);
const auto second = vec3(-4.33, 5.4325, -1.0005);
const auto scalar = 5.0f;

TEST(vec3, element_access)
{
    ASSERT_FLOAT_EQ(first.x,   2.0f);
    ASSERT_FLOAT_EQ(first.y,   4.33f);
    ASSERT_FLOAT_EQ(first.z,  -5.56f);
}

TEST(vec3, vector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_FLOAT_EQ(result.x, 10.0f);
    ASSERT_FLOAT_EQ(result.y, 21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
}

TEST(vec3, scalar_vector_multiplication)
{
    auto result = scalar * first;

    ASSERT_FLOAT_EQ(result.x, 10.0f);
    ASSERT_FLOAT_EQ(result.y, 21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
}

TEST(vec3, vector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_FLOAT_EQ(result.x,  0.4f);
    ASSERT_FLOAT_EQ(result.y,  0.866f);
    ASSERT_FLOAT_EQ(result.z, -1.112f);
}

TEST(vec3, scalar_vector_devision)
{
    auto result = scalar / first;

    ASSERT_FLOAT_EQ(result.x,  2.5f);
    ASSERT_FLOAT_EQ(result.y,  1.154734411f);
    ASSERT_FLOAT_EQ(result.z,  -0.89928057);
}

TEST(vec3, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_FLOAT_EQ(result.x, 7.0f);
    ASSERT_FLOAT_EQ(result.y, 9.33f);
    ASSERT_FLOAT_EQ(result.z, -0.56f);
}

TEST(vec3, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_FLOAT_EQ(result.x, -3.0f);
    ASSERT_FLOAT_EQ(result.y, -0.67f);
    ASSERT_FLOAT_EQ(result.z, -10.56f);
}

TEST(vec3, vector_addition)
{
    auto result = first + second;

    ASSERT_FLOAT_EQ(result.x, -2.33f);
    ASSERT_FLOAT_EQ(result.y,  9.7625f);
    ASSERT_FLOAT_EQ(result.z, -6.5605f);
}

TEST(vec3, vector_substraction)
{
    auto result = first - second;

    ASSERT_FLOAT_EQ(result.x,  6.33f);
    ASSERT_FLOAT_EQ(result.y, -1.1025f);
    ASSERT_FLOAT_EQ(result.z, -4.5595f);
}

TEST(vec3, vector_unar_substraction)
{
    auto result = -first;

    ASSERT_FLOAT_EQ(result.x,  -first.x);
    ASSERT_FLOAT_EQ(result.y,  -first.y);
    ASSERT_FLOAT_EQ(result.z,  -first.z);
}

TEST(vec3, vector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_FLOAT_EQ(result.x, -8.66f);
    ASSERT_FLOAT_EQ(result.y,  23.522725);
    ASSERT_FLOAT_EQ(result.z,  5.56278);
}

TEST(vec3, vector_access)
{
    auto result = first;

    result[0] = 1.0f;
    result[1] = 1.0f;
    result[2] = 1.0f;

    ASSERT_FLOAT_EQ(result[0], 1.0f);
    ASSERT_FLOAT_EQ(result[1], 1.0f);
    ASSERT_FLOAT_EQ(result[2], 1.0f);
}

TEST(vec3, vector_const_access)
{
    const auto result = first;

    ASSERT_FLOAT_EQ(result[0],  2.0);
    ASSERT_FLOAT_EQ(result[1],  4.33);
    ASSERT_FLOAT_EQ(result[2],  -5.56);
}

//
// Vector operations
//

TEST(vec3, vector_dot)
{
    auto result = dot(first,second);

    ASSERT_FLOAT_EQ(result, 20.425505f);
}

TEST(vec3, vector_cross)
{
    auto result = cross(first,second);

    ASSERT_FLOAT_EQ(result.x,  25.872535);
    ASSERT_FLOAT_EQ(result.y,  26.0758);
    ASSERT_FLOAT_EQ(result.z,  29.6139);
}

TEST(vec3, vector_distance)
{
    auto result = distance(first,second);

    ASSERT_FLOAT_EQ(result,  7.8786697f);
}

TEST(vec3, vector_lenght)
{
    auto result = length(first);

    ASSERT_FLOAT_EQ(result,  7.32547);
}

TEST(vec3, vector_normalize)
{
    auto result = normalize(first);

    ASSERT_FLOAT_EQ(result.x,  0.2730200246537f);
    ASSERT_FLOAT_EQ(result.y,  0.5910883533752f);
    ASSERT_FLOAT_EQ(result.z,  -0.758995668537f);
}

TEST(vec3, shuffle)
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

    result = first.xz;

    ASSERT_FLOAT_EQ(result.x,  first.x);
    ASSERT_FLOAT_EQ(result.y,  first.z);

    result = first.zy;

    ASSERT_FLOAT_EQ(result.x,  first.z);
    ASSERT_FLOAT_EQ(result.y,  first.y);

    zcm::vec3 result3 = first.yxz;

    ASSERT_FLOAT_EQ(result3.x,  first.y);
    ASSERT_FLOAT_EQ(result3.y,  first.x);
    ASSERT_FLOAT_EQ(result3.z,  first.z);

}

//TODO: test - faceforward, reflect, refract
