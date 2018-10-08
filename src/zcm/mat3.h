#pragma once

#include "vec3.h"
#include "type_traits"
#include "assert.h"

namespace zcm
{
    struct mat3
    {
        ~mat3() = default;

        mat3(float value) :
            col0(value, 0.0f, 0.0f),
            col1(0.0f, value, 0.0f),
            col2(0.0f, 0.0f, value)
        {}

        mat3(const vec3& _col0,  const vec3& _col1, const vec3& _col2) :
            col0(_col0),
            col1(_col1),
            col2(_col2)
        {}

        vec3& operator[](const uint8_t pos );
        const vec3& operator[](const uint8_t pos ) const;

        vec3 col0;
        vec3 col1;
        vec3 col2;

//    private:
        mat3() = default;
    };

    static_assert (std::is_pod<mat3>::value);


    mat3 operator +(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first, const mat3& second);
    mat3 operator -(const mat3& first);
    mat3 operator *(const mat3& first, const mat3& second);

    mat3 operator *(const mat3& mat, const float scalar);
    mat3 operator /(const mat3& mat, const float scalar);

    mat3 operator *(const float scalar, const mat3& mat);
    mat3 operator /(const float scalar, const mat3& mat);

}
