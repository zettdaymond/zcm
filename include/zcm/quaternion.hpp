#pragma once

namespace zcm {

    class quat;
    class vec3;
    class mat3;
    class mat4;

    quat  conjugate   (const quat& x);
    quat  inverse     (const quat& x);
    quat  lerp        (const quat& x, const quat& y, float t);
    quat  nlerp       (const quat& x, const quat& y, float t);
    quat  slerp       (const quat& x, const quat& y, float t);
    quat  sterp       (const quat& x, const quat& y, const vec3& twist_axis, float t);

    vec3  axis(const quat& q);
    float angle(const quat& q);
    quat  angleAxis(float angle, vec3 axis);

    vec3  rotate      (const vec3& v, const quat& q);
    vec3  rotate      (const quat& q, const vec3& v);

    vec3  eulerAngles (const quat& x);
    float pitch       (const quat& x);
    float yaw         (const quat& x);
    float roll        (const quat& x);

    mat3  mat3_cast   (const quat& x);
    mat4  mat4_cast   (const quat& x);

    quat  quat_cast   (const mat3& m);
    quat  quat_cast   (const mat4& m);

    quat  quatLookAtLH(const vec3& direction, const vec3& up);
    quat  quatLookAtRH(const vec3& direction, const vec3& up);

}
