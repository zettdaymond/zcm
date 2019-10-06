#include <cassert>
#include <type_traits>
#include <zcm/ivec3.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/common.hpp>


static_assert(std::is_standard_layout<zcm::ivec3>::value, "");
static_assert(sizeof(zcm::ivec3) == 3 * sizeof(int32_t), "extra padding detected!");

zcm::ivec3::ivec3() noexcept :
    ivec3(0.0f)
{}

zcm::ivec3::ivec3(zcm::no_init_t) noexcept
{}

zcm::ivec3::ivec3(int32_t value) noexcept
{
    _data[0] = value;
    _data[1] = value;
    _data[2] = value;
}

zcm::ivec3::ivec3(int32_t _x, int32_t _y, int32_t _z) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = _z;
}

zcm::ivec3::ivec3(zcm::ivec2 xy, int32_t _z) noexcept
{
    _data[0] = xy.x;
    _data[1] = xy.y;
    _data[2] = _z;
}

zcm::ivec3::ivec3(int32_t _x, zcm::ivec2 yz) noexcept
{
    _data[0] = _x;
    _data[1] = yz.x;
    _data[2] = yz.y;
}

zcm::ivec3 zcm::operator +(const zcm::ivec3& first, const zcm::ivec3& second) noexcept
{
    return { first.x + second.x,
             first.y + second.y,
             first.z + second.z };
}

zcm::ivec3 zcm::operator -(const zcm::ivec3& first, const ivec3& second) noexcept
{
    return { first.x - second.x,
             first.y - second.y,
             first.z - second.z };
}


zcm::ivec3 zcm::operator *(const zcm::ivec3& first, const zcm::ivec3& second) noexcept
{
    return { first.x * second.x,
             first.y * second.y,
             first.z * second.z };
}

zcm::ivec3 zcm::operator *(int32_t scalar, zcm::ivec3 vec) noexcept
{
    return { scalar * vec.x,
             scalar * vec.y,
             scalar * vec.z };
}

zcm::ivec3 zcm::operator /(const int32_t scalar, zcm::ivec3 vec) noexcept
{
    return { scalar / vec.x,
             scalar / vec.y,
             scalar / vec.z };
}

zcm::ivec3 zcm::operator /(const zcm::ivec3& first, const zcm::ivec3& second) noexcept
{
    return { first.x / second.x,
             first.y / second.y,
             first.z / second.z };
}


zcm::ivec3 zcm::operator *(const zcm::ivec3& vec, const int32_t scalar) noexcept
{
    return { vec.x * scalar,
             vec.y * scalar,
             vec.z * scalar };
}

zcm::ivec3 zcm::operator /(const zcm::ivec3& vec, const int32_t scalar) noexcept
{
    return { vec.x / scalar,
             vec.y / scalar,
             vec.z / scalar };
}


zcm::ivec3 zcm::operator -(zcm::ivec3 first) noexcept
{
    return { -first.x,
                -first.y,
                -first.z };
}

zcm::ivec3 zcm::operator +(zcm::ivec3 first) noexcept
{
    return { +first.x,
                +first.y,
                +first.z };
}


void zcm::ivec3::operator +=(zcm::ivec3 other) noexcept
{
    x += other.x;
    y += other.y;
    z += other.z;
}

void zcm::ivec3::operator -=(zcm::ivec3 other) noexcept
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

void zcm::ivec3::operator *=(zcm::ivec3 other) noexcept
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
}

void zcm::ivec3::operator /=(zcm::ivec3 other) noexcept
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
}

void zcm::ivec3::operator +=(int32_t scalar) noexcept
{
    x += scalar;
    y += scalar;
    z += scalar;
}

void zcm::ivec3::operator -=(int32_t scalar) noexcept
{
    x -= scalar;
    y -= scalar;
    z -= scalar;
}

void zcm::ivec3::operator *=(int32_t scalar) noexcept
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void zcm::ivec3::operator /=(int32_t scalar) noexcept
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

bool zcm::operator==(const zcm::ivec3 &first, const zcm::ivec3 &second) noexcept
{
    return first.x == second.x && first.y == second.y && first.z == second.z;
}

bool zcm::operator!=(const zcm::ivec3 &first, const zcm::ivec3 &second) noexcept
{
    return !(first == second);
}


int32_t& zcm::ivec3::operator[](unsigned val) noexcept
{
    assert(val < 3);
    return _data[val];
}

const int32_t& zcm::ivec3::operator[](unsigned val) const noexcept
{
    assert(val < 3);
    return _data[val];
}

