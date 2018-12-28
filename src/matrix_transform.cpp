#include <zcm/matrix_transform.hpp>
#include <zcm/geometric.hpp>
#include <zcm/angle_and_trigonometry.hpp>
#include <zcm/vec3.hpp>
#include <zcm/mat4.hpp>

zcm::mat4 zcm::translate(const zcm::mat4& m, const zcm::vec3& v) noexcept
{
    mat4 Result(m);
    Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
    return Result;
}

zcm::mat4 zcm::rotate(const zcm::mat4& m, float angle, const zcm::vec3& v) noexcept
{
    auto const a = angle;
    auto const c = cos(a);
    auto const s = sin(a);

    vec3 axis(normalize(v));
    vec3 temp((1.0f - c) * axis);

    mat4 Rotate;
    Rotate[0][0] = c + temp[0] * axis[0];
    Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
    Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

    Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
    Rotate[1][1] = c + temp[1] * axis[1];
    Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

    Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
    Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
    Rotate[2][2] = c + temp[2] * axis[2];

    mat4 Result;
    Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
    Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
    Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
    Result[3] = m[3];
    return Result;
}

//zcm::mat4 zcm::rotate_slow(zcm::mat4 const& m, float angle, zcm::vec3 const& v)
//{
//    auto const a = angle;
//    auto const c = cos(a);
//    auto const s = sin(a);
//    mat4 Result;

//    vec3 axis = normalize(v);

//    Result[0][0] = c + (1.0f - c)      * axis.x     * axis.x;
//    Result[0][1] = (1.0f - c) * axis.x * axis.y + s * axis.z;
//    Result[0][2] = (1.0f - c) * axis.x * axis.z - s * axis.y;
//    Result[0][3] = 0.0f;

//    Result[1][0] = (1.0f - c) * axis.y * axis.x - s * axis.z;
//    Result[1][1] = c + (1.0f - c) * axis.y * axis.y;
//    Result[1][2] = (1.0f - c) * axis.y * axis.z + s * axis.x;
//    Result[1][3] = 0.0f;

//    Result[2][0] = (1.0f - c) * axis.z * axis.x + s * axis.y;
//    Result[2][1] = (1.0f - c) * axis.z * axis.y - s * axis.x;
//    Result[2][2] = c + (1.0f - c) * axis.z * axis.z;
//    Result[2][3] = 0.0f;

//    Result[3] = vec4(0, 0, 0, 1);
//    return m * Result;
//}

zcm::mat4 zcm::scale(const zcm::mat4& m, const zcm::vec3& v) noexcept
{
    mat4 Result;
    Result[0] = m[0] * v[0];
    Result[1] = m[1] * v[1];
    Result[2] = m[2] * v[2];
    Result[3] = m[3];
    return Result;
}

//zcm::mat4 zcm::scale_slow(const zcm::mat4& m, const zcm::vec3& v)
//{
//    mat4 Result(1.0f);
//    Result[0][0] = v.x;
//    Result[1][1] = v.y;
//    Result[2][2] = v.z;
//    return m * Result;
//}

zcm::mat4 zcm::lookAtRH(const zcm::vec3& eye, const zcm::vec3& center, const zcm::vec3& up) noexcept
{
    vec3 const f(normalize(center - eye));
    vec3 const s(normalize(cross(f, up)));
    vec3 const u(cross(s, f));

    mat4 Result(1);
    Result[0][0] = s.x;
    Result[1][0] = s.y;
    Result[2][0] = s.z;
    Result[0][1] = u.x;
    Result[1][1] = u.y;
    Result[2][1] = u.z;
    Result[0][2] =-f.x;
    Result[1][2] =-f.y;
    Result[2][2] =-f.z;
    Result[3][0] =-dot(s, eye);
    Result[3][1] =-dot(u, eye);
    Result[3][2] = dot(f, eye);
    return Result;
}

zcm::mat4 zcm::lookAtLH(const zcm::vec3& eye, const zcm::vec3& center, const zcm::vec3& up) noexcept
{
    vec3 const f(normalize(center - eye));
    vec3 const s(normalize(cross(up, f)));
    vec3 const u(cross(f, s));

    mat4 Result(1);
    Result[0][0] = s.x;
    Result[1][0] = s.y;
    Result[2][0] = s.z;
    Result[0][1] = u.x;
    Result[1][1] = u.y;
    Result[2][1] = u.z;
    Result[0][2] = f.x;
    Result[1][2] = f.y;
    Result[2][2] = f.z;
    Result[3][0] = -dot(s, eye);
    Result[3][1] = -dot(u, eye);
    Result[3][2] = -dot(f, eye);
    return Result;
}

zcm::mat4 zcm::lookAt(const zcm::vec3& eye, const zcm::vec3& center, const zcm::vec3& up) noexcept
{
    //TODO:
//    if(GLM_CONFIG_CLIP_CONTROL & GLM_CLIP_CONTROL_LH_BIT)
//        return lookAtLH(eye, center, up);
//    else
//        return lookAtRH(eye, center, up);

    return lookAtRH(eye, center, up);
}
