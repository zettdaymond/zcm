#pragma once
#include <zcm/detail/vectorcall.hpp>

namespace zcm {

    struct vec2;
    struct vec3;
    struct vec4;
    struct ivec2;
    struct ivec3;
    struct ivec4;

    float compAdd(const zcm::vec2&) noexcept;
    float compAdd(const zcm::vec3&) noexcept;
    float zcm_vectorcall compAdd(zcm::vec4) noexcept;
    int compAdd(const zcm::ivec2&) noexcept;
    int compAdd(const zcm::ivec3&) noexcept;
    int compAdd(const zcm::ivec4&) noexcept;

    float compMul(const zcm::vec2&) noexcept;
    float compMul(const zcm::vec3&) noexcept;
    float zcm_vectorcall compMul(zcm::vec4) noexcept;
    int compMul(const zcm::ivec2&) noexcept;
    int compMul(const zcm::ivec3&) noexcept;
    int compMul(const zcm::ivec4&) noexcept;

    float compMin(const zcm::vec2&) noexcept;
    float compMin(const zcm::vec3&) noexcept;
    float zcm_vectorcall compMin(zcm::vec4) noexcept;
    int compMin(const zcm::ivec2&) noexcept;
    int compMin(const zcm::ivec3&) noexcept;
    int compMin(const zcm::ivec4&) noexcept;

    float compMax(const zcm::vec2&) noexcept;
    float compMax(const zcm::vec3&) noexcept;
    float zcm_vectorcall compMax(zcm::vec4) noexcept;
    int compMax(const zcm::ivec2&) noexcept;
    int compMax(const zcm::ivec3&) noexcept;
    int compMax(const zcm::ivec4&) noexcept;

}
