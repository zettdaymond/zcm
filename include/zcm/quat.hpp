#pragma once

namespace zcm
{

    class vec3;
    class vec4;

    struct quat
    {
        quat();
        quat(float x, float y, float z, float w);

        quat(float s, vec3 v);

        /// Create a quaternion from two normalized axis
        /// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
        quat(vec3 u, vec3 v);


        float& operator[](unsigned val);
        const float& operator[](unsigned val) const;

        float x;
        float y;
        float z;
        float w;
    };

    quat operator +(const quat& a, const quat& b);
    quat operator -(const quat& a, const quat& b);
    quat operator +(const quat& a);
    quat operator -(const quat& a);
    quat operator *(const quat& a, const quat& b);

    vec3 operator *(const quat& q, const vec3& v);
    vec3 operator *(const vec3& v, const quat& q);

    vec4 operator *(const quat& q, const vec4& v);
    vec4 operator *(const vec4& v, const quat& q);


    quat operator *(const quat& q, const float s);
    quat operator *(const float s, const quat& q);
    quat operator /(const float s, const quat& q);
    
}
