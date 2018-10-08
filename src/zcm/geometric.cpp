#include "geometric.h"

#include "exponential.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

float zcm::dot(const float first, const float second)
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

//------------------------------------------------------------------------------------------

zcm::vec3 zcm::cross(const zcm::vec3& first, const zcm::vec3& second)
{
    return vec3{ first.y * second.z - first.z * second.y,
                 first.z * second.x - first.x * second.z,
                 first.x * second.y - first.y * second.x};
}

//------------------------------------------------------------------------------------------

float zcm::normalize(const float)
{
    //FIXME: shall we implement this??
    return 1.0;
}

zcm::vec2 zcm::normalize(const zcm::vec2& vec)
{
    // Calculate the magnitude of the vector
    auto magnitude = zcm::sqrt((vec.x * vec.x) + (vec.y * vec.y));

    //FIXME: If this is valid???
    if(magnitude == 0.0f) {
        return {0.0f};
    }

    //TODO: rewrite with fastInverseSqrt() from Q3.
    return vec / magnitude;
}

zcm::vec3 zcm::normalize(const zcm::vec3& vec)
{
    // Calculate the magnitude of the vector
    auto magnitude = zcm::sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

    //FIXME: If this is valid???
    if(magnitude == 0.0f) {
        return {0.0f};
    }

    //TODO: rewrite with fastInverseSqrt() from Q3.
    return vec / magnitude;
}

zcm::vec4 zcm::normalize(const zcm::vec4& vec)
{
    // Calculate the magnitude of the vector
    auto magnitude = zcm::sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z) + (vec.w * vec.w));

    //FIXME: If this is valid???
    if(magnitude == 0.0f) {
        return {0.0f};
    }

    //TODO: rewrite with fastInverseSqrt() from Q3.
    return vec / magnitude;
}


//------------------------------------------------------------------------------------------

float zcm::distance(const float first, const float second)
{
    //FIXME: implement
    //return abs(first - second);
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

float zcm::faceforward(const float N, const float I, const float Nref)
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

float zcm::reflect(const float I, const float N)
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

float zcm::refract(const float I, const float N, float eta)
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

float zcm::length(const float first)
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


//------------------------------------------------------------------------------------------
