#pragma once

#include <stdint.h>
#include <zcm/detail/vec3_access.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/init.hpp>

namespace zcm
{
    struct ivec2;
    struct ivec3
    {
        ivec3() noexcept;
        explicit ivec3(no_init_t) noexcept;
        ivec3(int32_t value) noexcept;
        ivec3(int64_t) = delete;
        ivec3(float)   = delete;
        ivec3(double)  = delete;
        ivec3(int32_t x, int32_t y, int32_t z) noexcept;

        ivec3(ivec2 xy, int32_t z) noexcept;
        ivec3(int32_t x, ivec2 yz) noexcept;

        int32_t& operator[](unsigned val) noexcept;
        const int32_t& operator[](unsigned val) const noexcept;

        operator bvec3() const noexcept;

        ivec3& operator++()    noexcept; // prefix
        ivec3& operator--()    noexcept; // prefix

        ivec3  operator++(int) noexcept; // postfix
        ivec3  operator--(int) noexcept; // postfix

        void operator +=(ivec3 other) noexcept;
        void operator -=(ivec3 other) noexcept;
        void operator *=(ivec3 other) noexcept;
        void operator /=(ivec3 other) noexcept;
        void operator %=(ivec3 other) noexcept;
        void operator |=(ivec3 other) noexcept;
        void operator &=(ivec3 other) noexcept;
        void operator ^=(ivec3 other) noexcept;
        void operator>>=(ivec3 other) noexcept;
        void operator<<=(ivec3 other) noexcept;

        void operator +=(int32_t scalar) noexcept;
        void operator -=(int32_t scalar) noexcept;
        void operator *=(int32_t scalar) noexcept;
        void operator /=(int32_t scalar) noexcept;
        void operator %=(int32_t scalar) noexcept;
        void operator |=(int32_t scalar) noexcept;
        void operator &=(int32_t scalar) noexcept;
        void operator ^=(int32_t scalar) noexcept;
        void operator>>=(int32_t scalar) noexcept;
        void operator<<=(int32_t scalar) noexcept;

        union{
            int32_t _data[3];
            detail::scalar_accessor_3i<int32_t, 0> x, r, s;
            detail::scalar_accessor_3i<int32_t, 1> y, g, t;
            detail::scalar_accessor_3i<int32_t, 2> z, b, p;

#ifndef ZCM_DISABLE_SWIZZLE
            detail::shuffle_accessor_3<int32_t, ivec2, 0, 0> xx, rr, ss;
            detail::shuffle_accessor_3<int32_t, ivec2, 1, 0> yx, gr, ts;
            detail::shuffle_accessor_3<int32_t, ivec2, 2, 0> zx, br, ps;
            detail::shuffle_accessor_3<int32_t, ivec2, 0, 1> xy, rg, st;
            detail::shuffle_accessor_3<int32_t, ivec2, 1, 1> yy, gg, tt;
            detail::shuffle_accessor_3<int32_t, ivec2, 2, 1> zy, bg, pt;
            detail::shuffle_accessor_3<int32_t, ivec2, 0, 2> xz, rb, sp;
            detail::shuffle_accessor_3<int32_t, ivec2, 1, 2> yz, gb, tp;
            detail::shuffle_accessor_3<int32_t, ivec2, 2, 2> zz, bb, pp;

            detail::shuffle_accessor_3<int32_t, ivec3, 0, 0, 0> xxx, rrr, sss;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 0, 0> yxx, grr, tss;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 0, 0> zxx, brr, pss;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 1, 0> xyx, rgr, sts;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 1, 0> yyx, ggr, tts;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 1, 0> zyx, bgr, pts;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 2, 0> xzx, rbr, sps;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 2, 0> yzx, gbr, tps;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 2, 0> zzx, bbr, pps;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 0, 1> xxy, rrg, sst;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 0, 1> yxy, grg, tst;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 0, 1> zxy, brg, pst;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 1, 1> xyy, rgg, stt;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 1, 1> yyy, ggg, ttt;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 1, 1> zyy, bgg, ptt;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 2, 1> xzy, rbg, spt;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 2, 1> yzy, gbg, tpt;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 2, 1> zzy, bbg, ppt;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 0, 2> xxz, rrb, ssp;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 0, 2> yxz, grb, tsp;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 0, 2> zxz, brb, psp;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 1, 2> xyz, rgb, stp;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 1, 2> yyz, ggb, ttp;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 1, 2> zyz, bgb, ptp;
            detail::shuffle_accessor_3<int32_t, ivec3, 0, 2, 2> xzz, rbb, spp;
            detail::shuffle_accessor_3<int32_t, ivec3, 1, 2, 2> yzz, gbb, tpp;
            detail::shuffle_accessor_3<int32_t, ivec3, 2, 2, 2> zzz, bbb, ppp;
#endif // ZCM_DISABLE_SWIZZLE
        };
    };

    zcm::ivec3 make_ivec3(const int32_t* ptr) noexcept;

    bool operator==(ivec3 first, ivec3 second) noexcept;
    bool operator!=(ivec3 first, ivec3 second) noexcept;
    // to allow sorting and storing in maps.
    bool operator <(ivec3 first, ivec3 second) noexcept;
    bool operator<=(ivec3 first, ivec3 second) noexcept;
    bool operator >(ivec3 first, ivec3 second) noexcept;
    bool operator>=(ivec3 first, ivec3 second) noexcept;

    ivec3 operator -(ivec3 first) noexcept;
    ivec3 operator +(ivec3 first) noexcept;

    ivec3 operator +(ivec3 first, ivec3 second) noexcept;
    ivec3 operator -(ivec3 first, ivec3 second) noexcept;
    ivec3 operator *(ivec3 first, ivec3 second) noexcept;
    ivec3 operator /(ivec3 first, ivec3 second) noexcept;
    ivec3 operator %(ivec3 first, ivec3 second) noexcept;
    ivec3 operator &(ivec3 first, ivec3 second) noexcept;
    ivec3 operator |(ivec3 first, ivec3 second) noexcept;
    ivec3 operator ^(ivec3 first, ivec3 second) noexcept;
    ivec3 operator<<(ivec3 first, ivec3 second) noexcept;
    ivec3 operator>>(ivec3 first, ivec3 second) noexcept;

    ivec3 operator +(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator -(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator *(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator /(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator %(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator &(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator |(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator ^(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator<<(ivec3 vec, int32_t scalar) noexcept;
    ivec3 operator>>(ivec3 vec, int32_t scalar) noexcept;

    ivec3 operator +(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator -(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator *(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator /(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator %(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator &(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator |(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator ^(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator<<(int32_t scalar, ivec3 vec) noexcept;
    ivec3 operator>>(int32_t scalar, ivec3 vec) noexcept;
}
