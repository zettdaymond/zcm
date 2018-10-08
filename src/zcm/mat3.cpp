#include "mat3.h"

zcm::mat3 zcm::operator +(const zcm::mat3& first, const zcm::mat3& second)
{
    return { first.col0 + second.col0,
             first.col1 + second.col1,
             first.col2 + second.col2 };
}

zcm::mat3 zcm::operator -(const zcm::mat3& first, const zcm::mat3& second)
{
    return { first.col0 - second.col0,
             first.col1 - second.col1,
             first.col2 - second.col2 };
}

zcm::mat3 zcm::operator -(const zcm::mat3& first)
{
    return { - first.col0,
             - first.col1,
             - first.col2 };
}

//zcm::mat3 zcm::operator *(const zcm::mat3& first, const zcm::mat3& second)
//{
//    auto a00 = first.col0.x * second.col0.x + first.col1.x * second.col0.y + first.col2.x * second.col0.z;
//    auto a01 = first.col0.x * second.col1.x + first.col1.x * second.col1.y + first.col2.x * second.col1.z;
//    auto a02 = first.col0.x * second.col2.x + first.col1.x * second.col2.y + first.col2.x * second.col2.z;

//    auto a10 = first.col0.y * second.col0.x + first.col1.y * second.col0.y + first.col2.y * second.col0.z;
//    auto a11 = first.col0.y * second.col1.x + first.col1.y * second.col1.y + first.col2.y * second.col1.z;
//    auto a12 = first.col0.y * second.col2.x + first.col1.y * second.col2.y + first.col2.y * second.col2.z;

//    auto a20 = first.col0.z * second.col0.x + first.col1.z * second.col0.y + first.col2.z * second.col0.z;
//    auto a21 = first.col0.z * second.col1.x + first.col1.z * second.col1.y + first.col2.z * second.col1.z;
//    auto a22 = first.col0.z * second.col2.x + first.col1.z * second.col2.y + first.col2.z * second.col2.z;

//    return mat3{ vec3{a00, a10, a20}, vec3{a01, a11, a21}, vec3{a02, a12, a22}};
//}

zcm::mat3 zcm::operator *(const zcm::mat3& m1, const zcm::mat3& m2)
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


zcm::mat3 zcm::operator *(const zcm::mat3& mat, const float scalar)
{
    return { mat.col0 * scalar,
             mat.col1 * scalar,
             mat.col2 * scalar };
}

zcm::mat3 zcm::operator /(const zcm::mat3& mat, const float scalar)
{
    return { mat.col0 / scalar,
             mat.col1 / scalar,
             mat.col2 / scalar };
}

zcm::mat3 zcm::operator *(const float scalar, const zcm::mat3& mat)
{
    return { scalar * mat.col0,
             scalar * mat.col1,
             scalar * mat.col2 };
}

zcm::mat3 zcm::operator /(const float scalar, const zcm::mat3& mat)
{
    return { scalar / mat.col0,
             scalar / mat.col1,
             scalar / mat.col2 };
}

zcm::vec3&zcm::mat3::operator[](const uint8_t pos)
{
    assert(pos < 3);
    if(pos == 0) {
        return col0;
    }
    else if (pos == 1) {
        return col1;
    }
    else {
        return col2;
    }
}

const zcm::vec3&zcm::mat3::operator[](const uint8_t pos) const
{
    assert(pos < 3);
    if(pos == 0) {
        return col0;
    }
    else if (pos == 1) {
        return col1;
    }
    else {
        return col2;
    }
}
