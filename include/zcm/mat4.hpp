#pragma once

#include <zcm/vec4.hpp>

namespace zcm
{
    struct mat3;

    struct mat4
    {
        mat4() noexcept;
        explicit mat4(float value) noexcept;
        explicit mat4(const mat3& m) noexcept;

        mat4(const vec4& c0,  const vec4& c1, const vec4& c2, const vec4& c3) noexcept;

        vec4& operator[](unsigned pos) noexcept;
        const vec4& operator[](unsigned pos) const noexcept;

        explicit operator mat3() const noexcept;

    //private:
        vec4 _columns[4];
    };

    mat4 operator +(const mat4& first, const mat4& second) noexcept;
    mat4 operator -(const mat4& first, const mat4& second) noexcept;
    mat4 operator -(const mat4& first) noexcept;
    mat4 operator *(const mat4& first, const mat4& second) noexcept;

    mat4 operator *(const mat4& mat, float scalar) noexcept;
    mat4 operator /(const mat4& mat, float scalar) noexcept;

    mat4 operator *(float scalar, const mat4& mat) noexcept;
    mat4 operator /(float scalar, const mat4& mat) noexcept;

}
