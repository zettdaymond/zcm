#pragma once

#include <stdint.h>
#include <zcm/detail/vec3_access.hpp>
#include <zcm/init.hpp>

namespace zcm
{
    struct vec2;
    struct vec3
    {
        vec3() noexcept;
        explicit vec3(no_init_t) noexcept;
        vec3(float value) noexcept;
        vec3(int32_t) noexcept;
        vec3(int64_t) = delete;
        vec3(double)  = delete;
        vec3(float x, float y, float z) noexcept;

        vec3(vec2 xy, float z) noexcept;
        vec3(float x, vec2 yz) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;

        void operator +=(vec3 other) noexcept;
        void operator -=(vec3 other) noexcept;
        void operator *=(vec3 other) noexcept;
        void operator /=(vec3 other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        vec3& operator++()    noexcept;
        vec3  operator++(int) noexcept;
        vec3& operator--()    noexcept;
        vec3  operator--(int) noexcept;

        union{
            float _data[3];
            detail::scalar_accessor_3<float, 0> x, r, s;
            detail::scalar_accessor_3<float, 1> y, g, t;
            detail::scalar_accessor_3<float, 2> z, b, p;

#ifndef ZCM_DISABLE_SWIZZLE
            detail::shuffle_accessor_3<float, vec2, 0, 0> xx, rr, ss;
            detail::shuffle_accessor_3<float, vec2, 1, 0> yx, gr, ts;
            detail::shuffle_accessor_3<float, vec2, 2, 0> zx, br, ps;
            detail::shuffle_accessor_3<float, vec2, 0, 1> xy, rg, st;
            detail::shuffle_accessor_3<float, vec2, 1, 1> yy, gg, tt;
            detail::shuffle_accessor_3<float, vec2, 2, 1> zy, bg, pt;
            detail::shuffle_accessor_3<float, vec2, 0, 2> xz, rb, sp;
            detail::shuffle_accessor_3<float, vec2, 1, 2> yz, gb, tp;
            detail::shuffle_accessor_3<float, vec2, 2, 2> zz, bb, pp;

            detail::shuffle_accessor_3<float, vec3, 0, 0, 0> xxx, rrr, sss;
            detail::shuffle_accessor_3<float, vec3, 1, 0, 0> yxx, grr, tss;
            detail::shuffle_accessor_3<float, vec3, 2, 0, 0> zxx, brr, pss;
            detail::shuffle_accessor_3<float, vec3, 0, 1, 0> xyx, rgr, sts;
            detail::shuffle_accessor_3<float, vec3, 1, 1, 0> yyx, ggr, tts;
            detail::shuffle_accessor_3<float, vec3, 2, 1, 0> zyx, bgr, pts;
            detail::shuffle_accessor_3<float, vec3, 0, 2, 0> xzx, rbr, sps;
            detail::shuffle_accessor_3<float, vec3, 1, 2, 0> yzx, gbr, tps;
            detail::shuffle_accessor_3<float, vec3, 2, 2, 0> zzx, bbr, pps;
            detail::shuffle_accessor_3<float, vec3, 0, 0, 1> xxy, rrg, sst;
            detail::shuffle_accessor_3<float, vec3, 1, 0, 1> yxy, grg, tst;
            detail::shuffle_accessor_3<float, vec3, 2, 0, 1> zxy, brg, pst;
            detail::shuffle_accessor_3<float, vec3, 0, 1, 1> xyy, rgg, stt;
            detail::shuffle_accessor_3<float, vec3, 1, 1, 1> yyy, ggg, ttt;
            detail::shuffle_accessor_3<float, vec3, 2, 1, 1> zyy, bgg, ptt;
            detail::shuffle_accessor_3<float, vec3, 0, 2, 1> xzy, rbg, spt;
            detail::shuffle_accessor_3<float, vec3, 1, 2, 1> yzy, gbg, tpt;
            detail::shuffle_accessor_3<float, vec3, 2, 2, 1> zzy, bbg, ppt;
            detail::shuffle_accessor_3<float, vec3, 0, 0, 2> xxz, rrb, ssp;
            detail::shuffle_accessor_3<float, vec3, 1, 0, 2> yxz, grb, tsp;
            detail::shuffle_accessor_3<float, vec3, 2, 0, 2> zxz, brb, psp;
            detail::shuffle_accessor_3<float, vec3, 0, 1, 2> xyz, rgb, stp;
            detail::shuffle_accessor_3<float, vec3, 1, 1, 2> yyz, ggb, ttp;
            detail::shuffle_accessor_3<float, vec3, 2, 1, 2> zyz, bgb, ptp;
            detail::shuffle_accessor_3<float, vec3, 0, 2, 2> xzz, rbb, spp;
            detail::shuffle_accessor_3<float, vec3, 1, 2, 2> yzz, gbb, tpp;
            detail::shuffle_accessor_3<float, vec3, 2, 2, 2> zzz, bbb, ppp;
#endif // ZCM_DISABLE_SWIZZLE
        };
    };

    bool operator==(const vec3& first, const vec3& second) noexcept;
    bool operator!=(const vec3& first, const vec3& second) noexcept;

    vec3 operator -(vec3 first) noexcept;
    vec3 operator +(vec3 first) noexcept;

    vec3 operator +(vec3 first, vec3 second) noexcept;
    vec3 operator -(vec3 first, vec3 second) noexcept;
    vec3 operator *(vec3 first, vec3 second) noexcept;
    vec3 operator /(vec3 first, vec3 second) noexcept;

    vec3 operator +(vec3 vec, float scalar) noexcept;
    vec3 operator -(vec3 vec, float scalar) noexcept;
    vec3 operator *(vec3 vec, float scalar) noexcept;
    vec3 operator /(vec3 vec, float scalar) noexcept;

    vec3 operator +(float scalar, vec3 vec) noexcept;
    vec3 operator -(float scalar, vec3 vec) noexcept;
    vec3 operator *(float scalar, vec3 vec) noexcept;
    vec3 operator /(float scalar, vec3 vec) noexcept;
}
