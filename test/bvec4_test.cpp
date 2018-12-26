#include <gtest/gtest.h>
#include <zcm/bvec4.hpp>
using namespace zcm;

const auto first = bvec4(true, false, false, true);
const auto second = bvec4(false, true, false, true);
const auto scalar = true;

TEST(bvec4, element_access)
{
    ASSERT_EQ(first.x,   true);
    ASSERT_EQ(first.y,   false);
    ASSERT_EQ(first.z,   false);
    ASSERT_EQ(first.w,   true);
}

TEST(bvec4, vector_and)
{
    auto result = first && second;

    ASSERT_EQ(result.x, false);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
    ASSERT_EQ(result.w, true);
}

TEST(bvec4, scalar_vector_and)
{
    auto result = scalar && first;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
    ASSERT_EQ(result.w, true);
}

TEST(bvec4, vector_scalar_and)
{
    auto result = first && scalar;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
    ASSERT_EQ(result.w, true);
}

TEST(bvec4, vector_scalar_or)
{
    auto result = first || scalar;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  true);
    ASSERT_EQ(result.w,  true);
}

TEST(bvec4, scalar_vector_or)
{
    auto result = scalar || first;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  true);
    ASSERT_EQ(result.w,  true);
}


TEST(bvec4, vector_or)
{
    auto result = first || second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
    ASSERT_EQ(result.w,  true);
}

TEST(bvec4, vector_xor)
{
    auto result = first ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
    ASSERT_EQ(result.w,  false);
    result = first ^ first;
    ASSERT_EQ(result,  bvec4(false));
    result = second ^ (!second);
    ASSERT_EQ(result,  bvec4(true));

}

TEST(bvec4, scalar_vector_xor)
{
    auto result = true ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);
    ASSERT_EQ(result.z,  true);
    ASSERT_EQ(result.w,  false);

    result = false ^ second;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
    ASSERT_EQ(result.w,  true);
}

TEST(bvec4, vector_scalar_xor)
{
    auto result = second ^ true;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);
    ASSERT_EQ(result.z,  true);
    ASSERT_EQ(result.w,  false);

    result = second ^ false;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
    ASSERT_EQ(result.w,  true);
}


TEST(bvec4, vector_unar_neg)
{
    auto result = !first;

    ASSERT_EQ(result.x,  !first.x);
    ASSERT_EQ(result.y,  !first.y);
    ASSERT_EQ(result.z,  !first.z);
    ASSERT_EQ(result.w,  !first.w);
}

TEST(bvec4, vector_access)
{
    auto result = first;

    result[0] = false;
    result[1] = false;
    result[2] = true;
    result[3] = false;

    ASSERT_EQ(result[0], false);
    ASSERT_EQ(result[1], false);
    ASSERT_EQ(result[2], true);
    ASSERT_EQ(result[3], false);
}

TEST(bvec4, vector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  true);
    ASSERT_EQ(result[1],  false);
    ASSERT_EQ(result[2],  false);
    ASSERT_EQ(result[3],  true);
}


TEST(bvec4, vector_compare_eq)
{
    auto result = first == second;

    ASSERT_EQ(result,  false);

    result = first == first;

    ASSERT_EQ(result,  true);
}

TEST(bvec4, vector_compare_neq)
{
    auto result = first != second;

    ASSERT_EQ(result,  true);

    result = first != first;

    ASSERT_EQ(result,  false);
}
