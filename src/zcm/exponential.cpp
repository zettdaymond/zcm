#include "exponential.h"

#include "cmath"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"


float zcm::sqrt(const float x)
{
    return sqrtf(x);
}

zcm::vec2 zcm::sqrt(const zcm::vec2& x)
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y) };
}

zcm::vec3 zcm::sqrt(const zcm::vec3& x)
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y), zcm::sqrt(x.z)};
}

zcm::vec4 zcm::sqrt(const zcm::vec4& x)
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y), zcm::sqrt(x.z), zcm::sqrt(x.w)};
}

//-----------------------------------------------------------------------------------------------------


float zcm::pow(const float x, const float y)
{
    return powf(x,y);
}

zcm::vec2 zcm::pow(const zcm::vec2& x, const zcm::vec2& y)
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y) };
}

zcm::vec3 zcm::pow(const zcm::vec3& x, const zcm::vec3& y)
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y),  zcm::pow(x.z, y.z)};
}

zcm::vec4 zcm::pow(const zcm::vec4& x, const zcm::vec4& y)
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y),  zcm::pow(x.z, y.z), zcm::pow(x.w, y.w)};
}

//-----------------------------------------------------------------------------------------------------


float zcm::log(const float x)
{
    return logf(x);
}

zcm::vec2 zcm::log(const zcm::vec2& x)
{
    return { zcm::log(x.x), zcm::log(x.y) };
}

zcm::vec3 zcm::log(const zcm::vec3& x)
{
    return { zcm::log(x.x), zcm::log(x.y), zcm::log(x.z) };
}

zcm::vec4 zcm::log(const zcm::vec4& x)
{
    return { zcm::log(x.x), zcm::log(x.y), zcm::log(x.z), zcm::log(x.w) };
}

//-----------------------------------------------------------------------------------------------------


float zcm::log2(const float x)
{
    return log2f(x);
}

zcm::vec2 zcm::log2(const zcm::vec2& x)
{
    return { zcm::log2(x.x), zcm::log2(x.y) };
}

zcm::vec3 zcm::log2(const zcm::vec3& x)
{
    return { zcm::log2(x.x), zcm::log2(x.y), zcm::log2(x.z) };
}

zcm::vec4 zcm::log2(const zcm::vec4& x)
{
    return { zcm::log2(x.x), zcm::log2(x.y), zcm::log2(x.z), zcm::log2(x.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::inversesqrt(const float x)
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec2 zcm::inversesqrt(const zcm::vec2& x)
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec3 zcm::inversesqrt(const zcm::vec3& x)
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec4 zcm::inversesqrt(const zcm::vec4& x)
{
    return 1.0f / zcm::sqrt(x);
}

//-----------------------------------------------------------------------------------------------------

float zcm::exp(const float x)
{
    return expf(x);
}

zcm::vec2 zcm::exp(const zcm::vec2& x)
{
    return {zcm::exp(x.x), zcm::exp(x.y)};
}

zcm::vec3 zcm::exp(const zcm::vec3& x)
{
    return {zcm::exp(x.x), zcm::exp(x.y), zcm::exp(x.z)};
}

zcm::vec4 zcm::exp(const zcm::vec4& x)
{
    return {zcm::exp(x.x), zcm::exp(x.y), zcm::exp(x.z), zcm::exp(x.w)};
}

//-----------------------------------------------------------------------------------------------------

float zcm::exp2(const float x)
{
    return expf(x);
}

zcm::vec2 zcm::exp2(const zcm::vec2& x)
{
    return {zcm::exp2(x.x),zcm::exp2(x.y)};
}

zcm::vec3 zcm::exp2(const zcm::vec3& x)
{
    return {zcm::exp2(x.x),zcm::exp2(x.y), zcm::exp2(x.z)};
}

zcm::vec4 zcm::exp2(const zcm::vec4& x)
{
    return {zcm::exp2(x.x),zcm::exp2(x.y), zcm::exp2(x.z), zcm::exp2(x.w)};
}
