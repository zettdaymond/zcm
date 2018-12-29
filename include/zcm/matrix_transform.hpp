#pragma once

namespace zcm
{
    class vec3;
    class mat4;

    mat4  lookAtLH (const vec3& eye, const vec3& center, const vec3& up) noexcept;
    mat4  lookAtRH (const vec3& eye, const vec3& center, const vec3& up) noexcept;

    mat4  ortho (float left, float right, float bottom, float top) noexcept;

    /// clip space from zero to one (DX convention)
    mat4  orthoLH_ZO (float left, float right, float bottom, float top, float zNear, float zFar) noexcept;
    mat4  orthoRH_ZO (float left, float right, float bottom, float top, float znear, float zfar) noexcept;

    /// clip space from negative one to one (OpenGL default convention)
    mat4  orthoLH_NO (float left, float right, float bottom, float top, float znear, float zfar) noexcept;
    mat4  orthoRH_NO (float left, float right, float bottom, float top, float znear, float zfar) noexcept;

    mat4  rotate (const mat4& m, float angle, const vec3& axis) noexcept;
    mat4  scale (const mat4& m, const vec3& v) noexcept;
    mat4  translate (const mat4& m, const vec3& v) noexcept;
}
