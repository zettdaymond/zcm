#include <zcm/vec2.hpp>
#include <zcm/ivec2.hpp>

namespace zcm {
namespace detail {

template<typename T, int index>
void scalar_accessor_2<T, index>::operator +=(T s) noexcept
{
	_data[index] += s;
}

template<typename T, int index>
void scalar_accessor_2<T, index>::operator -=(T s) noexcept
{
	_data[index] -= s;
}

template<typename T, int index>
void scalar_accessor_2<T, index>::operator *=(T s) noexcept
{
	_data[index] *= s;
}

template<typename T, int index>
void scalar_accessor_2<T, index>::operator /=(T s) noexcept
{
    _data[index] /= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator %=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] %= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator |=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] |= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator &=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] &= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator ^=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] ^= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator<<=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] <<= s;
}

template<typename T, int index>
void scalar_accessor_2i<T, index>::operator>>=(T s) noexcept
{
    scalar_accessor_2<T,index>::_data[index] >>= s;
}

template<typename T, int index>
void scalar_accessor_2<T, index>::operator =(T s) noexcept
{
    _data[index] = s;
}

template<typename T, int index>
T &scalar_accessor_2<T, index>::operator++() noexcept
{
    return ++_data[index];
}

template<typename T, int index>
T scalar_accessor_2<T, index>::operator++(int) noexcept
{
    return _data[index]++;
}

template<typename T, int index>
T &scalar_accessor_2<T, index>::operator--() noexcept
{
    return --_data[index];
}

template<typename T, int index>
T scalar_accessor_2<T, index>::operator--(int) noexcept
{
    return _data[index]--;
}

template<typename T, int index>
scalar_accessor_2<T, index>::operator T() const noexcept
{
	return _data[index];
}



#define ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(T, x) \
    template      scalar_accessor_2<T, x>::operator T() const noexcept; \
    template void scalar_accessor_2<T, x>::operator=(T) noexcept;  \
    template void scalar_accessor_2<T, x>::operator+=(T) noexcept; \
    template void scalar_accessor_2<T, x>::operator-=(T) noexcept; \
    template void scalar_accessor_2<T, x>::operator*=(T) noexcept; \
    template void scalar_accessor_2<T, x>::operator/=(T) noexcept; \
    template T&   scalar_accessor_2<T, x>::operator++() noexcept; \
    template T    scalar_accessor_2<T, x>::operator++(int) noexcept; \
    template T&   scalar_accessor_2<T, x>::operator--() noexcept; \
    template T    scalar_accessor_2<T, x>::operator--(int) noexcept;

#define ZCM_VEC2_TEMPLATE_SCALAR_ACESSOR_INT(T, x) \
    template void scalar_accessor_2i<T, x>::operator%=(T) noexcept; \
    template void scalar_accessor_2i<T, x>::operator|=(T) noexcept; \
    template void scalar_accessor_2i<T, x>::operator&=(T) noexcept; \
    template void scalar_accessor_2i<T, x>::operator^=(T) noexcept; \
    template void scalar_accessor_2i<T, x>::operator<<=(T) noexcept; \
    template void scalar_accessor_2i<T, x>::operator>>=(T) noexcept; \

ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(float, 0)
ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(float, 1)
ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(int32_t, 0)
ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(int32_t, 1)
ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 0)
ZCM_VEC2_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 1)
ZCM_VEC2_TEMPLATE_SCALAR_ACESSOR_INT(int32_t, 0)
ZCM_VEC2_TEMPLATE_SCALAR_ACESSOR_INT(int32_t, 1)
ZCM_VEC2_TEMPLATE_SCALAR_ACESSOR_INT(uint32_t, 0)
ZCM_VEC2_TEMPLATE_SCALAR_ACESSOR_INT(uint32_t, 1)

#ifndef ZCM_DISABLE_SWIZZLE

template<typename T, typename V, int... indices>
shuffle_accessor_2<T, V, indices...>::operator V() const noexcept
{
	return V{_data[indices]...};
}

#define ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(T, V, x, y) \
    template shuffle_accessor_2<T, V, x, y>::operator V() const noexcept;

ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(float, vec2, 0, 0)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(float, vec2, 0, 1)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(float, vec2, 1, 0)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(float, vec2, 1, 1)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, ivec2, 0, 0)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, ivec2, 0, 1)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, ivec2, 1, 0)
ZCM_VEC2_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, ivec2, 1, 1)
#endif // ZCM_DISABLE_SWIZZLE

}
}
