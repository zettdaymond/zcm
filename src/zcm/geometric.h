#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;

    float dot(const float first, const float second);
    float dot(const vec2& first, const vec2& second);
    float dot(const vec3& first, const vec3& second);
    float dot(const vec4& first, const vec4& second);

    float distance(const float first, const float second);
    float distance(const vec2& first, const vec2& second);
    float distance(const vec3& first, const vec3& second);
    float distance(const vec4& first, const vec4& second);

    float length(const float first);
    float length(const vec2& first);
    float length(const vec3& first);
    float length(const vec4& first);

    float faceforward(const float N, const float I, const float Nref);
    vec2  faceforward(const vec2& N, const vec2& I, const vec2& Nref);
    vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref);
    vec4  faceforward(const vec4& N, const vec4& I, const vec4& Nref);

    vec3  cross(const vec3& first, const vec3& second);

    float normalize(const float first);
    vec2  normalize(const vec2& first);
    vec3  normalize(const vec3& first);
    vec4  normalize(const vec4& first);

    float reflect (const float I, const float N);
    vec2  reflect (const vec2 &I, const vec2& N);
    vec3  reflect (const vec3 &I, const vec3& N);
    vec4  reflect (const vec4 &I, const vec4& N);

    float refract (const float I, const float N, float eta);
    vec2  refract (const vec2 &I, const vec2& N, float eta);
    vec3  refract (const vec3 &I, const vec3& N, float eta);
    vec4  refract (const vec4 &I, const vec4& N, float eta);
}
