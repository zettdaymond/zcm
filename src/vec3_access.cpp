#include <stdint.h>
#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/ivec3.hpp>

namespace zcm {
namespace detail {

#ifndef ZCM_RELEASE_BUILD

#define ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(T, x) \
    template scalar_accessor_3<T, x>::operator T() const noexcept; \
    template void scalar_accessor_3<T, x>::operator=(T) noexcept;  \
    template void scalar_accessor_3<T, x>::operator+=(T) noexcept; \
    template void scalar_accessor_3<T, x>::operator-=(T) noexcept; \
    template void scalar_accessor_3<T, x>::operator*=(T) noexcept; \
    template void scalar_accessor_3<T, x>::operator/=(T) noexcept; \
    template T&   scalar_accessor_3<T, x>::operator++() noexcept; \
    template T    scalar_accessor_3<T, x>::operator++(int) noexcept; \
    template T&   scalar_accessor_3<T, x>::operator--() noexcept; \
    template T    scalar_accessor_3<T, x>::operator--(int) noexcept;

#define ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(T, x) \
    template void scalar_accessor_3i<T, x>::operator%=(T) noexcept; \
    template void scalar_accessor_3i<T, x>::operator|=(T) noexcept; \
    template void scalar_accessor_3i<T, x>::operator&=(T) noexcept; \
    template void scalar_accessor_3i<T, x>::operator^=(T) noexcept; \
    template void scalar_accessor_3i<T, x>::operator<<=(T) noexcept; \
    template void scalar_accessor_3i<T, x>::operator>>=(T) noexcept; \

ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(float, 0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(float, 1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(float, 2)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(int32_t, 0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(int32_t, 1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(int32_t, 2)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(uint32_t, 2)

ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(int32_t, 2)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR_INT(uint32_t, 2)


#ifndef ZCM_DISABLE_SWIZZLE

#define ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(T, V, x, y) \
    template shuffle_accessor_3<T, V, x, y>::operator V() const noexcept;

#define ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(T, V, x, y, z) \
    template shuffle_accessor_3<T, V, x, y, z>::operator V() const noexcept;


ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(float, vec2, 2, 2)

ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(int32_t, ivec2, 2, 2)

ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 0, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 1, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(float, vec3, 2, 2, 2)

ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 0, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 1, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(int32_t, ivec3, 2, 2, 2)

#endif // ZCM_DISABLE_SWIZZLE

#endif // ZCM_RELEASE_BUILD
}
}
