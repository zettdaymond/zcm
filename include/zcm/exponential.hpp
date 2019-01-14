#pragma once

namespace zcm
{
    struct vec2;
    struct vec3;
    struct vec4;
    struct quat;

    float exp (float x) noexcept;
    vec2  exp (const vec2& x) noexcept;
    vec3  exp (const vec3& x) noexcept;
    vec4  exp (const vec4& x) noexcept;
    quat  exp (const quat& x) noexcept;

    float exp2 (float x) noexcept;
    vec2  exp2 (const vec2& x) noexcept;
    vec3  exp2 (const vec3& x) noexcept;
    vec4  exp2 (const vec4& x) noexcept;
    quat  exp2 (const quat& x) noexcept;

    float inversesqrt (float x) noexcept;
    vec2  inversesqrt (const vec2& x) noexcept;
    vec3  inversesqrt (const vec3& x) noexcept;
    vec4  inversesqrt (const vec4& x) noexcept;
    quat  inversesqrt (const quat& x) noexcept;

    float log (float x) noexcept;
    vec2  log (const vec2& x) noexcept;
    vec3  log (const vec3& x) noexcept;
    vec4  log (const vec4& x) noexcept;
    quat  log (const quat& x) noexcept;

    float log2 (float x) noexcept;
    vec2  log2 (const vec2& x) noexcept;
    vec3  log2 (const vec3& x) noexcept;
    vec4  log2 (const vec4& x) noexcept;
    quat  log2 (const quat& x) noexcept;

    float pow (float x, float y) noexcept;
    vec2  pow (const vec2& x, const vec2& y) noexcept;
    vec3  pow (const vec3& x, const vec3& y) noexcept;
    vec4  pow (const vec4& x, const vec4& y) noexcept;
    quat  pow (const quat& x, float y) noexcept;

    float sqrt (float x) noexcept;
    vec2  sqrt (const vec2& x) noexcept;
    vec3  sqrt (const vec3& x) noexcept;
    vec4  sqrt (const vec4& x) noexcept;
    quat  sqrt (const quat& x) noexcept;
}
