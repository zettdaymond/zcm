#pragma once

#include "vec3.h"

namespace zcm
{
    struct mat3
    {
        mat3();
        explicit mat3(float value);
        mat3(const vec3& _col0,  const vec3& _col1, const vec3& _col2);

        vec3& operator[](unsigned pos);
        const vec3& operator[](unsigned pos) const;

    //private:
        vec3 col0;
        vec3 col1;
        vec3 col2;
    };

    mat3 operator +(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first);
    mat3 operator *(const mat3& first, const mat3& second);

    mat3 operator *(const mat3& mat, const float scalar);
    mat3 operator /(const mat3& mat, const float scalar);

    mat3 operator *(const float scalar, const mat3& mat);
    mat3 operator /(const float scalar, const mat3& mat);

}
