#include <cassert>
#include <type_traits>
#include <zcm/bvec4.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/bvec2.hpp>

static_assert(std::is_standard_layout<zcm::bvec4>::value, "");
static_assert(sizeof(zcm::bvec4) == 4 * sizeof(bool), "extra padding detected!");

zcm::bvec4::bvec4() noexcept :
    bvec4(false)
{}

zcm::bvec4::bvec4(bool value) noexcept :
    x(value),
    y(value),
    z(value),
    w(value)
{}
zcm::bvec4::bvec4(bool _x, bool _y, bool _z, bool _w) noexcept :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{}

zcm::bvec4::bvec4(zcm::bvec3 xyz, bool _w) noexcept :
    x(xyz.x),
    y(xyz.y),
    z(xyz.z),
    w(_w)
{}

zcm::bvec4::bvec4(bool _x, zcm::bvec3 yzw) noexcept :
    x(_x),
    y(yzw.x),
    z(yzw.y),
    w(yzw.z)
{}

zcm::bvec4::bvec4(zcm::bvec2 xy, zcm::bvec2 zw) noexcept :
    x(xy.x),
    y(xy.y),
    z(zw.x),
    w(zw.y)
{}

zcm::bvec4::bvec4(zcm::bvec2 xy, bool _z, bool _w) noexcept :
    x(xy.x),
    y(xy.y),
    z(_z),
    w(_w)
{}

zcm::bvec4::bvec4(bool _x, zcm::bvec2 yz, bool _w) noexcept :
    x(_x),
    y(yz.x),
    z(yz.y),
    w(_w)
{}

zcm::bvec4::bvec4(bool _x, bool _y, zcm::bvec2 zw) noexcept :
    x(_x),
    y(_y),
    z(zw.x),
    w(zw.y)
{}


zcm::bvec4 zcm::operator &&(bvec4 first, bvec4 second) noexcept
{
    return { first.x && second.x,
             first.y && second.y,
             first.z && second.z,
             first.w && second.w};
}

zcm::bvec4 zcm::operator &&(bvec4 vec, bool scalar) noexcept
{
    return { vec.x && scalar,
             vec.y && scalar,
             vec.z && scalar,
             vec.w && scalar };
}

zcm::bvec4 zcm::operator &&(bool scalar, bvec4 vec) noexcept
{
    return { vec.x && scalar,
             vec.y && scalar,
             vec.z && scalar,
             vec.w && scalar };
}


zcm::bvec4 zcm::operator ||(bvec4 first, bvec4 second) noexcept
{
    return { first.x || second.x,
             first.y || second.y,
             first.z || second.z,
             first.w || second.w };
}

zcm::bvec4 zcm::operator ||(bvec4 vec, const bool scalar) noexcept
{
    return { vec.x || scalar,
             vec.y || scalar,
             vec.z || scalar,
             vec.w || scalar };
}

zcm::bvec4 zcm::operator ||(const bool scalar, bvec4 vec) noexcept
{
    return { vec.x || scalar,
             vec.y || scalar,
             vec.z || scalar,
             vec.w || scalar };
}


zcm::bvec4 zcm::operator ^(bvec4 first, bvec4 second) noexcept
{
    return { bool(first.x ^ second.x),
             bool(first.y ^ second.y),
             bool(first.z ^ second.z),
             bool(first.w ^ second.w) };
}

zcm::bvec4 zcm::operator ^(zcm::bvec4 first, bool scalar) noexcept
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar),
             bool(first.z ^ scalar),
             bool(first.w ^ scalar) };
}

zcm::bvec4 zcm::operator ^(bool scalar, zcm::bvec4 first) noexcept
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar),
             bool(first.z ^ scalar),
             bool(first.w ^ scalar) };
}

zcm::bvec4 zcm::operator !(bvec4 first) noexcept
{
    return { !first.x,
             !first.y,
             !first.z,
             !first.w };
}

bool zcm::operator ==(zcm::bvec4 first, zcm::bvec4 second) noexcept
{
    return  first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w;
}

bool zcm::operator !=(zcm::bvec4 first, zcm::bvec4 second) noexcept
{
    return !(first == second);
}

void zcm::bvec4::operator &=(bool scalar) noexcept
{
    x &= scalar;
    y &= scalar;
    z &= scalar;
    w &= scalar;
}

void zcm::bvec4::operator |=(bool scalar) noexcept
{
    x |= scalar;
    y |= scalar;
    z |= scalar;
    w |= scalar;
}

void zcm::bvec4::operator ^=(bool scalar) noexcept
{
    x ^= scalar;
    y ^= scalar;
    z ^= scalar;
    w ^= scalar;
}

void zcm::bvec4::operator &=(zcm::bvec4 other) noexcept
{
    x &= other.x;
    y &= other.y;
    z &= other.z;
    w &= other.w;
}

void zcm::bvec4::operator |=(zcm::bvec4 other) noexcept
{
    x |= other.x;
    y |= other.y;
    z |= other.z;
    w |= other.w;
}

void zcm::bvec4::operator ^=(zcm::bvec4 other) noexcept
{
    x ^= other.x;
    y ^= other.y;
    z ^= other.z;
    w ^= other.w;
}


bool& zcm::bvec4::operator[](unsigned val) noexcept
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

bool zcm::bvec4::operator[](unsigned val) const noexcept
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
