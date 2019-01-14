#pragma once

#include <zcm/detail/vec2_access.hpp>

namespace zcm
{
    struct vec2
    {
        vec2() noexcept;
        vec2(float value) noexcept;
        vec2(float x, float y) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;


        void operator +=(const vec2& other) noexcept;
        void operator -=(const vec2& other) noexcept;
        void operator *=(const vec2& other) noexcept;
        void operator /=(const vec2& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        union{
            float _data[2];
            detail::scalar_accessor_2<0> x;
            detail::scalar_accessor_2<1> y;

            detail::shuffle_accessor_2<vec2, 0, 0> xx;
            detail::shuffle_accessor_2<vec2, 0, 1> xy;
            detail::shuffle_accessor_2<vec2, 1, 0> yx;
            detail::shuffle_accessor_2<vec2, 1, 1> yy;
        };
    };

    bool operator==(const vec2& first, const vec2& second) noexcept;
    bool operator!=(const vec2& first, const vec2& second) noexcept;

    vec2 operator +(const vec2& first) noexcept;
    vec2 operator -(const vec2& first) noexcept;

    vec2 operator +(const vec2& first, const vec2& second) noexcept;
    vec2 operator -(const vec2& first, const vec2& second) noexcept;
    vec2 operator *(const vec2& first, const vec2& second) noexcept;
    vec2 operator /(const vec2& first, const vec2& second) noexcept;

    vec2 operator *(const vec2& vec, const float scalar) noexcept;
    vec2 operator /(const vec2& vec, const float scalar) noexcept;

    vec2 operator *(const float scalar, const vec2& vec) noexcept;
    vec2 operator /(const float scalar, const vec2& vec) noexcept;

}


