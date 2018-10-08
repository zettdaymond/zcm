#include "mat4.h"

zcm::mat4 zcm::operator +(const zcm::mat4& first, const zcm::mat4& second)
{
    return { first[0] + second[0],
             first[1] + second[1],
             first[2] + second[2],
             first[3] + second[3] };
}

zcm::mat4 zcm::operator -(const zcm::mat4& first, const zcm::mat4& second)
{
    return { first[0] - second[0],
             first[1] - second[1],
             first[2] - second[2],
             first[3] - second[3] };
}

zcm::mat4 zcm::operator -(const zcm::mat4& first)
{
    return { -first[0],
             -first[1],
             -first[2],
             -first[3] };
}

zcm::mat4 zcm::operator *(const zcm::mat4& m1, const zcm::mat4& m2)
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

zcm::mat4 zcm::operator *(const zcm::mat4& mat, const float scalar)
{
    return { mat[0] * scalar,
             mat[1] * scalar,
             mat[2] * scalar,
             mat[3] * scalar };
}

zcm::mat4 zcm::operator /(const zcm::mat4& mat, const float scalar)
{
    return { mat[0] / scalar,
             mat[1] / scalar,
             mat[2] / scalar,
             mat[3] / scalar };
}

zcm::mat4 zcm::operator *(const float scalar, const zcm::mat4& mat)
{
    return { scalar * mat[0],
             scalar * mat[1],
             scalar * mat[2],
             scalar * mat[3] };
}

zcm::mat4 zcm::operator /(const float scalar, const zcm::mat4& mat)
{
    return { scalar / mat[0],
             scalar / mat[1],
             scalar / mat[2],
             scalar / mat[3] };
}

zcm::vec4&zcm::mat4::operator[](const uint8_t pos)
{
    assert(pos < 4);
    if(pos == 0) {
        return col0;
    }
    else if (pos == 1) {
        return col1;
    }
    else if (pos == 2){
        return col2;
    }
    else {
        return col3;
    }
}

const zcm::vec4&zcm::mat4::operator[](const uint8_t pos) const
{
    assert(pos < 4);
    if(pos == 0) {
        return col0;
    }
    else if (pos == 1) {
        return col1;
    }
    else if (pos == 2){
        return col2;
    }
    else {
        return col3;
    }
}
