#include <cassert>
#include <type_traits>
#include <zcm/ivec2.hpp>


static_assert (std::is_standard_layout<zcm::ivec2>::value, "");
static_assert(sizeof(zcm::ivec2) == 2 * sizeof(int32_t), "extra padding detected!");

zcm::ivec2::ivec2() noexcept :
    ivec2(0)
{}

zcm::ivec2::ivec2(zcm::no_init_t) noexcept
{}

zcm::ivec2::ivec2(int32_t value) noexcept
{
    _data[0] = value;
    _data[1] = value;
}

zcm::ivec2::ivec2(int32_t _x, int32_t _y) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
}

zcm::ivec2 zcm::operator +(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return { first.x + second.x,
             first.y + second.y };
}

zcm::ivec2 zcm::operator -(zcm::ivec2 first, ivec2 second) noexcept
{
    return { first.x - second.x,
             first.y - second.y };
}

zcm::ivec2 zcm::operator *(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return { first.x * second.x,
             first.y * second.y };
}

zcm::ivec2 zcm::operator *(zcm::ivec2 vec, int32_t scalar) noexcept
{
    return { vec.x * scalar,
             vec.y * scalar };
}

zcm::ivec2 zcm::operator *(int32_t scalar, zcm::ivec2 vec) noexcept
{
    return { scalar * vec.x,
             scalar * vec.y };
}


zcm::ivec2 zcm::operator /(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return { first.x / second.x,
             first.y / second.y };
}


zcm::ivec2 zcm::operator /(zcm::ivec2 vec, int32_t scalar) noexcept
{
    return { vec.x / scalar,
             vec.y / scalar };
}

zcm::ivec2 zcm::operator /(int32_t scalar, zcm::ivec2 vec) noexcept
{
    return { scalar / vec.x,
             scalar / vec.y };
}


zcm::ivec2 zcm::operator +(zcm::ivec2 first) noexcept
{
    return { +first.x,
             +first.y };
}

zcm::ivec2 zcm::operator -(zcm::ivec2 first) noexcept
{
    return { -first.x,
             -first.y };
}

void zcm::ivec2::operator +=(zcm::ivec2 other) noexcept
{
    x += other.x;
    y += other.y;
}

void zcm::ivec2::operator -=(zcm::ivec2 other) noexcept
{
    x -= other.x;
    y -= other.y;
}

void zcm::ivec2::operator *=(zcm::ivec2 other) noexcept
{
    x *= other.x;
    y *= other.y;
}

void zcm::ivec2::operator/=(ivec2 other) noexcept
{
    x /= other.x;
    y /= other.y;
}

void zcm::ivec2::operator +=(int32_t scalar) noexcept
{
    x += scalar;
    y += scalar;
}

void zcm::ivec2::operator -=(int32_t scalar) noexcept
{
    x -= scalar;
    y -= scalar;
}

void zcm::ivec2::operator *=(int32_t scalar) noexcept
{
    x *= scalar;
    y *= scalar;
}

void zcm::ivec2::operator /=(int32_t scalar) noexcept
{
    x /= scalar;
    y /= scalar;
}

bool zcm::operator==(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return first.x == second.x && first.y == second.y;
}

bool zcm::operator!=(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return !(first == second);
}


int32_t& zcm::ivec2::operator[](unsigned val) noexcept
{
    assert(val < 3);
    return _data[val];
}

const int32_t& zcm::ivec2::operator[](unsigned val) const noexcept
{
    assert(val < 3);
    return _data[val];
}
