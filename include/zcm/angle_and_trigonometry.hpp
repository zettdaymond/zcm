#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;

    float cos (float angle);
    vec2  cos (const vec2& angle);
    vec3  cos (const vec3& angle);
    vec4  cos (const vec4& angle);

    float sin (float angle);
    vec2  sin (const vec2& angle);
    vec3  sin (const vec3& angle);
    vec4  sin (const vec4& angle);

    float acos (float x);
    vec2  acos (const vec2& x);
    vec3  acos (const vec3& x);
    vec4  acos (const vec4& x);

    float acosh (float x);
    vec2  acosh (const vec2& x);
    vec3  acosh (const vec3& x);
    vec4  acosh (const vec4& x);

    float asin (float x);
    vec2  asin (const vec2& x);
    vec3  asin (const vec3& x);
    vec4  asin (const vec4& x);

    float asinh (float x);
    vec2  asinh (const vec2& x);
    vec3  asinh (const vec3& x);
    vec4  asinh (const vec4& x);

    float atan (float y, float x);
    vec2  atan (const vec2& y, const vec2& x);
    vec3  atan (const vec3& y, const vec3& x);
    vec4  atan (const vec4& y, const vec4& x);

    float atan (float y_over_x);
    vec2  atan (const vec2& y_over_x);
    vec3  atan (const vec3& y_over_x);
    vec4  atan (const vec4& y_over_x);

    float atanh (float x);
    vec2  atanh (const vec2& x);
    vec3  atanh (const vec3& x);
    vec4  atanh (const vec4& x);

    float cosh (float angle);
    vec2  cosh (const vec2& angle);
    vec3  cosh (const vec3& angle);
    vec4  cosh (const vec4& angle);

    float degrees (float radians);
    vec2  degrees (const vec2& radians);
    vec3  degrees (const vec3& radians);
    vec4  degrees (const vec4& radians);

    float radians (float degrees);
    vec2  radians (const vec2& degrees);
    vec3  radians (const vec3& degrees);
    vec4  radians (const vec4& degrees);

    float sinh (float angle);
    vec2  sinh (const vec2& angle);
    vec3  sinh (const vec3& angle);
    vec4  sinh (const vec4& angle);

    float tan (float angle);
    vec2  tan (const vec2& angle);
    vec3  tan (const vec3& angle);
    vec4  tan (const vec4& angle);

    float tanh (float angle);
    vec2  tanh (const vec2& angle);
    vec3  tanh (const vec3& angle);
    vec4  tanh (const vec4& angle);
}
