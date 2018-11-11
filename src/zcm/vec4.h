#pragma once

namespace zcm
{
    struct vec4
    {
        vec4();
        vec4(float value);
        vec4(float x, float y, float z, float w);

        float& operator[](unsigned val);
        const float& operator[](unsigned val) const;

        float x;
        float y;
        float z;
        float w;
    };

    vec4 operator +(const vec4& first, const vec4& second);
    vec4 operator -(const vec4& first, const vec4& second);
    vec4 operator -(const vec4& first);
    vec4 operator *(const vec4& first, const vec4& second);
    vec4 operator /(const vec4& first, const vec4& second);

    vec4 operator *(const vec4& vec, const float scalar);
    vec4 operator /(const vec4& vec, const float scalar);

    vec4 operator *(const float scalar, const vec4& vec);
    vec4 operator /(const float scalar, const vec4& vec);
}


