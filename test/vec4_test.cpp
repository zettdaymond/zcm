#include <gtest/gtest.h>
#include <zcm/vec4.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/geometric.hpp>
#include <zcm/common.hpp>
#include <zcm/component_wise.hpp>

using namespace zcm;

const auto first = vec4(2.0, 4.33, -5.56, 6.121);
const auto second = vec4(-4.33, 5.4325, -1.0005, -2.3465);
const auto scalar = 5.0f;

TEST(vec4, element_access)
{
    ASSERT_FLOAT_EQ(first.x,   2.0f);
    ASSERT_FLOAT_EQ(first.y,   4.33f);
    ASSERT_FLOAT_EQ(first.z,  -5.56f);
    ASSERT_FLOAT_EQ(first.w,   6.121f);
}

TEST(vec4, vector_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_FLOAT_EQ(result.x,  10.0f);
    ASSERT_FLOAT_EQ(result.y,  21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
    ASSERT_FLOAT_EQ(result.w,  30.605f);
}

TEST(vec4, scalar_vector_multiplication)
{
    auto result = scalar * first;

    ASSERT_FLOAT_EQ(result.x,  10.0f);
    ASSERT_FLOAT_EQ(result.y,  21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
    ASSERT_FLOAT_EQ(result.w,  30.605f);
}

TEST(vec4, vector_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_FLOAT_EQ(result.x,  0.4f);
    ASSERT_FLOAT_EQ(result.y,  0.866f);
    ASSERT_FLOAT_EQ(result.z, -1.112f);
    ASSERT_FLOAT_EQ(result.w,  1.2242);
}

TEST(vec4, scalar_vector_devision)
{
    auto result = scalar / first;

    ASSERT_FLOAT_EQ(result.x,  2.5f);
    ASSERT_FLOAT_EQ(result.y,  1.154734411f);
    ASSERT_FLOAT_EQ(result.z,  -0.89928057);
    ASSERT_FLOAT_EQ(result.w,  0.816859990);
}

TEST(vec4, scalar_addition)
{
    auto result = first + scalar;

    ASSERT_FLOAT_EQ(result.x,   7.0f);
    ASSERT_FLOAT_EQ(result.y,   9.33f);
    ASSERT_FLOAT_EQ(result.z,  -0.56f);
    ASSERT_FLOAT_EQ(result.w,  11.121f);
}

TEST(vec4, scalar_substraction)
{
    auto result = first - scalar;

    ASSERT_FLOAT_EQ(result.x, -3.0f);
    ASSERT_FLOAT_EQ(result.y, -0.67f);
    ASSERT_FLOAT_EQ(result.z, -10.56f);
    ASSERT_FLOAT_EQ(result.w,  1.121f);
}

TEST(vec4, vector_addition)
{
    auto result = first + second;

    ASSERT_FLOAT_EQ(result.x, -2.33f);
    ASSERT_FLOAT_EQ(result.y,  9.7625f);
    ASSERT_FLOAT_EQ(result.z, -6.5605f);
    ASSERT_FLOAT_EQ(result.w,  3.7745f);
}

TEST(vec4, vector_substraction)
{
    auto result = first - second;

    ASSERT_FLOAT_EQ(result.x,  6.33f);
    ASSERT_FLOAT_EQ(result.y, -1.1025f);
    ASSERT_FLOAT_EQ(result.z, -4.5595f);
    ASSERT_FLOAT_EQ(result.w,  8.4675f);
}

TEST(vec4, vector_unar_substraction)
{
    auto result = -first;

    ASSERT_FLOAT_EQ(result.x,  -first.x);
    ASSERT_FLOAT_EQ(result.y,  -first.y);
    ASSERT_FLOAT_EQ(result.z,  -first.z);
    ASSERT_FLOAT_EQ(result.w,  -first.w);
}

TEST(vec4, vector_per_component_multiplication)
{
    auto result = first * second;

    ASSERT_FLOAT_EQ(result.x, -8.66f);
    ASSERT_FLOAT_EQ(result.y,  23.522725);
    ASSERT_FLOAT_EQ(result.z,  5.56278);
    ASSERT_FLOAT_EQ(result.w,  -14.3629265);
}

TEST(vec4, vector_access)
{
    auto result = first;

    result[0] = 1.0f;
    result[1] = 1.0f;
    result[2] = 1.0f;
    result[3] = 1.0f;

    ASSERT_FLOAT_EQ(result[0], 1.0f);
    ASSERT_FLOAT_EQ(result[1], 1.0f);
    ASSERT_FLOAT_EQ(result[2], 1.0f);
    ASSERT_FLOAT_EQ(result[3], 1.0f);
}

TEST(vec4, vector_const_access)
{
    const auto result = first;

    ASSERT_FLOAT_EQ(result[0],  2.0);
    ASSERT_FLOAT_EQ(result[1],  4.33);
    ASSERT_FLOAT_EQ(result[2],  -5.56);
    ASSERT_FLOAT_EQ(result[3],  6.121);
}

//
// Vector operations
//

TEST(vec4, vector_dot)
{
    auto result = dot(first,second);

    ASSERT_FLOAT_EQ(result, 6.0625785f);
}

TEST(vec4, vector_distance)
{
    auto result = distance(first,second);

    ASSERT_FLOAT_EQ(result,  11.56598472893f);
}

TEST(vec4, vector_lenght)
{
    auto result = length(first);

    ASSERT_FLOAT_EQ(result,  9.54616f);
}

TEST(vec4, vector_normalize)
{
    //vec4(2.0, 4.33, -5.56, 6.121)
    auto result = normalize(first);

    ASSERT_FLOAT_EQ(result.x,  0.2095083254f);
    ASSERT_FLOAT_EQ(result.y,  0.453585525f);
    ASSERT_FLOAT_EQ(result.z, -0.582433145f);
    ASSERT_FLOAT_EQ(result.w,  0.6412002312f);
}

TEST(vec4, vector_component_wise)
{
    auto v = vec4{1.0f, 2.0f, 3.0f, 4.0f};

    ASSERT_FLOAT_EQ(compMin(v), 1.0f);
    ASSERT_FLOAT_EQ(compMax(v), 4.0f);
    ASSERT_FLOAT_EQ(compAdd(v), 10.0f);
    ASSERT_FLOAT_EQ(compMul(v), 24.0f);
}

#ifndef ZCM_DISABLE_SWIZZLE
TEST(vec4, shuffle)
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

    zcm::vec4 result4 = first.wwxy;
    ASSERT_FLOAT_EQ(result4.x,  first.w);
    ASSERT_FLOAT_EQ(result4.y,  first.w);
    ASSERT_FLOAT_EQ(result4.z,  first.x);
    ASSERT_FLOAT_EQ(result4.w,  first.y);

    auto res = zcm::mix(result3, result4.xzy, 1.0f);
    ASSERT_FLOAT_EQ(res.x, result4.x);
    ASSERT_FLOAT_EQ(res.y, result4.z);
    ASSERT_FLOAT_EQ(res.z, result4.y);
}
#endif

TEST(vec4, make) {
    float d[] = {0.0f, 1.0f, -1.0f, 2.0f};
    auto result = zcm::make_vec4(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
    ASSERT_EQ(result[2], d[2]);
    ASSERT_EQ(result[3], d[3]);
}

//TODO: test - faceforward, reflect, refract
