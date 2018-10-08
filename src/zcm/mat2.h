#pragma once

#include "vec2.h"
#include "type_traits"
#include "assert.h"

namespace zcm
{
    struct mat2
    {
        ~mat2() = default;

        mat2(float value) :
            col0(value, 0.0f),
            col1(0.0f, value)
        {}

        mat2(float a00, float a01, float a10, float a11) :
            col0{a00, a10},
            col1{a01, a11}
        {}

        mat2(const vec2& _col0, const vec2& _col1) :
            col0{_col0},
            col1{_col1}
        {}

        vec2& operator[](const uint8_t pos );
        const vec2& operator[](const uint8_t pos ) const;

        vec2 col0;
        vec2 col1;

//    private:
        mat2() = default;
    };

    static_assert (std::is_pod<mat2>::value);


    mat2 operator +(const mat2& first, const mat2& second);
    mat2 operator -(const mat2& first, const mat2& second);
    mat2 operator -(const mat2& first);
    mat2 operator *(const mat2& first, const mat2& second);

    mat2 operator *(const mat2& mat, const float scalar);
    mat2 operator /(const mat2& mat, const float scalar);

    mat2 operator *(const float scalar, const mat2& mat);
    mat2 operator /(const float scalar, const mat2& mat);

}
