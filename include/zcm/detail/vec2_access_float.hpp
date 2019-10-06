#pragma once
namespace zcm {
struct vec2;
namespace detail {
#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
    extern template      scalar_accessor_2<float, x>::operator float() const noexcept; \
    extern template void scalar_accessor_2<float, x>::operator= (float) noexcept;  \
    extern template void scalar_accessor_2<float, x>::operator+=(float) noexcept; \
    extern template void scalar_accessor_2<float, x>::operator-=(float) noexcept; \
    extern template void scalar_accessor_2<float, x>::operator*=(float) noexcept; \
    extern template void scalar_accessor_2<float, x>::operator/=(float) noexcept; \

ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR

#ifndef ZCM_DISABLE_SWIZZLE
#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(x, y) \
    extern template shuffle_accessor_2<float, vec2, x, y>::operator vec2() const noexcept;

ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 1)
#undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR
#endif // ZCM_DISABLE_SWIZZLE
}
}
