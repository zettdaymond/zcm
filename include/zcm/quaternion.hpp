#pragma once
#include <zcm/detail/vectorcall.hpp>

namespace zcm {

    struct quat;
    struct vec3;
    struct mat3;
    struct mat4;

    quat  zcm_vectorcall conjugate   (quat x) noexcept;
    quat  zcm_vectorcall inverse     (quat x) noexcept;
    quat  zcm_vectorcall lerp        (quat x, quat y, float t) noexcept;
    quat  zcm_vectorcall nlerp       (quat x, quat y, float t) noexcept;
    quat  zcm_vectorcall slerp       (quat x, quat y, float t) noexcept;
    quat  zcm_vectorcall sterp       (quat x, quat y, const vec3& twist_axis, float t) noexcept;

    vec3  zcm_vectorcall axis(quat q) noexcept;
    float zcm_vectorcall angle(quat q) noexcept;
    quat  angleAxis(float angle, vec3 axis) noexcept;
    quat  zcm_vectorcall rotate(quat q, float angle, const vec3& v) noexcept;

    vec3  zcm_vectorcall eulerAngles (quat x) noexcept;
    float zcm_vectorcall pitch       (quat x) noexcept;
    float zcm_vectorcall yaw         (quat x) noexcept;
    float zcm_vectorcall roll        (quat x) noexcept;

    mat3  zcm_vectorcall mat3_cast   (quat x) noexcept;
    mat4  zcm_vectorcall mat4_cast   (quat x) noexcept;

    quat  quat_cast   (const mat3& m) noexcept;
    quat  quat_cast   (const mat4& m) noexcept;

    quat  quatLookAtLH(const vec3& direction, const vec3& up) noexcept;
    quat  quatLookAtRH(const vec3& direction, const vec3& up) noexcept;

}
