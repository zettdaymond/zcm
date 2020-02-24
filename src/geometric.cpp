#include <zcm/geometric.hpp>
#include <limits>
#include <zcm/common.hpp>
#include <zcm/exponential.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/quat.hpp>


float zcm::dot(float first, float second) noexcept
{
    return first * second;
}

float zcm::dot(const zcm::vec2& first, const zcm::vec2& second) noexcept
{
    return first.x * second.x + first.y * second.y;
}

float zcm::dot(const zcm::vec3& first, const zcm::vec3& second) noexcept
{
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

float zcm::dot(const zcm::vec4& first, const zcm::vec4& second) noexcept
{
    return first.x * second.x + first.y * second.y + first.z * second.z + first.w * second.w;
}

float zcm::dot(const zcm::quat & first, const zcm::quat & second) noexcept
{
	return first.x * second.x + first.y * second.y + first.z * second.z + first.w * second.w;
}


//------------------------------------------------------------------------------------------


zcm::vec3 zcm::cross(const zcm::vec3& first, const zcm::vec3& second) noexcept
{
    return vec3{ first.y * second.z - first.z * second.y,
                 first.z * second.x - first.x * second.z,
                 first.x * second.y - first.y * second.x};
}

//------------------------------------------------------------------------------------------


zcm::vec2 zcm::normalize(const zcm::vec2& vec) noexcept
{
    return vec * inversesqrt(dot(vec, vec));
}

zcm::vec3 zcm::normalize(const zcm::vec3& vec) noexcept
{
    return vec * inversesqrt(dot(vec, vec));
}

zcm::vec4 zcm::normalize(const zcm::vec4& vec) noexcept
{
    return vec * inversesqrt(dot(vec, vec));
}
\
zcm::quat zcm::normalize(const zcm::quat & q) noexcept
{
    return q / length(q);
}


//------------------------------------------------------------------------------------------


float zcm::distance(float first, float second) noexcept
{
    return abs(first - second);
}

float zcm::distance(const zcm::vec2& first, const zcm::vec2& second) noexcept
{
    return length(first - second);
}

float zcm::distance(const zcm::vec3& first, const zcm::vec3& second) noexcept
{
    return length(first - second);
}

float zcm::distance(const zcm::vec4& first, const zcm::vec4& second) noexcept
{
    return length(first - second);
}


//------------------------------------------------------------------------------------------


float zcm::faceforward(float N, float I, float Nref) noexcept
{
    if (dot(Nref, I) < 0.0f) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec2 zcm::faceforward(const vec2& N, const vec2& I, const vec2& Nref) noexcept
{
    if (dot(Nref, I) < 0.0f) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec3 zcm::faceforward(const vec3& N, const vec3& I, const vec3& Nref) noexcept
{
    if (dot(Nref, I) < 0.0f) {
        return N;
    }
    else {
        return -N;
    }
}

zcm::vec4 zcm::faceforward(const vec4& N, const vec4& I, const vec4& Nref) noexcept
{
    if (dot(Nref, I) < 0.0f) {
        return N;
    }
    else {
        return -N;
    }
}


//------------------------------------------------------------------------------------------


float zcm::reflect(float I, float N) noexcept
{
    return I - 2.0f * dot(N, I) * N;
}

zcm::vec2 zcm::reflect(const zcm::vec2& I, const zcm::vec2& N) noexcept
{
    return I - 2.0f * dot(N, I) * N;
}

zcm::vec3 zcm::reflect(const zcm::vec3& I, const zcm::vec3& N) noexcept
{
    return I - 2.0f * dot(N, I) * N;
}

zcm::vec4 zcm::reflect(const zcm::vec4& I, const zcm::vec4& N) noexcept
{
    return I - 2.0f * dot(N, I) * N;
}


//------------------------------------------------------------------------------------------


float zcm::refract(float I, float N, float eta) noexcept
{
    auto k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
    if (k < 0.0f){
        return 0.f;       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec2 zcm::refract(const zcm::vec2& I, const zcm::vec2& N, float eta) noexcept
{
    auto k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
    if (k < 0.0f){
        return {0.0f};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec3 zcm::refract(const zcm::vec3& I, const zcm::vec3& N, float eta) noexcept
{
    auto k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
    if (k < 0.0f){
        return {0.0f};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}

zcm::vec4 zcm::refract(const zcm::vec4& I, const zcm::vec4& N, float eta) noexcept
{
    auto k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
    if (k < 0.0f){
        return {0.0f};       // or genDType(0.0)
    }
    else{
        return eta * I - (eta * dot(N, I) + sqrt(k)) * N;
    }
}


//------------------------------------------------------------------------------------------


float zcm::length(float first) noexcept
{
    return first;
}

float zcm::length(const zcm::vec2& first) noexcept
{
    return sqrt(first.x * first.x + first.y * first.y);
}


float zcm::length(const zcm::vec3& first) noexcept
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z);
}


float zcm::length(const zcm::vec4& first) noexcept
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z + first.w * first.w);
}

float zcm::length(const zcm::quat & first) noexcept
{
    return sqrt(first.x * first.x + first.y * first.y + first.z * first.z + first.w * first.w);
}


//------------------------------------------------------------------------------------------


float zcm::length2(float first) noexcept
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec2 &first) noexcept
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec3 &first) noexcept
{
    return dot(first, first);
}

float zcm::length2(const zcm::vec4 &first) noexcept
{
    return dot(first, first);
}

float zcm::length2(const zcm::quat &first) noexcept
{
    return dot(first, first);
}


//------------------------------------------------------------------------------------------


float zcm::distance2(float first, float second) noexcept
{
    return length2(first - second);
}

float zcm::distance2(const zcm::vec2 &first, const zcm::vec2 &second) noexcept
{
        return length2(first - second);
}

float zcm::distance2(const zcm::vec3 &first, const zcm::vec3 &second) noexcept
{
    return length(first - second);
}

float zcm::distance2(const zcm::vec4 &first, const zcm::vec4 &second) noexcept
{
    return length(first - second);
}


//------------------------------------------------------------------------------------------


zcm::vec3 zcm::orthogonal(const vec3 &v) noexcept
{
    return abs(v.x) > abs(v.z) ? vec3{-v.y, v.x, 0.0f}
                               : vec3{0.0f, -v.z, v.y};

}

zcm::vec3 zcm::orthogonal_branchless(const vec3 &v) noexcept
{
    float k = fract(abs(v.x) + 0.5f);
    return vec3{-v.y, v.x - k * v.z, k * v.y};
}


zcm::vec2 zcm::encode_octahedral(zcm::vec3 v) noexcept
{
    // @ref: Zina H. Cigolle, Sam Donow, Daniel Evangelakos, Michael Mara, Morgan McGuire, and Quirin Meyer,
    // Survey of Efficient Representations for Independent Unit Vectors,
    // Journal of Computer Graphics Techniques (JCGT), vol. 3, no. 2, 1-30, 2014
    // URL: http://jcgt.org/published/0003/02/01/

    // project the sphere onto octahedron and then onto XY plane (top hemisphere)
    auto p = zcm::vec2(v.x, v.y) * (1.0f / (abs(v.x) + abs(v.y) + abs(v.z)));

    // reflect the folds of the lower hemisphere over the diagonals
    return (v.z <= 0.0f) ? ((1.0f - abs(zcm::vec2(p.y, p.x))) * signNotZero(p)) : p;
}

zcm::vec3 zcm::decode_octahedral(zcm::vec2 e) noexcept
{
    auto v = zcm::vec3(e.x, e.y, 1.0f - abs(e.x) - abs(e.y));
    if (v.z < 0.0f) {
        v.x = 1.0f - abs(v.y) * signNotZero(v.x);
        v.y = 1.0f - abs(v.x) * signNotZero(v.y);
    }
    return normalize(v);
}
