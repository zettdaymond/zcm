#pragma once

#include <zcm/vec3.hpp>

namespace zcm
{

    struct mat2;
    struct mat3
    {
        mat3() noexcept;
        explicit mat3(float value) noexcept;
        explicit mat3(const mat2& m2) noexcept;
        mat3(const vec3& c0,  const vec3& c1, const vec3& c2) noexcept;

        vec3& operator[](unsigned pos) noexcept;
        const vec3& operator[](unsigned pos) const noexcept;

        explicit operator mat2() const noexcept;

    //private:
        vec3 _columns[3];
    };

    mat3 operator +(const mat3& first, const mat3& second) noexcept;
    mat3 operator -(const mat3& first, const mat3& second) noexcept;
    mat3 operator -(const mat3& first) noexcept;
    mat3 operator *(const mat3& first, const mat3& second) noexcept;

    mat3 operator *(const mat3& mat, float scalar) noexcept;
    mat3 operator /(const mat3& mat, float scalar) noexcept;

    mat3 operator *(float scalar, const mat3& mat) noexcept;
    mat3 operator /(float scalar, const mat3& mat) noexcept;

}
