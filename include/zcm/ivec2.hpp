#pragma once

#include <stdint.h>
#include <zcm/detail/vec2_access.hpp>
#include <zcm/detail/vec2_access_int.hpp>
#include <zcm/init.hpp>

namespace zcm
{
    struct ivec2
    {
        ivec2() noexcept;
        explicit ivec2(no_init_t) noexcept;
        ivec2(int32_t value) noexcept;
        ivec2(int32_t x, int32_t y) noexcept;

        int32_t& operator[](unsigned val) noexcept;
        const int32_t& operator[](unsigned val) const noexcept;


        void operator +=(ivec2 other) noexcept;
        void operator -=(ivec2 other) noexcept;
        void operator *=(ivec2 other) noexcept;
        void operator /=(ivec2 other) noexcept;

        void operator +=(int32_t scalar) noexcept;
        void operator -=(int32_t scalar) noexcept;
        void operator *=(int32_t scalar) noexcept;
        void operator /=(int32_t scalar) noexcept;

        union{
            int32_t _data[2];
            detail::scalar_accessor_2<int32_t, 0> x, r, s;
            detail::scalar_accessor_2<int32_t, 1> y, g, t;
#ifndef ZCM_DISABLE_SWIZZLE
            detail::shuffle_accessor_2<int32_t, ivec2, 0, 0> xx, rr, ss;
            detail::shuffle_accessor_2<int32_t, ivec2, 1, 0> yx, gr, ts;
            detail::shuffle_accessor_2<int32_t, ivec2, 0, 1> xy, rg, st;
            detail::shuffle_accessor_2<int32_t, ivec2, 1, 1> yy, gg, tt;
#endif // ZCM_DISABLE_SWIZZLE
        };
    };

    bool operator==(ivec2 first, ivec2 second) noexcept;
    bool operator!=(ivec2 first, ivec2 second) noexcept;

    ivec2 operator +(ivec2 first) noexcept;
    ivec2 operator -(ivec2 first) noexcept;

    ivec2 operator +(ivec2 first, ivec2 second) noexcept;
    ivec2 operator -(ivec2 first, ivec2 second) noexcept;
    ivec2 operator *(ivec2 first, ivec2 second) noexcept;
    ivec2 operator /(ivec2 first, ivec2 second) noexcept;

    ivec2 operator *(ivec2 vec, int32_t scalar) noexcept;
    ivec2 operator /(ivec2 vec, int32_t scalar) noexcept;

    ivec2 operator *(int32_t scalar, ivec2 vec) noexcept;
    ivec2 operator /(int32_t scalar, ivec2 vec) noexcept;

}


