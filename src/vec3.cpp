#include <cassert>
#include <type_traits>
#include <zcm/vec3.hpp>
#include <zcm/common.hpp>

static_assert(std::is_standard_layout<zcm::vec3>::value, "");


zcm::vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) { }
zcm::vec3::vec3(float value) : x(value), y(value), z(value) { }
zcm::vec3::vec3(float _x, float _y, float _z) :
    x(_x),
    y(_y),
    z(_z) 
{}

zcm::vec3 zcm::operator +(const zcm::vec3& first, const zcm::vec3& second)
{
    return vec3{ first.x + second.x,
                 first.y + second.y,
                 first.z + second.z };
}

zcm::vec3 zcm::operator -(const zcm::vec3& first, const vec3& second)
{
    return vec3{ first.x - second.x,
                 first.y - second.y,
                 first.z - second.z };
}

zcm::vec3 zcm::operator -(const zcm::vec3& first)
{
    return vec3{ -first.x,
                 -first.y,
                 -first.z};
}

zcm::vec3 zcm::operator *(const zcm::vec3& vec, const float scalar)
{
    return vec3{ vec.x * scalar,
                 vec.y * scalar,
                 vec.z * scalar };
}

zcm::vec3 zcm::operator /(const zcm::vec3& vec, const float scalar)
{
    return vec3{ vec.x / scalar,
                 vec.y / scalar,
                 vec.z / scalar };
}

zcm::vec3 zcm::operator *(const zcm::vec3& first, const zcm::vec3& second)
{
    return {first.x * second.x, first.y * second.y, first.z * second.z};
}

zcm::vec3 zcm::operator *(const float scalar, const zcm::vec3& vec)
{
    return { scalar * vec.x,
             scalar * vec.y,
             scalar * vec.z };
}

zcm::vec3 zcm::operator /(const float scalar, const zcm::vec3& vec)
{
    return { scalar / vec.x,
             scalar / vec.y,
             scalar / vec.z };
}

float&zcm::vec3::operator[](unsigned val)
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else if (val == 1) {
        return y;
    }
    else {
        return z;
    }
}

const float&zcm::vec3::operator[](unsigned val) const
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else if (val == 1) {
        return y;
    }
    else {
        return z;
    }
}

zcm::vec3 zcm::operator /(const zcm::vec3& first, const zcm::vec3& second)
{
    return {first.x / second.x, first.y / second.y, first.z / second.z};
}
