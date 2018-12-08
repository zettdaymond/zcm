#pragma once

namespace zcm {

    class mat2;
    class mat3;
    class mat4;


    mat2 matrixCompMult(const mat2& x, const mat2& y);
    mat3 matrixCompMult(const mat3& x, const mat3& y);
    mat4 matrixCompMult(const mat4& x, const mat4& y);

    mat2 transpose(const mat2& m);
    mat3 transpose(const mat3& m);
    mat4 transpose(const mat4& m);

    float determinant(const mat2& m);
    float determinant(const mat3& m);
    float determinant(const mat4& m);

    mat2 inverse(const mat2& m);
    mat3 inverse(const mat3& m);
    mat4 inverse(const mat4& m);

    mat2 inverseTranspose(const mat2& m);
    mat3 inverseTranspose(const mat3& m);
    mat4 inverseTranspose(const mat4& m);
}
