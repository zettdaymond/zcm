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

    size_t hash(float);
    size_t hash(const vec2&);
    size_t hash(const vec3&);
    size_t hash(const vec4&);
    size_t hash(const quat&);
    size_t hash(const mat2&);
    size_t hash(const mat3&);
    size_t hash(const mat4&);
}

namespace std {

    template<>
    struct hash<zcm::vec2>
    {
        size_t operator()(const zcm::vec2& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::vec3>
    {
        size_t operator()(const zcm::vec3& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::vec4>
    {
        size_t operator()(const zcm::vec4& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::quat>
    {
        size_t operator()(const zcm::quat& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat2>
    {
        size_t operator()(const zcm::mat2& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat3>
    {
        size_t operator()(const zcm::mat3& v) const
        {
    	    return zcm::hash(v);
        }
    };

    template<>
    struct hash<zcm::mat4>
    {
        size_t operator()(const zcm::mat4& v) const
        {
    	    return zcm::hash(v);
        }
    };

}
