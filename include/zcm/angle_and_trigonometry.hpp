#pragma once

namespace zcm
{
    struct vec2;
    struct vec3;
    struct vec4;

    float cos (float angle) noexcept;
    vec2  cos (const vec2& angle) noexcept;
    vec3  cos (const vec3& angle) noexcept;
    vec4  cos (const vec4& angle) noexcept;

    float sin (float angle) noexcept;
    vec2  sin (const vec2& angle) noexcept;
    vec3  sin (const vec3& angle) noexcept;
    vec4  sin (const vec4& angle) noexcept;

    float acos (float x) noexcept;
    vec2  acos (const vec2& x) noexcept;
    vec3  acos (const vec3& x) noexcept;
    vec4  acos (const vec4& x) noexcept;

    float acosh (float x) noexcept;
    vec2  acosh (const vec2& x) noexcept;
    vec3  acosh (const vec3& x) noexcept;
    vec4  acosh (const vec4& x) noexcept;

    float asin (float x) noexcept;
    vec2  asin (const vec2& x) noexcept;
    vec3  asin (const vec3& x) noexcept;
    vec4  asin (const vec4& x) noexcept;

    float asinh (float x) noexcept;
    vec2  asinh (const vec2& x) noexcept;
    vec3  asinh (const vec3& x) noexcept;
    vec4  asinh (const vec4& x) noexcept;

    float atan (float y, float x) noexcept;
    vec2  atan (const vec2& y, const vec2& x) noexcept;
    vec3  atan (const vec3& y, const vec3& x) noexcept;
    vec4  atan (const vec4& y, const vec4& x) noexcept;

    float atan (float y_over_x) noexcept;
    vec2  atan (const vec2& y_over_x) noexcept;
    vec3  atan (const vec3& y_over_x) noexcept;
    vec4  atan (const vec4& y_over_x) noexcept;

    float atanh (float x) noexcept;
    vec2  atanh (const vec2& x) noexcept;
    vec3  atanh (const vec3& x) noexcept;
    vec4  atanh (const vec4& x) noexcept;

    float cosh (float angle) noexcept;
    vec2  cosh (const vec2& angle) noexcept;
    vec3  cosh (const vec3& angle) noexcept;
    vec4  cosh (const vec4& angle) noexcept;

    float degrees (float radians) noexcept;
    vec2  degrees (const vec2& radians) noexcept;
    vec3  degrees (const vec3& radians) noexcept;
    vec4  degrees (const vec4& radians) noexcept;

    float radians (float degrees) noexcept;
    vec2  radians (const vec2& degrees) noexcept;
    vec3  radians (const vec3& degrees) noexcept;
    vec4  radians (const vec4& degrees) noexcept;

    float sinh (float angle) noexcept;
    vec2  sinh (const vec2& angle) noexcept;
    vec3  sinh (const vec3& angle) noexcept;
    vec4  sinh (const vec4& angle) noexcept;

    float tan (float angle) noexcept;
    vec2  tan (const vec2& angle) noexcept;
    vec3  tan (const vec3& angle) noexcept;
    vec4  tan (const vec4& angle) noexcept;

    float tanh (float angle) noexcept;
    vec2  tanh (const vec2& angle) noexcept;
    vec3  tanh (const vec3& angle) noexcept;
    vec4  tanh (const vec4& angle) noexcept;
}
