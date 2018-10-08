#pragma once

#include <stdint.h>
#include <type_traits>


namespace zcm
{

    struct vec3
    {
        vec3() = default;
        ~vec3() = default;

        vec3(float value) :
            x(value),
            y(value),
            z(value)
        {}

        vec3(float _x, float _y, float _z) :
            x(_x),
            y(_y),
            z(_z)
        {}

        float& operator[](const uint8_t val);
        const float& operator[](const uint8_t val) const;

        float x;
        float y;
        float z;
    };


    static_assert (std::is_pod<vec3>::value);


    vec3 operator +(const vec3& first, const vec3& second);
    vec3 operator -(const vec3& first, const vec3& second);
    vec3 operator -(const vec3& first);
    vec3 operator *(const vec3& first, const vec3& second);

    vec3 operator *(const vec3& vec, const float scalar);
    vec3 operator /(const vec3& vec, const float scalar);

    vec3 operator *(const float scalar, const vec3& vec);
    vec3 operator /(const float scalar, const vec3& vec);
}
