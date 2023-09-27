#pragma once

#include <stdint.h>

namespace zcm {
    struct vec2;
    struct vec3;
    struct ivec2;
    struct ivec3;

namespace detail {

template<typename T, int index>
struct scalar_accessor_3
{
    T _data[3];

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
    void operator  =(T s) noexcept {
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


template<typename T, int index>
T format_as(const scalar_accessor_3<T, index> &a)
{
    return static_cast<T>(a);
}


template <typename T, int index>
struct scalar_accessor_3i : public scalar_accessor_3<T, index>
{
    void operator %=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] %= s;
    }
    void operator |=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] |= s;
    }
    void operator &=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] &= s;
    }
    void operator ^=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] ^= s;
    }
    void operator<<=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] <<= s;
    }
    void operator>>=(T s) noexcept {
        scalar_accessor_3<T,index>::_data[index] >>= s;
    }
};


template<typename T, int index>
T format_as(const scalar_accessor_3i<T, index> &a)
{
    return static_cast<T>(a);
}


#ifndef ZCM_RELEASE_BUILD

#define ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(T, x) \
    extern template scalar_accessor_3<T, x>::operator T() const noexcept; \
    extern template void scalar_accessor_3<T, x>::operator=(T) noexcept;  \
    extern template void scalar_accessor_3<T, x>::operator+=(T) noexcept; \
    extern template void scalar_accessor_3<T, x>::operator-=(T) noexcept; \
    extern template void scalar_accessor_3<T, x>::operator*=(T) noexcept; \
    extern template void scalar_accessor_3<T, x>::operator/=(T) noexcept; \
    extern template T&   scalar_accessor_3<T, x>::operator++() noexcept; \
    extern template T    scalar_accessor_3<T, x>::operator++(int) noexcept; \
    extern template T&   scalar_accessor_3<T, x>::operator--() noexcept; \
    extern template T    scalar_accessor_3<T, x>::operator--(int) noexcept;

#define ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(T, x) \
    extern template void scalar_accessor_3i<T, x>::operator%=(T) noexcept; \
    extern template void scalar_accessor_3i<T, x>::operator|=(T) noexcept; \
    extern template void scalar_accessor_3i<T, x>::operator&=(T) noexcept; \
    extern template void scalar_accessor_3i<T, x>::operator^=(T) noexcept; \
    extern template void scalar_accessor_3i<T, x>::operator<<=(T) noexcept; \
    extern template void scalar_accessor_3i<T, x>::operator>>=(T) noexcept; \

ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(float, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(float, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(float, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(int32_t, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(int32_t, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(int32_t, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 2)
#undef ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR

ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 2)
#undef ZCM_VEC3_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT


#endif // ZCM_RELEASE_BUILD

#ifndef ZCM_DISABLE_SWIZZLE
template<typename T, typename V, int... indices>
struct shuffle_accessor_3
{
    T _data[3];

    operator V() const noexcept {
        return V{_data[indices]...};
    }
};

template<typename T, typename V, int... indices>
V format_as(const shuffle_accessor_3<T, V, indices...> &a)
{
    return static_cast<V>(a);
}


#ifndef ZCM_RELEASE_BUILD

#define ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(T, V, x, y) \
    extern template shuffle_accessor_3<T, V, x, y>::operator V() const noexcept;

#define ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(T, V, x, y, z) \
    extern template shuffle_accessor_3<T, V, x, y, z>::operator V() const noexcept;


ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 2)

ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 2)

ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 2)

ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 0)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 1)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 2)
ZCM_VEC3_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 2)

#endif // ZCM_RELEASE_BUILD

#endif // ZCM_DISABLE_SWIZZLE

}
}
