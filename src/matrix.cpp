#include <zcm/matrix.hpp>
#include <zcm/mat2.hpp>
#include <zcm/mat3.hpp>
#include <zcm/mat4.hpp>

zcm::mat2 zcm::matrixCompMult(const zcm::mat2& x, const zcm::mat2& y) noexcept
{
    return { x[0] * y[0], x[1] * y[1] };
}


zcm::mat3 zcm::matrixCompMult(const zcm::mat3& x, const zcm::mat3& y) noexcept
{
    return { x[0] * y[0], x[1] * y[1], x[2] * y[2] };
}

zcm::mat4 zcm::matrixCompMult(const zcm::mat4& x, const zcm::mat4& y) noexcept
{
    return { x[0] * y[0], x[1] * y[1], x[2] * y[2], x[3] * y[3] };
}

zcm::mat2 zcm::transpose(const zcm::mat2& m) noexcept
{
    mat2 result(zcm::no_init_t{});

    result[0][0] = m[0][0];
    result[0][1] = m[1][0];
    result[1][0] = m[0][1];
    result[1][1] = m[1][1];

    return result;
}

zcm::mat3 zcm::transpose(const zcm::mat3& m) noexcept
{
    mat3 result(zcm::no_init_t{});

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

zcm::mat4 zcm::transpose(const zcm::mat4& m) noexcept
{
    mat4 result(zcm::no_init_t{});

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

float zcm::determinant(const zcm::mat2& m) noexcept
{
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

float zcm::determinant(const zcm::mat3& m) noexcept
{
    return
            + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
            - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
            + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

float zcm::determinant(const zcm::mat4& m) noexcept
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

zcm::mat2 zcm::inverse(const zcm::mat2& m) noexcept
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

zcm::mat3 zcm::inverse(const zcm::mat3& m) noexcept
{
    auto oneOverDeterminant = 1.0f / (
                                  + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
                                  - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
                                  + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]));

    mat3 inverse(zcm::no_init_t{});
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

zcm::mat4 zcm::inverse(const zcm::mat4& m) noexcept
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


zcm::mat2 zcm::adjugate(const zcm::mat2& m) noexcept
{
    mat2 Adjugate(+ m[1][1],
                  - m[0][1],
                  - m[1][0],
                  + m[0][0]);

    return Adjugate;
}


zcm::mat3 zcm::adjugate(const zcm::mat3& m) noexcept
{
    mat3 Adjugate(zcm::no_init_t{});
    Adjugate[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
    Adjugate[1][0] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]);
    Adjugate[2][0] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
    Adjugate[0][1] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]);
    Adjugate[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]);
    Adjugate[2][1] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]);
    Adjugate[0][2] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    Adjugate[1][2] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]);
    Adjugate[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]);

    return Adjugate;
}

zcm::mat4 zcm::adjugate(const zcm::mat4& m) noexcept
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

    return inverse;
}

zcm::mat2 zcm::inverseTranspose(const zcm::mat2 &m) noexcept
{
    auto Determinant = m[0][0] * m[1][1] - m[1][0] * m[0][1];

    mat2 Inverse(
        + m[1][1] / Determinant,
        - m[0][1] / Determinant,
        - m[1][0] / Determinant,
        + m[0][0] / Determinant);

    return Inverse;
}

zcm::mat3 zcm::inverseTranspose(const zcm::mat3 &m) noexcept
{
    auto Determinant =
            + m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
            + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

    mat3 Inverse{zcm::no_init_t{}};
    Inverse[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
    Inverse[0][1] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]);
    Inverse[0][2] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
    Inverse[1][0] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]);
    Inverse[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]);
    Inverse[1][2] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]);
    Inverse[2][0] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    Inverse[2][1] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]);
    Inverse[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
    return Inverse / Determinant;
}

zcm::mat4 zcm::inverseTranspose(const zcm::mat4 &m) noexcept
{
    auto SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    auto SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    auto SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    auto SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    auto SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    auto SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    auto SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    auto SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    auto SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    auto SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    auto SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    auto SubFactor11 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    auto SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    auto SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
    auto SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
    auto SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
    auto SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
    auto SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
    auto SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    mat4 Inverse;
    Inverse[0][0] = + (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02);
    Inverse[0][1] = - (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04);
    Inverse[0][2] = + (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05);
    Inverse[0][3] = - (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05);

    Inverse[1][0] = - (m[0][1] * SubFactor00 - m[0][2] * SubFactor01 + m[0][3] * SubFactor02);
    Inverse[1][1] = + (m[0][0] * SubFactor00 - m[0][2] * SubFactor03 + m[0][3] * SubFactor04);
    Inverse[1][2] = - (m[0][0] * SubFactor01 - m[0][1] * SubFactor03 + m[0][3] * SubFactor05);
    Inverse[1][3] = + (m[0][0] * SubFactor02 - m[0][1] * SubFactor04 + m[0][2] * SubFactor05);

    Inverse[2][0] = + (m[0][1] * SubFactor06 - m[0][2] * SubFactor07 + m[0][3] * SubFactor08);
    Inverse[2][1] = - (m[0][0] * SubFactor06 - m[0][2] * SubFactor09 + m[0][3] * SubFactor10);
    Inverse[2][2] = + (m[0][0] * SubFactor11 - m[0][1] * SubFactor09 + m[0][3] * SubFactor12);
    Inverse[2][3] = - (m[0][0] * SubFactor08 - m[0][1] * SubFactor10 + m[0][2] * SubFactor12);

    Inverse[3][0] = - (m[0][1] * SubFactor13 - m[0][2] * SubFactor14 + m[0][3] * SubFactor15);
    Inverse[3][1] = + (m[0][0] * SubFactor13 - m[0][2] * SubFactor16 + m[0][3] * SubFactor17);
    Inverse[3][2] = - (m[0][0] * SubFactor14 - m[0][1] * SubFactor16 + m[0][3] * SubFactor18);
    Inverse[3][3] = + (m[0][0] * SubFactor15 - m[0][1] * SubFactor17 + m[0][2] * SubFactor18);

    auto Determinant =
            + m[0][0] * Inverse[0][0]
            + m[0][1] * Inverse[0][1]
            + m[0][2] * Inverse[0][2]
            + m[0][3] * Inverse[0][3];

    return Inverse / Determinant;
}

zcm::mat2 zcm::adjugateTranspose(const mat2 &m) noexcept
{
    mat2 Adjugate(+ m[1][1],
                  - m[0][1],
                  - m[1][0],
                  + m[0][0]);

    return Adjugate;
}

zcm::mat3 zcm::adjugateTranspose(const mat3 &m) noexcept
{
    mat3 Adjugate{zcm::no_init_t{}};
    Adjugate[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
    Adjugate[0][1] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]);
    Adjugate[0][2] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
    Adjugate[1][0] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]);
    Adjugate[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]);
    Adjugate[1][2] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]);
    Adjugate[2][0] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    Adjugate[2][1] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]);
    Adjugate[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
    return Adjugate;
}

zcm::mat4 zcm::adjugateTranspose(const mat4 &m) noexcept
{
    auto SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    auto SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    auto SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    auto SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    auto SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    auto SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    auto SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    auto SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    auto SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    auto SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    auto SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    auto SubFactor11 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    auto SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    auto SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];
    auto SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];
    auto SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];
    auto SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];
    auto SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];
    auto SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    mat4 Adjugate{zcm::no_init_t{}};
    Adjugate[0][0] = + (m[1][1] * SubFactor00 - m[1][2] * SubFactor01 + m[1][3] * SubFactor02);
    Adjugate[0][1] = - (m[1][0] * SubFactor00 - m[1][2] * SubFactor03 + m[1][3] * SubFactor04);
    Adjugate[0][2] = + (m[1][0] * SubFactor01 - m[1][1] * SubFactor03 + m[1][3] * SubFactor05);
    Adjugate[0][3] = - (m[1][0] * SubFactor02 - m[1][1] * SubFactor04 + m[1][2] * SubFactor05);

    Adjugate[1][0] = - (m[0][1] * SubFactor00 - m[0][2] * SubFactor01 + m[0][3] * SubFactor02);
    Adjugate[1][1] = + (m[0][0] * SubFactor00 - m[0][2] * SubFactor03 + m[0][3] * SubFactor04);
    Adjugate[1][2] = - (m[0][0] * SubFactor01 - m[0][1] * SubFactor03 + m[0][3] * SubFactor05);
    Adjugate[1][3] = + (m[0][0] * SubFactor02 - m[0][1] * SubFactor04 + m[0][2] * SubFactor05);

    Adjugate[2][0] = + (m[0][1] * SubFactor06 - m[0][2] * SubFactor07 + m[0][3] * SubFactor08);
    Adjugate[2][1] = - (m[0][0] * SubFactor06 - m[0][2] * SubFactor09 + m[0][3] * SubFactor10);
    Adjugate[2][2] = + (m[0][0] * SubFactor11 - m[0][1] * SubFactor09 + m[0][3] * SubFactor12);
    Adjugate[2][3] = - (m[0][0] * SubFactor08 - m[0][1] * SubFactor10 + m[0][2] * SubFactor12);

    Adjugate[3][0] = - (m[0][1] * SubFactor13 - m[0][2] * SubFactor14 + m[0][3] * SubFactor15);
    Adjugate[3][1] = + (m[0][0] * SubFactor13 - m[0][2] * SubFactor16 + m[0][3] * SubFactor17);
    Adjugate[3][2] = - (m[0][0] * SubFactor14 - m[0][1] * SubFactor16 + m[0][3] * SubFactor18);
    Adjugate[3][3] = + (m[0][0] * SubFactor15 - m[0][1] * SubFactor17 + m[0][2] * SubFactor18);

    return Adjugate;
}
