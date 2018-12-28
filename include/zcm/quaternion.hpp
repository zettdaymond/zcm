#pragma once

namespace zcm {

    class quat;
    class vec3;
    class mat3;
    class mat4;

    quat  conjugate   (const quat& x) noexcept;
    quat  inverse     (const quat& x) noexcept;
    quat  lerp        (const quat& x, const quat& y, float t) noexcept;
    quat  nlerp       (const quat& x, const quat& y, float t) noexcept;
    quat  slerp       (const quat& x, const quat& y, float t) noexcept;
    quat  sterp       (const quat& x, const quat& y, const vec3& twist_axis, float t) noexcept;

    vec3  axis(const quat& q) noexcept;
    float angle(const quat& q) noexcept;
    quat  angleAxis(float angle, vec3 axis) noexcept;
    quat  rotate(const quat& q, float angle, const vec3& v) noexcept;

    vec3  eulerAngles (const quat& x) noexcept;
    float pitch       (const quat& x) noexcept;
    float yaw         (const quat& x) noexcept;
    float roll        (const quat& x) noexcept;

    mat3  mat3_cast   (const quat& x) noexcept;
    mat4  mat4_cast   (const quat& x) noexcept;

    quat  quat_cast   (const mat3& m) noexcept;
    quat  quat_cast   (const mat4& m) noexcept;

    quat  quatLookAtLH(const vec3& direction, const vec3& up) noexcept;
    quat  quatLookAtRH(const vec3& direction, const vec3& up) noexcept;

}
