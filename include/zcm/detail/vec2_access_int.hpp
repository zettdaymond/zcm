#pragma once
namespace zcm {
struct ivec2;
namespace detail {
#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
    extern template      scalar_accessor_2<int32_t, x>::operator int32_t() const noexcept; \
    extern template void scalar_accessor_2<int32_t, x>::operator= (int32_t) noexcept;  \
    extern template void scalar_accessor_2<int32_t, x>::operator+=(int32_t) noexcept; \
    extern template void scalar_accessor_2<int32_t, x>::operator-=(int32_t) noexcept; \
    extern template void scalar_accessor_2<int32_t, x>::operator*=(int32_t) noexcept; \
    extern template void scalar_accessor_2<int32_t, x>::operator/=(int32_t) noexcept; \

ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR

#ifndef ZCM_DISABLE_SWIZZLE
#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(x, y) \
    extern template shuffle_accessor_2<int32_t, ivec2, x, y>::operator ivec2() const noexcept;

ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 1)
#undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR
#endif // ZCM_DISABLE_SWIZZLE
}
}
