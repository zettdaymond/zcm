#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;
    class quat;

    float exp (const float x);
    vec2  exp (const vec2& x);
    vec3  exp (const vec3& x);
    vec4  exp (const vec4& x);
    quat  exp (const quat& x);

    float exp2 (const float x);
    vec2  exp2 (const vec2& x);
    vec3  exp2 (const vec3& x);
    vec4  exp2 (const vec4& x);
    quat  exp2 (const quat& x);

    float inversesqrt (const float x);
    vec2  inversesqrt (const vec2& x);
    vec3  inversesqrt (const vec3& x);
    vec4  inversesqrt (const vec4& x);
    quat  inversesqrt (const quat& x);

    float log (const float x);
    vec2  log (const vec2& x);
    vec3  log (const vec3& x);
    vec4  log (const vec4& x);
    quat  log (const quat& x);

    float log2 (const float x);
    vec2  log2 (const vec2& x);
    vec3  log2 (const vec3& x);
    vec4  log2 (const vec4& x);
    quat  log2 (const quat& x);

    float pow (const float x, const float y);
    vec2  pow (const vec2& x, const vec2& y);
    vec3  pow (const vec3& x, const vec3& y);
    vec4  pow (const vec4& x, const vec4& y);
    quat  pow (const quat& x, float y);

    float sqrt (const float x);
    vec2  sqrt (const vec2& x);
    vec3  sqrt (const vec3& x);
    vec4  sqrt (const vec4& x);
    quat  sqrt (const quat& x);
}
