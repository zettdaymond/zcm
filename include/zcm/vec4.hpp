#pragma once

#include <zcm/access.hpp>

namespace zcm
{
    struct vec3;
    struct vec2;
    struct vec4
    {
        vec4 () noexcept;
        vec4 (float value) noexcept;
        vec4 (float x, float y, float z, float w) noexcept;

        vec4 (const vec3& xyz, float w) noexcept;
        vec4 (float x, const vec3& yzw) noexcept;

        vec4 (const vec2& xy, const vec2& zw) noexcept;
        vec4 (const vec2& xy, float z, float w) noexcept;
        vec4 (float x, const vec2& yz, float w) noexcept;
        vec4 (float x, float y, const vec2& zw) noexcept;

        float& operator[](unsigned val) noexcept;
        const float& operator[](unsigned val) const noexcept;

        void operator +=(const vec4& other) noexcept;
        void operator -=(const vec4& other) noexcept;
        void operator *=(const vec4& other) noexcept;
        void operator /=(const vec4& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        union {
            float _data[4];

            _scalar_accessor<0, 4> x;
            _scalar_accessor<1, 4> y;
            _scalar_accessor<2, 4> z;
            _scalar_accessor<3, 4> w;

            _shuffle_accessor<vec2, 0, 0> xx;
            _shuffle_accessor<vec2, 1, 0> yx;
            _shuffle_accessor<vec2, 2, 0> zx;
            _shuffle_accessor<vec2, 3, 0> wx;
            _shuffle_accessor<vec2, 0, 1> xy;
            _shuffle_accessor<vec2, 1, 1> yy;
            _shuffle_accessor<vec2, 2, 1> zy;
            _shuffle_accessor<vec2, 3, 1> wy;
            _shuffle_accessor<vec2, 0, 2> xz;
            _shuffle_accessor<vec2, 1, 2> yz;
            _shuffle_accessor<vec2, 2, 2> zz;
            _shuffle_accessor<vec2, 3, 2> wz;
            _shuffle_accessor<vec2, 0, 3> xw;
            _shuffle_accessor<vec2, 1, 3> yw;
            _shuffle_accessor<vec2, 2, 3> zw;
            _shuffle_accessor<vec2, 3, 3> ww;

            _shuffle_accessor<vec3, 0, 0, 0> xxx;
            _shuffle_accessor<vec3, 1, 0, 0> yxx;
            _shuffle_accessor<vec3, 2, 0, 0> zxx;
            _shuffle_accessor<vec3, 3, 0, 0> wxx;
            _shuffle_accessor<vec3, 0, 1, 0> xyx;
            _shuffle_accessor<vec3, 1, 1, 0> yyx;
            _shuffle_accessor<vec3, 2, 1, 0> zyx;
            _shuffle_accessor<vec3, 3, 1, 0> wyx;
            _shuffle_accessor<vec3, 0, 2, 0> xzx;
            _shuffle_accessor<vec3, 1, 2, 0> yzx;
            _shuffle_accessor<vec3, 2, 2, 0> zzx;
            _shuffle_accessor<vec3, 3, 2, 0> wzx;
            _shuffle_accessor<vec3, 0, 3, 0> xwx;
            _shuffle_accessor<vec3, 1, 3, 0> ywx;
            _shuffle_accessor<vec3, 2, 3, 0> zwx;
            _shuffle_accessor<vec3, 3, 3, 0> wwx;
            _shuffle_accessor<vec3, 0, 0, 1> xxy;
            _shuffle_accessor<vec3, 1, 0, 1> yxy;
            _shuffle_accessor<vec3, 2, 0, 1> zxy;
            _shuffle_accessor<vec3, 3, 0, 1> wxy;
            _shuffle_accessor<vec3, 0, 1, 1> xyy;
            _shuffle_accessor<vec3, 1, 1, 1> yyy;
            _shuffle_accessor<vec3, 2, 1, 1> zyy;
            _shuffle_accessor<vec3, 3, 1, 1> wyy;
            _shuffle_accessor<vec3, 0, 2, 1> xzy;
            _shuffle_accessor<vec3, 1, 2, 1> yzy;
            _shuffle_accessor<vec3, 2, 2, 1> zzy;
            _shuffle_accessor<vec3, 3, 2, 1> wzy;
            _shuffle_accessor<vec3, 0, 3, 1> xwy;
            _shuffle_accessor<vec3, 1, 3, 1> ywy;
            _shuffle_accessor<vec3, 2, 3, 1> zwy;
            _shuffle_accessor<vec3, 3, 3, 1> wwy;
            _shuffle_accessor<vec3, 0, 0, 2> xxz;
            _shuffle_accessor<vec3, 1, 0, 2> yxz;
            _shuffle_accessor<vec3, 2, 0, 2> zxz;
            _shuffle_accessor<vec3, 3, 0, 2> wxz;
            _shuffle_accessor<vec3, 0, 1, 2> xyz;
            _shuffle_accessor<vec3, 1, 1, 2> yyz;
            _shuffle_accessor<vec3, 2, 1, 2> zyz;
            _shuffle_accessor<vec3, 3, 1, 2> wyz;
            _shuffle_accessor<vec3, 0, 2, 2> xzz;
            _shuffle_accessor<vec3, 1, 2, 2> yzz;
            _shuffle_accessor<vec3, 2, 2, 2> zzz;
            _shuffle_accessor<vec3, 3, 2, 2> wzz;
            _shuffle_accessor<vec3, 0, 3, 2> xwz;
            _shuffle_accessor<vec3, 1, 3, 2> ywz;
            _shuffle_accessor<vec3, 2, 3, 2> zwz;
            _shuffle_accessor<vec3, 3, 3, 2> wwz;
            _shuffle_accessor<vec3, 0, 0, 3> xxw;
            _shuffle_accessor<vec3, 1, 0, 3> yxw;
            _shuffle_accessor<vec3, 2, 0, 3> zxw;
            _shuffle_accessor<vec3, 3, 0, 3> wxw;
            _shuffle_accessor<vec3, 0, 1, 3> xyw;
            _shuffle_accessor<vec3, 1, 1, 3> yyw;
            _shuffle_accessor<vec3, 2, 1, 3> zyw;
            _shuffle_accessor<vec3, 3, 1, 3> wyw;
            _shuffle_accessor<vec3, 0, 2, 3> xzw;
            _shuffle_accessor<vec3, 1, 2, 3> yzw;
            _shuffle_accessor<vec3, 2, 2, 3> zzw;
            _shuffle_accessor<vec3, 3, 2, 3> wzw;
            _shuffle_accessor<vec3, 0, 3, 3> xww;
            _shuffle_accessor<vec3, 1, 3, 3> yww;
            _shuffle_accessor<vec3, 2, 3, 3> zww;
            _shuffle_accessor<vec3, 3, 3, 3> www;

            _shuffle_accessor<vec4, 0, 0, 0, 0> xxxx;
            _shuffle_accessor<vec4, 1, 0, 0, 0> yxxx;
            _shuffle_accessor<vec4, 2, 0, 0, 0> zxxx;
            _shuffle_accessor<vec4, 3, 0, 0, 0> wxxx;
            _shuffle_accessor<vec4, 0, 1, 0, 0> xyxx;
            _shuffle_accessor<vec4, 1, 1, 0, 0> yyxx;
            _shuffle_accessor<vec4, 2, 1, 0, 0> zyxx;
            _shuffle_accessor<vec4, 3, 1, 0, 0> wyxx;
            _shuffle_accessor<vec4, 0, 2, 0, 0> xzxx;
            _shuffle_accessor<vec4, 1, 2, 0, 0> yzxx;
            _shuffle_accessor<vec4, 2, 2, 0, 0> zzxx;
            _shuffle_accessor<vec4, 3, 2, 0, 0> wzxx;
            _shuffle_accessor<vec4, 0, 3, 0, 0> xwxx;
            _shuffle_accessor<vec4, 1, 3, 0, 0> ywxx;
            _shuffle_accessor<vec4, 2, 3, 0, 0> zwxx;
            _shuffle_accessor<vec4, 3, 3, 0, 0> wwxx;
            _shuffle_accessor<vec4, 0, 0, 1, 0> xxyx;
            _shuffle_accessor<vec4, 1, 0, 1, 0> yxyx;
            _shuffle_accessor<vec4, 2, 0, 1, 0> zxyx;
            _shuffle_accessor<vec4, 3, 0, 1, 0> wxyx;
            _shuffle_accessor<vec4, 0, 1, 1, 0> xyyx;
            _shuffle_accessor<vec4, 1, 1, 1, 0> yyyx;
            _shuffle_accessor<vec4, 2, 1, 1, 0> zyyx;
            _shuffle_accessor<vec4, 3, 1, 1, 0> wyyx;
            _shuffle_accessor<vec4, 0, 2, 1, 0> xzyx;
            _shuffle_accessor<vec4, 1, 2, 1, 0> yzyx;
            _shuffle_accessor<vec4, 2, 2, 1, 0> zzyx;
            _shuffle_accessor<vec4, 3, 2, 1, 0> wzyx;
            _shuffle_accessor<vec4, 0, 3, 1, 0> xwyx;
            _shuffle_accessor<vec4, 1, 3, 1, 0> ywyx;
            _shuffle_accessor<vec4, 2, 3, 1, 0> zwyx;
            _shuffle_accessor<vec4, 3, 3, 1, 0> wwyx;
            _shuffle_accessor<vec4, 0, 0, 2, 0> xxzx;
            _shuffle_accessor<vec4, 1, 0, 2, 0> yxzx;
            _shuffle_accessor<vec4, 2, 0, 2, 0> zxzx;
            _shuffle_accessor<vec4, 3, 0, 2, 0> wxzx;
            _shuffle_accessor<vec4, 0, 1, 2, 0> xyzx;
            _shuffle_accessor<vec4, 1, 1, 2, 0> yyzx;
            _shuffle_accessor<vec4, 2, 1, 2, 0> zyzx;
            _shuffle_accessor<vec4, 3, 1, 2, 0> wyzx;
            _shuffle_accessor<vec4, 0, 2, 2, 0> xzzx;
            _shuffle_accessor<vec4, 1, 2, 2, 0> yzzx;
            _shuffle_accessor<vec4, 2, 2, 2, 0> zzzx;
            _shuffle_accessor<vec4, 3, 2, 2, 0> wzzx;
            _shuffle_accessor<vec4, 0, 3, 2, 0> xwzx;
            _shuffle_accessor<vec4, 1, 3, 2, 0> ywzx;
            _shuffle_accessor<vec4, 2, 3, 2, 0> zwzx;
            _shuffle_accessor<vec4, 3, 3, 2, 0> wwzx;
            _shuffle_accessor<vec4, 0, 0, 3, 0> xxwx;
            _shuffle_accessor<vec4, 1, 0, 3, 0> yxwx;
            _shuffle_accessor<vec4, 2, 0, 3, 0> zxwx;
            _shuffle_accessor<vec4, 3, 0, 3, 0> wxwx;
            _shuffle_accessor<vec4, 0, 1, 3, 0> xywx;
            _shuffle_accessor<vec4, 1, 1, 3, 0> yywx;
            _shuffle_accessor<vec4, 2, 1, 3, 0> zywx;
            _shuffle_accessor<vec4, 3, 1, 3, 0> wywx;
            _shuffle_accessor<vec4, 0, 2, 3, 0> xzwx;
            _shuffle_accessor<vec4, 1, 2, 3, 0> yzwx;
            _shuffle_accessor<vec4, 2, 2, 3, 0> zzwx;
            _shuffle_accessor<vec4, 3, 2, 3, 0> wzwx;
            _shuffle_accessor<vec4, 0, 3, 3, 0> xwwx;
            _shuffle_accessor<vec4, 1, 3, 3, 0> ywwx;
            _shuffle_accessor<vec4, 2, 3, 3, 0> zwwx;
            _shuffle_accessor<vec4, 3, 3, 3, 0> wwwx;
            _shuffle_accessor<vec4, 0, 0, 0, 1> xxxy;
            _shuffle_accessor<vec4, 1, 0, 0, 1> yxxy;
            _shuffle_accessor<vec4, 2, 0, 0, 1> zxxy;
            _shuffle_accessor<vec4, 3, 0, 0, 1> wxxy;
            _shuffle_accessor<vec4, 0, 1, 0, 1> xyxy;
            _shuffle_accessor<vec4, 1, 1, 0, 1> yyxy;
            _shuffle_accessor<vec4, 2, 1, 0, 1> zyxy;
            _shuffle_accessor<vec4, 3, 1, 0, 1> wyxy;
            _shuffle_accessor<vec4, 0, 2, 0, 1> xzxy;
            _shuffle_accessor<vec4, 1, 2, 0, 1> yzxy;
            _shuffle_accessor<vec4, 2, 2, 0, 1> zzxy;
            _shuffle_accessor<vec4, 3, 2, 0, 1> wzxy;
            _shuffle_accessor<vec4, 0, 3, 0, 1> xwxy;
            _shuffle_accessor<vec4, 1, 3, 0, 1> ywxy;
            _shuffle_accessor<vec4, 2, 3, 0, 1> zwxy;
            _shuffle_accessor<vec4, 3, 3, 0, 1> wwxy;
            _shuffle_accessor<vec4, 0, 0, 1, 1> xxyy;
            _shuffle_accessor<vec4, 1, 0, 1, 1> yxyy;
            _shuffle_accessor<vec4, 2, 0, 1, 1> zxyy;
            _shuffle_accessor<vec4, 3, 0, 1, 1> wxyy;
            _shuffle_accessor<vec4, 0, 1, 1, 1> xyyy;
            _shuffle_accessor<vec4, 1, 1, 1, 1> yyyy;
            _shuffle_accessor<vec4, 2, 1, 1, 1> zyyy;
            _shuffle_accessor<vec4, 3, 1, 1, 1> wyyy;
            _shuffle_accessor<vec4, 0, 2, 1, 1> xzyy;
            _shuffle_accessor<vec4, 1, 2, 1, 1> yzyy;
            _shuffle_accessor<vec4, 2, 2, 1, 1> zzyy;
            _shuffle_accessor<vec4, 3, 2, 1, 1> wzyy;
            _shuffle_accessor<vec4, 0, 3, 1, 1> xwyy;
            _shuffle_accessor<vec4, 1, 3, 1, 1> ywyy;
            _shuffle_accessor<vec4, 2, 3, 1, 1> zwyy;
            _shuffle_accessor<vec4, 3, 3, 1, 1> wwyy;
            _shuffle_accessor<vec4, 0, 0, 2, 1> xxzy;
            _shuffle_accessor<vec4, 1, 0, 2, 1> yxzy;
            _shuffle_accessor<vec4, 2, 0, 2, 1> zxzy;
            _shuffle_accessor<vec4, 3, 0, 2, 1> wxzy;
            _shuffle_accessor<vec4, 0, 1, 2, 1> xyzy;
            _shuffle_accessor<vec4, 1, 1, 2, 1> yyzy;
            _shuffle_accessor<vec4, 2, 1, 2, 1> zyzy;
            _shuffle_accessor<vec4, 3, 1, 2, 1> wyzy;
            _shuffle_accessor<vec4, 0, 2, 2, 1> xzzy;
            _shuffle_accessor<vec4, 1, 2, 2, 1> yzzy;
            _shuffle_accessor<vec4, 2, 2, 2, 1> zzzy;
            _shuffle_accessor<vec4, 3, 2, 2, 1> wzzy;
            _shuffle_accessor<vec4, 0, 3, 2, 1> xwzy;
            _shuffle_accessor<vec4, 1, 3, 2, 1> ywzy;
            _shuffle_accessor<vec4, 2, 3, 2, 1> zwzy;
            _shuffle_accessor<vec4, 3, 3, 2, 1> wwzy;
            _shuffle_accessor<vec4, 0, 0, 3, 1> xxwy;
            _shuffle_accessor<vec4, 1, 0, 3, 1> yxwy;
            _shuffle_accessor<vec4, 2, 0, 3, 1> zxwy;
            _shuffle_accessor<vec4, 3, 0, 3, 1> wxwy;
            _shuffle_accessor<vec4, 0, 1, 3, 1> xywy;
            _shuffle_accessor<vec4, 1, 1, 3, 1> yywy;
            _shuffle_accessor<vec4, 2, 1, 3, 1> zywy;
            _shuffle_accessor<vec4, 3, 1, 3, 1> wywy;
            _shuffle_accessor<vec4, 0, 2, 3, 1> xzwy;
            _shuffle_accessor<vec4, 1, 2, 3, 1> yzwy;
            _shuffle_accessor<vec4, 2, 2, 3, 1> zzwy;
            _shuffle_accessor<vec4, 3, 2, 3, 1> wzwy;
            _shuffle_accessor<vec4, 0, 3, 3, 1> xwwy;
            _shuffle_accessor<vec4, 1, 3, 3, 1> ywwy;
            _shuffle_accessor<vec4, 2, 3, 3, 1> zwwy;
            _shuffle_accessor<vec4, 3, 3, 3, 1> wwwy;
            _shuffle_accessor<vec4, 0, 0, 0, 2> xxxz;
            _shuffle_accessor<vec4, 1, 0, 0, 2> yxxz;
            _shuffle_accessor<vec4, 2, 0, 0, 2> zxxz;
            _shuffle_accessor<vec4, 3, 0, 0, 2> wxxz;
            _shuffle_accessor<vec4, 0, 1, 0, 2> xyxz;
            _shuffle_accessor<vec4, 1, 1, 0, 2> yyxz;
            _shuffle_accessor<vec4, 2, 1, 0, 2> zyxz;
            _shuffle_accessor<vec4, 3, 1, 0, 2> wyxz;
            _shuffle_accessor<vec4, 0, 2, 0, 2> xzxz;
            _shuffle_accessor<vec4, 1, 2, 0, 2> yzxz;
            _shuffle_accessor<vec4, 2, 2, 0, 2> zzxz;
            _shuffle_accessor<vec4, 3, 2, 0, 2> wzxz;
            _shuffle_accessor<vec4, 0, 3, 0, 2> xwxz;
            _shuffle_accessor<vec4, 1, 3, 0, 2> ywxz;
            _shuffle_accessor<vec4, 2, 3, 0, 2> zwxz;
            _shuffle_accessor<vec4, 3, 3, 0, 2> wwxz;
            _shuffle_accessor<vec4, 0, 0, 1, 2> xxyz;
            _shuffle_accessor<vec4, 1, 0, 1, 2> yxyz;
            _shuffle_accessor<vec4, 2, 0, 1, 2> zxyz;
            _shuffle_accessor<vec4, 3, 0, 1, 2> wxyz;
            _shuffle_accessor<vec4, 0, 1, 1, 2> xyyz;
            _shuffle_accessor<vec4, 1, 1, 1, 2> yyyz;
            _shuffle_accessor<vec4, 2, 1, 1, 2> zyyz;
            _shuffle_accessor<vec4, 3, 1, 1, 2> wyyz;
            _shuffle_accessor<vec4, 0, 2, 1, 2> xzyz;
            _shuffle_accessor<vec4, 1, 2, 1, 2> yzyz;
            _shuffle_accessor<vec4, 2, 2, 1, 2> zzyz;
            _shuffle_accessor<vec4, 3, 2, 1, 2> wzyz;
            _shuffle_accessor<vec4, 0, 3, 1, 2> xwyz;
            _shuffle_accessor<vec4, 1, 3, 1, 2> ywyz;
            _shuffle_accessor<vec4, 2, 3, 1, 2> zwyz;
            _shuffle_accessor<vec4, 3, 3, 1, 2> wwyz;
            _shuffle_accessor<vec4, 0, 0, 2, 2> xxzz;
            _shuffle_accessor<vec4, 1, 0, 2, 2> yxzz;
            _shuffle_accessor<vec4, 2, 0, 2, 2> zxzz;
            _shuffle_accessor<vec4, 3, 0, 2, 2> wxzz;
            _shuffle_accessor<vec4, 0, 1, 2, 2> xyzz;
            _shuffle_accessor<vec4, 1, 1, 2, 2> yyzz;
            _shuffle_accessor<vec4, 2, 1, 2, 2> zyzz;
            _shuffle_accessor<vec4, 3, 1, 2, 2> wyzz;
            _shuffle_accessor<vec4, 0, 2, 2, 2> xzzz;
            _shuffle_accessor<vec4, 1, 2, 2, 2> yzzz;
            _shuffle_accessor<vec4, 2, 2, 2, 2> zzzz;
            _shuffle_accessor<vec4, 3, 2, 2, 2> wzzz;
            _shuffle_accessor<vec4, 0, 3, 2, 2> xwzz;
            _shuffle_accessor<vec4, 1, 3, 2, 2> ywzz;
            _shuffle_accessor<vec4, 2, 3, 2, 2> zwzz;
            _shuffle_accessor<vec4, 3, 3, 2, 2> wwzz;
            _shuffle_accessor<vec4, 0, 0, 3, 2> xxwz;
            _shuffle_accessor<vec4, 1, 0, 3, 2> yxwz;
            _shuffle_accessor<vec4, 2, 0, 3, 2> zxwz;
            _shuffle_accessor<vec4, 3, 0, 3, 2> wxwz;
            _shuffle_accessor<vec4, 0, 1, 3, 2> xywz;
            _shuffle_accessor<vec4, 1, 1, 3, 2> yywz;
            _shuffle_accessor<vec4, 2, 1, 3, 2> zywz;
            _shuffle_accessor<vec4, 3, 1, 3, 2> wywz;
            _shuffle_accessor<vec4, 0, 2, 3, 2> xzwz;
            _shuffle_accessor<vec4, 1, 2, 3, 2> yzwz;
            _shuffle_accessor<vec4, 2, 2, 3, 2> zzwz;
            _shuffle_accessor<vec4, 3, 2, 3, 2> wzwz;
            _shuffle_accessor<vec4, 0, 3, 3, 2> xwwz;
            _shuffle_accessor<vec4, 1, 3, 3, 2> ywwz;
            _shuffle_accessor<vec4, 2, 3, 3, 2> zwwz;
            _shuffle_accessor<vec4, 3, 3, 3, 2> wwwz;
            _shuffle_accessor<vec4, 0, 0, 0, 3> xxxw;
            _shuffle_accessor<vec4, 1, 0, 0, 3> yxxw;
            _shuffle_accessor<vec4, 2, 0, 0, 3> zxxw;
            _shuffle_accessor<vec4, 3, 0, 0, 3> wxxw;
            _shuffle_accessor<vec4, 0, 1, 0, 3> xyxw;
            _shuffle_accessor<vec4, 1, 1, 0, 3> yyxw;
            _shuffle_accessor<vec4, 2, 1, 0, 3> zyxw;
            _shuffle_accessor<vec4, 3, 1, 0, 3> wyxw;
            _shuffle_accessor<vec4, 0, 2, 0, 3> xzxw;
            _shuffle_accessor<vec4, 1, 2, 0, 3> yzxw;
            _shuffle_accessor<vec4, 2, 2, 0, 3> zzxw;
            _shuffle_accessor<vec4, 3, 2, 0, 3> wzxw;
            _shuffle_accessor<vec4, 0, 3, 0, 3> xwxw;
            _shuffle_accessor<vec4, 1, 3, 0, 3> ywxw;
            _shuffle_accessor<vec4, 2, 3, 0, 3> zwxw;
            _shuffle_accessor<vec4, 3, 3, 0, 3> wwxw;
            _shuffle_accessor<vec4, 0, 0, 1, 3> xxyw;
            _shuffle_accessor<vec4, 1, 0, 1, 3> yxyw;
            _shuffle_accessor<vec4, 2, 0, 1, 3> zxyw;
            _shuffle_accessor<vec4, 3, 0, 1, 3> wxyw;
            _shuffle_accessor<vec4, 0, 1, 1, 3> xyyw;
            _shuffle_accessor<vec4, 1, 1, 1, 3> yyyw;
            _shuffle_accessor<vec4, 2, 1, 1, 3> zyyw;
            _shuffle_accessor<vec4, 3, 1, 1, 3> wyyw;
            _shuffle_accessor<vec4, 0, 2, 1, 3> xzyw;
            _shuffle_accessor<vec4, 1, 2, 1, 3> yzyw;
            _shuffle_accessor<vec4, 2, 2, 1, 3> zzyw;
            _shuffle_accessor<vec4, 3, 2, 1, 3> wzyw;
            _shuffle_accessor<vec4, 0, 3, 1, 3> xwyw;
            _shuffle_accessor<vec4, 1, 3, 1, 3> ywyw;
            _shuffle_accessor<vec4, 2, 3, 1, 3> zwyw;
            _shuffle_accessor<vec4, 3, 3, 1, 3> wwyw;
            _shuffle_accessor<vec4, 0, 0, 2, 3> xxzw;
            _shuffle_accessor<vec4, 1, 0, 2, 3> yxzw;
            _shuffle_accessor<vec4, 2, 0, 2, 3> zxzw;
            _shuffle_accessor<vec4, 3, 0, 2, 3> wxzw;
            _shuffle_accessor<vec4, 0, 1, 2, 3> xyzw;
            _shuffle_accessor<vec4, 1, 1, 2, 3> yyzw;
            _shuffle_accessor<vec4, 2, 1, 2, 3> zyzw;
            _shuffle_accessor<vec4, 3, 1, 2, 3> wyzw;
            _shuffle_accessor<vec4, 0, 2, 2, 3> xzzw;
            _shuffle_accessor<vec4, 1, 2, 2, 3> yzzw;
            _shuffle_accessor<vec4, 2, 2, 2, 3> zzzw;
            _shuffle_accessor<vec4, 3, 2, 2, 3> wzzw;
            _shuffle_accessor<vec4, 0, 3, 2, 3> xwzw;
            _shuffle_accessor<vec4, 1, 3, 2, 3> ywzw;
            _shuffle_accessor<vec4, 2, 3, 2, 3> zwzw;
            _shuffle_accessor<vec4, 3, 3, 2, 3> wwzw;
            _shuffle_accessor<vec4, 0, 0, 3, 3> xxww;
            _shuffle_accessor<vec4, 1, 0, 3, 3> yxww;
            _shuffle_accessor<vec4, 2, 0, 3, 3> zxww;
            _shuffle_accessor<vec4, 3, 0, 3, 3> wxww;
            _shuffle_accessor<vec4, 0, 1, 3, 3> xyww;
            _shuffle_accessor<vec4, 1, 1, 3, 3> yyww;
            _shuffle_accessor<vec4, 2, 1, 3, 3> zyww;
            _shuffle_accessor<vec4, 3, 1, 3, 3> wyww;
            _shuffle_accessor<vec4, 0, 2, 3, 3> xzww;
            _shuffle_accessor<vec4, 1, 2, 3, 3> yzww;
            _shuffle_accessor<vec4, 2, 2, 3, 3> zzww;
            _shuffle_accessor<vec4, 3, 2, 3, 3> wzww;
            _shuffle_accessor<vec4, 0, 3, 3, 3> xwww;
            _shuffle_accessor<vec4, 1, 3, 3, 3> ywww;
            _shuffle_accessor<vec4, 2, 3, 3, 3> zwww;
            _shuffle_accessor<vec4, 3, 3, 3, 3> wwww;
        };
    };

    bool operator==(const vec4& first, const vec4& second) noexcept;
    bool operator!=(const vec4& first, const vec4& second) noexcept;

    vec4 operator -(const vec4& first) noexcept;
    vec4 operator +(const vec4& first) noexcept;

    vec4 operator +(const vec4& first, const vec4& second) noexcept;
    vec4 operator -(const vec4& first, const vec4& second) noexcept;
    vec4 operator *(const vec4& first, const vec4& second) noexcept;
    vec4 operator /(const vec4& first, const vec4& second) noexcept;

    vec4 operator *(const vec4& vec, const float scalar) noexcept;
    vec4 operator /(const vec4& vec, const float scalar) noexcept;

    vec4 operator *(const float scalar, const vec4& vec) noexcept;
    vec4 operator /(const float scalar, const vec4& vec) noexcept;

    //----------------------

    #define ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(x) \
        extern template _scalar_accessor<x, 4>::operator float() const noexcept; \
        extern template void _scalar_accessor<x, 4>::operator=(float) noexcept;  \
        extern template void _scalar_accessor<x, 4>::operator+=(float) noexcept; \
        extern template void _scalar_accessor<x, 4>::operator-=(float) noexcept; \
        extern template void _scalar_accessor<x, 4>::operator*=(float) noexcept; \
        extern template void _scalar_accessor<x, 4>::operator/=(float) noexcept; \

    #define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
        extern template  _shuffle_accessor<vec2, x, y>::operator vec2() const noexcept;

    #define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
        extern template  _shuffle_accessor<vec3, x, y, z>::operator vec3() const noexcept;

    #define ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(x, y, z, w) \
        extern template  _shuffle_accessor<vec4, x, y, z, w>::operator vec4() const noexcept;

    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(0)
    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(1)
    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(2)
    ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR(3)

    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2(3, 3)

    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3(3, 3, 3)

    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 0, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 1, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 2, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 3, 0)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 0, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 1, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 2, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 3, 1)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 0, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 1, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 2, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 3, 2)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 0, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 1, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 2, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 0, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 0, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 0, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 0, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 1, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 1, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 1, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 1, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 2, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 2, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 2, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 2, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(0, 3, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(1, 3, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(2, 3, 3, 3)
    ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4(3, 3, 3, 3)

    #undef ZCM_EXTERN_TEMPLATE_SCALAR_ACCESSOR
    #undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_2
    #undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_3
    #undef ZCM_EXTERN_TEMPLATE_SHUFFLE_ACCESSOR_4
}
