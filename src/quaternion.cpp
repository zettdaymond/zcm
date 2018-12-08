#include <cassert>
#include <limits>
#include <zcm/quaternion.hpp>
#include <zcm/common.hpp>
#include <zcm/exponential.hpp>
#include <zcm/geometric.hpp>
#include <zcm/angle_and_trigonometry.hpp>
#include <zcm/mat3.hpp>
#include <zcm/mat4.hpp>
#include <zcm/quat.hpp>

zcm::vec3 zcm::eulerAngles(const zcm::quat &x)
{
    return vec3(pitch(x), yaw(x), roll(x));
}

float zcm::pitch(const zcm::quat &q)
{
    const float y = 2.0f * (q.y * q.z + q.w * q.x);
    const float x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

    if(x == 0.0f && y == 0.0f) //avoid atan2(0,0) - handle singularity - Matiis
        return 2.0f * atan(q.x, q.w);

    return atan(y, x);
}

float zcm::yaw(const zcm::quat &q)
{
    return asin(clamp(-2.0f * (q.x * q.z - q.w * q.y), -1.0f, 1.0f));
}

float zcm::roll(const zcm::quat &q)
{
    return atan(2.0f * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z);
}

zcm::mat3 zcm::mat3_cast(const zcm::quat &q)
{
    mat3 Result(1.0f);
    auto qxx(q.x * q.x);
    auto qyy(q.y * q.y);
    auto qzz(q.z * q.z);
    auto qxz(q.x * q.z);
    auto qxy(q.x * q.y);
    auto qyz(q.y * q.z);
    auto qwx(q.w * q.x);
    auto qwy(q.w * q.y);
    auto qwz(q.w * q.z);

    Result[0][0] = 1.0f - 2.0f * (qyy +  qzz);
    Result[0][1] = 2.0f * (qxy + qwz);
    Result[0][2] = 2.0f * (qxz - qwy);

    Result[1][0] = 2.0f * (qxy - qwz);
    Result[1][1] = 1.0f - 2.0f * (qxx +  qzz);
    Result[1][2] = 2.0f * (qyz + qwx);

    Result[2][0] = 2.0f * (qxz + qwy);
    Result[2][1] = 2.0f * (qyz - qwx);
    Result[2][2] = 1.0f - 2.0f * (qxx +  qyy);
    return Result;
}

zcm::mat4 zcm::mat4_cast(const zcm::quat &q)
{
    return mat4(mat3_cast(q));
}

zcm::quat zcm::quat_cast(const zcm::mat3 &m)
{
    auto fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
    auto fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
    auto fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
    auto fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

    int biggestIndex = 0;
    auto fourBiggestSquaredMinus1 = fourWSquaredMinus1;
    if(fourXSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourXSquaredMinus1;
        biggestIndex = 1;
    }
    if(fourYSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourYSquaredMinus1;
        biggestIndex = 2;
    }
    if(fourZSquaredMinus1 > fourBiggestSquaredMinus1)
    {
        fourBiggestSquaredMinus1 = fourZSquaredMinus1;
        biggestIndex = 3;
    }

    auto biggestVal = sqrt(fourBiggestSquaredMinus1 + 1.0f) * 0.5f;
    auto mult = 0.25f / biggestVal;

    switch(biggestIndex)
    {
    case 0:
        return quat(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
    case 1:
        return quat((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
    case 2:
        return quat((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
    case 3:
        return quat((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
    }
    return quat();
}

zcm::quat zcm::quat_cast(const zcm::mat4 &m)
{
    return quat_cast(mat3(m));
}

zcm::quat zcm::quatLookAtLH(const zcm::vec3 &direction, const zcm::vec3 &up)
{
    mat3 Result;

    Result[2] = direction;
    Result[0] = normalize(cross(up, Result[2]));
    Result[1] = cross(Result[2], Result[0]);

    return quat_cast(Result);
}

zcm::quat zcm::quatLookAtRH(const zcm::vec3 &direction, const zcm::vec3 &up)
{
    mat3 Result;

    Result[2] = -direction;
    Result[0] = normalize(cross(up, Result[2]));
    Result[1] = cross(Result[2], Result[0]);

    return quat_cast(Result);
}

zcm::quat zcm::conjugate(const zcm::quat &x)
{
    return quat(-x.x, -x.y,-x.z, x.w);
}

zcm::quat zcm::inverse(const zcm::quat &x)
{
    return conjugate(x) / dot(x, x);
}

zcm::quat zcm::lerp(const zcm::quat &x, const zcm::quat &y, float t)
{
    // Lerp is only defined in [0, 1]
    assert(t >= 0.0f);
    assert(t <= 1.0f);

    return x * (1.0f - t) + (y * t);
}

zcm::quat zcm::nlerp(const zcm::quat &x, const zcm::quat &y, float t)
{
    return normalize(lerp(x, y, t));
}

zcm::quat zcm::slerp(const zcm::quat &x, const zcm::quat &y, float t)
{
    quat z = y;

    auto cosTheta = dot(x, y);

    // If cosTheta < 0, the interpolation will take the long way around the sphere.
    // To fix this, one quat must be negated.
    if(cosTheta < 0.f)
    {
        z = -y;
        cosTheta = -cosTheta;
    }

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
    if(cosTheta > 1.0f - std::numeric_limits<float>::epsilon())
    {
        // Linear interpolation
        return quat(
                    mix(x.w, z.w, t),
                    mix(x.x, z.x, t),
                    mix(x.y, z.y, t),
                    mix(x.z, z.z, t));
    }
    else
    {
        // Essential Mathematics, page 467
        auto angle = acos(cosTheta);
        return (sin((1.0f - t) * angle) * x + sin(t * angle) * z) / sin(angle);
    }
}

zcm::vec3 zcm::rotate(const zcm::vec3 &v, const zcm::quat &q)
{
    auto qv = vec3{q.x, q.y, q.z};
    auto t = 2.0f * cross(qv, v);
    return v + q.w * t + cross(qv, t);
}

zcm::vec3 zcm::rotate(const zcm::quat &q, const zcm::vec3 &v)
{
    return rotate(v, q);
}

zcm::vec3 zcm::axis(const zcm::quat &q)
{
    auto tmp1 = 1.0f - q.w * q.w;
    if(tmp1 <= 0.0f)
        return vec3(0, 0, 1);

    auto tmp2 = inversesqrt(tmp1);
    return vec3(q.x * tmp2, q.y * tmp2, q.z * tmp2);
}

float zcm::angle(const zcm::quat &q)
{
    return acos(q.w) * 2.0f;
}

zcm::quat zcm::angleAxis(float angle, zcm::vec3 axis)
{
    auto s = sin(angle * 0.5f);
    return quat(cos(angle * 0.5f), axis * s);
}
