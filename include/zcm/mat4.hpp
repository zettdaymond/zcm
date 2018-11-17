#pragma once

#include <zcm/vec4.hpp>

namespace zcm
{
    struct mat4
    {
        mat4();
        mat4(float value);
        mat4(const vec4& _col0,  const vec4& _col1, const vec4& _col2, const vec4& _col3);

        vec4& operator[](unsigned pos);
        const vec4& operator[](unsigned pos) const;

    //private:
        vec4 col0;
        vec4 col1;
        vec4 col2;
        vec4 col3;
    };

    mat4 operator +(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first);
    mat4 operator *(const mat4& first, const mat4& second);

    mat4 operator *(const mat4& mat, const float scalar);
    mat4 operator /(const mat4& mat, const float scalar);

    mat4 operator *(const float scalar, const mat4& mat);
    mat4 operator /(const float scalar, const mat4& mat);

}
