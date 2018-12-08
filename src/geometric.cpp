#include <zcm/geometric.hpp>
#include <limits>
#include <zcm/common.hpp>
#include <zcm/exponential.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/quat.hpp>


float zcm::dot(float first, float second)
{
    return first * second;
}

float zcm::dot(const zcm::vec2& first, const zcm::vec2& second)
{
    return first.x * second.x + first.y * second.y;
}

float zcm::dot(const zcm::vec3& first, const zcm::vec3& second)
{
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

float zcm::dot(const zcm::vec4& first, const zcm::vec4& second)
{
    return first.x * second.x + first.y * second.y + first.z * second.z + first.w * second.w;
}

float zcm::dot(const zcm::quat & first, const zcm::quat & second)
{
	return first.x * second.x + first.y * second.y + first.z * second.z + first.w * second.w;
}


//------------------------------------------------------------------------------------------


zcm::vec3 zcm::cross(const zcm::vec3& first, const zcm::vec3& second)
{
    return vec3{ first.y * second.z - first.z * second.y,
                 first.z * second.x - first.x * second.z,
                 first.x * second.y - first.y * second.x};
}

//------------------------------------------------------------------------------------------


zcm::vec2 zcm::normalize(const zcm::vec2& vec)
{
    return vec * inversesqrt(dot(vec, vec));
}

zcm::vec3 zcm::normalize(const zcm::vec3& vec)
{
    return vec * inversesqrt(dot(vec, vec));
}

zcm::vec4 zcm::normalize(const zcm::vec4& vec)
{
    return vec * inversesqrt(dot(vec, vec));
}
\
zcm::quat zcm::normalize(const zcm::quat & q)
{
    return q / length(q);
}


//------------------------------------------------------------------------------------------


float zcm::distance(float first, float second)
{
    return abs(first - second);
}

float zcm::distance(const zcm::vec2& first, const zcm::vec2& second)
{
    return length(first - second);
}

float zcm::distance(const zcm::vec3& first, const zcm::vec3& second)
{
    return length(first - second);
}

float zcm::distance(const zcm::vec4& first, const zcm::vec4& second)
{
    return length(first - second);
}


//------------------------------------------------------------------------------------------


float zcm::faceforward(float N, float I, float Nref)
{
    if (dot(Nref, I) < 0.0) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec2 zcm::faceforward(const vec2& N, const vec2& I, const vec2& Nref)
{
    if (dot(Nref, I) < 0.0) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec3 zcm::faceforward(const vec3& N, const vec3& I, const vec3& Nref)
{
    if (dot(Nref, I) < 0.0) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec4 zcm::faceforward(const vec4& N, const vec4& I, const vec4& Nref)
{
    if (dot(Nref, I) < 0.0) {
        return N;
    }
    else {
        return -N;
    }
}


//------------------------------------------------------------------------------------------


float zcm::reflect(float I, float N)
{
    return I - 2.0 * dot(N, I) * N;
}

zcm::vec2 zcm::reflect(const zcm::vec2& I, const zcm::vec2& N)
{
    return I - 2.0 * dot(N, I) * N;
}

zcm::vec3 zcm::reflect(const zcm::vec3& I, const zcm::vec3& N)
{
    return I - 2.0 * dot(N, I) * N;
}

zcm::vec4 zcm::reflect(const zcm::vec4& I, const zcm::vec4& N)
{
    return I - 2.0 * dot(N, I) * N;
}


//------------------------------------------------------------------------------------------


float zcm::refract(float I, float N, float eta)
{
    auto k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
    if (k < 0.0){
        return 0.f;       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec2 zcm::refract(const zcm::vec2& I, const zcm::vec2& N, float eta)
{
    auto k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
    if (k < 0.0){
        return {0.0};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec3 zcm::refract(const zcm::vec3& I, const zcm::vec3& N, float eta)
{
    auto k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
    if (k < 0.0){
        return {0.0};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec4 zcm::refract(const zcm::vec4& I, const zcm::vec4& N, float eta)
{
    auto k = 1.0 - eta * eta * (1.0 - dot(N, I) * dot(N, I));
    if (k < 0.0){
        return {0.0};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}


//------------------------------------------------------------------------------------------


float zcm::length(float first)
{
    return first;
}

float zcm::length(const zcm::vec2& first)
{
    return sqrt(first.x * first.x + first.y * first.y);
}


float zcm::length(const zcm::vec3& first)
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z);
}


float zcm::length(const zcm::vec4& first)
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z + first.w * first.w);
}

float zcm::length(const zcm::quat & first)
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z + first.w * first.w);
}


//------------------------------------------------------------------------------------------


float zcm::length2(float first)
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec2 &first)
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec3 &first)
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec4 &first)
{
    return dot(first, first);
}

float zcm::length2(const zcm::quat &first)
{
    return dot(first, first);
}


//------------------------------------------------------------------------------------------


zcm::vec3 zcm::orthogonal(const vec3 &v)
{
    return abs(v.x) > abs(v.z) ? vec3(-v.y, v.x, 0.0f)
                               : vec3(0.0f, -v.z, v.y);

}

zcm::vec3 zcm::orthogonal_branchless(const vec3 &v)
{
    float k = fract(abs(v.x) + 0.5f);
    return vec3(-v.y, v.x - k * v.z, k * v.y);
}
