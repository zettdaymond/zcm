#pragma once

namespace zcm
{

    class vec3;
    class vec4;

    struct quat
    {
        quat();
        quat(float w, float x, float y, float z);
        quat(float s, vec3 v);
        quat(vec3 v, float s);

        /// Build a unit quaternion representing the rotation from u to v.
        /// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
        /// The input vectors need not be normalised.
        quat(vec3 u, vec3 v);

        float& operator[](unsigned val);
        float operator[](unsigned val) const;

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

    quat operator *(const quat& q, float s);
    quat operator *(float s, const quat& q);
    quat operator /(float s, const quat& q);
    quat operator /(const quat& q, float s);

}
