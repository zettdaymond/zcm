#include <cassert>
#include <type_traits>
#include <zcm/vec4.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/detail/impl_op_macro.hpp>


static_assert(std::is_standard_layout<zcm::vec4>::value, "");
static_assert(sizeof(zcm::vec4) == 4 * sizeof(float), "extra padding detected!");

zcm::vec4::vec4() noexcept :
    vec4(0.0f)
{}

zcm::vec4::vec4(zcm::no_init_t) noexcept
{}

zcm::vec4::vec4(float value) noexcept
{
    _data[0] = value;
    _data[1] = value;
    _data[2] = value;
    _data[3] = value;
}

zcm::vec4::vec4(int32_t value) noexcept : vec4(static_cast<float>(value))
{}

zcm::vec4::vec4(float _x, float _y, float _z, float _w) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = _z;
    _data[3] = _w;
}

zcm::vec4::vec4(vec3 xyz, float _w) noexcept
{
    _data[0] = xyz._data[0];
    _data[1] = xyz._data[1];
    _data[2] = xyz._data[2];
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, vec3 yzw) noexcept
{
    _data[0] = _x;
    _data[1] = yzw._data[0];
    _data[2] = yzw._data[1];
    _data[3] = yzw._data[2];
}

zcm::vec4::vec4(vec2 xy, vec2 zw) noexcept
{
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = zw._data[0];
    _data[3] = zw._data[1];
}

zcm::vec4::vec4(vec2 xy, float _z, float _w) noexcept
{
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = _z;
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, vec2 yz, float _w) noexcept
{
    _data[0] = _x;
    _data[1] = yz._data[0];
    _data[2] = yz._data[1];
    _data[3] = _w;
}

zcm::vec4::vec4(float _x, float _y, vec2 zw) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = zw._data[0];
    _data[3] = zw._data[1];
}

zcm::vec4 zcm::make_vec4(const float * ptr) noexcept
{
    assert(ptr);
    return zcm::vec4{ptr[0], ptr[1], ptr[2], ptr[3]};
}

namespace zcm {
ZCM_IMPL_V4_BINOP(float, zcm::vec4, +)
ZCM_IMPL_V4_BINOP(float, zcm::vec4, -)
ZCM_IMPL_V4_BINOP(float, zcm::vec4, *)
ZCM_IMPL_V4_BINOP(float, zcm::vec4, /)
}

ZCM_IMPL_V4_COMPOUND_OP(float, zcm::vec4, +=)
ZCM_IMPL_V4_COMPOUND_OP(float, zcm::vec4, -=)
ZCM_IMPL_V4_COMPOUND_OP(float, zcm::vec4, *=)
ZCM_IMPL_V4_COMPOUND_OP(float, zcm::vec4, /=)



zcm::vec4 zcm::operator -(zcm::vec4 first) noexcept
{
    return vec4{ -first._data[0],
                 -first._data[1],
                 -first._data[2],
                 -first._data[3] };
}


zcm::vec4 zcm::operator +(zcm::vec4 first) noexcept
{
    return { +first._data[0],
             +first._data[1],
             +first._data[2],
             +first._data[3] };
}

zcm::vec4& zcm::vec4::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    ++_data[2];
    ++_data[3];
    return *this;
}

zcm::vec4 zcm::vec4::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    ++_data[2];
    ++_data[3];
    return tmp;
}

zcm::vec4& zcm::vec4::operator--() noexcept
{
    --_data[0];
    --_data[1];
    --_data[2];
    --_data[3];
    return *this;
}

zcm::vec4  zcm::vec4::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    --_data[2];
    --_data[3];
    return tmp;
}

bool zcm::operator==(const zcm::vec4 &first, const zcm::vec4 &second) noexcept
{
    return first._data[0] == second._data[0] && first._data[1] == second._data[1] && first._data[2] == second._data[2] && first._data[3] == second._data[3];
}

bool zcm::operator!=(const zcm::vec4 &first, const zcm::vec4 &second) noexcept
{
    return !(first == second);
}

float& zcm::vec4::operator[](unsigned val) noexcept
{
    assert(val < 4);
    return _data[val];
}

const float& zcm::vec4::operator[](unsigned val) const noexcept
{
    assert(val < 4);
    return _data[val];
}
