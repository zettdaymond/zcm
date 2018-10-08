#include "mat2.h"
#include "cassert"


zcm::vec2&zcm::mat2::operator[](const uint8_t pos)
{
    assert(pos < 2);
    if(pos == 0) {
        return col0;
    }
    else {
        return col1;
    }
}

const zcm::vec2&zcm::mat2::operator[](const uint8_t pos) const
{
    assert(pos < 2);
    if(pos == 0) {
        return col0;
    }
    else {
        return col1;
    }
}

zcm::mat2 zcm::operator +(const zcm::mat2& first, const zcm::mat2& second)
{
    return { first[0] + second[0],
             first[1] + second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first, const zcm::mat2& second)
{
    return { first[0] - second[0],
             first[1] - second[1] };
}

zcm::mat2 zcm::operator -(const zcm::mat2& first)
{
    return { -first[0],
             -first[1] };
}

zcm::mat2 zcm::operator *(const zcm::mat2& m1, const zcm::mat2& m2)
{
    return mat2(
        m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1],
        m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1],
        m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1],
        m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1]);
}

zcm::mat2 zcm::operator *(const zcm::mat2& mat, const float scalar)
{
    return { mat[0] * scalar,
             mat[1] * scalar };
}

zcm::mat2 zcm::operator /(const zcm::mat2& mat, const float scalar)
{
    return { mat[0] / scalar,
             mat[1] / scalar };
}

zcm::mat2 zcm::operator *(const float scalar, const zcm::mat2& mat)
{
    return { scalar * mat[0],
             scalar * mat[1] };
}

zcm::mat2 zcm::operator /(const float scalar, const zcm::mat2& mat)
{
    return { scalar / mat[0],
             scalar / mat[1] };
}
