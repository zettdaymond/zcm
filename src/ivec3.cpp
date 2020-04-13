#include <cassert>
#include <type_traits>
#include <zcm/ivec3.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/detail/impl_op_macro.hpp>


static_assert(std::is_standard_layout<zcm::ivec3>::value, "");
static_assert(sizeof(zcm::ivec3) == 3 * sizeof(int32_t), "extra padding detected!");

zcm::ivec3::ivec3() noexcept :
    ivec3(0)
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
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = _z;
}

zcm::ivec3::ivec3(int32_t _x, zcm::ivec2 yz) noexcept
{
    _data[0] = _x;
    _data[1] = yz._data[0];
    _data[2] = yz._data[1];
}


namespace zcm {
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, +)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, -)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, *)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, /)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, %)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, |)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, &)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, ^)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, >>)
ZCM_IMPL_V3_BINOP(int32_t, zcm::ivec3, <<)
}

ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, +=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, -=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, *=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, /=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, %=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, |=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, &=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, ^=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, >>=)
ZCM_IMPL_V3_COMPOUND_OP(int32_t, zcm::ivec3, <<=)


zcm::ivec3 zcm::operator -(zcm::ivec3 first) noexcept
{
    return { -first._data[0],
             -first._data[1],
             -first._data[2] };
}

zcm::ivec3 zcm::operator +(zcm::ivec3 first) noexcept
{
    return { +first._data[0],
             +first._data[1],
             +first._data[2] };
}

bool zcm::operator==(zcm::ivec3 first, zcm::ivec3 second) noexcept
{
    return first._data[0] == second._data[0] && first._data[1] == second._data[1] && first._data[2] == second._data[2];
}

bool zcm::operator!=(zcm::ivec3 first, zcm::ivec3 second) noexcept
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

zcm::ivec3& zcm::ivec3::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    ++_data[2];
    return *this;

}

zcm::ivec3 zcm::ivec3::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    ++_data[2];
    return tmp;
}

zcm::ivec3& zcm::ivec3::operator--() noexcept
{
    --_data[0];
    --_data[1];
    --_data[2];
    return *this;
}



zcm::ivec3 zcm::ivec3::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    --_data[2];
    return tmp;
}

zcm::ivec3::operator zcm::bvec3() const noexcept
{
    return { bool(_data[0]), bool(_data[1]), bool(_data[2])};
}


bool zcm::operator <(zcm::ivec3 first, zcm::ivec3 second) noexcept
{
    if (first._data[0] < second._data[0]) return true;
    if (first._data[0] > second._data[0]) return false;
    if (first._data[1] < second._data[1]) return true;
    if (first._data[1] > second._data[1]) return false;
    if (first._data[2] < second._data[2]) return true;
    return false;
}

bool zcm::operator<=(zcm::ivec3 first, zcm::ivec3 second) noexcept
{
    return !(second < first);
}

bool zcm::operator >(zcm::ivec3 first, zcm::ivec3 second) noexcept
{
    return second < first;
}

bool zcm::operator>=(zcm::ivec3 first, zcm::ivec3 second) noexcept
{
    return !(first < second);
}
