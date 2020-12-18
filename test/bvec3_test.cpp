#include <gtest/gtest.h>
#include <zcm/bvec3.hpp>
using namespace zcm;

const auto first = bvec3(true, false, false);
const auto second = bvec3(false, true, false);
const auto scalar = true;

TEST(bvec3, element_access)
{
    ASSERT_EQ(first.x,   true);
    ASSERT_EQ(first.y,   false);
    ASSERT_EQ(first.z,   false);
}

TEST(bvec3, vector_and)
{
    auto result = first && second;

    ASSERT_EQ(result.x, false);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
}

TEST(bvec3, scalar_vector_and)
{
    auto result = scalar && first;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
}

TEST(bvec3, vector_scalar_and)
{
    auto result = first && scalar;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y, false);
    ASSERT_EQ(result.z, false);
}

TEST(bvec3, vector_scalar_or)
{
    auto result = first || scalar;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  true);
}

TEST(bvec3, scalar_vector_or)
{
    auto result = scalar || first;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  true);
}


TEST(bvec3, vector_or)
{
    auto result = first || second;

    ASSERT_EQ(result.x, true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
}

TEST(bvec3, vector_xor)
{
    auto result = first ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
    result = first ^ first;
    ASSERT_EQ(result,  bvec3(false));
    result = second ^ (!second);
    ASSERT_EQ(result,  bvec3(true));

}

TEST(bvec3, scalar_vector_xor)
{
    auto result = true ^ second;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);
    ASSERT_EQ(result.z,  true);

    result = false ^ second;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
}

TEST(bvec3, vector_scalar_xor)
{
    auto result = second ^ true;

    ASSERT_EQ(result.x,  true);
    ASSERT_EQ(result.y,  false);
    ASSERT_EQ(result.z,  true);

    result = second ^ false;

    ASSERT_EQ(result.x,  false);
    ASSERT_EQ(result.y,  true);
    ASSERT_EQ(result.z,  false);
}


TEST(bvec3, vector_unar_neg)
{
    auto result = !first;

    ASSERT_EQ(result.x,  !first.x);
    ASSERT_EQ(result.y,  !first.y);
    ASSERT_EQ(result.z,  !first.z);
}

TEST(bvec3, vector_access)
{
    auto result = first;

    result[0] = false;
    result[1] = false;
    result[2] = true;

    ASSERT_EQ(result[0], false);
    ASSERT_EQ(result[1], false);
    ASSERT_EQ(result[2], true);
}

TEST(bvec3, vector_const_access)
{
    const auto result = first;

    ASSERT_EQ(result[0],  true);
    ASSERT_EQ(result[1],  false);
    ASSERT_EQ(result[2],  false);
}


TEST(bvec3, vector_compare_eq)
{
    auto result = first == second;

    ASSERT_EQ(result,  false);

    result = first == first;

    ASSERT_EQ(result,  true);
}

TEST(bvec3, vector_compare_neq)
{
    auto result = first != second;

    ASSERT_EQ(result,  true);

    result = first != first;

    ASSERT_EQ(result,  false);
}

TEST(bvec3, make) {
    bool d[] = {true, false, true};
    auto result = zcm::make_bvec3(d);

    ASSERT_EQ(result[0], d[0]);
    ASSERT_EQ(result[1], d[1]);
    ASSERT_EQ(result[2], d[2]);
}
