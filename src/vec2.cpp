#include <cassert>
#include <type_traits>
#include <zcm/vec2.hpp>


static_assert (std::is_standard_layout<zcm::vec2>::value, "");
static_assert(sizeof(zcm::vec2) == 2 * sizeof(float), "extra padding detected!");

zcm::vec2::vec2() noexcept :
    vec2(0.0f)
{}
zcm::vec2::vec2(float value) noexcept
{
    _data[0] = value;
    _data[1] = value;
}

zcm::vec2::vec2(float _x, float _y) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
}

zcm::vec2 zcm::operator +(const zcm::vec2& first, const zcm::vec2& second) noexcept
{
    return { first.x + second.x,
             first.y + second.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first, const vec2& second) noexcept
{
    return { first.x - second.x,
             first.y - second.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2& first, const zcm::vec2& second) noexcept
{
    return { first.x * second.x,
             first.y * second.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2& vec, const float scalar) noexcept
{
    return { vec.x * scalar,
             vec.y * scalar };
}

zcm::vec2 zcm::operator *(const float scalar, const zcm::vec2& vec) noexcept
{
    return { scalar * vec.x,
             scalar * vec.y };
}


zcm::vec2 zcm::operator /(const zcm::vec2& first, const zcm::vec2& second) noexcept
{
    return { first.x / second.x,
             first.y / second.y };
}


zcm::vec2 zcm::operator /(const zcm::vec2& vec, const float scalar) noexcept
{
    return { vec.x / scalar,
             vec.y / scalar };
}

zcm::vec2 zcm::operator /(const float scalar, const zcm::vec2& vec) noexcept
{
    return { scalar / vec.x,
             scalar / vec.y };
}


zcm::vec2 zcm::operator +(const zcm::vec2& first) noexcept
{
    return { +first.x,
             +first.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first) noexcept
{
    return { -first.x,
             -first.y };
}

void zcm::vec2::operator +=(const zcm::vec2 &other) noexcept
{
    x += other.x;
    y += other.y;
}

void zcm::vec2::operator -=(const zcm::vec2 &other) noexcept
{
    x -= other.x;
    y -= other.y;
}

void zcm::vec2::operator *=(const zcm::vec2 &other) noexcept
{
    x *= other.x;
    y *= other.y;
}

void zcm::vec2::operator/=(const vec2 &other) noexcept
{
    x /= other.x;
    y /= other.y;
}

void zcm::vec2::operator +=(float scalar) noexcept
{
    x += scalar;
    y += scalar;
}

void zcm::vec2::operator -=(float scalar) noexcept
{
    x -= scalar;
    y -= scalar;
}

void zcm::vec2::operator *=(float scalar) noexcept
{
    x *= scalar;
    y *= scalar;
}

void zcm::vec2::operator /=(float scalar) noexcept
{
    x /= scalar;
    y /= scalar;
}

bool zcm::operator==(const zcm::vec2 &first, const zcm::vec2 &second) noexcept
{
    return first.x == second.x && first.y == second.y;
}

bool zcm::operator!=(const zcm::vec2 &first, const zcm::vec2 &second) noexcept
{
    return !(first == second);
}


float& zcm::vec2::operator[](unsigned val) noexcept
{
    assert(val < 3);
    return _data[val];
}

const float& zcm::vec2::operator[](unsigned val) const noexcept
{
    assert(val < 3);
    return _data[val];
}
