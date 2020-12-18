#include <cassert>
#include <type_traits>
#include <zcm/ivec2.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec4.hpp>
#include <zcm/detail/impl_op_macro.hpp>


static_assert(std::is_standard_layout<zcm::ivec4>::value, "");
static_assert(sizeof(zcm::ivec4) == 4 * sizeof(int32_t), "extra padding detected!");

zcm::ivec4::ivec4() noexcept :
    ivec4(0)
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
    _data[0] = xyz._data[0];
    _data[1] = xyz._data[1];
    _data[2] = xyz._data[2];
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, ivec3 yzw) noexcept
{
    _data[0] = _x;
    _data[1] = yzw._data[0];
    _data[2] = yzw._data[1];
    _data[3] = yzw._data[2];
}

zcm::ivec4::ivec4(ivec2 xy, ivec2 zw) noexcept
{
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = zw._data[0];
    _data[3] = zw._data[1];
}

zcm::ivec4::ivec4(ivec2 xy, int32_t _z, int32_t _w) noexcept
{
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = _z;
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, ivec2 yz, int32_t _w) noexcept
{
    _data[0] = _x;
    _data[1] = yz._data[0];
    _data[2] = yz._data[1];
    _data[3] = _w;
}

zcm::ivec4::ivec4(int32_t _x, int32_t _y, ivec2 zw) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = zw._data[0];
    _data[3] = zw._data[1];
}

zcm::ivec4 zcm::make_ivec4(const int32_t* ptr) noexcept
{
    assert(ptr);
    return zcm::ivec4{ptr[0], ptr[1], ptr[2], ptr[3]};
}

namespace zcm {
ZCM_IMPL_V4_BINOP(int32_t, zcm::ivec4, +)
ZCM_IMPL_V4_BINOP(int32_t, zcm::ivec4, -)
ZCM_IMPL_V4_BINOP(int32_t, zcm::ivec4, *)
ZCM_IMPL_V4_BINOP(int32_t, zcm::ivec4, /)
}

ZCM_IMPL_V4_COMPOUND_OP(int32_t, zcm::ivec4, +=)
ZCM_IMPL_V4_COMPOUND_OP(int32_t, zcm::ivec4, -=)
ZCM_IMPL_V4_COMPOUND_OP(int32_t, zcm::ivec4, *=)
ZCM_IMPL_V4_COMPOUND_OP(int32_t, zcm::ivec4, /=)

zcm::ivec4 zcm::operator -(zcm::ivec4 first) noexcept
{
    return { -first._data[0],
             -first._data[1],
             -first._data[2],
             -first._data[3] };
}


zcm::ivec4 zcm::operator +(zcm::ivec4 first) noexcept
{
    return { +first._data[0],
             +first._data[1],
             +first._data[2],
             +first._data[3] };
}

zcm::ivec4& zcm::ivec4::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    ++_data[2];
    ++_data[3];
    return *this;
}

zcm::ivec4 zcm::ivec4::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    ++_data[2];
    ++_data[3];
    return tmp;
}

zcm::ivec4& zcm::ivec4::operator--() noexcept
{
    --_data[0];
    --_data[1];
    --_data[2];
    --_data[3];
    return *this;
}

zcm::ivec4  zcm::ivec4::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    --_data[2];
    --_data[3];
    return tmp;
}

bool zcm::operator==(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w;
}

bool zcm::operator!=(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    return !(first == second);
}

bool zcm::operator <(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    if (first._data[0] < second._data[0]) return true;
    if (first._data[0] > second._data[0]) return false;
    if (first._data[1] < second._data[1]) return true;
    if (first._data[1] > second._data[1]) return false;
    if (first._data[2] < second._data[2]) return true;
    if (first._data[2] > second._data[2]) return false;
    if (first._data[3] < second._data[3]) return true;
    return false;
}

bool zcm::operator<=(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    return !(second < first);
}

bool zcm::operator >(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    return second < first;
}

bool zcm::operator>=(zcm::ivec4 first, zcm::ivec4 second) noexcept
{
    return !(first < second);
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

zcm::ivec4::operator zcm::bvec4() const noexcept
{
    return { bool(_data[0]), bool(_data[1]), bool(_data[2]), bool(_data[3]) };
}
