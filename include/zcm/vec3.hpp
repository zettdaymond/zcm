#pragma once

namespace zcm
{

    struct vec2;
    struct vec3
    {
        vec3() noexcept;
        vec3(float value) noexcept;
        vec3(float x, float y, float z) noexcept;

        vec3(vec2 xy, float z) noexcept;
        vec3(float x, vec2 yz) noexcept;

        float& operator[](unsigned val) noexcept;
        float operator[](unsigned val) const noexcept;

        void operator +=(const vec3& other) noexcept;
        void operator -=(const vec3& other) noexcept;
        void operator *=(const vec3& other) noexcept;
        void operator /=(const vec3& other) noexcept;

        void operator +=(float scalar) noexcept;
        void operator -=(float scalar) noexcept;
        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        float x;
        float y;
        float z;
    };

    bool operator==(const vec3& first, const vec3& second) noexcept;
    bool operator!=(const vec3& first, const vec3& second) noexcept;

    vec3 operator -(const vec3& first) noexcept;
    vec3 operator +(const vec3& first) noexcept;

    vec3 operator +(const vec3& first, const vec3& second) noexcept;
    vec3 operator -(const vec3& first, const vec3& second) noexcept;
    vec3 operator *(const vec3& first, const vec3& second) noexcept;
    vec3 operator /(const vec3& first, const vec3& second) noexcept;

    vec3 operator *(const vec3& vec, const float scalar) noexcept;
    vec3 operator /(const vec3& vec, const float scalar) noexcept;

    vec3 operator *(const float scalar, const vec3& vec) noexcept;
    vec3 operator /(const float scalar, const vec3& vec) noexcept;
}
