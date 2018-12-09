#include <cassert>
#include <type_traits>
#include <zcm/vec3.hpp>
#include <zcm/exponential.hpp>
#include <zcm/geometric.hpp>
#include <zcm/quat.hpp>
#include <zcm/common.hpp>
#include <zcm/geometric.hpp>

static_assert(std::is_standard_layout<zcm::quat>::value, "");

zcm::quat::quat() :
    x(0.0f),
    y(0.0f),
    z(0.0f),
    w(1.0f)
{}

zcm::quat::quat(float _w, float _x, float _y, float _z) :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{}

zcm::quat::quat(float s, zcm::vec3 v) :
    x(v.x),
    y(v.y),
    z(v.z),
    w(s)
{}

zcm::quat::quat(zcm::vec3 v, float s) :
    x(v.x),
    y(v.y),
    z(v.z),
    w(s)
{}

zcm::quat::quat(zcm::vec3 u, zcm::vec3 v)
{
    float norm_u_norm_v = sqrt(dot(u, u) * dot(v, v));
    float real_part = norm_u_norm_v + dot(u, v);
    vec3 w;

    if (real_part < 1.e-6f * norm_u_norm_v)
    {
        /* If u and v are exactly opposite, rotate 180 degrees
         * around an arbitrary orthogonal axis. Axis normalisation
         * can happen later, when we normalise the quaternion. */
        real_part = 0.0f;
        w = zcm::abs(u.x) > zcm::abs(u.z) ? vec3(-u.y, u.x, 0.f)
                                : vec3(0.f, -u.z, u.y);
    }
    else
    {
        /* Otherwise, build quaternion the standard way. */
        w = cross(u, v);
    }

    auto res = normalize(quat(real_part, w.x, w.y, w.z));
    *this = res;
}

float& zcm::quat::operator[](unsigned val)
{
    assert(val < 4);
    switch (val) {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
    return w;
}

float zcm::quat::operator[](unsigned val) const
{
    assert(val < 4);
    switch (val) {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
    return w;
}

zcm::quat zcm::operator +(const zcm::quat &a, const zcm::quat &b)
{
    return quat(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
}

zcm::quat zcm::operator -(const zcm::quat &a, const zcm::quat &b)
{
    return quat(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z);
}

zcm::quat zcm::operator +(const zcm::quat &a)
{
    return a;
}

zcm::quat zcm::operator -(const zcm::quat &a)
{
    return quat(-a.w, -a.x, -a.y, -a.z);
}

zcm::quat zcm::operator *(const zcm::quat& q1, const zcm::quat& q2)
{
    float ww = (q1.z + q1.x) * (q2.x + q2.y);
    float yy = (q1.w - q1.y) * (q2.w + q2.z);
    float zz = (q1.w + q1.y) * (q2.w - q2.z);
    float xx = ww + yy + zz;
    float qq = 0.5f * (xx + (q1.z - q1.x) * (q2.x - q2.y));

    float w = qq - ww + (q1.z - q1.y) * (q2.y - q2.z);
    float x = qq - xx + (q1.x + q1.w) * (q2.x + q2.w);
    float y = qq - yy + (q1.w - q1.x) * (q2.y + q2.z);
    float z = qq - zz + (q1.z + q1.y) * (q2.w - q2.x);
    return quat(w, x, y, z);
}

zcm::quat zcm::operator *(const zcm::quat &q, float s)
{
    return quat(q.w * s, q.x * s, q.y * s, q.z * s);
}

zcm::quat zcm::operator *(float s, const zcm::quat &q)
{
    return quat(q.w * s, q.x * s, q.y * s, q.z * s);
}

zcm::quat zcm::operator /(float s, const zcm::quat &q)
{
    s = 1.0f / s;
    return quat(q.w * s, q.x * s, q.y * s, q.z * s);
}

zcm::quat zcm::operator /(const zcm::quat &q, float s)
{
    s = 1.0f / s;
    return quat(q.w * s, q.x * s, q.y * s, q.z * s);
}
