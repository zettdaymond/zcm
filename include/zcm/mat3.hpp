#pragma once

#include <zcm/vec3.hpp>

namespace zcm
{

    struct mat2;
    struct mat3
    {
        mat3 () noexcept;
        explicit mat3 (no_init_t) noexcept;
        explicit mat3 (float value) noexcept;
        explicit mat3 (const mat2& m2) noexcept;
        mat3 (const vec3& c0,  const vec3& c1, const vec3& c2) noexcept;
        mat3 (float c00, float c01, float c02,
              float c10, float c11, float c12,
              float c20, float c21, float c22) noexcept;

        vec3&       operator[] (unsigned pos) noexcept;
        const vec3& operator[] (unsigned pos) const noexcept;

        void  operator+= (const mat3& first) noexcept;
        void  operator-= (const mat3& first) noexcept;
        void  operator*= (const mat3& first) noexcept;
        void  operator/= (const mat3& first) noexcept;

        explicit operator mat2() const noexcept;

    //private:
        vec3 _columns[3];
    };

    mat3  operator - (const mat3& first) noexcept;
    mat3  operator + (const mat3& first) noexcept;

    bool  operator == (const mat3& first, const mat3& second) noexcept;
    bool  operator != (const mat3& first, const mat3& second) noexcept;

    mat3  operator + (const mat3& first, const mat3& second) noexcept;
    mat3  operator - (const mat3& first, const mat3& second) noexcept;
    mat3  operator * (const mat3& first, const mat3& second) noexcept;
    mat3  operator / (const mat3& first, const mat3& second) noexcept;

    mat3  operator * (const mat3& mat, float scalar) noexcept;
    mat3  operator / (const mat3& mat, float scalar) noexcept;

    mat3  operator * (float scalar, const mat3& mat) noexcept;
    mat3  operator / (float scalar, const mat3& mat) noexcept;

    vec3  operator * (const mat3& mat, const vec3& vec) noexcept;
    vec3  operator * (const vec3& vec, const mat3& mat) noexcept;
    vec3  operator / (const mat3& mat, const vec3& vec) noexcept;
    vec3  operator / (const vec3& vec, const mat3& mat) noexcept;

}
