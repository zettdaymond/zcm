#include <gtest/gtest.h>
#include <zcm/quat.hpp>
#include <zcm/geometric.hpp>
#include <zcm/common.hpp>
#include <zcm/bvec4.hpp>
#include <zcm/exponential.hpp>
#include <cmath>

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

TEST(quat, isnan)
{
    auto result = isnan(first);
    EXPECT_EQ(zcm::any(result), false);

    auto tmp = first;
    tmp.x = NAN;

    result = zcm::bvec4{true, false, false, false};

    EXPECT_EQ(zcm::isnan(tmp), result);
}

TEST(quat, isinf)
{
    auto result = isinf(first);
    EXPECT_EQ(zcm::any(result), false);

    auto tmp = first;
    tmp.y = INFINITY;
    tmp.x = -INFINITY;

    result = zcm::bvec4{true, true, false, false};

    EXPECT_EQ(zcm::isinf(tmp), result);
}

TEST(quat, equal)
{
    auto result = equal(first, first);
    EXPECT_EQ(zcm::all(result), true);

    auto tmp = first;
    tmp.x = 12312412;
    result = zcm::bvec4{false, true, true, true};
    EXPECT_EQ(zcm::equal(first, tmp), result);

}

TEST(quat, make) {
    float d[] = {0.0f, 1.0f, -1.0f, 2.0f};
    auto result = zcm::make_quat(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
    ASSERT_EQ(result[2], d[2]);
    ASSERT_EQ(result[3], d[3]);
}

TEST(quat, sqrt) {
    float s[] = { zcm::sqrt(2.0f), zcm::sqrt(3.0f), zcm::sqrt(4.0f), zcm::sqrt(5.0f) };
    auto result = zcm::sqrt(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, cbrt) {
    float s[] = { zcm::cbrt(2.0f), zcm::cbrt(3.0f), zcm::cbrt(4.0f), zcm::cbrt(5.0f) };
    auto result = zcm::cbrt(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, pow) {
    float s[] = { zcm::pow(2.0f, 1.5f), zcm::pow(3.0f, 1.5f), zcm::pow(4.0f, 1.5f), zcm::pow(5.0f, 1.5f) };
    auto result = zcm::pow(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f), 1.5f);
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, exp) {
    float s[] = { zcm::exp(2.0f), zcm::exp(3.0f), zcm::exp(4.0f), zcm::exp(5.0f) };
    auto result = zcm::exp(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, log) {
    float s[] = { zcm::log(2.0f), zcm::log(3.0f), zcm::log(4.0f), zcm::log(5.0f) };
    auto result = zcm::log(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, log2) {
    float s[] = { zcm::log2(2.0f), zcm::log2(3.0f), zcm::log2(4.0f), zcm::log2(5.0f) };
    auto result = zcm::log2(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, exp2) {
    float s[] = { zcm::exp2(2.0f), zcm::exp2(3.0f), zcm::exp2(4.0f), zcm::exp2(5.0f) };
    auto result = zcm::exp2(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

TEST(quat, inversesqrt) {
    float s[] = { zcm::inversesqrt(2.0f), zcm::inversesqrt(3.0f), zcm::inversesqrt(4.0f), zcm::inversesqrt(5.0f) };
    auto result = zcm::inversesqrt(zcm::quat::wxyz(5.0f, 2.0f, 3.0f, 4.0f));
    ASSERT_EQ(result, make_quat(s));
}

