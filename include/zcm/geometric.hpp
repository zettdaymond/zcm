#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;
    class quat;

    float dot(float first, float second) noexcept;
    float dot(const vec2& first, const vec2& second) noexcept;
    float dot(const vec3& first, const vec3& second) noexcept;
    float dot(const vec4& first, const vec4& second) noexcept;
    float dot(const quat& first, const quat& second) noexcept;

    float distance(float first, float second) noexcept;
    float distance(const vec2& first, const vec2& second) noexcept;
    float distance(const vec3& first, const vec3& second) noexcept;
    float distance(const vec4& first, const vec4& second) noexcept;

    float length(float first) noexcept;
    float length(const vec2& first) noexcept;
    float length(const vec3& first) noexcept;
    float length(const vec4& first) noexcept;
    float length(const quat& first) noexcept;

    float length2(float first) noexcept;
    float length2(const vec2& first) noexcept;
    float length2(const vec3& first) noexcept;
    float length2(const vec4& first) noexcept;
    float length2(const quat& first) noexcept;

    float faceforward(float N, float I, float Nref) noexcept;
    vec2  faceforward(const vec2& N, const vec2& I, const vec2& Nref) noexcept;
    vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref) noexcept;
    vec4  faceforward(const vec4& N, const vec4& I, const vec4& Nref) noexcept;

    vec3  cross(const vec3& first, const vec3& second) noexcept;

    vec2  normalize(const vec2& first) noexcept;
    vec3  normalize(const vec3& first) noexcept;
    vec4  normalize(const vec4& first) noexcept;
    quat  normalize(const quat& first) noexcept;

    float reflect (float I, float N) noexcept;
    vec2  reflect (const vec2 &I, const vec2& N) noexcept;
    vec3  reflect (const vec3 &I, const vec3& N) noexcept;
    vec4  reflect (const vec4 &I, const vec4& N) noexcept;

    float refract (float I, float N, float eta) noexcept;
    vec2  refract (const vec2 &I, const vec2& N, float eta) noexcept;
    vec3  refract (const vec3 &I, const vec3& N, float eta) noexcept;
    vec4  refract (const vec4 &I, const vec4& N, float eta) noexcept;

    /* Requires the input to be non-zero.
     * Doesn’t require the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal(const vec3& v) noexcept;

    /* Requires the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal_branchless(const vec3& v) noexcept;

}
