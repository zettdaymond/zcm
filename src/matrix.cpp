#include <zcm/matrix.hpp>
#include <zcm/mat2.hpp>
#include <zcm/mat3.hpp>
#include <zcm/mat4.hpp>

zcm::mat2 zcm::matrixCompMult(const zcm::mat2& x, const zcm::mat2& y)
{
    return { x[0] * y[0], x[1] * y[1] };
}


zcm::mat3 zcm::matrixCompMult(const zcm::mat3& x, const zcm::mat3& y)
{
    return { x[0] * y[0], x[1] * y[1], x[2] * y[2] };
}

zcm::mat4 zcm::matrixCompMult(const zcm::mat4& x, const zcm::mat4& y)
{
    return { x[0] * y[0], x[1] * y[1], x[2] * y[2], x[3] * y[3] };
}

zcm::mat2 zcm::transpose(const zcm::mat2& m)
{
    mat2 result(0.0f);

    result[0][0] = m[0][0];
    result[0][1] = m[1][0];
    result[1][0] = m[0][1];
    result[1][1] = m[1][1];

    return result;
}

zcm::mat3 zcm::transpose(const zcm::mat3& m)
{
    mat3 result(0.0);

    result[0][0] = m[0][0];
    result[0][1] = m[1][0];
    result[0][2] = m[2][0];

    result[1][0] = m[0][1];
    result[1][1] = m[1][1];
    result[1][2] = m[2][1];

    result[2][0] = m[0][2];
    result[2][1] = m[1][2];
    result[2][2] = m[2][2];

    return result;
}

zcm::mat4 zcm::transpose(const zcm::mat4& m)
{
    mat4 result(0.0);

    result[0][0] = m[0][0];
    result[0][1] = m[1][0];
    result[0][2] = m[2][0];
    result[0][3] = m[3][0];

    result[1][0] = m[0][1];
    result[1][1] = m[1][1];
    result[1][2] = m[2][1];
    result[1][3] = m[3][1];

    result[2][0] = m[0][2];
    result[2][1] = m[1][2];
    result[2][2] = m[2][2];
    result[2][3] = m[3][2];

    result[3][0] = m[0][3];
    result[3][1] = m[1][3];
    result[3][2] = m[2][3];
    result[3][3] = m[3][3];

    return result;
}

float zcm::determinant(const zcm::mat2& m)
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

float zcm::determinant(const zcm::mat3& m)
{
    return
            + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
            - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
            + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

float zcm::determinant(const zcm::mat4& m)
{
    auto SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    auto SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    auto SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    auto SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    auto SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    auto SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

    vec4 DetCof(
            + (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02),
            - (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04),
            + (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05),
            - (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05));


    return  m[0][0] * DetCof[0] + m[0][1] * DetCof[1] +
            m[0][2] * DetCof[2] + m[0][3] * DetCof[3];
}

zcm::mat2 zcm::inverse(const zcm::mat2& m)
{
    float OneOverDeterminant = 1.0f / ( + m[0][0] * m[1][1]
                                        - m[1][0] * m[0][1]);

    mat2 inverse(
                + m[1][1] * OneOverDeterminant,
                - m[0][1] * OneOverDeterminant,
                - m[1][0] * OneOverDeterminant,
                + m[0][0] * OneOverDeterminant);

    return inverse;
}

zcm::mat3 zcm::inverse(const zcm::mat3& m)
{
    auto oneOverDeterminant = 1.0f / (
                                  + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
                                  - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
                                  + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]));

    mat3 inverse(0.0f);
    inverse[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * oneOverDeterminant;
    inverse[1][0] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]) * oneOverDeterminant;
    inverse[2][0] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * oneOverDeterminant;
    inverse[0][1] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]) * oneOverDeterminant;
    inverse[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]) * oneOverDeterminant;
    inverse[2][1] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]) * oneOverDeterminant;
    inverse[0][2] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]) * oneOverDeterminant;
    inverse[1][2] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]) * oneOverDeterminant;
    inverse[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * oneOverDeterminant;

    return inverse;
}

zcm::mat4 zcm::inverse(const zcm::mat4& m)
{
    auto Coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    auto Coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    auto Coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

    auto Coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    auto Coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    auto Coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

    auto Coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    auto Coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    auto Coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

    auto Coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    auto Coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    auto Coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

    auto Coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    auto Coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    auto Coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

    auto Coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    auto Coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    auto Coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    vec4 Fac0(Coef00, Coef00, Coef02, Coef03);
    vec4 Fac1(Coef04, Coef04, Coef06, Coef07);
    vec4 Fac2(Coef08, Coef08, Coef10, Coef11);
    vec4 Fac3(Coef12, Coef12, Coef14, Coef15);
    vec4 Fac4(Coef16, Coef16, Coef18, Coef19);
    vec4 Fac5(Coef20, Coef20, Coef22, Coef23);

    vec4 Vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
    vec4 Vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
    vec4 Vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
    vec4 Vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

    vec4 Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
    vec4 Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
    vec4 Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
    vec4 Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

    vec4 SignA(+1, -1, +1, -1);
    vec4 SignB(-1, +1, -1, +1);
    mat4 inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

    vec4 Row0(inverse[0][0], inverse[1][0], inverse[2][0], inverse[3][0]);

    vec4 Dot0(m[0] * Row0);
    auto Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

    auto oneOverDeterminant = 1.0f / Dot1;

    return inverse * oneOverDeterminant;
}
