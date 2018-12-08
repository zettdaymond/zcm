#pragma once

#include <zcm/vec4.hpp>

namespace zcm
{
    struct mat3;

    struct mat4
    {
        mat4();
        explicit mat4(float value);
        explicit mat4(const mat3& m);

        mat4(const vec4& c0,  const vec4& c1, const vec4& c2, const vec4& c3);

        vec4& operator[](unsigned pos);
        const vec4& operator[](unsigned pos) const;

        explicit operator mat3() const;

    //private:
        vec4 _columns[4];
    };

    mat4 operator +(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first, const mat4& second);
    mat4 operator -(const mat4& first);
    mat4 operator *(const mat4& first, const mat4& second);

    mat4 operator *(const mat4& mat, float scalar);
    mat4 operator /(const mat4& mat, float scalar);

    mat4 operator *(float scalar, const mat4& mat);
    mat4 operator /(float scalar, const mat4& mat);

}
