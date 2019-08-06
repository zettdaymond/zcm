#pragma once

#include <zcm/init.hpp>

namespace zcm
{

    struct vec3;
    struct vec4;

    struct quat
    {
        quat() noexcept;
        explicit quat(no_init_t) noexcept;
        quat(float w, float x, float y, float z) noexcept;
        quat(float s, vec3 v) noexcept;
        quat(vec3 v, float s) noexcept;

        /// Build a unit quaternion representing the rotation from u to v.
        /// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
        /// The input vectors need not be normalised.
        quat(vec3 u, vec3 v) noexcept;

        /// Build a quaternion from euler angles (pitch, yaw, roll), in radians.
        explicit quat(vec3 eulerAngles) noexcept;

        float& operator[](unsigned val) noexcept;
        float operator[](unsigned val) const noexcept;

        void operator +=(const quat& other) noexcept;
        void operator -=(const quat& other) noexcept;
        void operator *=(const quat& other) noexcept;

        void operator *=(float scalar) noexcept;
        void operator /=(float scalar) noexcept;

        float x;
        float y;
        float z;
        float w;
    };

    bool operator==(const quat& first, const quat& second) noexcept;
    bool operator!=(const quat& first, const quat& second) noexcept;

    quat operator +(const quat& a, const quat& b) noexcept;
    quat operator -(const quat& a, const quat& b) noexcept;
    quat operator *(const quat& a, const quat& b) noexcept;
    quat operator +(const quat& a) noexcept;
    quat operator -(const quat& a) noexcept;

    quat operator *(const quat& q, float s) noexcept;
    quat operator *(float s, const quat& q) noexcept;
    quat operator /(float s, const quat& q) noexcept;
    quat operator /(const quat& q, float s) noexcept;

    /// rotate vector
    vec3 operator*(const quat& q, const vec3& v) noexcept;
    /// inverse-rotate vector
    vec3 operator*(const vec3& v, const quat& q) noexcept;

}
