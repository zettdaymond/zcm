#include <cassert>
#include <type_traits>
#include <zcm/vec3.hpp>
#include <zcm/exponential.hpp>
#include <zcm/geometric.hpp>
#include <zcm/quat.hpp>
#include <zcm/common.hpp>
#include <zcm/geometric.hpp>
#include <zcm/quaternion.hpp>


static_assert(std::is_standard_layout<zcm::quat>::value, "");
static_assert(sizeof(zcm::quat) == 4 * sizeof(float), "extra padding detected!");

zcm::quat::quat() noexcept :
    x(0.0f),
    y(0.0f),
    z(0.0f),
    w(1.0f)
{}

zcm::quat::quat(float _w, float _x, float _y, float _z) noexcept :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{}

zcm::quat::quat(float s, zcm::vec3 v) noexcept :
    x(v.x),
    y(v.y),
    z(v.z),
    w(s)
{}

zcm::quat::quat(zcm::vec3 v, float s) noexcept :
    x(v.x),
    y(v.y),
    z(v.z),
    w(s)
{}

zcm::quat::quat(zcm::vec3 u, zcm::vec3 v) noexcept
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

float& zcm::quat::operator[](unsigned val) noexcept
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

float zcm::quat::operator[](unsigned val) const noexcept
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

void zcm::quat::operator +=(const zcm::quat &other) noexcept
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

void zcm::quat::operator -=(const zcm::quat &other) noexcept
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}

void zcm::quat::operator *=(const zcm::quat &q2) noexcept
{
    float ww = (z + x) * (q2.x + q2.y);
    float yy = (w - y) * (q2.w + q2.z);
    float zz = (w + y) * (q2.w - q2.z);
    float xx = ww + yy + zz;
    float qq = 0.5f * (xx + (z - x) * (q2.x - q2.y));

    float _w = qq - ww + (z - y) * (q2.y - q2.z);
    float _x = qq - xx + (x + w) * (q2.x + q2.w);
    float _y = qq - yy + (w - x) * (q2.y + q2.z);
    float _z = qq - zz + (z + y) * (q2.w - q2.x);
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

void zcm::quat::operator *=(float scalar) noexcept
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

void zcm::quat::operator /=(float scalar) noexcept
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
}

zcm::quat zcm::operator +(const zcm::quat &a, const zcm::quat &b) noexcept
{
    return { a.w + b.w,
             a.x + b.x,
             a.y + b.y,
             a.z + b.z };
}

zcm::quat zcm::operator -(const zcm::quat &a, const zcm::quat &b) noexcept
{
    return { a.w - b.w,
             a.x - b.x,
             a.y - b.y,
             a.z - b.z };
}

zcm::quat zcm::operator +(const zcm::quat &a) noexcept
{
    return { +a.w,
             +a.x,
             +a.y,
             +a.z };
}

zcm::quat zcm::operator -(const zcm::quat &a) noexcept
{
    return { -a.w,
             -a.x,
             -a.y,
             -a.z };
}

zcm::quat zcm::operator *(const zcm::quat& q1, const zcm::quat& q2) noexcept
{
    float ww = (q1.z + q1.x) * (q2.x + q2.y);
    float yy = (q1.w - q1.y) * (q2.w + q2.z);
    float zz = (q1.w + q1.y) * (q2.w - q2.z);
    float xx = ww + yy + zz;
    float qq = 0.5f * (xx + (q1.z - q1.x) * (q2.x - q2.y));

    return { qq - ww + (q1.z - q1.y) * (q2.y - q2.z),
             qq - xx + (q1.x + q1.w) * (q2.x + q2.w),
             qq - yy + (q1.w - q1.x) * (q2.y + q2.z),
             qq - zz + (q1.z + q1.y) * (q2.w - q2.x) };
}

zcm::quat zcm::operator *(const zcm::quat &q, float s) noexcept
{
    return { q.w * s,
             q.x * s,
             q.y * s,
             q.z * s };
}

zcm::quat zcm::operator *(float s, const zcm::quat &q) noexcept
{
    return { q.w * s,
             q.x * s,
             q.y * s,
             q.z * s };
}

zcm::quat zcm::operator /(float s, const zcm::quat &q) noexcept
{
    return { s / q.w,
             s / q.x,
             s / q.y,
             s / q.z };
}

zcm::quat zcm::operator /(const zcm::quat &q, float s) noexcept
{
    return { q.w / s,
             q.x / s,
             q.y / s,
             q.z / s };
}


zcm::vec3 zcm::operator *(const zcm::quat& q, const zcm::vec3& v) noexcept
{
    auto qv = vec3{q.x, q.y, q.z};
    auto t = 2.0f * cross(qv, v);
    return v + q.w * t + cross(qv, t);
}

zcm::vec3 zcm::operator*(const zcm::vec3 &v, const zcm::quat &q) noexcept
{
    return inverse(q) * v;
}


bool zcm::operator==(const zcm::quat &first, const zcm::quat &second) noexcept
{
    return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w;
}

bool zcm::operator!=(const zcm::quat &first, const zcm::quat &second) noexcept
{
    return !(first == second);
}


