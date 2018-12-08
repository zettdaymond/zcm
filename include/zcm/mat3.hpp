#pragma once

#include <zcm/vec3.hpp>

namespace zcm
{

    struct mat2;
    struct mat3
    {
        mat3();
        explicit mat3(float value);
        explicit mat3(const mat2& m2);
        mat3(const vec3& c0,  const vec3& c1, const vec3& c2);

        vec3& operator[](unsigned pos);
        const vec3& operator[](unsigned pos) const;

        explicit operator mat2() const;

    //private:
        vec3 _columns[3];
    };

    mat3 operator +(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first);
    mat3 operator *(const mat3& first, const mat3& second);

    mat3 operator *(const mat3& mat, float scalar);
    mat3 operator /(const mat3& mat, float scalar);

    mat3 operator *(float scalar, const mat3& mat);
    mat3 operator /(float scalar, const mat3& mat);

}
