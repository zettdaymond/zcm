#pragma once

namespace zcm {

    struct bvec2;
    struct bvec3;
    struct bvec4;

    struct vec2;
    struct vec3;
    struct vec4;

    struct quat;

    struct mat2;
    struct mat3;
    struct mat4;

    // non-const
    bool*  value_ptr (bvec2& val);
    bool*  value_ptr (bvec3& val);
    bool*  value_ptr (bvec4& val);

    float* value_ptr (vec2& val);
    float* value_ptr (vec3& val);
    float* value_ptr (vec4& val);

    float* value_ptr (quat& val);

    float* value_ptr (mat2& val);
    float* value_ptr (mat3& val);
    float* value_ptr (mat4& val);

    // const
    const bool*  value_ptr (const bvec2& val);
    const bool*  value_ptr (const bvec3& val);
    const bool*  value_ptr (const bvec4& val);

    const float* value_ptr (const vec2& val);
    const float* value_ptr (const vec3& val);
    const float* value_ptr (const vec4& val);

    const float* value_ptr (const quat& val);

    const float* value_ptr (const mat2& val);
    const float* value_ptr (const mat3& val);
    const float* value_ptr (const mat4& val);

}
