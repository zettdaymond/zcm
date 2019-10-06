#include <cassert>
#include <type_traits>
#include <zcm/ivec4.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec2.hpp>


static_assert(std::is_standard_layout<zcm::ivec4>::value, "");
static_assert(sizeof(zcm::ivec4) == 4 * sizeof(int32_t), "extra padding detected!");

zcm::ivec4::ivec4() noexcept :
    ivec4(0.0f)
{}

zcm::ivec4::ivec4(zcm::no_init_t) noexcept
{}

zcm::ivec4::ivec4(int32_t value) noexcept
{
    _data[0] = value;
    _data[1] = value;
    _data[2] = value;
    _data[3] = value;
}
zcm::ivec4::ivec4(int32_t _x, int32_t _y, int32_t _z, int32_t _w) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = _z;
    _data[3] = _w;
}

zcm::ivec4::ivec4(ivec3 xyz, int32_t _w) noexcept
{
    _data[0] = xyz.x;
    _data[1] = xyz.y;
    _data[2] = xyz.z;
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, ivec3 yzw) noexcept
{
    _data[0] = _x;
    _data[1] = yzw.x;
    _data[2] = yzw.y;
    _data[3] = yzw.z;
}

zcm::ivec4::ivec4(ivec2 xy, ivec2 zw) noexcept
{
    _data[0] = xy.x;
    _data[1] = xy.y;
    _data[2] = zw.x;
    _data[3] = zw.y;
}

zcm::ivec4::ivec4(ivec2 xy, int32_t _z, int32_t _w) noexcept
{
    _data[0] = xy.x;
    _data[1] = xy.y;
    _data[2] = _z;
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, ivec2 yz, int32_t _w) noexcept
{
    _data[0] = _x;
    _data[1] = yz.x;
    _data[2] = yz.y;
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, int32_t _y, ivec2 zw) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = zw.x;
    _data[3] = zw.y;
}

zcm::ivec4 zcm::operator +(const zcm::ivec4& first, const zcm::ivec4& second) noexcept
{
    return ivec4{ first.x + second.x,
                 first.y + second.y,
                 first.z + second.z,
                 first.w + second.w };
}

zcm::ivec4 zcm::operator -(const zcm::ivec4& first, const ivec4& second) noexcept
{
    return ivec4{ first.x - second.x,
                 first.y - second.y,
                 first.z - second.z,
                 first.w - second.w };
}

zcm::ivec4 zcm::operator -(zcm::ivec4 first) noexcept
{
    return ivec4{ -first.x,
                 -first.y,
                 -first.z,
                 -first.w };
}


zcm::ivec4 zcm::operator +(zcm::ivec4 first) noexcept
{
    return { +first.x,
             +first.y,
             +first.z,
             +first.w };
}

zcm::ivec4 zcm::operator *(const zcm::ivec4& ivec, const int32_t scalar) noexcept
{
    return ivec4{ ivec.x * scalar,
                 ivec.y * scalar,
                 ivec.z * scalar,
                 ivec.w * scalar };
}

zcm::ivec4 zcm::operator /(const zcm::ivec4& ivec, const int32_t scalar) noexcept
{
    return ivec4{ ivec.x / scalar,
                 ivec.y / scalar,
                 ivec.z / scalar,
                 ivec.w / scalar };
}

zcm::ivec4 zcm::operator *(const zcm::ivec4& first, const zcm::ivec4& second) noexcept
{
    return { first.x * second.x,
             first.y * second.y,
             first.z * second.z,
             first.w * second.w };
}

zcm::ivec4 zcm::operator *(const int32_t scalar, const zcm::ivec4& ivec) noexcept
{
    return { scalar * ivec.x,
             scalar * ivec.y,
             scalar * ivec.z,
             scalar * ivec.w };
}

zcm::ivec4 zcm::operator /(const int32_t scalar, const zcm::ivec4& ivec) noexcept
{
    return { scalar / ivec.x,
             scalar / ivec.y,
             scalar / ivec.z,
             scalar / ivec.w };
}

zcm::ivec4 zcm::operator /(const zcm::ivec4& first, const zcm::ivec4& second) noexcept
{
    return { first.x / second.x,
             first.y / second.y,
             first.z / second.z,
             first.w / second.w };
}

void zcm::ivec4::operator +=(zcm::ivec4 other) noexcept
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

void zcm::ivec4::operator -=(zcm::ivec4 other) noexcept
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}

void zcm::ivec4::operator *=(zcm::ivec4 other) noexcept
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
}

void zcm::ivec4::operator /=(zcm::ivec4 other) noexcept
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
}

void zcm::ivec4::operator +=(int32_t scalar) noexcept
{
    x += scalar;
    y += scalar;
    z += scalar;
    w += scalar;
}

void zcm::ivec4::operator -=(int32_t scalar) noexcept
{
    x -= scalar;
    y -= scalar;
    z -= scalar;
    w -= scalar;
}

void zcm::ivec4::operator *=(int32_t scalar) noexcept
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

void zcm::ivec4::operator /=(int32_t scalar) noexcept
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
}

bool zcm::operator==(const zcm::ivec4 &first, const zcm::ivec4 &second) noexcept
{
    return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w;
}

bool zcm::operator!=(const zcm::ivec4 &first, const zcm::ivec4 &second) noexcept
{
    return !(first == second);
}

int32_t& zcm::ivec4::operator[](unsigned val) noexcept
{
    assert(val < 4);
    return _data[val];
}

const int32_t& zcm::ivec4::operator[](unsigned val) const noexcept
{
    assert(val < 4);
    return _data[val];
}
