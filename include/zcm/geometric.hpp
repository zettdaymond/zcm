#pragma once
#include <zcm/detail/vectorcall.hpp>

namespace zcm
{
    struct vec2;
    struct vec3;
    struct vec4;
    struct quat;

    float dot(float first, float second) noexcept;
    float dot(const vec2& first, const vec2& second) noexcept;
    float dot(const vec3& first, const vec3& second) noexcept;
    float zcm_vectorcall dot(vec4 first, vec4 second) noexcept;
    float zcm_vectorcall dot(quat first, quat second) noexcept;

    float distance(float first, float second) noexcept;
    float distance(const vec2& first, const vec2& second) noexcept;
    float distance(const vec3& first, const vec3& second) noexcept;
    float zcm_vectorcall distance(vec4 first, vec4 second) noexcept;

    float distance2(float first, float second) noexcept;
    float distance2(const vec2& first, const vec2& second) noexcept;
    float distance2(const vec3& first, const vec3& second) noexcept;
    float zcm_vectorcall distance2(vec4 first, vec4 second) noexcept;

    float length(float first) noexcept;
    float length(const vec2& first) noexcept;
    float length(const vec3& first) noexcept;
    float zcm_vectorcall length(vec4 first) noexcept;
    float zcm_vectorcall length(quat first) noexcept;

    float length2(float first) noexcept;
    float length2(const vec2& first) noexcept;
    float length2(const vec3& first) noexcept;
    float zcm_vectorcall length2(vec4 first) noexcept;
    float zcm_vectorcall length2(quat first) noexcept;

    float faceforward(float N, float I, float Nref) noexcept;
    vec2  faceforward(const vec2& N, const vec2& I, const vec2& Nref) noexcept;
    vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref) noexcept;
    vec4  zcm_vectorcall faceforward(vec4 N, vec4 I, vec4 Nref) noexcept;

    vec3  cross(const vec3& first, const vec3& second) noexcept;

    vec2  normalize(const vec2& first) noexcept;
    vec3  normalize(const vec3& first) noexcept;
    vec4  zcm_vectorcall normalize(vec4 first) noexcept;
    quat  zcm_vectorcall normalize(quat first) noexcept;

    float reflect (float I, float N) noexcept;
    vec2  reflect (const vec2 &I, const vec2& N) noexcept;
    vec3  reflect (const vec3 &I, const vec3& N) noexcept;
    vec4  zcm_vectorcall reflect (vec4 I, vec4 N) noexcept;

    float refract (float I, float N, float eta) noexcept;
    vec2  refract (const vec2 &I, const vec2& N, float eta) noexcept;
    vec3  refract (const vec3 &I, const vec3& N, float eta) noexcept;
    vec4  zcm_vectorcall refract (vec4 I, vec4 N, float eta) noexcept;

    /* Requires the input to be non-zero.
     * Doesn’t require the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal(const vec3& v) noexcept;

    /* Requires the input to be normalized.
     * Doesn’t normalise the output. */
    vec3 orthogonal_branchless(const vec3& v) noexcept;

    /* Encodes unit vector to octahedral representation.
     * Output is on [-1, 1] for each component. */
    vec2 encode_octahedral(zcm::vec3 unit_vector) noexcept;

    /* Decodes unit vector from octahedral representation. */
    vec3 decode_octahedral(zcm::vec2 oct_vector) noexcept;

}
