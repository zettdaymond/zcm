#include <cassert>
#include <type_traits>
#include <zcm/bvec2.hpp>


static_assert (std::is_standard_layout<zcm::bvec2>::value, "");


zcm::bvec2::bvec2() :
    bvec2(false)
{}
zcm::bvec2::bvec2(bool value) :
    x(value),
    y(value)
{}

zcm::bvec2::bvec2(bool _x, bool _y) :
    x(_x),
    y(_y)
{}

zcm::bvec2 zcm::operator &&(bvec2 first, bvec2 second)
{
    return { first.x && second.x,
             first.y && second.y };
}

zcm::bvec2 zcm::operator &&(bvec2 vec, bool scalar)
{
    return { vec.x && scalar,
             vec.y && scalar };
}

zcm::bvec2 zcm::operator &&(bool scalar, bvec2 vec)
{
    return { vec.x && scalar,
             vec.y && scalar };
}


zcm::bvec2 zcm::operator ||(bvec2 first, bvec2 second)
{
    return { first.x || second.x,
             first.y || second.y };
}

zcm::bvec2 zcm::operator ||(bvec2 vec, const bool scalar)
{
    return { vec.x || scalar,
             vec.y || scalar };
}

zcm::bvec2 zcm::operator ||(const bool scalar, bvec2 vec)
{
    return { vec.x || scalar,
             vec.y || scalar };
}


zcm::bvec2 zcm::operator ^(bvec2 first, bvec2 second)
{
    return { bool(first.x ^ second.x),
             bool(first.y ^ second.y) };
}

zcm::bvec2 zcm::operator ^(zcm::bvec2 first, bool scalar)
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar) };
}

zcm::bvec2 zcm::operator ^(bool scalar, zcm::bvec2 first)
{
    return { bool(first.x ^ scalar),
             bool(first.y ^ scalar) };
}

zcm::bvec2 zcm::operator !(bvec2 first)
{
    return { !first.x,
             !first.y };
}


void zcm::bvec2::operator &=(bool scalar)
{
    x &= scalar;
    y &= scalar;
}

void zcm::bvec2::operator |=(bool scalar)
{
    x |= scalar;
    y |= scalar;
}

void zcm::bvec2::operator ^=(bool scalar)
{
    x ^= scalar;
    y ^= scalar;
}

void zcm::bvec2::operator &=(zcm::bvec2 other)
{
    x &= other.x;
    y &= other.y;
}

void zcm::bvec2::operator |=(zcm::bvec2 other)
{
    x |= other.x;
    y |= other.y;
}

void zcm::bvec2::operator ^=(zcm::bvec2 other)
{
    x ^= other.x;
    y ^= other.y;
}

bool zcm::operator ==(zcm::bvec2 first, zcm::bvec2 second)
{
    return  first.x == second.x && first.y == second.y;
}

bool zcm::operator !=(zcm::bvec2 first, zcm::bvec2 second)
{
    return !(first == second);
}

bool& zcm::bvec2::operator[](unsigned val)
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

bool zcm::bvec2::operator[](unsigned val) const
{
    assert(val < 3);

    if (val == 0) {
        return x;
    }
    else {
        return y;
    }
}

