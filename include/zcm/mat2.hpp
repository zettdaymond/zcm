#pragma once

#include <zcm/vec2.hpp>

namespace zcm
{
    struct mat2
    {
        mat2();
        explicit mat2(float value);

        mat2(float a00, float a01, float a10, float a11);
        mat2(vec2 col0, vec2 col1);

        vec2& operator[](unsigned pos);
        vec2 operator[](unsigned pos) const;

    //private:
        vec2 _columns[2];
    };


    mat2 operator +(const mat2& first, const mat2& second);
    mat2 operator -(const mat2& first, const mat2& second);
    mat2 operator -(const mat2& first);
    mat2 operator *(const mat2& first, const mat2& second);

    mat2 operator *(const mat2& mat, float scalar);
    mat2 operator /(const mat2& mat, float scalar);

    mat2 operator *(float scalar, const mat2& mat);
    mat2 operator /(float scalar, const mat2& mat);

}
