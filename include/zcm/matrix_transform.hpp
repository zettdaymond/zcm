#pragma once

namespace zcm
{
    class vec3;
    class mat4;

    mat4  lookAt (const vec3& eye, const vec3& center, const vec3& up) noexcept;

    mat4  lookAtLH (const vec3& eye, const vec3& center, const vec3& up) noexcept;

    mat4  lookAtRH (const vec3& eye, const vec3& center, const vec3& up) noexcept;

    mat4  rotate (const mat4& m, float angle, const vec3& axis) noexcept;

    mat4  scale (const mat4& m, const vec3& v) noexcept;

    mat4  translate (const mat4& m, const vec3& v) noexcept;
}
