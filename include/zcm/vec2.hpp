#pragma once

#include <stdint.h>
#include <zcm/detail/vec2_access.hpp>
#include <zcm/init.hpp>

namespace zcm
{
    struct vec2
    {
        vec2() noexcept;
        explicit vec2(no_init_t) noexcept;
        vec2(float value) noexcept;
        vec2(int32_t) noexcept;
        vec2(int64_t) = delete;
        vec2(double)  = delete;
        vec2(float x, float y) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;


        void operator +=(vec2 other) noexcept;
        void operator -=(vec2 other) noexcept;
        void operator *=(vec2 other) noexcept;
        void operator /=(vec2 other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        vec2& operator++()    noexcept;
        vec2  operator++(int) noexcept;
        vec2& operator--()    noexcept;
        vec2  operator--(int) noexcept;

        union{
            float _data[2];
            detail::scalar_accessor_2<float, 0> x, r, s;
            detail::scalar_accessor_2<float, 1> y, g, t;
#ifndef ZCM_DISABLE_SWIZZLE
            detail::shuffle_accessor_2<float, vec2, 0, 0> xx, rr, ss;
            detail::shuffle_accessor_2<float, vec2, 1, 0> yx, gr, ts;
            detail::shuffle_accessor_2<float, vec2, 0, 1> xy, rg, st;
            detail::shuffle_accessor_2<float, vec2, 1, 1> yy, gg, tt;
#endif // ZCM_DISABLE_SWIZZLE
        };
    };

    bool operator==(vec2 first, vec2 second) noexcept;
    bool operator!=(vec2 first, vec2 second) noexcept;

    vec2 operator +(vec2 first) noexcept;
    vec2 operator -(vec2 first) noexcept;

    vec2 operator +(vec2 first, vec2 second) noexcept;
    vec2 operator -(vec2 first, vec2 second) noexcept;
    vec2 operator *(vec2 first, vec2 second) noexcept;
    vec2 operator /(vec2 first, vec2 second) noexcept;

    vec2 operator +(vec2 vec, float scalar) noexcept;
    vec2 operator -(vec2 vec, float scalar) noexcept;
    vec2 operator *(vec2 vec, float scalar) noexcept;
    vec2 operator /(vec2 vec, float scalar) noexcept;

    vec2 operator +(vec2 vec, float scalar) noexcept;
    vec2 operator -(vec2 vec, float scalar) noexcept;
    vec2 operator *(float scalar, vec2 vec) noexcept;
    vec2 operator /(float scalar, vec2 vec) noexcept;

}


