#pragma once

#include "vec4.h"
#include "type_traits"
#include "assert.h"

namespace zcm
{
    struct mat4
    {
        ~mat4() = default;

        mat4(float value) :
            col0(value, 0.0f, 0.0f, 0.0f),
            col1(0.0f, value, 0.0f, 0.0f),
            col2(0.0f, 0.0f, value, 0.0f),
            col3(0.0f, 0.0f, 0.0f, value)
        {}

        mat4(const vec4& _col0,  const vec4& _col1, const vec4& _col2, const vec4& _col3) :
            col0(_col0),
            col1(_col1),
            col2(_col2),
            col3(_col3)
        {}

        vec4& operator[](const uint8_t pos );
        const vec4& operator[](const uint8_t pos ) const;

        vec4 col0;
        vec4 col1;
        vec4 col2;
        vec4 col3;

    //private:
        mat4() = default;
    };

    static_assert (std::is_pod<mat4>::value);


    mat4 operator +(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first);
    mat4 operator *(const mat4& first, const mat4& second);

    mat4 operator *(const mat4& mat, const float scalar);
    mat4 operator /(const mat4& mat, const float scalar);

    mat4 operator *(const float scalar, const mat4& mat);
    mat4 operator /(const float scalar, const mat4& mat);

}
