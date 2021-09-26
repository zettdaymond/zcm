#pragma once

#include <zcm/detail/vectorcall.hpp>
#include <functional>
#include <zcm/vec4.hpp>
#include <zcm/quat.hpp>

namespace zcm {

    struct bvec2;
    struct bvec3;
    struct bvec4;
    struct ivec2;
    struct ivec3;
    struct ivec4;
    struct vec2;
    struct vec3;
    struct vec4;
    struct quat;
    struct mat2;
    struct mat3;
    struct mat4;

    size_t hash(float) noexcept;
    size_t hash(bool) noexcept;
    size_t hash(int) noexcept;
    size_t hash(unsigned) noexcept;
    size_t hash(const bvec2&) noexcept;
    size_t hash(const bvec3&) noexcept;
    size_t hash(const bvec4&) noexcept;
    size_t hash(const ivec2&) noexcept;
    size_t hash(const ivec3&) noexcept;
    size_t hash(const ivec4&) noexcept;
    size_t hash(const vec2&) noexcept;
    size_t hash(const vec3&) noexcept;
    size_t zcm_vectorcall hash(vec4) noexcept;
    size_t zcm_vectorcall hash(quat) noexcept;
    size_t hash(const mat2&) noexcept;
    size_t hash(const mat3&) noexcept;
    size_t hash(const mat4&) noexcept;
}

namespace std {

    template<>
    struct hash<zcm::bvec2>
    {
        size_t operator()(const zcm::bvec2& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::bvec3>
    {
        size_t operator()(const zcm::bvec3& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::bvec4>
    {
        size_t operator()(const zcm::bvec4& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::ivec2>
    {
        size_t operator()(const zcm::ivec2& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::ivec3>
    {
        size_t operator()(const zcm::ivec3& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::ivec4>
    {
        size_t operator()(const zcm::ivec4& v) const noexcept
        {
            return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::vec2>
    {
        size_t operator()(const zcm::vec2& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::vec3>
    {
        size_t operator()(const zcm::vec3& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::vec4>
    {
        size_t operator()(zcm::vec4 v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::quat>
    {
        size_t operator()(zcm::quat v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat2>
    {
        size_t operator()(const zcm::mat2& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat3>
    {
        size_t operator()(const zcm::mat3& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat4>
    {
        size_t operator()(const zcm::mat4& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

}
