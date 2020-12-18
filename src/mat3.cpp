#include <cassert>
#include <type_traits>
#include <zcm/mat3.hpp>
#include <zcm/mat2.hpp>
#include <zcm/matrix.hpp>


static_assert (std::is_standard_layout<zcm::mat3>::value, "");

zcm::mat3::mat3() noexcept : mat3(1.0f)
{}

zcm::mat3::mat3(zcm::no_init_t) noexcept
{}

zcm::mat3::mat3(float value) noexcept
{
    _columns[0] = vec3(value, 0.0f, 0.0f);
    _columns[1] = vec3(0.0f, value, 0.0f);
    _columns[2] = vec3(0.0f, 0.0f, value);
}

zcm::mat3::mat3(const zcm::mat2 &m2) noexcept
{
    _columns[0] = vec3(m2[0].x, m2[0].y, 0.0f);
    _columns[1] = vec3(m2[1].x, m2[1].y, 0.0f);
    _columns[2] = vec3(m2[2].x, m2[2].y, 1.0f);
}

zcm::mat3::operator zcm::mat2() const noexcept
{
    return mat2{_columns[0].x, _columns[0].y, _columns[1].x, _columns[1].y};
}


zcm::mat3::mat3(const vec3& c0,  const vec3& c1, const vec3& c2) noexcept
{
    _columns[0] = c0;
    _columns[1] = c1;
    _columns[2] = c2;
}

zcm::mat3::mat3(float c00, float c01, float c02, float c10, float c11, float c12, float c20, float c21, float c22) noexcept
{
    _columns[0] = {c00, c01, c02};
    _columns[1] = {c10, c11, c12};
    _columns[2] = {c20, c21, c22};
}

zcm::mat3 zcm::operator +(const zcm::mat3& first, const zcm::mat3& second) noexcept
{
    return { first[0] + second[0],
             first[1] + second[1],
             first[2] + second[2] };
}

zcm::mat3 zcm::operator -(const zcm::mat3& first, const zcm::mat3& second) noexcept
{
    return { first[0] - second[0],
             first[1] - second[1],
             first[2] - second[2] };
}

zcm::mat3 zcm::operator -(const zcm::mat3& first) noexcept
{
    return { - first[0],
             - first[1],
             - first[2] };
}

zcm::mat3 zcm::operator +(const zcm::mat3 &first) noexcept
{
    return first;
}


//zcm::mat3 zcm::operator *(const zcm::mat3& first, const zcm::mat3& second)
//{
//    auto a00 = first[0].x * second[0].x + first[1].x * second[0].y + first[2].x * second[0].z;
//    auto a01 = first[0].x * second[1].x + first[1].x * second[1].y + first[2].x * second[1].z;
//    auto a02 = first[0].x * second[2].x + first[1].x * second[2].y + first[2].x * second[2].z;

//    auto a10 = first[0].y * second[0].x + first[1].y * second[0].y + first[2].y * second[0].z;
//    auto a11 = first[0].y * second[1].x + first[1].y * second[1].y + first[2].y * second[1].z;
//    auto a12 = first[0].y * second[2].x + first[1].y * second[2].y + first[2].y * second[2].z;

//    auto a20 = first[0].z * second[0].x + first[1].z * second[0].y + first[2].z * second[0].z;
//    auto a21 = first[0].z * second[1].x + first[1].z * second[1].y + first[2].z * second[1].z;
//    auto a22 = first[0].z * second[2].x + first[1].z * second[2].y + first[2].z * second[2].z;

//    return mat3{ vec3{a00, a10, a20}, vec3{a01, a11, a21}, vec3{a02, a12, a22}};
//}

zcm::mat3 zcm::operator *(const zcm::mat3& m1, const zcm::mat3& m2) noexcept
{
    auto const SrcA00 = m1[0][0];
    auto const SrcA01 = m1[0][1];
    auto const SrcA02 = m1[0][2];
    auto const SrcA10 = m1[1][0];
    auto const SrcA11 = m1[1][1];
    auto const SrcA12 = m1[1][2];
    auto const SrcA20 = m1[2][0];
    auto const SrcA21 = m1[2][1];
    auto const SrcA22 = m1[2][2];

    auto const SrcB00 = m2[0][0];
    auto const SrcB01 = m2[0][1];
    auto const SrcB02 = m2[0][2];
    auto const SrcB10 = m2[1][0];
    auto const SrcB11 = m2[1][1];
    auto const SrcB12 = m2[1][2];
    auto const SrcB20 = m2[2][0];
    auto const SrcB21 = m2[2][1];
    auto const SrcB22 = m2[2][2];

    mat3 Result;
    Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02;
    Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02;
    Result[0][2] = SrcA02 * SrcB00 + SrcA12 * SrcB01 + SrcA22 * SrcB02;
    Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12;
    Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12;
    Result[1][2] = SrcA02 * SrcB10 + SrcA12 * SrcB11 + SrcA22 * SrcB12;
    Result[2][0] = SrcA00 * SrcB20 + SrcA10 * SrcB21 + SrcA20 * SrcB22;
    Result[2][1] = SrcA01 * SrcB20 + SrcA11 * SrcB21 + SrcA21 * SrcB22;
    Result[2][2] = SrcA02 * SrcB20 + SrcA12 * SrcB21 + SrcA22 * SrcB22;
    return Result;
}

zcm::mat3 zcm::operator /(const zcm::mat3 &first, const zcm::mat3 &second) noexcept
{
    return first * inverse(second);
}

zcm::mat3 zcm::operator *(const zcm::mat3& mat, float scalar) noexcept
{
    return { mat[0] * scalar,
             mat[1] * scalar,
             mat[2] * scalar };
}

zcm::mat3 zcm::operator /(const zcm::mat3& mat, float scalar) noexcept
{
    return { mat[0] / scalar,
             mat[1] / scalar,
             mat[2] / scalar };
}

zcm::mat3 zcm::operator *(float scalar, const mat3 &mat) noexcept
{
    return { scalar * mat[0],
             scalar * mat[1],
             scalar * mat[2] };
}

zcm::mat3 zcm::operator /(float scalar, const mat3 &mat) noexcept
{
    return { scalar / mat[0],
             scalar / mat[1],
             scalar / mat[2] };
}

zcm::vec3& zcm::mat3::operator[](unsigned pos) noexcept
{
    assert(pos < 3);
    return _columns[pos];
}

const zcm::vec3& zcm::mat3::operator[](unsigned pos) const noexcept
{
    assert(pos < 3);
    return _columns[pos];
}

void zcm::mat3::operator+=(const zcm::mat3 &first) noexcept
{
    *this = *this + first;
}

void zcm::mat3::operator-=(const zcm::mat3 &first) noexcept
{
    *this = *this - first;
}

void zcm::mat3::operator*=(const zcm::mat3 &first) noexcept
{
    *this = *this * first;
}

void zcm::mat3::operator/=(const zcm::mat3 &first) noexcept
{
    *this = *this / first;
}

zcm::vec3 zcm::operator *(const zcm::mat3 &m, const zcm::vec3 &v) noexcept
{
    return { m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z,
             m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z,
             m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z };
}

zcm::vec3 zcm::operator *(const zcm::vec3 &v, const zcm::mat3 &m) noexcept
{
    return { m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
             m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
             m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z };
}

zcm::vec3 zcm::operator /(const zcm::mat3 &mat, const zcm::vec3 &vec) noexcept
{
    return inverse(mat) * vec;
}

zcm::vec3 zcm::operator /(const zcm::vec3 &vec, const zcm::mat3 &mat) noexcept
{
    return vec * inverse(mat);
}

bool zcm::operator ==(const zcm::mat3 &first, const zcm::mat3 &second) noexcept
{
    return first[0] == second[0] && first[1] == second[1] && first[2] == second[2];
}

bool zcm::operator !=(const zcm::mat3 &first, const zcm::mat3 &second) noexcept
{
    return !(first == second);
}

zcm::mat3 zcm::make_mat3(const float * ptr) noexcept
{
    assert(ptr);
    return zcm::mat3{
        ptr[0], ptr[1], ptr[2],
        ptr[3], ptr[4], ptr[5],
        ptr[6], ptr[7], ptr[8]
    };
}
