#include <gtest/gtest.h>
#include <zcm/quat.hpp>
#include <zcm/geometric.hpp>

using namespace zcm;

const auto first = quat(6.121f, 2.0f, 4.33f, -5.56f);
const auto second = quat(-2.3465f, -4.33f, 5.4325f, -1.0005f);
const auto scalar = 5.0f;

TEST(quat, element_access)
{
    ASSERT_FLOAT_EQ(first.x,   2.0f);
    ASSERT_FLOAT_EQ(first.y,   4.33f);
    ASSERT_FLOAT_EQ(first.z,  -5.56f);
    ASSERT_FLOAT_EQ(first.w,   6.121f);
}

TEST(quat, quat_scalar_multiplication)
{
    auto result = first * scalar;

    ASSERT_FLOAT_EQ(result.x,  10.0f);
    ASSERT_FLOAT_EQ(result.y,  21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
    ASSERT_FLOAT_EQ(result.w,  30.605f);
}

TEST(quat, scalar_quat_multiplication)
{
    auto result = scalar * first;

    ASSERT_FLOAT_EQ(result.x,  10.0f);
    ASSERT_FLOAT_EQ(result.y,  21.65f);
    ASSERT_FLOAT_EQ(result.z, -27.8f);
    ASSERT_FLOAT_EQ(result.w,  30.605f);
}

TEST(quat, quat_scalar_devision)
{
    auto result = first / scalar;

    ASSERT_FLOAT_EQ(result.x,  0.4f);
    ASSERT_FLOAT_EQ(result.y,  0.866f);
    ASSERT_FLOAT_EQ(result.z, -1.112f);
    ASSERT_FLOAT_EQ(result.w,  1.2242);
}

TEST(quat, scalar_quat_devision)
{
    auto result = scalar / first;

    ASSERT_FLOAT_EQ(result.x,  2.5f);
    ASSERT_FLOAT_EQ(result.y,  1.154734411f);
    ASSERT_FLOAT_EQ(result.z,  -0.89928057);
    ASSERT_FLOAT_EQ(result.w,  0.816859990);
}

TEST(quat, quat_addition)
{
    auto result = first + second;

    ASSERT_FLOAT_EQ(result.x, -2.33f);
    ASSERT_FLOAT_EQ(result.y,  9.7625f);
    ASSERT_FLOAT_EQ(result.z, -6.5605f);
    ASSERT_FLOAT_EQ(result.w,  3.7745f);
}

TEST(quat, quat_substraction)
{
    auto result = first - second;

    ASSERT_FLOAT_EQ(result.x,  6.33f);
    ASSERT_FLOAT_EQ(result.y, -1.1025f);
    ASSERT_FLOAT_EQ(result.z, -4.5595f);
    ASSERT_FLOAT_EQ(result.w,  8.4675f);
}

TEST(quat, quat_unar_substraction)
{
    auto result = -first;

    ASSERT_FLOAT_EQ(result.x,  -first.x);
    ASSERT_FLOAT_EQ(result.y,  -first.y);
    ASSERT_FLOAT_EQ(result.z,  -first.z);
    ASSERT_FLOAT_EQ(result.w,  -first.w);
}

TEST(quat, quat_multiplication)
{
    auto result = first * second;

    ASSERT_FLOAT_EQ(result.x,   -5.324394f);
    ASSERT_FLOAT_EQ(result.y,   49.16779f);
    ASSERT_FLOAT_EQ(result.z,   36.53638f);
    ASSERT_FLOAT_EQ(result.w,  -34.78843f);
}

TEST(quat, access)
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

TEST(quat, const_access)
{
    const auto result = first;

    ASSERT_FLOAT_EQ(result[0],  2.0);
    ASSERT_FLOAT_EQ(result[1],  4.33);
    ASSERT_FLOAT_EQ(result[2],  -5.56);
    ASSERT_FLOAT_EQ(result[3],  6.121);
}

TEST(quat, dot)
{
    auto result = dot(first,second);

    ASSERT_FLOAT_EQ(result, 6.0625785f);
}

TEST(quat, lenght)
{
    auto result = length(first);

    ASSERT_FLOAT_EQ(result,  9.54616f);
}

TEST(quat, normalize)
{
    //quat(2.0, 4.33, -5.56, 6.121)
    auto result = normalize(first);

    ASSERT_FLOAT_EQ(result.x,  0.2095083254f);
    ASSERT_FLOAT_EQ(result.y,  0.453585525f);
    ASSERT_FLOAT_EQ(result.z, -0.582433145f);
    ASSERT_FLOAT_EQ(result.w,  0.6412002312f);
}

