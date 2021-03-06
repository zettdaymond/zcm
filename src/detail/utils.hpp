#pragma once

#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>

namespace zcm {

    namespace detail
    {
        template<class Op>
        constexpr float applyOp(const float v, const Op& op) noexcept
        {
            return op(v);
        }

        template<class Op>
        vec2 applyOp(const vec2& v, const Op& op) noexcept
        {
            return { op(v.x), op(v.y) };
        }

        template<class Op>
        vec3 applyOp(const vec3& v, const Op& op) noexcept
        {
            return { op(v.x), op(v.y), op(v.z) };
        }

        template<class Op>
        vec4 applyOp(const vec4& v, const Op& op) noexcept
        {
            return { op(v.x), op(v.y), op(v.z), op(v.w) };
        }
    }
}
