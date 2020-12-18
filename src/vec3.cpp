#include <cassert>
#include <type_traits>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/detail/impl_op_macro.hpp>


static_assert(std::is_standard_layout<zcm::vec3>::value, "");
static_assert(sizeof(zcm::vec3) == 3 * sizeof(float), "extra padding detected!");

zcm::vec3::vec3() noexcept :
    vec3(0.0f)
{}

zcm::vec3::vec3(zcm::no_init_t) noexcept
{}

zcm::vec3::vec3(float value) noexcept
{
    _data[0] = value;
    _data[1] = value;
    _data[2] = value;
}

zcm::vec3::vec3(int32_t value) noexcept : vec3(static_cast<float>(value))
{}

zcm::vec3::vec3(float _x, float _y, float _z) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
    _data[2] = _z;
}

zcm::vec3::vec3(zcm::vec2 xy, float _z) noexcept
{
    _data[0] = xy._data[0];
    _data[1] = xy._data[1];
    _data[2] = _z;
}

zcm::vec3::vec3(float _x, zcm::vec2 yz) noexcept
{
    _data[0] = _x;
    _data[1] = yz._data[0];
    _data[2] = yz._data[1];
}

zcm::vec3 zcm::make_vec3(const float * ptr) noexcept
{
    assert(ptr);
    return zcm::vec3{ptr[0], ptr[1], ptr[2]};
}

namespace zcm {
ZCM_IMPL_V3_BINOP(float, zcm::vec3, +)
ZCM_IMPL_V3_BINOP(float, zcm::vec3, -)
ZCM_IMPL_V3_BINOP(float, zcm::vec3, *)
ZCM_IMPL_V3_BINOP(float, zcm::vec3, /)
}

ZCM_IMPL_V3_COMPOUND_OP(float, zcm::vec3, +=)
ZCM_IMPL_V3_COMPOUND_OP(float, zcm::vec3, -=)
ZCM_IMPL_V3_COMPOUND_OP(float, zcm::vec3, *=)
ZCM_IMPL_V3_COMPOUND_OP(float, zcm::vec3, /=)


zcm::vec3 zcm::operator -(zcm::vec3 first) noexcept
{
    return { -first.x, -first.y, -first.z };
}

zcm::vec3 zcm::operator +(zcm::vec3 first) noexcept
{
    return { +first.x, +first.y, +first.z };
}

zcm::vec3& zcm::vec3::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    ++_data[2];
    return *this;
}

zcm::vec3 zcm::vec3::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    ++_data[2];
    return tmp;
}

zcm::vec3& zcm::vec3::operator--() noexcept
{
    --_data[0];
    --_data[1];
    --_data[2];
    return *this;
}

zcm::vec3  zcm::vec3::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    --_data[2];
    return tmp;
}

bool zcm::operator==(const zcm::vec3 &first, const zcm::vec3 &second) noexcept
{
    return first._data[0] == second._data[0] && first._data[1] == second._data[1] && first._data[2] == second._data[2];
}

bool zcm::operator!=(const zcm::vec3 &first, const zcm::vec3 &second) noexcept
{
    return !(first == second);
}


float& zcm::vec3::operator[](unsigned val) noexcept
{
    assert(val < 3);
    return _data[val];
}

const float& zcm::vec3::operator[](unsigned val) const noexcept
{
    assert(val < 3);
    return _data[val];
}

