#include "vec4.h"
#include <cassert>


zcm::vec4 zcm::operator +(const zcm::vec4& first, const zcm::vec4& second)
{
    return vec4{ first.x + second.x,
                 first.y + second.y,
                 first.z + second.z,
                 first.w + second.w };
}

zcm::vec4 zcm::operator -(const zcm::vec4& first, const vec4& second)
{
    return vec4{ first.x - second.x,
                 first.y - second.y,
                 first.z - second.z,
                 first.w - second.w };
}

zcm::vec4 zcm::operator -(const zcm::vec4& first)
{
    return vec4{ -first.x,
                 -first.y,
                 -first.z,
                 -first.w };
}

zcm::vec4 zcm::operator *(const zcm::vec4& vec, const float scalar)
{
    return vec4{ vec.x * scalar,
                 vec.y * scalar,
                 vec.z * scalar,
                 vec.w * scalar };
}

zcm::vec4 zcm::operator /(const zcm::vec4& vec, const float scalar)
{
    return vec4{ vec.x / scalar,
                 vec.y / scalar,
                 vec.z / scalar,
                 vec.w / scalar };
}

zcm::vec4 zcm::operator *(const zcm::vec4& first, const zcm::vec4& second)
{
    return {first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w };
}

zcm::vec4 zcm::operator *(const float scalar, const zcm::vec4& vec)
{
    return { scalar * vec.x,
             scalar * vec.y,
             scalar * vec.z,
             scalar * vec.w };
}

zcm::vec4 zcm::operator /(const float scalar, const zcm::vec4& vec)
{
    return { scalar / vec.x,
             scalar / vec.y,
             scalar / vec.z,
             scalar / vec.w };
}

float&zcm::vec4::operator[](const uint8_t val)
{
    assert(val < 4);
    if (val == 0) {
        return x;
    }
    else if (val == 1) {
        return y;
    }
    else if (val == 2) {
        return z;
    }
    else {
        return w;
    }
}

const float&zcm::vec4::operator[](const uint8_t val) const
{
    assert(val < 4);
    if (val == 0) {
        return x;
    }
    else if (val == 1) {
        return y;
    }
    else if (val == 2) {
        return z;
    }
    else {
        return w;
    }
}

zcm::vec4 zcm::operator /(const zcm::vec4& first, const zcm::vec4& second)
{
    return {first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w };
}
