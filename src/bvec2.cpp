#include <cassert>
#include <type_traits>
#include <zcm/bvec2.hpp>


static_assert (std::is_standard_layout<zcm::bvec2>::value, "");

#define BXOR(X, Y) (!(X) != !(Y))

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
    return { vec.x && scalar, vec.y && scalar };
}

zcm::bvec2 zcm::operator &&(bool scalar, bvec2 vec)
{
    return { vec.x && scalar, vec.y && scalar };
}


zcm::bvec2 zcm::operator ||(bvec2 first, bvec2 second)
{
    return { first.x || second.x,
                 first.y || second.y };
}

zcm::bvec2 zcm::operator ||(bvec2 vec, const bool scalar)
{
    return { vec.x || scalar, vec.y || scalar };
}

zcm::bvec2 zcm::operator ||(const bool scalar, bvec2 vec)
{
    return { vec.x || scalar, vec.y || scalar };
}


zcm::bvec2 zcm::operator ^(bvec2 first, bvec2 second)
{
    return {BXOR(first.x, second.x), BXOR(first.y , second.y) };
}

zcm::bvec2 zcm::operator ^(zcm::bvec2 first, bool scalar)
{
    return {BXOR(first.x, scalar), BXOR(first.y , scalar) };
}

zcm::bvec2 zcm::operator ^(bool scalar, zcm::bvec2 first)
{
    return {BXOR(first.x, scalar), BXOR(first.y , scalar) };
}

zcm::bvec2 zcm::operator !(bvec2 first)
{
    return { !first.x, !first.y };
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


bool zcm::operator ==(zcm::bvec2 first, zcm::bvec2 second)
{
    return  first.x == second.x && first.y == second.y;
}

bool zcm::operator !=(zcm::bvec2 first, zcm::bvec2 second)
{
    return !(first == second);
}
