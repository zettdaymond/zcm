#include <gtest/gtest.h>
#include <zcm/bvec2.hpp>
using namespace zcm;

const auto first = bvec2(true, false);
const auto second = bvec2(false, true);
const auto scalar = true;

TEST(bvec2, element_access)
{
    ASSERT_EQ(first.x,   true);
    ASSERT_EQ(first.y,   false);
}

TEST(bvec2, vector_and)
{
    auto result = first && second;

    ASSERT_EQ(result.x, false);
    ASSERT_EQ(result.y, false);
}

TEST(bvec2, scalar_vector_and)
{
    auto result = scalar && first;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
}

TEST(bvec2, vector_scalar_and)
{
    auto result = first && scalar;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
}

TEST(bvec2, vector_scalar_or)
{
    auto result = first || scalar;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
}

TEST(bvec2, scalar_vector_or)
{
    auto result = scalar || first;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
}


TEST(bvec2, vector_or)
{
    auto result = first || second;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y,  true);
}

TEST(bvec2, vector_xor)
{
    auto result = first ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    result = first ^ first;
    ASSERT_EQ(result,  bvec2(false));
    result = second ^ (!second);
    ASSERT_EQ(result,  bvec2(true));

}

TEST(bvec2, scalar_vector_xor)
{
    auto result = true ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);

    result = false ^ second;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
}

TEST(bvec2, vector_scalar_xor)
{
    auto result = second ^ true;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);

    result = second ^ false;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
}


TEST(bvec2, vector_unar_neg)
{
    auto result = !first;

    ASSERT_EQ(result.x,  !first.x);
    ASSERT_EQ(result.y,  !first.y);
}

TEST(bvec2, vector_access)
{
    auto result = first;

    result[0] = false;
    result[1] = false;

    ASSERT_EQ(result[0], false);
    ASSERT_EQ(result[1], false);
}

TEST(bvec2, vector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  true);
    ASSERT_EQ(result[1],  false);
}


TEST(bvec2, vector_compare_eq)
{
    auto result = first == second;

    ASSERT_EQ(result,  false);

    result = first == first;

    ASSERT_EQ(result,  true);
}

TEST(bvec2, vector_compare_neq)
{
    auto result = first != second;

    ASSERT_EQ(result,  true);

    result = first != first;

    ASSERT_EQ(result,  false);
}
