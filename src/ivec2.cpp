#include <cassert>
#include <type_traits>
#include <zcm/ivec2.hpp>
#include <zcm/detail/impl_op_macro.hpp>


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

zcm::ivec2 zcm::operator +(zcm::ivec2 first) noexcept
{
    return { +first._data[0],
             +first._data[1] };
}

zcm::ivec2 zcm::operator -(zcm::ivec2 first) noexcept
{
    return { -first._data[0],
             -first._data[1] };
}

namespace zcm {
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, +)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, -)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, *)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, /)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, %)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, |)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, &)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, ^)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, >>)
ZCM_IMPL_V2_BINOP(int32_t, zcm::ivec2, <<)
}

ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, +=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, -=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, *=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, /=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, %=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, |=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, &=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, ^=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, >>=)
ZCM_IMPL_V2_COMPOUND_OP(int32_t, zcm::ivec2, <<=)


bool zcm::operator==(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return first._data[0] == second._data[0] && first._data[1] == second._data[1];
}

bool zcm::operator!=(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return !(first == second);
}

bool zcm::operator <(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    if (first._data[0] < second._data[0]) return true;
    if (first._data[0] > second._data[0]) return false;
    if (first._data[1] < second._data[1]) return true;
    return false;
}

bool zcm::operator<=(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return !(second < first);
}


bool zcm::operator >(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return second < first;
}

bool zcm::operator>=(zcm::ivec2 first, zcm::ivec2 second) noexcept
{
    return !(first < second);
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

zcm::ivec2::operator zcm::bvec2() const noexcept
{
    return { bool(_data[0]), bool(_data[1]) };
}

zcm::ivec2& zcm::ivec2::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    return *this;
}

zcm::ivec2 zcm::ivec2::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    return tmp;
}

zcm::ivec2 &zcm::ivec2::operator--() noexcept
{
    --_data[0];
    --_data[1];
    return *this;
}

zcm::ivec2 zcm::ivec2::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    return tmp;
}
