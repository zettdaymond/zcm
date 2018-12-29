#include <cassert>
#include <type_traits>
#include <zcm/mat2.hpp>
#include <zcm/mat3.hpp>
#include <zcm/matrix.hpp>


static_assert(std::is_standard_layout<zcm::mat2>::value, "");

zcm::mat2::mat2() noexcept : mat2(1.0f)
{}

zcm::mat2::mat2(float value) noexcept
{
    _columns[0] = vec2(value, 0.0f);
    _columns[1] = vec2(0.0f, value);
}

zcm::mat2::mat2(float a00, float a01, float a10, float a11) noexcept
{
    _columns[0].x = a00;
    _columns[0].y = a01;
    _columns[1].x = a10;
    _columns[1].y = a11;
}

zcm::mat2::mat2(zcm::vec2 col0, zcm::vec2 col1) noexcept
{
    _columns[0] = col0;
    _columns[1] = col1;
}

zcm::vec2& zcm::mat2::operator[](unsigned pos) noexcept
{
    assert(pos < 2);
    return _columns[pos];
}

zcm::vec2 zcm::mat2::operator[](unsigned pos) const noexcept
{
    assert(pos < 2);
    return _columns[pos];
}

zcm::mat2 zcm::operator +(const zcm::mat2& first, const zcm::mat2& second) noexcept
{
    return { first[0] + second[0],
             first[1] + second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first, const zcm::mat2& second) noexcept
{
    return { first[0] - second[0],
             first[1] - second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first) noexcept
{
    return { -first[0],
             -first[1] };
}

zcm::mat2 zcm::operator +(const zcm::mat2 &first) noexcept
{
    return first;
}


zcm::mat2 zcm::operator *(const zcm::mat2& m1, const zcm::mat2& m2) noexcept
{
    return mat2(
        m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1]);
}


zcm::mat2 zcm::operator /(const zcm::mat2 &first, const zcm::mat2 &second) noexcept
{
    return first * inverse(second);
}


zcm::mat2 zcm::operator *(const zcm::mat2& mat, float scalar) noexcept
{
    return { mat[0] * scalar,
             mat[1] * scalar };
}

zcm::mat2 zcm::operator /(const zcm::mat2& mat, float scalar) noexcept
{
    return { mat[0] / scalar,
             mat[1] / scalar };
}

zcm::mat2 zcm::operator *(float scalar, const zcm::mat2& mat) noexcept
{
    return { scalar * mat[0],
             scalar * mat[1] };
}

zcm::mat2 zcm::operator /(float scalar, const zcm::mat2& mat) noexcept
{
    return { scalar / mat[0],
             scalar / mat[1] };
}

zcm::vec2 zcm::operator *(const zcm::mat2 &m, const zcm::vec2 &v) noexcept
{
    return { m[0][0] * v.x + m[1][0] * v.y,
             m[0][1] * v.x + m[1][1] * v.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2 &v, const zcm::mat2 &m) noexcept
{
    return { v.x * m[0][0] + v.y * m[0][1],
             v.x * m[1][0] + v.y * m[1][1] };
}

zcm::vec2 zcm::operator /(const zcm::mat2 &mat, const zcm::vec2 &vec) noexcept
{
    return inverse(mat) * vec;
}

zcm::vec2 zcm::operator /(const zcm::vec2 &vec, const zcm::mat2 &mat) noexcept
{
    return vec * inverse(mat);
}

void zcm::mat2::operator+=(const zcm::mat2 &first) noexcept
{
    *this = *this + first;
}

void zcm::mat2::operator-=(const zcm::mat2 &first) noexcept
{
    *this = *this - first;
}

void zcm::mat2::operator*=(const zcm::mat2 &first) noexcept
{
    *this = *this * first;
}

void zcm::mat2::operator/=(const zcm::mat2 &first) noexcept
{
    *this = *this / first;
}

bool zcm::operator ==(const zcm::mat2 &first, const zcm::mat2 &second) noexcept
{
    return first[0] == second[0] && first[1] == second[1];
}

bool zcm::operator !=(const zcm::mat2 &first, const zcm::mat2 &second) noexcept
{
    return !(first == second);
}


