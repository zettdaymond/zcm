#include <cassert>
#include <type_traits>
#include <zcm/mat2.hpp>

static_assert(std::is_standard_layout<zcm::mat2>::value, "");

zcm::mat2::mat2(float value) :
    col0(value, 0.0f),
    col1(0.0f, value)
{}
zcm::mat2::mat2(float a00, float a01, float a10, float a11) :
    col0{a00, a10},
    col1{a01, a11}
{}
zcm::mat2::mat2(zcm::vec2 _col0, zcm::vec2 _col1) :
    col0{_col0},
    col1{_col1}
{}

zcm::vec2& zcm::mat2::operator[](unsigned pos)
{
    assert(pos < 2);
    if(pos == 0) {
        return col0;
    }
    else {
        return col1;
    }
}

const zcm::vec2& zcm::mat2::operator[](unsigned pos) const
{
    assert(pos < 2);
    if(pos == 0) {
        return col0;
    }
    else {
        return col1;
    }
}

zcm::mat2 zcm::operator +(const zcm::mat2& first, const zcm::mat2& second)
{
    return { first[0] + second[0],
             first[1] + second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first, const zcm::mat2& second)
{
    return { first[0] - second[0],
             first[1] - second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first)
{
    return { -first[0],
             -first[1] };
}

zcm::mat2 zcm::operator *(const zcm::mat2& m1, const zcm::mat2& m2)
{
    return mat2(
        m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1]);
}

zcm::mat2 zcm::operator *(const zcm::mat2& mat, const float scalar)
{
    return { mat[0] * scalar,
             mat[1] * scalar };
}

zcm::mat2 zcm::operator /(const zcm::mat2& mat, const float scalar)
{
    return { mat[0] / scalar,
             mat[1] / scalar };
}

zcm::mat2 zcm::operator *(const float scalar, const zcm::mat2& mat)
{
    return { scalar * mat[0],
             scalar * mat[1] };
}

zcm::mat2 zcm::operator /(const float scalar, const zcm::mat2& mat)
{
    return { scalar / mat[0],
             scalar / mat[1] };
}
