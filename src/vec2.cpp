#include <cassert>
#include <type_traits>
#include <zcm/vec2.hpp>
#include <zcm/detail/impl_op_macro.hpp>


static_assert (std::is_standard_layout<zcm::vec2>::value, "");
static_assert(sizeof(zcm::vec2) == 2 * sizeof(float), "extra padding detected!");

zcm::vec2::vec2() noexcept :
    vec2(0.0f)
{}

zcm::vec2::vec2(zcm::no_init_t) noexcept
{}

zcm::vec2::vec2(float value) noexcept
{
    _data[0] = value;
    _data[1] = value;
}

zcm::vec2::vec2(int32_t value) noexcept : vec2(static_cast<float>(value))
{}

zcm::vec2::vec2(float _x, float _y) noexcept
{
    _data[0] = _x;
    _data[1] = _y;
}

zcm::vec2 zcm::make_vec2(const float * ptr) noexcept
{
    assert(ptr);
    return zcm::vec2{ptr[0], ptr[1]};
}

namespace zcm {
ZCM_IMPL_V2_BINOP(float, zcm::vec2, +)
ZCM_IMPL_V2_BINOP(float, zcm::vec2, -)
ZCM_IMPL_V2_BINOP(float, zcm::vec2, *)
ZCM_IMPL_V2_BINOP(float, zcm::vec2, /)
}

ZCM_IMPL_V2_COMPOUND_OP(float, zcm::vec2, +=)
ZCM_IMPL_V2_COMPOUND_OP(float, zcm::vec2, -=)
ZCM_IMPL_V2_COMPOUND_OP(float, zcm::vec2, *=)
ZCM_IMPL_V2_COMPOUND_OP(float, zcm::vec2, /=)


zcm::vec2 zcm::operator +(zcm::vec2 first) noexcept
{
    return { +first._data[0], +first._data[1] };
}

zcm::vec2 zcm::operator -(zcm::vec2 first) noexcept
{
    return { -first._data[0], -first._data[1] };
}

zcm::vec2& zcm::vec2::operator++() noexcept
{
    ++_data[0];
    ++_data[1];
    return *this;
}

zcm::vec2  zcm::vec2::operator++(int) noexcept
{
    auto tmp = *this;
    ++_data[0];
    ++_data[1];
    return tmp;
}

zcm::vec2& zcm::vec2::operator--() noexcept
{
    --_data[0];
    --_data[1];
    return *this;
}

zcm::vec2  zcm::vec2::operator--(int) noexcept
{
    auto tmp = *this;
    --_data[0];
    --_data[1];
    return tmp;
}

bool zcm::operator==(zcm::vec2 first, zcm::vec2 second) noexcept
{
    return first._data[0] == second._data[0] && first._data[1] == second._data[1];
}

bool zcm::operator!=(zcm::vec2 first, zcm::vec2 second) noexcept
{
    return !(first == second);
}


float& zcm::vec2::operator[](unsigned val) noexcept
{
    assert(val < 3);
    return _data[val];
}

const float& zcm::vec2::operator[](unsigned val) const noexcept
{
    assert(val < 3);
    return _data[val];
}

