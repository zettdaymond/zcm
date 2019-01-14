#pragma once

namespace zcm {

    struct vec2;

namespace detail {

    template<int index>
    struct scalar_accessor_2
    {
        float _data[2];

        void operator +=(float s) noexcept;
        void operator -=(float s) noexcept;
        void operator *=(float s) noexcept;
        void operator /=(float s) noexcept;
        void operator  =(float s) noexcept;
        operator float() const noexcept;
    };

    template<typename T, int... indices>
    struct shuffle_accessor_2
    {
        float _data[2];

        operator T() const noexcept;
    };

#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
    extern template scalar_accessor_2<x>::operator float() const noexcept; \
    extern template void scalar_accessor_2<x>::operator=(float) noexcept;  \
    extern template void scalar_accessor_2<x>::operator+=(float) noexcept; \
    extern template void scalar_accessor_2<x>::operator-=(float) noexcept; \
    extern template void scalar_accessor_2<x>::operator*=(float) noexcept; \
    extern template void scalar_accessor_2<x>::operator/=(float) noexcept; \

#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(x, y) \
    extern template shuffle_accessor_2<vec2, x, y>::operator vec2() const noexcept;

ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)

ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(0, 1)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 0)
ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR(1, 1)

#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR
#undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR
}
}
