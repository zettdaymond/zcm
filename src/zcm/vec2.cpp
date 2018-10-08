#include "vec2.h"


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
