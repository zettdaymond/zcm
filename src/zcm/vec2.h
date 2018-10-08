#pragma once


#include <stdint.h>
#include <type_traits>


namespace zcm
{

    struct vec2
    {
        vec2() = default;
        ~vec2() = default;

        vec2(float value) :
            x(value),
            y(value)
        {}

        vec2(float _x, float _y) :
            x(_x),
            y(_y)
        {}

        float& operator[](const uint8_t val);
        const float& operator[](const uint8_t val) const;

        float x;
        float y;
    };


    static_assert (std::is_pod<vec2>::value);


    vec2 operator +(const vec2& first, const vec2& second);
    vec2 operator -(const vec2& first, const vec2& second);
    vec2 operator -(const vec2& first);
    vec2 operator *(const vec2& first, const vec2& second);

    vec2 operator *(const vec2& vec, const float scalar);
    vec2 operator /(const vec2& vec, const float scalar);

    vec2 operator *(const float scalar, const vec2& vec);
    vec2 operator /(const float scalar, const vec2& vec);
}


