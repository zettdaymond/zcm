#include <cassert>
#include <type_traits>
#include <zcm/vec2.hpp>

static_assert (std::is_standard_layout<zcm::vec2>::value, "");

zcm::vec2::vec2() : x(0.0f), y(0.0f) {}
zcm::vec2::vec2(float value) : x(value), y(value) { }
zcm::vec2::vec2(float _x, float _y) : x(_x), y(_y) { }

zcm::vec2 zcm::operator +(const zcm::vec2& first, const zcm::vec2& second)
{
    return vec2{ first.x + second.x,
                 first.y + second.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first, const vec2& second)
{
    return vec2{ first.x - second.x,
                 first.y - second.y };
}

zcm::vec2 zcm::operator -(const zcm::vec2& first)
{
    return vec2{ -first.x,
                 -first.y };
}

zcm::vec2 zcm::operator *(const zcm::vec2& vec, const float scalar)
{
    return vec2{ vec.x * scalar,
                 vec.y * scalar };
}

zcm::vec2 zcm::operator /(const zcm::vec2& vec, const float scalar)
{
    return vec2{ vec.x / scalar,
                 vec.y / scalar };
}

zcm::vec2 zcm::operator *(const zcm::vec2& first, const zcm::vec2& second)
{
    return {first.x * second.x, first.y * second.y };
}

zcm::vec2 zcm::operator *(const float scalar, const zcm::vec2& vec)
{
    return vec2{ scalar * vec.x,
                 scalar * vec.y };
}

zcm::vec2 zcm::operator /(const float scalar, const zcm::vec2& vec)
{
    return vec2{ scalar / vec.x,
                 scalar / vec.y };
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

const float&zcm::vec2::operator[](unsigned val) const
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

zcm::vec2 zcm::operator /(const zcm::vec2& first, const zcm::vec2& second)
{
    return {first.x / second.x, first.y / second.y };
}
