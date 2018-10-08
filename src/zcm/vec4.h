#pragma once


#include <stdint.h>
#include <type_traits>


namespace zcm
{

    struct vec4
    {
        vec4() = default;
        ~vec4() = default;

        vec4(float value) :
            x(value),
            y(value),
            z(value),
            w(value)
        {}

        vec4(float _x, float _y, float _z, float _w) :
            x(_x),
            y(_y),
            z(_z),
            w(_w)
        {}

        float& operator[](const uint8_t val);
        const float& operator[](const uint8_t val) const;

        float x;
        float y;
        float z;
        float w;
    };


    static_assert (std::is_pod<vec4>::value);


    vec4 operator +(const vec4& first, const vec4& second);
    vec4 operator -(const vec4& first, const vec4& second);
    vec4 operator -(const vec4& first);
    vec4 operator *(const vec4& first, const vec4& second);

    vec4 operator *(const vec4& vec, const float scalar);
    vec4 operator /(const vec4& vec, const float scalar);

    vec4 operator *(const float scalar, const vec4& vec);
    vec4 operator /(const float scalar, const vec4& vec);
}


