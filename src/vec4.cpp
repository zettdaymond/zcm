#include <cassert>
#include <type_traits>
#include <zcm/vec4.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>


static_assert(std::is_standard_layout<zcm::vec4>::value, "");
static_assert(sizeof(zcm::vec4) == 4 * sizeof(float), "extra padding detected!");

zcm::vec4::vec4() noexcept :
    vec4(0.0f)
{}

zcm::vec4::vec4(zcm::no_init_t) noexcept
{}

zcm::vec4::vec4(float value) noexcept
{
    _data[0] = value;
    _data[1] = value;
    _data[2] = value;
    _data[3] = value;
}
zcm::vec4::vec4(float _x, float _y, float _z, float _w) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = _z;
    _data[3] = _w;
}

zcm::vec4::vec4(vec3 xyz, float _w) noexcept
{
    _data[0] = xyz.x;
    _data[1] = xyz.y;
    _data[2] = xyz.z;
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, vec3 yzw) noexcept
{
    _data[0] = _x;
    _data[1] = yzw.x;
    _data[2] = yzw.y;
    _data[3] = yzw.z;
}

zcm::vec4::vec4(vec2 xy, vec2 zw) noexcept
{
    _data[0] = xy.x;
    _data[1] = xy.y;
    _data[2] = zw.x;
    _data[3] = zw.y;
}

zcm::vec4::vec4(vec2 xy, float _z, float _w) noexcept
{
    _data[0] = xy.x;
    _data[1] = xy.y;
    _data[2] = _z;
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, vec2 yz, float _w) noexcept
{
    _data[0] = _x;
    _data[1] = yz.x;
    _data[2] = yz.y;
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, float _y, vec2 zw) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = zw.x;
    _data[3] = zw.y;
}

zcm::vec4 zcm::operator +(const zcm::vec4& first, const zcm::vec4& second) noexcept
{
    return vec4{ first.x + second.x,
                 first.y + second.y,
                 first.z + second.z,
                 first.w + second.w };
}

zcm::vec4 zcm::operator -(const zcm::vec4& first, const vec4& second) noexcept
{
    return vec4{ first.x - second.x,
                 first.y - second.y,
                 first.z - second.z,
                 first.w - second.w };
}

zcm::vec4 zcm::operator -(zcm::vec4 first) noexcept
{
    return vec4{ -first.x,
                 -first.y,
                 -first.z,
                 -first.w };
}


zcm::vec4 zcm::operator +(zcm::vec4 first) noexcept
{
    return { +first.x,
             +first.y,
             +first.z,
             +first.w };
}

zcm::vec4 zcm::operator *(const zcm::vec4& vec, const float scalar) noexcept
{
    return vec4{ vec.x * scalar,
                 vec.y * scalar,
                 vec.z * scalar,
                 vec.w * scalar };
}

zcm::vec4 zcm::operator /(const zcm::vec4& vec, const float scalar) noexcept
{
    return vec4{ vec.x / scalar,
                 vec.y / scalar,
                 vec.z / scalar,
                 vec.w / scalar };
}

zcm::vec4 zcm::operator *(const zcm::vec4& first, const zcm::vec4& second) noexcept
{
    return { first.x * second.x,
             first.y * second.y,
             first.z * second.z,
             first.w * second.w };
}

zcm::vec4 zcm::operator *(const float scalar, const zcm::vec4& vec) noexcept
{
    return { scalar * vec.x,
             scalar * vec.y,
             scalar * vec.z,
             scalar * vec.w };
}

zcm::vec4 zcm::operator /(const float scalar, const zcm::vec4& vec) noexcept
{
    return { scalar / vec.x,
             scalar / vec.y,
             scalar / vec.z,
             scalar / vec.w };
}

zcm::vec4 zcm::operator /(const zcm::vec4& first, const zcm::vec4& second) noexcept
{
    return { first.x / second.x,
             first.y / second.y,
             first.z / second.z,
             first.w / second.w };
}

void zcm::vec4::operator +=(zcm::vec4 other) noexcept
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

void zcm::vec4::operator -=(zcm::vec4 other) noexcept
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}

void zcm::vec4::operator *=(zcm::vec4 other) noexcept
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
}

void zcm::vec4::operator /=(zcm::vec4 other) noexcept
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
}

void zcm::vec4::operator +=(float scalar) noexcept
{
    x += scalar;
    y += scalar;
    z += scalar;
    w += scalar;
}

void zcm::vec4::operator -=(float scalar) noexcept
{
    x -= scalar;
    y -= scalar;
    z -= scalar;
    w -= scalar;
}

void zcm::vec4::operator *=(float scalar) noexcept
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

void zcm::vec4::operator /=(float scalar) noexcept
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
}

bool zcm::operator==(const zcm::vec4 &first, const zcm::vec4 &second) noexcept
{
    return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w;
}

bool zcm::operator!=(const zcm::vec4 &first, const zcm::vec4 &second) noexcept
{
    return !(first == second);
}

float& zcm::vec4::operator[](unsigned val) noexcept
{
    assert(val < 4);
    return _data[val];
}

const float& zcm::vec4::operator[](unsigned val) const noexcept
{
    assert(val < 4);
    return _data[val];
}
