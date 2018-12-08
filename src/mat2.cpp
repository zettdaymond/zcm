#include <cassert>
#include <type_traits>
#include <zcm/mat2.hpp>
#include <zcm/mat3.hpp>


static_assert(std::is_standard_layout<zcm::mat2>::value, "");

zcm::mat2::mat2() : mat2(1.0f)
{}

zcm::mat2::mat2(float value)
{
    _columns[0] = vec2(value, 0.0f);
    _columns[1] = vec2(0.0f, value);
}

zcm::mat2::mat2(float a00, float a01, float a10, float a11)
{
    _columns[0].x = a00;
    _columns[0].y = a01;
    _columns[1].x = a10;
    _columns[1].y = a11;
}

zcm::mat2::mat2(zcm::vec2 col0, zcm::vec2 col1)
{
    _columns[0] = col0;
    _columns[1] = col1;
}

zcm::vec2& zcm::mat2::operator[](unsigned pos)
{
    assert(pos < 2);
    return _columns[pos];
}

zcm::vec2 zcm::mat2::operator[](unsigned pos) const
{
    assert(pos < 2);
    return _columns[pos];
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

zcm::mat2 zcm::operator *(const zcm::mat2& mat, float scalar)
{
    return { mat[0] * scalar,
             mat[1] * scalar };
}

zcm::mat2 zcm::operator /(const zcm::mat2& mat, float scalar)
{
    return { mat[0] / scalar,
             mat[1] / scalar };
}

zcm::mat2 zcm::operator *(float scalar, const zcm::mat2& mat)
{
    return { scalar * mat[0],
             scalar * mat[1] };
}

zcm::mat2 zcm::operator /(float scalar, const zcm::mat2& mat)
{
    return { scalar / mat[0],
             scalar / mat[1] };
}
