#pragma once

#include <stdint.h>
#include <zcm/detail/vec4_access.hpp>
#include <zcm/init.hpp>

namespace zcm
{

    struct vec3;
    struct vec2;
    struct alignas(16) vec4
    {
        vec4 () noexcept;
        explicit vec4 (no_init_t) noexcept;
        vec4 (float value) noexcept;
        vec4 (int32_t) noexcept;
        vec4 (int64_t) = delete;
        vec4 (double)  = delete;
        vec4 (float x, float y, float z, float w) noexcept;

        vec4 (vec3 xyz, float w) noexcept;
        vec4 (float x, vec3 yzw) noexcept;

        vec4 (vec2 xy, vec2 zw) noexcept;
        vec4 (vec2 xy, float z, float w) noexcept;
        vec4 (float x, vec2 yz, float w) noexcept;
        vec4 (float x, float y, vec2 zw) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;

        void operator +=(vec4 other) noexcept;
        void operator -=(vec4 other) noexcept;
        void operator *=(vec4 other) noexcept;
        void operator /=(vec4 other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        vec4& operator++()    noexcept;
        vec4  operator++(int) noexcept;
        vec4& operator--()    noexcept;
        vec4  operator--(int) noexcept;

        union {
            float _data[4];

            detail::scalar_accessor_4<float, 0> x, r, s;
            detail::scalar_accessor_4<float, 1> y, g, t;
            detail::scalar_accessor_4<float, 2> z, b, p;
            detail::scalar_accessor_4<float, 3> w, a, q;

#ifndef ZCM_DISABLE_SWIZZLE
            detail::shuffle_accessor_4<float, vec2, 0, 0> xx, rr, ss;
            detail::shuffle_accessor_4<float, vec2, 1, 0> yx, gr, ts;
            detail::shuffle_accessor_4<float, vec2, 2, 0> zx, br, ps;
            detail::shuffle_accessor_4<float, vec2, 3, 0> wx, ar, qs;
            detail::shuffle_accessor_4<float, vec2, 0, 1> xy, rg, st;
            detail::shuffle_accessor_4<float, vec2, 1, 1> yy, gg, tt;
            detail::shuffle_accessor_4<float, vec2, 2, 1> zy, bg, pt;
            detail::shuffle_accessor_4<float, vec2, 3, 1> wy, ag, qt;
            detail::shuffle_accessor_4<float, vec2, 0, 2> xz, rb, sp;
            detail::shuffle_accessor_4<float, vec2, 1, 2> yz, gb, tp;
            detail::shuffle_accessor_4<float, vec2, 2, 2> zz, bb, pp;
            detail::shuffle_accessor_4<float, vec2, 3, 2> wz, ab, qp;
            detail::shuffle_accessor_4<float, vec2, 0, 3> xw, ra, sq;
            detail::shuffle_accessor_4<float, vec2, 1, 3> yw, ga, tq;
            detail::shuffle_accessor_4<float, vec2, 2, 3> zw, ba, pq;
            detail::shuffle_accessor_4<float, vec2, 3, 3> ww, aa, qq;

            detail::shuffle_accessor_4<float, vec3, 0, 0, 0> xxx, rrr, sss;
            detail::shuffle_accessor_4<float, vec3, 1, 0, 0> yxx, grr, tss;
            detail::shuffle_accessor_4<float, vec3, 2, 0, 0> zxx, brr, pss;
            detail::shuffle_accessor_4<float, vec3, 3, 0, 0> wxx, arr, qss;
            detail::shuffle_accessor_4<float, vec3, 0, 1, 0> xyx, rgr, sts;
            detail::shuffle_accessor_4<float, vec3, 1, 1, 0> yyx, ggr, tts;
            detail::shuffle_accessor_4<float, vec3, 2, 1, 0> zyx, bgr, pts;
            detail::shuffle_accessor_4<float, vec3, 3, 1, 0> wyx, agr, qts;
            detail::shuffle_accessor_4<float, vec3, 0, 2, 0> xzx, rbr, sps;
            detail::shuffle_accessor_4<float, vec3, 1, 2, 0> yzx, gbr, tps;
            detail::shuffle_accessor_4<float, vec3, 2, 2, 0> zzx, bbr, pps;
            detail::shuffle_accessor_4<float, vec3, 3, 2, 0> wzx, abr, qps;
            detail::shuffle_accessor_4<float, vec3, 0, 3, 0> xwx, rar, sqs;
            detail::shuffle_accessor_4<float, vec3, 1, 3, 0> ywx, gar, tqs;
            detail::shuffle_accessor_4<float, vec3, 2, 3, 0> zwx, bar, pqs;
            detail::shuffle_accessor_4<float, vec3, 3, 3, 0> wwx, aar, qqs;
            detail::shuffle_accessor_4<float, vec3, 0, 0, 1> xxy, rrg, sst;
            detail::shuffle_accessor_4<float, vec3, 1, 0, 1> yxy, grg, tst;
            detail::shuffle_accessor_4<float, vec3, 2, 0, 1> zxy, brg, pst;
            detail::shuffle_accessor_4<float, vec3, 3, 0, 1> wxy, arg, qst;
            detail::shuffle_accessor_4<float, vec3, 0, 1, 1> xyy, rgg, stt;
            detail::shuffle_accessor_4<float, vec3, 1, 1, 1> yyy, ggg, ttt;
            detail::shuffle_accessor_4<float, vec3, 2, 1, 1> zyy, bgg, ptt;
            detail::shuffle_accessor_4<float, vec3, 3, 1, 1> wyy, agg, qtt;
            detail::shuffle_accessor_4<float, vec3, 0, 2, 1> xzy, rbg, spt;
            detail::shuffle_accessor_4<float, vec3, 1, 2, 1> yzy, gbg, tpt;
            detail::shuffle_accessor_4<float, vec3, 2, 2, 1> zzy, bbg, ppt;
            detail::shuffle_accessor_4<float, vec3, 3, 2, 1> wzy, abg, qpt;
            detail::shuffle_accessor_4<float, vec3, 0, 3, 1> xwy, rag, sqt;
            detail::shuffle_accessor_4<float, vec3, 1, 3, 1> ywy, gag, tqt;
            detail::shuffle_accessor_4<float, vec3, 2, 3, 1> zwy, bag, pqt;
            detail::shuffle_accessor_4<float, vec3, 3, 3, 1> wwy, aag, qqt;
            detail::shuffle_accessor_4<float, vec3, 0, 0, 2> xxz, rrb, ssp;
            detail::shuffle_accessor_4<float, vec3, 1, 0, 2> yxz, grb, tsp;
            detail::shuffle_accessor_4<float, vec3, 2, 0, 2> zxz, brb, psp;
            detail::shuffle_accessor_4<float, vec3, 3, 0, 2> wxz, arb, qsp;
            detail::shuffle_accessor_4<float, vec3, 0, 1, 2> xyz, rgb, stp;
            detail::shuffle_accessor_4<float, vec3, 1, 1, 2> yyz, ggb, ttp;
            detail::shuffle_accessor_4<float, vec3, 2, 1, 2> zyz, bgb, ptp;
            detail::shuffle_accessor_4<float, vec3, 3, 1, 2> wyz, agb, qtp;
            detail::shuffle_accessor_4<float, vec3, 0, 2, 2> xzz, rbb, spp;
            detail::shuffle_accessor_4<float, vec3, 1, 2, 2> yzz, gbb, tpp;
            detail::shuffle_accessor_4<float, vec3, 2, 2, 2> zzz, bbb, ppp;
            detail::shuffle_accessor_4<float, vec3, 3, 2, 2> wzz, abb, qpp;
            detail::shuffle_accessor_4<float, vec3, 0, 3, 2> xwz, rab, sqp;
            detail::shuffle_accessor_4<float, vec3, 1, 3, 2> ywz, gab, tqp;
            detail::shuffle_accessor_4<float, vec3, 2, 3, 2> zwz, bab, pqp;
            detail::shuffle_accessor_4<float, vec3, 3, 3, 2> wwz, aab, qqp;
            detail::shuffle_accessor_4<float, vec3, 0, 0, 3> xxw, rra, ssq;
            detail::shuffle_accessor_4<float, vec3, 1, 0, 3> yxw, gra, tsq;
            detail::shuffle_accessor_4<float, vec3, 2, 0, 3> zxw, bra, psq;
            detail::shuffle_accessor_4<float, vec3, 3, 0, 3> wxw, ara, qsq;
            detail::shuffle_accessor_4<float, vec3, 0, 1, 3> xyw, rga, stq;
            detail::shuffle_accessor_4<float, vec3, 1, 1, 3> yyw, gga, ttq;
            detail::shuffle_accessor_4<float, vec3, 2, 1, 3> zyw, bga, ptq;
            detail::shuffle_accessor_4<float, vec3, 3, 1, 3> wyw, aga, qtq;
            detail::shuffle_accessor_4<float, vec3, 0, 2, 3> xzw, rba, spq;
            detail::shuffle_accessor_4<float, vec3, 1, 2, 3> yzw, gba, tpq;
            detail::shuffle_accessor_4<float, vec3, 2, 2, 3> zzw, bba, ppq;
            detail::shuffle_accessor_4<float, vec3, 3, 2, 3> wzw, aba, qpq;
            detail::shuffle_accessor_4<float, vec3, 0, 3, 3> xww, raa, sqq;
            detail::shuffle_accessor_4<float, vec3, 1, 3, 3> yww, gaa, tqq;
            detail::shuffle_accessor_4<float, vec3, 2, 3, 3> zww, baa, pqq;
            detail::shuffle_accessor_4<float, vec3, 3, 3, 3> www, aaa, qqq;

            detail::shuffle_accessor_4<float, vec4, 0, 0, 0, 0> xxxx, rrrr, ssss;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 0, 0> yxxx, grrr, tsss;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 0, 0> zxxx, brrr, psss;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 0, 0> wxxx, arrr, qsss;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 0, 0> xyxx, rgrr, stss;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 0, 0> yyxx, ggrr, ttss;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 0, 0> zyxx, bgrr, ptss;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 0, 0> wyxx, agrr, qtss;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 0, 0> xzxx, rbrr, spss;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 0, 0> yzxx, gbrr, tpss;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 0, 0> zzxx, bbrr, ppss;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 0, 0> wzxx, abrr, qpss;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 0, 0> xwxx, rarr, sqss;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 0, 0> ywxx, garr, tqss;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 0, 0> zwxx, barr, pqss;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 0, 0> wwxx, aarr, qqss;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 1, 0> xxyx, rrgr, ssts;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 1, 0> yxyx, grgr, tsts;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 1, 0> zxyx, brgr, psts;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 1, 0> wxyx, argr, qsts;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 1, 0> xyyx, rggr, stts;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 1, 0> yyyx, gggr, ttts;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 1, 0> zyyx, bggr, ptts;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 1, 0> wyyx, aggr, qtts;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 1, 0> xzyx, rbgr, spts;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 1, 0> yzyx, gbgr, tpts;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 1, 0> zzyx, bbgr, ppts;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 1, 0> wzyx, abgr, qpts;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 1, 0> xwyx, ragr, sqts;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 1, 0> ywyx, gagr, tqts;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 1, 0> zwyx, bagr, pqts;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 1, 0> wwyx, aagr, qqts;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 2, 0> xxzx, rrbr, ssps;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 2, 0> yxzx, grbr, tsps;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 2, 0> zxzx, brbr, psps;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 2, 0> wxzx, arbr, qsps;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 2, 0> xyzx, rgbr, stps;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 2, 0> yyzx, ggbr, ttps;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 2, 0> zyzx, bgbr, ptps;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 2, 0> wyzx, agbr, qtps;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 2, 0> xzzx, rbbr, spps;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 2, 0> yzzx, gbbr, tpps;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 2, 0> zzzx, bbbr, ppps;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 2, 0> wzzx, abbr, qpps;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 2, 0> xwzx, rabr, sqps;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 2, 0> ywzx, gabr, tqps;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 2, 0> zwzx, babr, pqps;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 2, 0> wwzx, aabr, qqps;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 3, 0> xxwx, rrar, ssqs;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 3, 0> yxwx, grar, tsqs;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 3, 0> zxwx, brar, psqs;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 3, 0> wxwx, arar, qsqs;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 3, 0> xywx, rgar, stqs;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 3, 0> yywx, ggar, ttqs;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 3, 0> zywx, bgar, ptqs;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 3, 0> wywx, agar, qtqs;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 3, 0> xzwx, rbar, spqs;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 3, 0> yzwx, gbar, tpqs;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 3, 0> zzwx, bbar, ppqs;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 3, 0> wzwx, abar, qpqs;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 3, 0> xwwx, raar, sqqs;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 3, 0> ywwx, gaar, tqqs;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 3, 0> zwwx, baar, pqqs;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 3, 0> wwwx, aaar, qqqs;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 0, 1> xxxy, rrrg, ssst;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 0, 1> yxxy, grrg, tsst;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 0, 1> zxxy, brrg, psst;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 0, 1> wxxy, arrg, qsst;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 0, 1> xyxy, rgrg, stst;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 0, 1> yyxy, ggrg, ttst;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 0, 1> zyxy, bgrg, ptst;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 0, 1> wyxy, agrg, qtst;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 0, 1> xzxy, rbrg, spst;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 0, 1> yzxy, gbrg, tpst;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 0, 1> zzxy, bbrg, ppst;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 0, 1> wzxy, abrg, qpst;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 0, 1> xwxy, rarg, sqst;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 0, 1> ywxy, garg, tqst;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 0, 1> zwxy, barg, pqst;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 0, 1> wwxy, aarg, qqst;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 1, 1> xxyy, rrgg, sstt;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 1, 1> yxyy, grgg, tstt;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 1, 1> zxyy, brgg, pstt;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 1, 1> wxyy, argg, qstt;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 1, 1> xyyy, rggg, sttt;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 1, 1> yyyy, gggg, tttt;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 1, 1> zyyy, bggg, pttt;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 1, 1> wyyy, aggg, qttt;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 1, 1> xzyy, rbgg, sptt;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 1, 1> yzyy, gbgg, tptt;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 1, 1> zzyy, bbgg, pptt;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 1, 1> wzyy, abgg, qptt;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 1, 1> xwyy, ragg, sqtt;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 1, 1> ywyy, gagg, tqtt;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 1, 1> zwyy, bagg, pqtt;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 1, 1> wwyy, aagg, qqtt;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 2, 1> xxzy, rrbg, sspt;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 2, 1> yxzy, grbg, tspt;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 2, 1> zxzy, brbg, pspt;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 2, 1> wxzy, arbg, qspt;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 2, 1> xyzy, rgbg, stpt;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 2, 1> yyzy, ggbg, ttpt;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 2, 1> zyzy, bgbg, ptpt;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 2, 1> wyzy, agbg, qtpt;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 2, 1> xzzy, rbbg, sppt;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 2, 1> yzzy, gbbg, tppt;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 2, 1> zzzy, bbbg, pppt;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 2, 1> wzzy, abbg, qppt;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 2, 1> xwzy, rabg, sqpt;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 2, 1> ywzy, gabg, tqpt;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 2, 1> zwzy, babg, pqpt;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 2, 1> wwzy, aabg, qqpt;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 3, 1> xxwy, rrag, ssqt;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 3, 1> yxwy, grag, tsqt;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 3, 1> zxwy, brag, psqt;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 3, 1> wxwy, arag, qsqt;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 3, 1> xywy, rgag, stqt;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 3, 1> yywy, ggag, ttqt;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 3, 1> zywy, bgag, ptqt;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 3, 1> wywy, agag, qtqt;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 3, 1> xzwy, rbag, spqt;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 3, 1> yzwy, gbag, tpqt;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 3, 1> zzwy, bbag, ppqt;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 3, 1> wzwy, abag, qpqt;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 3, 1> xwwy, raag, sqqt;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 3, 1> ywwy, gaag, tqqt;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 3, 1> zwwy, baag, pqqt;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 3, 1> wwwy, aaag, qqqt;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 0, 2> xxxz, rrrb, sssp;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 0, 2> yxxz, grrb, tssp;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 0, 2> zxxz, brrb, pssp;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 0, 2> wxxz, arrb, qssp;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 0, 2> xyxz, rgrb, stsp;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 0, 2> yyxz, ggrb, ttsp;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 0, 2> zyxz, bgrb, ptsp;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 0, 2> wyxz, agrb, qtsp;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 0, 2> xzxz, rbrb, spsp;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 0, 2> yzxz, gbrb, tpsp;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 0, 2> zzxz, bbrb, ppsp;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 0, 2> wzxz, abrb, qpsp;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 0, 2> xwxz, rarb, sqsp;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 0, 2> ywxz, garb, tqsp;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 0, 2> zwxz, barb, pqsp;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 0, 2> wwxz, aarb, qqsp;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 1, 2> xxyz, rrgb, sstp;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 1, 2> yxyz, grgb, tstp;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 1, 2> zxyz, brgb, pstp;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 1, 2> wxyz, argb, qstp;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 1, 2> xyyz, rggb, sttp;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 1, 2> yyyz, gggb, tttp;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 1, 2> zyyz, bggb, pttp;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 1, 2> wyyz, aggb, qttp;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 1, 2> xzyz, rbgb, sptp;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 1, 2> yzyz, gbgb, tptp;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 1, 2> zzyz, bbgb, pptp;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 1, 2> wzyz, abgb, qptp;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 1, 2> xwyz, ragb, sqtp;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 1, 2> ywyz, gagb, tqtp;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 1, 2> zwyz, bagb, pqtp;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 1, 2> wwyz, aagb, qqtp;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 2, 2> xxzz, rrbb, sspp;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 2, 2> yxzz, grbb, tspp;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 2, 2> zxzz, brbb, pspp;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 2, 2> wxzz, arbb, qspp;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 2, 2> xyzz, rgbb, stpp;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 2, 2> yyzz, ggbb, ttpp;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 2, 2> zyzz, bgbb, ptpp;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 2, 2> wyzz, agbb, qtpp;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 2, 2> xzzz, rbbb, sppp;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 2, 2> yzzz, gbbb, tppp;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 2, 2> zzzz, bbbb, pppp;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 2, 2> wzzz, abbb, qppp;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 2, 2> xwzz, rabb, sqpp;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 2, 2> ywzz, gabb, tqpp;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 2, 2> zwzz, babb, pqpp;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 2, 2> wwzz, aabb, qqpp;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 3, 2> xxwz, rrab, ssqp;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 3, 2> yxwz, grab, tsqp;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 3, 2> zxwz, brab, psqp;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 3, 2> wxwz, arab, qsqp;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 3, 2> xywz, rgab, stqp;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 3, 2> yywz, ggab, ttqp;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 3, 2> zywz, bgab, ptqp;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 3, 2> wywz, agab, qtqp;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 3, 2> xzwz, rbab, spqp;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 3, 2> yzwz, gbab, tpqp;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 3, 2> zzwz, bbab, ppqp;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 3, 2> wzwz, abab, qpqp;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 3, 2> xwwz, raab, sqqp;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 3, 2> ywwz, gaab, tqqp;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 3, 2> zwwz, baab, pqqp;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 3, 2> wwwz, aaab, qqqp;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 0, 3> xxxw, rrra, sssq;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 0, 3> yxxw, grra, tssq;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 0, 3> zxxw, brra, pssq;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 0, 3> wxxw, arra, qssq;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 0, 3> xyxw, rgra, stsq;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 0, 3> yyxw, ggra, ttsq;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 0, 3> zyxw, bgra, ptsq;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 0, 3> wyxw, agra, qtsq;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 0, 3> xzxw, rbra, spsq;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 0, 3> yzxw, gbra, tpsq;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 0, 3> zzxw, bbra, ppsq;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 0, 3> wzxw, abra, qpsq;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 0, 3> xwxw, rara, sqsq;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 0, 3> ywxw, gara, tqsq;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 0, 3> zwxw, bara, pqsq;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 0, 3> wwxw, aara, qqsq;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 1, 3> xxyw, rrga, sstq;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 1, 3> yxyw, grga, tstq;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 1, 3> zxyw, brga, pstq;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 1, 3> wxyw, arga, qstq;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 1, 3> xyyw, rgga, sttq;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 1, 3> yyyw, ggga, tttq;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 1, 3> zyyw, bgga, pttq;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 1, 3> wyyw, agga, qttq;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 1, 3> xzyw, rbga, sptq;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 1, 3> yzyw, gbga, tptq;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 1, 3> zzyw, bbga, pptq;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 1, 3> wzyw, abga, qptq;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 1, 3> xwyw, raga, sqtq;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 1, 3> ywyw, gaga, tqtq;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 1, 3> zwyw, baga, pqtq;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 1, 3> wwyw, aaga, qqtq;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 2, 3> xxzw, rrba, sspq;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 2, 3> yxzw, grba, tspq;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 2, 3> zxzw, brba, pspq;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 2, 3> wxzw, arba, qspq;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 2, 3> xyzw, rgba, stpq;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 2, 3> yyzw, ggba, ttpq;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 2, 3> zyzw, bgba, ptpq;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 2, 3> wyzw, agba, qtpq;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 2, 3> xzzw, rbba, sppq;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 2, 3> yzzw, gbba, tppq;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 2, 3> zzzw, bbba, pppq;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 2, 3> wzzw, abba, qppq;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 2, 3> xwzw, raba, sqpq;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 2, 3> ywzw, gaba, tqpq;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 2, 3> zwzw, baba, pqpq;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 2, 3> wwzw, aaba, qqpq;
            detail::shuffle_accessor_4<float, vec4, 0, 0, 3, 3> xxww, rraa, ssqq;
            detail::shuffle_accessor_4<float, vec4, 1, 0, 3, 3> yxww, graa, tsqq;
            detail::shuffle_accessor_4<float, vec4, 2, 0, 3, 3> zxww, braa, psqq;
            detail::shuffle_accessor_4<float, vec4, 3, 0, 3, 3> wxww, araa, qsqq;
            detail::shuffle_accessor_4<float, vec4, 0, 1, 3, 3> xyww, rgaa, stqq;
            detail::shuffle_accessor_4<float, vec4, 1, 1, 3, 3> yyww, ggaa, ttqq;
            detail::shuffle_accessor_4<float, vec4, 2, 1, 3, 3> zyww, bgaa, ptqq;
            detail::shuffle_accessor_4<float, vec4, 3, 1, 3, 3> wyww, agaa, qtqq;
            detail::shuffle_accessor_4<float, vec4, 0, 2, 3, 3> xzww, rbaa, spqq;
            detail::shuffle_accessor_4<float, vec4, 1, 2, 3, 3> yzww, gbaa, tpqq;
            detail::shuffle_accessor_4<float, vec4, 2, 2, 3, 3> zzww, bbaa, ppqq;
            detail::shuffle_accessor_4<float, vec4, 3, 2, 3, 3> wzww, abaa, qpqq;
            detail::shuffle_accessor_4<float, vec4, 0, 3, 3, 3> xwww, raaa, sqqq;
            detail::shuffle_accessor_4<float, vec4, 1, 3, 3, 3> ywww, gaaa, tqqq;
            detail::shuffle_accessor_4<float, vec4, 2, 3, 3, 3> zwww, baaa, pqqq;
            detail::shuffle_accessor_4<float, vec4, 3, 3, 3, 3> wwww, aaaa, qqqq;
#endif // ZCM_DISABLE_SWIZZLE
        };
    };

    bool operator==(const vec4& first, const vec4& second) noexcept;
    bool operator!=(const vec4& first, const vec4& second) noexcept;

    vec4 operator -(vec4 first) noexcept;
    vec4 operator +(vec4 first) noexcept;

    vec4 operator +(vec4 first, vec4 second) noexcept;
    vec4 operator -(vec4 first, vec4 second) noexcept;
    vec4 operator *(vec4 first, vec4 second) noexcept;
    vec4 operator /(vec4 first, vec4 second) noexcept;

    vec4 operator +(vec4 vec, float scalar) noexcept;
    vec4 operator -(vec4 vec, float scalar) noexcept;
    vec4 operator *(vec4 vec, float scalar) noexcept;
    vec4 operator /(vec4 vec, float scalar) noexcept;

    vec4 operator +(float scalar, vec4 vec) noexcept;
    vec4 operator -(float scalar, vec4 vec) noexcept;
    vec4 operator *(float scalar, vec4 vec) noexcept;
    vec4 operator /(float scalar, vec4 vec) noexcept;

}
