#include <type_traits>
#include <cassert>
#include <zcm/mat4.hpp>
#include <zcm/mat3.hpp>
#include <zcm/matrix.hpp>


static_assert(std::is_standard_layout<zcm::mat4>::value, "");

zcm::mat4::mat4() noexcept : mat4(1.0f)
{}

zcm::mat4::mat4(zcm::no_init_t) noexcept
{}

zcm::mat4::mat4(float value) noexcept
{
    _columns[0] = vec4(value, 0.0f, 0.0f, 0.0f);
    _columns[1] = vec4(0.0f, value, 0.0f, 0.0f);
    _columns[2] = vec4(0.0f, 0.0f, value, 0.0f);
    _columns[3] = vec4(0.0f, 0.0f, 0.0f, value);
}

zcm::mat4::mat4(const vec4& c0,  const vec4& c1, const vec4& c2, const vec4& c3) noexcept
{
    _columns[0] = c0;
    _columns[1] = c1;
    _columns[2] = c2;
    _columns[3] = c3;
}

zcm::mat4::mat4(float c00, float c01, float c02, float c03,
                float c10, float c11, float c12, float c13,
                float c20, float c21, float c22, float c23,
                float c30, float c31, float c32, float c33) noexcept
{
    _columns[0] = { c00, c01, c02, c03 };
    _columns[1] = { c10, c11, c12, c13 };
    _columns[2] = { c20, c21, c22, c23 };
    _columns[3] = { c30, c31, c32, c33 };
}

zcm::mat4::mat4(const zcm::mat3 &m) noexcept
{
    _columns[0] = vec4(m[0], 0.0f);
    _columns[1] = vec4(m[1], 0.0f);
    _columns[2] = vec4(m[2], 0.0f);
    _columns[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

zcm::mat4::operator mat3() const noexcept
{
    return mat3{vec3{_columns[0].x, _columns[0].y, _columns[0].z},
                vec3{_columns[1].x, _columns[1].y, _columns[1].z},
                vec3{_columns[2].x, _columns[2].y, _columns[2].z}};
}


zcm::mat4 zcm::operator +(const zcm::mat4& first, const zcm::mat4& second) noexcept
{
    return { first[0] + second[0],
             first[1] + second[1],
             first[2] + second[2],
             first[3] + second[3] };
}

zcm::mat4 zcm::operator -(const zcm::mat4& first, const zcm::mat4& second) noexcept
{
    return { first[0] - second[0],
             first[1] - second[1],
             first[2] - second[2],
             first[3] - second[3] };
}

zcm::mat4 zcm::operator -(const zcm::mat4& first) noexcept
{
    return { -first[0],
             -first[1],
             -first[2],
             -first[3] };
}

zcm::mat4 zcm::operator +(const zcm::mat4 &first) noexcept
{
    return first;
}

zcm::mat4 zcm::operator *(const zcm::mat4& m1, const zcm::mat4& m2) noexcept
{
    vec4 const SrcA0 = m1[0];
    vec4 const SrcA1 = m1[1];
    vec4 const SrcA2 = m1[2];
    vec4 const SrcA3 = m1[3];

    vec4 const SrcB0 = m2[0];
    vec4 const SrcB1 = m2[1];
    vec4 const SrcB2 = m2[2];
    vec4 const SrcB3 = m2[3];

    mat4 Result;
    Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
    Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
    Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
    Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
    return Result;
}

zcm::mat4 zcm::operator /(const zcm::mat4 &first, const zcm::mat4 &second) noexcept
{
    return first * inverse(second);
}


zcm::mat4 zcm::operator *(const zcm::mat4& mat, float scalar) noexcept
{
    return { mat[0] * scalar,
             mat[1] * scalar,
             mat[2] * scalar,
             mat[3] * scalar };
}

zcm::mat4 zcm::operator /(const zcm::mat4& mat, float scalar) noexcept
{
    return { mat[0] / scalar,
             mat[1] / scalar,
             mat[2] / scalar,
             mat[3] / scalar };
}

zcm::mat4 zcm::operator *(float scalar, const zcm::mat4& mat) noexcept
{
    return { scalar * mat[0],
             scalar * mat[1],
             scalar * mat[2],
             scalar * mat[3] };
}

zcm::mat4 zcm::operator /(float scalar, const zcm::mat4& mat) noexcept
{
    return { scalar / mat[0],
             scalar / mat[1],
             scalar / mat[2],
             scalar / mat[3] };
}


void zcm::mat4::operator+=(const zcm::mat4 &first) noexcept
{
    *this = *this + first;
}

void zcm::mat4::operator-=(const zcm::mat4 &first) noexcept
{
    *this = *this - first;
}

void zcm::mat4::operator*=(const zcm::mat4 &first) noexcept
{
    *this = *this * first;
}

void zcm::mat4::operator/=(const zcm::mat4 &first) noexcept
{
    *this = *this / first;
}

zcm::vec4& zcm::mat4::operator[](unsigned pos) noexcept
{
    assert(pos < 4);
    return _columns[pos];
}

const zcm::vec4& zcm::mat4::operator[](unsigned pos) const noexcept
{
    assert(pos < 4);
    return _columns[pos];
}

zcm::vec4 zcm::operator *(const zcm::mat4 &m, const zcm::vec4 &v) noexcept
{
    auto Mov0 {v[0]};
    auto Mov1 {v[1]};
    auto Mul0 = m[0] * Mov0;
    auto Mul1 = m[1] * Mov1;
    auto Add0 = Mul0 + Mul1;
    auto Mov2 {v[2]};
    auto Mov3 {v[3]};
    auto Mul2 = m[2] * Mov2;
    auto Mul3 = m[3] * Mov3;
    auto Add1 = Mul2 + Mul3;
    auto Add2 = Add0 + Add1;
    return Add2;
}

zcm::vec4 zcm::operator *(const zcm::vec4 &v, const zcm::mat4 &m) noexcept
{
    return { m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
             m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
             m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
             m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3] };
}

zcm::vec4 zcm::operator /(const zcm::mat4 &mat, const zcm::vec4 &vec) noexcept
{
    return inverse(mat) * vec;
}

zcm::vec4 zcm::operator /(const zcm::vec4 &vec, const zcm::mat4 &mat) noexcept
{
    return vec * inverse(mat);
}

bool zcm::operator ==(const zcm::mat4 &first, const zcm::mat4 &second) noexcept
{
    return first[0] == second[0] && first[1] == second[1] && first[2] == second[2] && first[3] == second[3];
}

bool zcm::operator !=(const zcm::mat4 &first, const zcm::mat4 &second) noexcept
{
    return !(first == second);
}
