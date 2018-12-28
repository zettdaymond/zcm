#pragma once

#include <functional>

namespace zcm {

    struct vec2;
    struct vec3;
    struct vec4;
    struct quat;
    struct mat2;
    struct mat3;
    struct mat4;

    size_t hash(float) noexcept;
    size_t hash(const vec2&) noexcept;
    size_t hash(const vec3&) noexcept;
    size_t hash(const vec4&) noexcept;
    size_t hash(const quat&) noexcept;
    size_t hash(const mat2&) noexcept;
    size_t hash(const mat3&) noexcept;
    size_t hash(const mat4&) noexcept;
}

namespace std {

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
        size_t operator()(const zcm::vec4& v) const noexcept
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::quat>
    {
        size_t operator()(const zcm::quat& v) const noexcept
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
