#pragma once

#include "zcm/vec2.h"
#include "zcm/vec3.h"
#include "zcm/vec4.h"

namespace zcm {


    namespace detail
    {
        template<class Op>
        constexpr float applyOp(const float v, const Op& op)
        {
            return op(v);
        }

        template<class Op>
        constexpr vec2 applyOp(const vec2& v, const Op& op)
        {
            return { op(v.x), op(v.y) };
        }

        template<class Op>
        constexpr vec3 applyOp(const vec3& v, const Op& op)
        {
            return { op(v.x), op(v.y), op(v.z) };
        }

        template<class Op>
        constexpr vec4 applyOp(const vec4& v, const Op& op)
        {
            return { op(v.x), op(v.y), op(v.z), op(v.w) };
        }
    }
}
