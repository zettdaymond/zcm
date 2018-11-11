#pragma once

namespace zcm
{
    struct vec2
    {
        vec2();
        vec2(float value);
        vec2(float x, float y);

        float& operator[](unsigned val);
        const float& operator[](unsigned val) const;

        float x;
        float y;
    };

    vec2 operator +(const vec2& first, const vec2& second);
    vec2 operator -(const vec2& first, const vec2& second);
    vec2 operator -(const vec2& first);
    vec2 operator *(const vec2& first, const vec2& second);
    vec2 operator /(const vec2& first, const vec2& second);

    vec2 operator *(const vec2& vec, const float scalar);
    vec2 operator /(const vec2& vec, const float scalar);

    vec2 operator *(const float scalar, const vec2& vec);
    vec2 operator /(const float scalar, const vec2& vec);
}


