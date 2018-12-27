#pragma once

namespace zcm
{

    struct vec2;
    struct vec3
    {
        vec3();
        vec3(float value);
        vec3(float x, float y, float z);

        vec3(vec2 xy, float z);
        vec3(float x, vec2 yz);

        float& operator[](unsigned val);
        float operator[](unsigned val) const;

        void operator +=(const vec3& other);
        void operator -=(const vec3& other);
        void operator *=(const vec3& other);
        void operator /=(const vec3& other);

        void operator +=(float scalar);
        void operator -=(float scalar);
        void operator *=(float scalar);
        void operator /=(float scalar);

        float x;
        float y;
        float z;
    };

    bool operator==(const vec3& first, const vec3& second);
    bool operator!=(const vec3& first, const vec3& second);

    vec3 operator -(const vec3& first);
    vec3 operator +(const vec3& first);

    vec3 operator +(const vec3& first, const vec3& second);
    vec3 operator -(const vec3& first, const vec3& second);
    vec3 operator *(const vec3& first, const vec3& second);
    vec3 operator /(const vec3& first, const vec3& second);

    vec3 operator *(const vec3& vec, const float scalar);
    vec3 operator /(const vec3& vec, const float scalar);

    vec3 operator *(const float scalar, const vec3& vec);
    vec3 operator /(const float scalar, const vec3& vec);
}
