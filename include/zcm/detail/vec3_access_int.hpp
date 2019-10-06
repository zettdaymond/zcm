#pragma once
namespace zcm {
struct ivec2;
struct ivec3;
namespace detail {
#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
    extern template scalar_accessor_3<int32_t,x>::operator int32_t() const noexcept; \
    extern template void scalar_accessor_3<int32_t,x>::operator=(int32_t) noexcept;  \
    extern template void scalar_accessor_3<int32_t,x>::operator+=(int32_t) noexcept; \
    extern template void scalar_accessor_3<int32_t,x>::operator-=(int32_t) noexcept; \
    extern template void scalar_accessor_3<int32_t,x>::operator*=(int32_t) noexcept; \
    extern template void scalar_accessor_3<int32_t,x>::operator/=(int32_t) noexcept; \

#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(x) \
    extern template void scalar_accessor_3i<int32_t, x>::operator%=(int32_t) noexcept; \
    extern template void scalar_accessor_3i<int32_t, x>::operator|=(int32_t) noexcept; \
    extern template void scalar_accessor_3i<int32_t, x>::operator&=(int32_t) noexcept; \
    extern template void scalar_accessor_3i<int32_t, x>::operator^=(int32_t) noexcept; \
    extern template void scalar_accessor_3i<int32_t, x>::operator<<=(int32_t) noexcept; \
    extern template void scalar_accessor_3i<int32_t, x>::operator>>=(int32_t) noexcept; \

ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(2)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(1)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT(2)
#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR
#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR_INT

#ifndef ZCM_DISABLE_SWIZZLE

#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
    extern template shuffle_accessor_3<int32_t, ivec2, x, y>::operator ivec2() const noexcept;

#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
    extern template shuffle_accessor_3<int32_t, ivec3, x, y, z>::operator ivec3() const noexcept;


ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 2)

ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 2)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 2)
#undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2
#undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3
#endif // ZCM_DISABLE_SWIZZLE
}
}
