#pragma once

namespace zcm
{
    struct vec3;
    struct vec2;
    struct vec4
    {
        vec4 ();
        vec4 (float value);
        vec4 (float x, float y, float z, float w);

        vec4 (const vec3& xyz, float w);
        vec4 (float x, const vec3& yzw);

        vec4 (const vec2& xy, const vec2& zw);
        vec4 (const vec2& xy, float z, float w);
        vec4 (float x, const vec2& yz, float w);
        vec4 (float x, float y, const vec2& zw);

        float& operator[](unsigned val);
        float operator[](unsigned val) const;

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
