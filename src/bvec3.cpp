#include <cassert>
#include <type_traits>
#include <zcm/bvec2.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/common.hpp>

#define BXOR(X, Y) (!(X) != !(Y))


static_assert(std::is_standard_layout<zcm::bvec3>::value, "");

zcm::bvec3::bvec3() :
    bvec3(false)
{}

zcm::bvec3::bvec3(bool value) :
    x(value),
    y(value),
    z(value)
{}

zcm::bvec3::bvec3(bool _x, bool _y, bool _z) :
    x(_x),
    y(_y),
    z(_z)
{}

zcm::bvec3::bvec3(zcm::bvec2 xy, bool _z):
    x(xy.x),
    y(xy.y),
    z(_z)
{}

zcm::bvec3::bvec3(bool _x, zcm::bvec2 yz) :
    x(_x),
    y(yz.x),
    z(yz.y)
{}


zcm::bvec3 zcm::operator &&(bvec3 first, bvec3 second)
{
    return { first.x && second.x, first.y && second.y, first.z && second.z };
}

zcm::bvec3 zcm::operator &&(bvec3 vec, bool scalar)
{
    return { vec.x && scalar, vec.y && scalar, vec.z && scalar };
}

zcm::bvec3 zcm::operator &&(bool scalar, bvec3 vec)
{
    return { vec.x && scalar, vec.y && scalar, vec.z && scalar };
}


zcm::bvec3 zcm::operator ||(bvec3 first, bvec3 second)
{
    return { first.x || second.x, first.y || second.y, first.z || second.z };
}

zcm::bvec3 zcm::operator ||(bvec3 vec, const bool scalar)
{
    return { vec.x || scalar, vec.y || scalar, vec.z || scalar };
}

zcm::bvec3 zcm::operator ||(const bool scalar, bvec3 vec)
{
    return { vec.x || scalar, vec.y || scalar, vec.z || scalar };
}


zcm::bvec3 zcm::operator ^(bvec3 first, bvec3 second)
{
    return {BXOR(first.x, second.x), BXOR(first.y , second.y), BXOR(first.z , second.z) };
}

zcm::bvec3 zcm::operator ^(zcm::bvec3 first, bool scalar)
{
    return {BXOR(first.x, scalar), BXOR(first.y , scalar), BXOR(first.z , scalar) };
}

zcm::bvec3 zcm::operator ^(bool scalar, zcm::bvec3 first)
{
    return {BXOR(first.x, scalar), BXOR(first.y , scalar), BXOR(first.z , scalar) };
}

zcm::bvec3 zcm::operator !(bvec3 first)
{
    return { !first.x, !first.y, !first.z };
}

bool& zcm::bvec3::operator[](unsigned val)
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

bool zcm::bvec3::operator[](unsigned val) const
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

bool zcm::operator ==(zcm::bvec3 first, zcm::bvec3 second)
{
    return  first.x == second.x && first.y == second.y && first.z == second.z;
}

bool zcm::operator !=(zcm::bvec3 first, zcm::bvec3 second)
{
    return !(first == second);
}
