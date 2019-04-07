#include <cassert>
#include <type_traits>
#include <zcm/bvec2.hpp>


static_assert (std::is_standard_layout<zcm::bvec2>::value, "");
static_assert(sizeof(zcm::bvec2) == 2 * sizeof(bool), "extra padding detected!");


zcm::bvec2::bvec2() noexcept :
    bvec2(false)
{}

zcm::bvec2::bvec2(bool value) noexcept :
    x(value),
    y(value)
{}

zcm::bvec2::bvec2(bool _x, bool _y) noexcept :
    x(_x),
    y(_y)
{}

zcm::bvec2 zcm::operator &&(bvec2 first, bvec2 second) noexcept
{
    return { first.x && second.x,
             first.y && second.y };
}

zcm::bvec2 zcm::operator &&(bvec2 vec, bool scalar) noexcept
{
    return { vec.x && scalar,
             vec.y && scalar };
}

zcm::bvec2 zcm::operator &&(bool scalar, bvec2 vec) noexcept
{
    return { vec.x && scalar,
             vec.y && scalar };
}


zcm::bvec2 zcm::operator ||(bvec2 first, bvec2 second) noexcept
{
    return { first.x || second.x,
             first.y || second.y };
}

zcm::bvec2 zcm::operator ||(bvec2 vec, const bool scalar) noexcept
{
    return { vec.x || scalar,
             vec.y || scalar };
}

zcm::bvec2 zcm::operator ||(const bool scalar, bvec2 vec) noexcept
{
    return { vec.x || scalar,
             vec.y || scalar };
}


zcm::bvec2 zcm::operator ^(bvec2 first, bvec2 second) noexcept
{
    return { bool(first.x ^ second.x),
             bool(first.y ^ second.y) };
}

zcm::bvec2 zcm::operator ^(zcm::bvec2 first, bool scalar) noexcept
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar) };
}

zcm::bvec2 zcm::operator ^(bool scalar, zcm::bvec2 first) noexcept
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar) };
}

zcm::bvec2 zcm::operator !(bvec2 first) noexcept
{
    return { !first.x,
             !first.y };
}


void zcm::bvec2::operator &=(bool scalar) noexcept
{
    x &= scalar;
    y &= scalar;
}

void zcm::bvec2::operator |=(bool scalar) noexcept
{
    x |= scalar;
    y |= scalar;
}

void zcm::bvec2::operator ^=(bool scalar) noexcept
{
    x ^= scalar;
    y ^= scalar;
}

void zcm::bvec2::operator &=(zcm::bvec2 other) noexcept
{
    x &= other.x;
    y &= other.y;
}

void zcm::bvec2::operator |=(zcm::bvec2 other) noexcept
{
    x |= other.x;
    y |= other.y;
}

void zcm::bvec2::operator ^=(zcm::bvec2 other) noexcept
{
    x ^= other.x;
    y ^= other.y;
}

bool zcm::operator ==(zcm::bvec2 first, zcm::bvec2 second) noexcept
{
    return  first.x == second.x && first.y == second.y;
}

bool zcm::operator !=(zcm::bvec2 first, zcm::bvec2 second) noexcept
{
    return !(first == second);
}

bool& zcm::bvec2::operator[](unsigned val) noexcept
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

bool zcm::bvec2::operator[](unsigned val) const noexcept
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

