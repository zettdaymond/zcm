#pragma once

#include <zcm/vec2.hpp>

namespace zcm
{
    struct vec2;
    struct mat2
    {
        mat2  () noexcept;
        explicit mat2(no_init_t) noexcept;
        explicit mat2(float value) noexcept;

        mat2  (float a00, float a01, float a10, float a11) noexcept;
        mat2  (vec2 col0, vec2 col1) noexcept;

        vec2& operator[] (unsigned pos) noexcept;
        vec2  operator[] (unsigned pos) const noexcept;

        void  operator+= (const mat2& first) noexcept;
        void  operator-= (const mat2& first) noexcept;
        void  operator*= (const mat2& first) noexcept;
        void  operator/= (const mat2& first) noexcept;

    //private:
        vec2 _columns[2];
    };


    mat2  operator - (const mat2& first) noexcept;
    mat2  operator + (const mat2& first) noexcept;

    bool  operator == (const mat2& first, const mat2& second) noexcept;
    bool  operator != (const mat2& first, const mat2& second) noexcept;

    mat2  operator + (const mat2& first, const mat2& second) noexcept;
    mat2  operator - (const mat2& first, const mat2& second) noexcept;
    mat2  operator * (const mat2& first, const mat2& second) noexcept;
    mat2  operator / (const mat2& first, const mat2& second) noexcept;

    mat2  operator * (const mat2& mat, float scalar) noexcept;
    mat2  operator / (const mat2& mat, float scalar) noexcept;

    vec2  operator * (const mat2& mat, const vec2& vec) noexcept;
    vec2  operator * (const vec2& vec, const mat2& mat) noexcept;
    vec2  operator / (const mat2& mat, const vec2& vec) noexcept;
    vec2  operator / (const vec2& vec, const mat2& mat) noexcept;

    mat2  operator * (float scalar, const mat2& mat) noexcept;
    mat2  operator / (float scalar, const mat2& mat) noexcept;

}
