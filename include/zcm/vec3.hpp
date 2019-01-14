#pragma once

#include <zcm/detail/vec3_access.hpp>

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
            detail::scalar_accessor_3<0> x;
            detail::scalar_accessor_3<1> y;
            detail::scalar_accessor_3<2> z;

            detail::shuffle_accessor_3<vec2, 0, 0> xx;
            detail::shuffle_accessor_3<vec2, 1, 0> yx;
            detail::shuffle_accessor_3<vec2, 2, 0> zx;
            detail::shuffle_accessor_3<vec2, 0, 1> xy;
            detail::shuffle_accessor_3<vec2, 1, 1> yy;
            detail::shuffle_accessor_3<vec2, 2, 1> zy;
            detail::shuffle_accessor_3<vec2, 0, 2> xz;
            detail::shuffle_accessor_3<vec2, 1, 2> yz;
            detail::shuffle_accessor_3<vec2, 2, 2> zz;

            detail::shuffle_accessor_3<vec3, 0, 0, 0> xxx;
            detail::shuffle_accessor_3<vec3, 1, 0, 0> yxx;
            detail::shuffle_accessor_3<vec3, 2, 0, 0> zxx;
            detail::shuffle_accessor_3<vec3, 0, 1, 0> xyx;
            detail::shuffle_accessor_3<vec3, 1, 1, 0> yyx;
            detail::shuffle_accessor_3<vec3, 2, 1, 0> zyx;
            detail::shuffle_accessor_3<vec3, 0, 2, 0> xzx;
            detail::shuffle_accessor_3<vec3, 1, 2, 0> yzx;
            detail::shuffle_accessor_3<vec3, 2, 2, 0> zzx;
            detail::shuffle_accessor_3<vec3, 0, 0, 1> xxy;
            detail::shuffle_accessor_3<vec3, 1, 0, 1> yxy;
            detail::shuffle_accessor_3<vec3, 2, 0, 1> zxy;
            detail::shuffle_accessor_3<vec3, 0, 1, 1> xyy;
            detail::shuffle_accessor_3<vec3, 1, 1, 1> yyy;
            detail::shuffle_accessor_3<vec3, 2, 1, 1> zyy;
            detail::shuffle_accessor_3<vec3, 0, 2, 1> xzy;
            detail::shuffle_accessor_3<vec3, 1, 2, 1> yzy;
            detail::shuffle_accessor_3<vec3, 2, 2, 1> zzy;
            detail::shuffle_accessor_3<vec3, 0, 0, 2> xxz;
            detail::shuffle_accessor_3<vec3, 1, 0, 2> yxz;
            detail::shuffle_accessor_3<vec3, 2, 0, 2> zxz;
            detail::shuffle_accessor_3<vec3, 0, 1, 2> xyz;
            detail::shuffle_accessor_3<vec3, 1, 1, 2> yyz;
            detail::shuffle_accessor_3<vec3, 2, 1, 2> zyz;
            detail::shuffle_accessor_3<vec3, 0, 2, 2> xzz;
            detail::shuffle_accessor_3<vec3, 1, 2, 2> yzz;
            detail::shuffle_accessor_3<vec3, 2, 2, 2> zzz;
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
}
