#pragma once

namespace zcm {

    struct vec2;
    struct vec3;
    struct vec4;

    float compAdd(const zcm::vec2&) noexcept;
    float compAdd(const zcm::vec3&) noexcept;
    float compAdd(const zcm::vec4&) noexcept;

    float compMul(const zcm::vec2&) noexcept;
    float compMul(const zcm::vec3&) noexcept;
    float compMul(const zcm::vec4&) noexcept;

    float compMin(const zcm::vec2&) noexcept;
    float compMin(const zcm::vec3&) noexcept;
    float compMin(const zcm::vec4&) noexcept;

    float compMax(const zcm::vec2&) noexcept;
    float compMax(const zcm::vec3&) noexcept;
    float compMax(const zcm::vec4&) noexcept;

}
