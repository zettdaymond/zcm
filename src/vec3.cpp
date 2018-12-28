#include <cassert>
#include <type_traits>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/common.hpp>


static_assert(std::is_standard_layout<zcm::vec3>::value, "");
static_assert(sizeof(zcm::vec3) == 3 * sizeof(float), "extra padding detected!");

zcm::vec3::vec3() :
    vec3(0.0f)
{}

zcm::vec3::vec3(float value) :
    x(value),
    y(value),
    z(value)
{}

zcm::vec3::vec3(float _x, float _y, float _z) :
    x(_x),
    y(_y),
    z(_z)
{}

zcm::vec3::vec3(zcm::vec2 xy, float _z):
    x(xy.x),
    y(xy.y),
    z(_z)
{}

zcm::vec3::vec3(float _x, zcm::vec2 yz) :
    x(_x),
    y(yz.x),
    z(yz.y)
{}

zcm::vec3 zcm::operator +(const zcm::vec3& first, const zcm::vec3& second)
{
    return { first.x + second.x,
             first.y + second.y,
             first.z + second.z };
}

zcm::vec3 zcm::operator -(const zcm::vec3& first, const vec3& second)
{
    return { first.x - second.x,
             first.y - second.y,
             first.z - second.z };
}


zcm::vec3 zcm::operator *(const zcm::vec3& first, const zcm::vec3& second)
{
    return { first.x * second.x,
             first.y * second.y,
             first.z * second.z };
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

zcm::vec3 zcm::operator /(const zcm::vec3& first, const zcm::vec3& second)
{
    return { first.x / second.x,
             first.y / second.y,
             first.z / second.z };
}


zcm::vec3 zcm::operator *(const zcm::vec3& vec, const float scalar)
{
    return { vec.x * scalar,
             vec.y * scalar,
             vec.z * scalar };
}

zcm::vec3 zcm::operator /(const zcm::vec3& vec, const float scalar)
{
    return { vec.x / scalar,
             vec.y / scalar,
             vec.z / scalar };
}


zcm::vec3 zcm::operator -(const zcm::vec3& first)
{
    return { -first.x,
                -first.y,
                -first.z };
}

zcm::vec3 zcm::operator +(const zcm::vec3 &first)
{
    return { +first.x,
                +first.y,
                +first.z };
}


void zcm::vec3::operator +=(const zcm::vec3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
}

void zcm::vec3::operator -=(const zcm::vec3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

void zcm::vec3::operator *=(const zcm::vec3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
}

void zcm::vec3::operator /=(const zcm::vec3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
}

void zcm::vec3::operator +=(float scalar)
{
    x += scalar;
    y += scalar;
    z += scalar;
}

void zcm::vec3::operator -=(float scalar)
{
    x -= scalar;
    y -= scalar;
    z -= scalar;
}

void zcm::vec3::operator *=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void zcm::vec3::operator /=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

bool zcm::operator==(const zcm::vec3 &first, const zcm::vec3 &second)
{
    return first.x == second.x && first.y == second.y && first.z == second.z;
}

bool zcm::operator!=(const zcm::vec3 &first, const zcm::vec3 &second)
{
    return !(first == second);
}


float& zcm::vec3::operator[](unsigned val)
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

float zcm::vec3::operator[](unsigned val) const
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

