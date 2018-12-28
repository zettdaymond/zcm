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

zcm::vec4::vec4(float value) noexcept :
    x(value),
    y(value),
    z(value),
    w(value)
{}
zcm::vec4::vec4(float _x, float _y, float _z, float _w) noexcept :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{}

zcm::vec4::vec4(const zcm::vec3 &xyz, float _w) noexcept :
    x(xyz.x),
    y(xyz.y),
    z(xyz.z),
    w(_w)
{}

zcm::vec4::vec4(float _x, const zcm::vec3 &yzw) noexcept :
    x(_x),
    y(yzw.x),
    z(yzw.y),
    w(yzw.z)
{}

zcm::vec4::vec4(const zcm::vec2 &xy, const zcm::vec2 &zw) noexcept :
    x(xy.x),
    y(xy.y),
    z(zw.x),
    w(zw.y)
{}

zcm::vec4::vec4(const zcm::vec2 &xy, float _z, float _w) noexcept :
    x(xy.x),
    y(xy.y),
    z(_z),
    w(_w)
{}

zcm::vec4::vec4(float _x, const zcm::vec2 &yz, float _w) noexcept :
    x(_x),
    y(yz.x),
    z(yz.y),
    w(_w)
{}

zcm::vec4::vec4(float _x, float _y, const zcm::vec2 &zw) noexcept :
    x(_x),
    y(_y),
    z(zw.x),
    w(zw.y)
{}

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

zcm::vec4 zcm::operator -(const zcm::vec4& first) noexcept
{
    return vec4{ -first.x,
                 -first.y,
                 -first.z,
                 -first.w };
}


zcm::vec4 zcm::operator +(const zcm::vec4 &first) noexcept
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

void zcm::vec4::operator +=(const zcm::vec4 &other) noexcept
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

void zcm::vec4::operator -=(const zcm::vec4 &other) noexcept
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}

void zcm::vec4::operator *=(const zcm::vec4 &other) noexcept
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
}

void zcm::vec4::operator /=(const zcm::vec4 &other) noexcept
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

float zcm::vec4::operator[](unsigned val) const noexcept
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
