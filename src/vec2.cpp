#include <cassert>
#include <type_traits>
#include <zcm/vec2.hpp>


static_assert (std::is_standard_layout<zcm::vec2>::value, "");
static_assert(sizeof(zcm::vec2) == 2 * sizeof(float), "extra padding detected!");

zcm::vec2::vec2() :
    vec2(0.0f)
{}
zcm::vec2::vec2(float value) :
    x(value),
    y(value)
{}

zcm::vec2::vec2(float _x, float _y) :
    x(_x),
    y(_y)
{}

zcm::vec2 zcm::operator +(const zcm::vec2& first, const zcm::vec2& second)
{
    return { first.x + second.x,
             first.y + second.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first, const vec2& second)
{
    return { first.x - second.x,
             first.y - second.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2& first, const zcm::vec2& second)
{
    return { first.x * second.x,
             first.y * second.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2& vec, const float scalar)
{
    return { vec.x * scalar,
             vec.y * scalar };
}

zcm::vec2 zcm::operator *(const float scalar, const zcm::vec2& vec)
{
    return { scalar * vec.x,
             scalar * vec.y };
}


zcm::vec2 zcm::operator /(const zcm::vec2& first, const zcm::vec2& second)
{
    return { first.x / second.x,
             first.y / second.y };
}


zcm::vec2 zcm::operator /(const zcm::vec2& vec, const float scalar)
{
    return { vec.x / scalar,
             vec.y / scalar };
}

zcm::vec2 zcm::operator /(const float scalar, const zcm::vec2& vec)
{
    return { scalar / vec.x,
             scalar / vec.y };
}


zcm::vec2 zcm::operator +(const zcm::vec2& first)
{
    return { +first.x,
             +first.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first)
{
    return { -first.x,
             -first.y };
}

void zcm::vec2::operator +=(const zcm::vec2 &other)
{
    x += other.x;
    y += other.y;
}

void zcm::vec2::operator -=(const zcm::vec2 &other)
{
    x -= other.x;
    y -= other.y;
}

void zcm::vec2::operator *=(const zcm::vec2 &other)
{
    x *= other.x;
    y *= other.y;
}

void zcm::vec2::operator/=(const vec2 &other)
{
    x /= other.x;
    y /= other.y;
}

void zcm::vec2::operator +=(float scalar)
{
    x += scalar;
    y += scalar;
}

void zcm::vec2::operator -=(float scalar)
{
    x -= scalar;
    y -= scalar;
}

void zcm::vec2::operator *=(float scalar)
{
    x *= scalar;
    y *= scalar;
}

void zcm::vec2::operator /=(float scalar)
{
    x /= scalar;
    y /= scalar;
}

bool zcm::operator==(const zcm::vec2 &first, const zcm::vec2 &second)
{
    return first.x == second.x && first.y == second.y;
}

bool zcm::operator!=(const zcm::vec2 &first, const zcm::vec2 &second)
{
    return !(first == second);
}


float&zcm::vec2::operator[](unsigned val)
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

float zcm::vec2::operator[](unsigned val) const
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}
