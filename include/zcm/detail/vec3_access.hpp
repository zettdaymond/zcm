#pragma once

namespace zcm {

    struct vec2;
    struct vec3;

namespace detail {

    template<int index>
    struct scalar_accessor_3
    {
        float _data[3];

        void operator +=(float s) noexcept;
        void operator -=(float s) noexcept;
        void operator *=(float s) noexcept;
        void operator /=(float s) noexcept;
        void operator  =(float s) noexcept;
        operator float() const noexcept;
    };


#define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
    extern template scalar_accessor_3<x>::operator float() const noexcept; \
    extern template void scalar_accessor_3<x>::operator=(float) noexcept;  \
    extern template void scalar_accessor_3<x>::operator+=(float) noexcept; \
    extern template void scalar_accessor_3<x>::operator-=(float) noexcept; \
    extern template void scalar_accessor_3<x>::operator*=(float) noexcept; \
    extern template void scalar_accessor_3<x>::operator/=(float) noexcept; \



ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(2)
#undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR

#ifndef ZCM_DISABLE_SWIZZLE
template<typename T, int... indices>
struct shuffle_accessor_3
{
    float _data[3];

    operator T() const noexcept;
};

#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
    extern template shuffle_accessor_3<vec2, x, y>::operator vec2() const noexcept;

#define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
    extern template shuffle_accessor_3<vec3, x, y, z>::operator vec3() const noexcept;


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
