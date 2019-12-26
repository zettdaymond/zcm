#pragma once

namespace zcm {

    struct mat2;
    struct mat3;
    struct mat4;


    mat2 matrixCompMult(const mat2& x, const mat2& y) noexcept;
    mat3 matrixCompMult(const mat3& x, const mat3& y) noexcept;
    mat4 matrixCompMult(const mat4& x, const mat4& y) noexcept;

    mat2 transpose(const mat2& m) noexcept;
    mat3 transpose(const mat3& m) noexcept;
    mat4 transpose(const mat4& m) noexcept;

    float determinant(const mat2& m) noexcept;
    float determinant(const mat3& m) noexcept;
    float determinant(const mat4& m) noexcept;

    mat2 inverse(const mat2& m) noexcept;
    mat3 inverse(const mat3& m) noexcept;
    mat4 inverse(const mat4& m) noexcept;

    mat2 inverseTranspose(const mat2& m) noexcept;
    mat3 inverseTranspose(const mat3& m) noexcept;
    mat4 inverseTranspose(const mat4& m) noexcept;
}
