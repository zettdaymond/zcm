#pragma once

namespace zcm
{
    struct vec2
    {
        vec2() noexcept;
        vec2(float value) noexcept;
        vec2(float x, float y) noexcept;

        float& operator[](unsigned val) noexcept;
        float operator[](unsigned val) const noexcept;

        float x;
        float y;

        void operator +=(const vec2& other) noexcept;
        void operator -=(const vec2& other) noexcept;
        void operator *=(const vec2& other) noexcept;
        void operator /=(const vec2& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

    };

    bool operator==(const vec2& first, const vec2& second) noexcept;
    bool operator!=(const vec2& first, const vec2& second) noexcept;

    vec2 operator +(const vec2& first) noexcept;
    vec2 operator -(const vec2& first) noexcept;

    vec2 operator +(const vec2& first, const vec2& second) noexcept;
    vec2 operator -(const vec2& first, const vec2& second) noexcept;
    vec2 operator *(const vec2& first, const vec2& second) noexcept;
    vec2 operator /(const vec2& first, const vec2& second) noexcept;

    vec2 operator *(const vec2& vec, const float scalar) noexcept;
    vec2 operator /(const vec2& vec, const float scalar) noexcept;

    vec2 operator *(const float scalar, const vec2& vec) noexcept;
    vec2 operator /(const float scalar, const vec2& vec) noexcept;
}


