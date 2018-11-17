#pragma once

namespace zcm
{

    struct vec3
    {
        vec3();
        vec3(float value);
        vec3(float x, float y, float z);

        float& operator[](unsigned val);
        const float& operator[](unsigned val) const;

        float x;
        float y;
        float z;
    };

    vec3 operator +(const vec3& first, const vec3& second);
    vec3 operator -(const vec3& first, const vec3& second);
    vec3 operator -(const vec3& first);
    vec3 operator *(const vec3& first, const vec3& second);
    vec3 operator /(const vec3& first, const vec3& second);

    vec3 operator *(const vec3& vec, const float scalar);
    vec3 operator /(const vec3& vec, const float scalar);

    vec3 operator *(const float scalar, const vec3& vec);
    vec3 operator /(const float scalar, const vec3& vec);
}
