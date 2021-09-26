#pragma once
#include <zcm/detail/vectorcall.hpp>

namespace zcm
{
    struct vec2;
    struct vec3;
    struct vec4;
    struct quat;

    float exp (float x) noexcept;
    vec2  exp (const vec2& x) noexcept;
    vec3  exp (const vec3& x) noexcept;
    vec4  zcm_vectorcall exp (vec4 x) noexcept;
    quat  zcm_vectorcall exp (quat x) noexcept;

    float exp2 (float x) noexcept;
    vec2  exp2 (const vec2& x) noexcept;
    vec3  exp2 (const vec3& x) noexcept;
    vec4  zcm_vectorcall exp2 (vec4 x) noexcept;
    quat  zcm_vectorcall exp2 (quat x) noexcept;

    float inversesqrt (float x) noexcept;
    vec2  inversesqrt (const vec2& x) noexcept;
    vec3  inversesqrt (const vec3& x) noexcept;
    vec4  zcm_vectorcall inversesqrt (vec4 x) noexcept;
    quat  zcm_vectorcall inversesqrt (quat x) noexcept;

    float log (float x) noexcept;
    vec2  log (const vec2& x) noexcept;
    vec3  log (const vec3& x) noexcept;
    vec4  zcm_vectorcall log (vec4 x) noexcept;
    quat  zcm_vectorcall log (quat x) noexcept;

    float log2 (float x) noexcept;
    vec2  log2 (const vec2& x) noexcept;
    vec3  log2 (const vec3& x) noexcept;
    vec4  zcm_vectorcall log2 (vec4 x) noexcept;
    quat  zcm_vectorcall log2 (quat x) noexcept;

    float pow (float x, float y) noexcept;
    vec2  pow (const vec2& x, const vec2& y) noexcept;
    vec3  pow (const vec3& x, const vec3& y) noexcept;
    vec4  zcm_vectorcall pow (vec4 x, vec4 y) noexcept;
    quat  zcm_vectorcall pow (quat x, float y) noexcept;

    float sqrt (float x) noexcept;
    vec2  sqrt (const vec2& x) noexcept;
    vec3  sqrt (const vec3& x) noexcept;
    vec4  zcm_vectorcall sqrt (vec4 x) noexcept;
    quat  zcm_vectorcall sqrt (quat x) noexcept;

    float cbrt(float x) noexcept;
    vec2  cbrt(vec2 x) noexcept;
    vec3  cbrt(vec3 x) noexcept;
    vec4  zcm_vectorcall cbrt(vec4 x) noexcept;
    quat  zcm_vectorcall cbrt(quat x) noexcept;

}
