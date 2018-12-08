#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;
    class quat;

    float dot(float first, float second);
    float dot(const vec2& first, const vec2& second);
    float dot(const vec3& first, const vec3& second);
    float dot(const vec4& first, const vec4& second);
    float dot(const quat& first, const quat& second);

    float distance(float first, float second);
    float distance(const vec2& first, const vec2& second);
    float distance(const vec3& first, const vec3& second);
    float distance(const vec4& first, const vec4& second);

    float length(float first);
    float length(const vec2& first);
    float length(const vec3& first);
    float length(const vec4& first);
    float length(const quat& first);

    float length2(float first);
    float length2(const vec2& first);
    float length2(const vec3& first);
    float length2(const vec4& first);
    float length2(const quat& first);

    float faceforward(float N, float I, float Nref);
    vec2  faceforward(const vec2& N, const vec2& I, const vec2& Nref);
    vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref);
    vec4  faceforward(const vec4& N, const vec4& I, const vec4& Nref);

    vec3  cross(const vec3& first, const vec3& second);

    vec2  normalize(const vec2& first);
    vec3  normalize(const vec3& first);
    vec4  normalize(const vec4& first);
    quat  normalize(const quat& first);

    float reflect (float I, float N);
    vec2  reflect (const vec2 &I, const vec2& N);
    vec3  reflect (const vec3 &I, const vec3& N);
    vec4  reflect (const vec4 &I, const vec4& N);

    float refract (float I, float N, float eta);
    vec2  refract (const vec2 &I, const vec2& N, float eta);
    vec3  refract (const vec3 &I, const vec3& N, float eta);
    vec4  refract (const vec4 &I, const vec4& N, float eta);

    /* Requires the input to be non-zero.
     * Doesn’t require the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal(const vec3& v);

    /* Requires the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal_branchless(const vec3& v);

}
