#pragma once

#include <zcm/access.hpp>

namespace zcm
{

    struct vec2;
    struct vec3
    {
        vec3() noexcept;
        vec3(float value) noexcept;
        vec3(float x, float y, float z) noexcept;

        vec3(vec2 xy, float z) noexcept;
        vec3(float x, vec2 yz) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;

        void operator +=(const vec3& other) noexcept;
        void operator -=(const vec3& other) noexcept;
        void operator *=(const vec3& other) noexcept;
        void operator /=(const vec3& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        union{
            float _data[3];
            _scalar_accessor<0, 3> x;
            _scalar_accessor<1, 3> y;
            _scalar_accessor<2, 3> z;

            _shuffle_accessor<vec2, 0, 0> xx;
            _shuffle_accessor<vec2, 1, 0> yx;
            _shuffle_accessor<vec2, 2, 0> zx;
            _shuffle_accessor<vec2, 0, 1> xy;
            _shuffle_accessor<vec2, 1, 1> yy;
            _shuffle_accessor<vec2, 2, 1> zy;
            _shuffle_accessor<vec2, 0, 2> xz;
            _shuffle_accessor<vec2, 1, 2> yz;
            _shuffle_accessor<vec2, 2, 2> zz;

            _shuffle_accessor<vec3, 0, 0, 0> xxx;
            _shuffle_accessor<vec3, 1, 0, 0> yxx;
            _shuffle_accessor<vec3, 2, 0, 0> zxx;
            _shuffle_accessor<vec3, 0, 1, 0> xyx;
            _shuffle_accessor<vec3, 1, 1, 0> yyx;
            _shuffle_accessor<vec3, 2, 1, 0> zyx;
            _shuffle_accessor<vec3, 0, 2, 0> xzx;
            _shuffle_accessor<vec3, 1, 2, 0> yzx;
            _shuffle_accessor<vec3, 2, 2, 0> zzx;
            _shuffle_accessor<vec3, 0, 0, 1> xxy;
            _shuffle_accessor<vec3, 1, 0, 1> yxy;
            _shuffle_accessor<vec3, 2, 0, 1> zxy;
            _shuffle_accessor<vec3, 0, 1, 1> xyy;
            _shuffle_accessor<vec3, 1, 1, 1> yyy;
            _shuffle_accessor<vec3, 2, 1, 1> zyy;
            _shuffle_accessor<vec3, 0, 2, 1> xzy;
            _shuffle_accessor<vec3, 1, 2, 1> yzy;
            _shuffle_accessor<vec3, 2, 2, 1> zzy;
            _shuffle_accessor<vec3, 0, 0, 2> xxz;
            _shuffle_accessor<vec3, 1, 0, 2> yxz;
            _shuffle_accessor<vec3, 2, 0, 2> zxz;
            _shuffle_accessor<vec3, 0, 1, 2> xyz;
            _shuffle_accessor<vec3, 1, 1, 2> yyz;
            _shuffle_accessor<vec3, 2, 1, 2> zyz;
            _shuffle_accessor<vec3, 0, 2, 2> xzz;
            _shuffle_accessor<vec3, 1, 2, 2> yzz;
            _shuffle_accessor<vec3, 2, 2, 2> zzz;
        };
    };

    bool operator==(const vec3& first, const vec3& second) noexcept;
    bool operator!=(const vec3& first, const vec3& second) noexcept;

    vec3 operator -(const vec3& first) noexcept;
    vec3 operator +(const vec3& first) noexcept;

    vec3 operator +(const vec3& first, const vec3& second) noexcept;
    vec3 operator -(const vec3& first, const vec3& second) noexcept;
    vec3 operator *(const vec3& first, const vec3& second) noexcept;
    vec3 operator /(const vec3& first, const vec3& second) noexcept;

    vec3 operator *(const vec3& vec, const float scalar) noexcept;
    vec3 operator /(const vec3& vec, const float scalar) noexcept;

    vec3 operator *(const float scalar, const vec3& vec) noexcept;
    vec3 operator /(const float scalar, const vec3& vec) noexcept;

    //----------------------

    #define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
        extern template _scalar_accessor<x, 3>::operator float() const noexcept; \
        extern template void _scalar_accessor<x, 3>::operator=(float) noexcept;  \
        extern template void _scalar_accessor<x, 3>::operator+=(float) noexcept; \
        extern template void _scalar_accessor<x, 3>::operator-=(float) noexcept; \
        extern template void _scalar_accessor<x, 3>::operator*=(float) noexcept; \
        extern template void _scalar_accessor<x, 3>::operator/=(float) noexcept; \

    #define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
    extern template  _shuffle_accessor<vec2, x, y>::operator vec2() const noexcept;

    #define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
        extern template  _shuffle_accessor<vec3, x, y, z>::operator vec3() const noexcept;

    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(2)

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

    #undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR
    #undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2
    #undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3
}
