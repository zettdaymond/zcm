#pragma once

namespace zcm
{
    struct vec3;
    struct vec2;
    struct vec4
    {
        vec4 () noexcept;
        vec4 (float value) noexcept;
        vec4 (float x, float y, float z, float w) noexcept;

        vec4 (const vec3& xyz, float w) noexcept;
        vec4 (float x, const vec3& yzw) noexcept;

        vec4 (const vec2& xy, const vec2& zw) noexcept;
        vec4 (const vec2& xy, float z, float w) noexcept;
        vec4 (float x, const vec2& yz, float w) noexcept;
        vec4 (float x, float y, const vec2& zw) noexcept;

        float& operator[](unsigned val) noexcept;
        float operator[](unsigned val) const noexcept;

        void operator +=(const vec4& other) noexcept;
        void operator -=(const vec4& other) noexcept;
        void operator *=(const vec4& other) noexcept;
        void operator /=(const vec4& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        float x;
        float y;
        float z;
        float w;
    };

    bool operator==(const vec4& first, const vec4& second) noexcept;
    bool operator!=(const vec4& first, const vec4& second) noexcept;

    vec4 operator -(const vec4& first) noexcept;
    vec4 operator +(const vec4& first) noexcept;

    vec4 operator +(const vec4& first, const vec4& second) noexcept;
    vec4 operator -(const vec4& first, const vec4& second) noexcept;
    vec4 operator *(const vec4& first, const vec4& second) noexcept;
    vec4 operator /(const vec4& first, const vec4& second) noexcept;

    vec4 operator *(const vec4& vec, const float scalar) noexcept;
    vec4 operator /(const vec4& vec, const float scalar) noexcept;

    vec4 operator *(const float scalar, const vec4& vec) noexcept;
    vec4 operator /(const float scalar, const vec4& vec) noexcept;
}
