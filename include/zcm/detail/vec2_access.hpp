#pragma once
#include <stdint.h>

namespace zcm {

    struct vec2;
    struct ivec2;

namespace detail {

template<typename T, int index>
struct scalar_accessor_2
{
    T _data[2];

    void operator +=(T s) noexcept {
        _data[index] += s;
    }
    void operator -=(T s) noexcept {
        _data[index] -= s;
    }
    void operator *=(T s) noexcept {
        _data[index] *= s;
    }
    void operator /=(T s) noexcept {
        _data[index] /= s;
    }

    void operator =(T s) noexcept{
        _data[index] = s;
    }
    T& operator++()    noexcept {
        return ++_data[index];
    }
    T  operator++(int) noexcept {
        return _data[index]++;
    }
    T& operator--()    noexcept {
        return --_data[index];
    }
    T  operator--(int) noexcept {
        return _data[index]--;
    }

    operator T() const noexcept {
        return _data[index];
    }
};


template <typename T, int index>
struct scalar_accessor_2i : public scalar_accessor_2<T, index>
{
    void operator %=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] %= s;
    }
    void operator |=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] |= s;
    }
    void operator &=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] &= s;
    }
    void operator ^=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] ^= s;
    }
    void operator<<=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] <<= s;
    }
    void operator>>=(T s) noexcept {
        scalar_accessor_2<T,index>::_data[index] >>= s;
    }
};

#ifndef ZCM_RELEASE_BUILD

#define ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(T, x) \
    extern template      scalar_accessor_2<T, x>::operator T() const noexcept; \
    extern template void scalar_accessor_2<T, x>::operator=(T) noexcept;  \
    extern template void scalar_accessor_2<T, x>::operator+=(T) noexcept; \
    extern template void scalar_accessor_2<T, x>::operator-=(T) noexcept; \
    extern template void scalar_accessor_2<T, x>::operator*=(T) noexcept; \
    extern template void scalar_accessor_2<T, x>::operator/=(T) noexcept; \
    extern template T&   scalar_accessor_2<T, x>::operator++() noexcept; \
    extern template T    scalar_accessor_2<T, x>::operator++(int) noexcept; \
    extern template T&   scalar_accessor_2<T, x>::operator--() noexcept; \
    extern template T    scalar_accessor_2<T, x>::operator--(int) noexcept;

#define ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT(T, x) \
    extern template void scalar_accessor_2i<T, x>::operator%=(T) noexcept; \
    extern template void scalar_accessor_2i<T, x>::operator|=(T) noexcept; \
    extern template void scalar_accessor_2i<T, x>::operator&=(T) noexcept; \
    extern template void scalar_accessor_2i<T, x>::operator^=(T) noexcept; \
    extern template void scalar_accessor_2i<T, x>::operator<<=(T) noexcept; \
    extern template void scalar_accessor_2i<T, x>::operator>>=(T) noexcept; \

ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(float, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(float, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(int32_t, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(int32_t, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT(int32_t, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT(int32_t, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT(uint32_t, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT(uint32_t, 1)
#undef ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACCESSOR
#undef ZCM_VEC2_EXTERN_TEMPLATE_SCALAR_ACESSOR_INT

#endif // ZCM_RELEASE_BUILD


#ifndef ZCM_DISABLE_SWIZZLE

template<typename T, typename V, int... indices>
struct shuffle_accessor_2
{
    T _data[2];

    operator V() const noexcept {
        return V{_data[indices]...};
    }
};

#ifndef ZCM_RELEASE_BUILD

#define ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(T, V, x, y) \
    extern template shuffle_accessor_2<T, V, x, y>::operator V() const noexcept;

ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(float, zcm::vec2, 0, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(float, zcm::vec2, 0, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(float, zcm::vec2, 1, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(float, zcm::vec2, 1, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, zcm::ivec2, 0, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, zcm::ivec2, 0, 1)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, zcm::ivec2, 1, 0)
ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(int32_t, zcm::ivec2, 1, 1)
#undef ZCM_VEC2_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR

#endif // ZCM_RELEASE_BUILD

#endif // ZCM_DISABLE_SWIZZLE
}
}
