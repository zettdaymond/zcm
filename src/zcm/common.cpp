#include "common.h"

//FIXME: Do not use stl or libc
#include <math.h>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"


float zcm::abs(const float x)
{
    return fabsf(x);
}

zcm::vec2 zcm::abs(const zcm::vec2& x)
{
    return { zcm::abs(x.x), zcm::abs(x.y) };
}

zcm::vec3 zcm::abs(const zcm::vec3& x)
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z) };
}

zcm::vec4 zcm::abs(const zcm::vec4& x)
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z), zcm::abs(x.w) };
}

//-----------------------------------------------------------------------------------------------------


float zcm::ceil(const float x)
{
    return ceilf(x);
}

zcm::vec2 zcm::ceil(const zcm::vec2& x)
{
    return { zcm::ceil(x.x), zcm::ceil(x.y) };
}

zcm::vec3 zcm::ceil(const zcm::vec3& x)
{
    return { zcm::ceil(x.x), zcm::ceil(x.y), zcm::ceil(x.z) };
}

zcm::vec4 zcm::ceil(const zcm::vec4& x)
{
    return { zcm::ceil(x.x), zcm::ceil(x.y), zcm::ceil(x.z), zcm::ceil(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::clamp(const float x, const float minVal, const float maxVal)
{
   return min(max(x, minVal), maxVal);
}

zcm::vec2 zcm::clamp(const zcm::vec2& x, const zcm::vec2& minVal, const zcm::vec2& maxVal)
{
   return min(max(x, minVal), maxVal);
}

zcm::vec3 zcm::clamp(const zcm::vec3& x, const zcm::vec3& minVal, const zcm::vec3& maxVal)
{
    return min(max(x, minVal), maxVal);
}

zcm::vec4 zcm::clamp(const zcm::vec4& x, const zcm::vec4& minVal, const zcm::vec4& maxVal)
{
    return min(max(x, minVal), maxVal);
}

//-----------------------------------------------------------------------------------------------------



float zcm::floor(const float x)
{
    return floorf(x);
}

zcm::vec2 zcm::floor(const zcm::vec2& x)
{
    return { zcm::floor(x.x), zcm::floor(x.y) };
}

zcm::vec3 zcm::floor(const zcm::vec3& x)
{
    return { zcm::floor(x.x), zcm::floor(x.y), zcm::floor(x.z) };
}

zcm::vec4 zcm::floor(const zcm::vec4& x)
{
    return { zcm::floor(x.x), zcm::floor(x.y), zcm::floor(x.z), zcm::floor(x.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::fract(const float x)
{
    return x - floor(x);
}

zcm::vec2 zcm::fract(const zcm::vec2& x)
{
    return x - floor(x);
}

zcm::vec3 zcm::fract(const zcm::vec3& x)
{
    return x - floor(x);
}

zcm::vec4 zcm::fract(const zcm::vec4& x)
{
    return x - floor(x);
}

//-----------------------------------------------------------------------------------------------------


float zcm::max(const float x, const float y)
{
    return std::max(x, y);
}

zcm::vec2 zcm::max(const zcm::vec2& x, const zcm::vec2& y)
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y) };
}

zcm::vec3 zcm::max(const zcm::vec3& x, const zcm::vec3& y)
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z) };
}

zcm::vec4 zcm::max(const zcm::vec4& x, const zcm::vec4& y)
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z), zcm::max(x.w, y.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::min(const float x, const float y)
{
    return std::min(x,y);
}

zcm::vec2 zcm::min(const zcm::vec2& x, const zcm::vec2& y)
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y) };
}

zcm::vec3 zcm::min(const zcm::vec3& x, const zcm::vec3& y)
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z) };
}

zcm::vec4 zcm::min(const zcm::vec4& x, const zcm::vec4& y)
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z), zcm::min(x.w, y.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::mod(const float x, const float y)
{
    return x - y * floor(x/y);
}

zcm::vec2 zcm::mod(const zcm::vec2& x, const zcm::vec2& y)
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y) };
}

zcm::vec3 zcm::mod(const zcm::vec3& x, const zcm::vec3& y)
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y), zcm::mod(x.z, y.z) };
}

zcm::vec4 zcm::mod(const zcm::vec4& x, const zcm::vec4& y)
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y), zcm::mod(x.z, y.z), zcm::mod(x.w, y.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::round(const float x)
{
    return roundf(x);
}

zcm::vec2 zcm::round(const zcm::vec2& x)
{
    return { zcm::round(x.x), zcm::round(x.y) };
}

zcm::vec3 zcm::round(const zcm::vec3& x)
{
    return { zcm::round(x.x), zcm::round(x.y), zcm::round(x.z)};
}

zcm::vec4 zcm::round(const zcm::vec4& x)
{
    return { zcm::round(x.x), zcm::round(x.y), zcm::round(x.z), zcm::round(x.w) };
}

//-----------------------------------------------------------------------------------------------------


float zcm::roundEven(const float x)
{
    return roundevenf(x);
}

zcm::vec2 zcm::roundEven(const zcm::vec2& x)
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y) };
}

zcm::vec3 zcm::roundEven(const zcm::vec3& x)
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y), zcm::roundEven(x.z)};
}

zcm::vec4 zcm::roundEven(const zcm::vec4& x)
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y), zcm::roundEven(x.z), zcm::roundEven(x.w) };
}

//-----------------------------------------------------------------------------------------------------



float zcm::sign(const float x)
{
    if(x < 0.0f) {
        return -1.0f;
    }
    else if(x == 0.0f) {
        return 0.0f;
    }
    return 1.0f;
}

zcm::vec2 zcm::sign(const zcm::vec2& x)
{
    return { zcm::sign(x.x), zcm::sign(x.y) };
}

zcm::vec3 zcm::sign(const zcm::vec3& x)
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z)};
}

zcm::vec4 zcm::sign(const zcm::vec4& x)
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z), zcm::sign(x.w) };
}

//-----------------------------------------------------------------------------------------------------

float zcm::trunc(const float x)
{
    return truncf(x);
}

zcm::vec2 zcm::trunc(const zcm::vec2& x)
{
    return { zcm::trunc(x.x), zcm::trunc(x.y) };
}

zcm::vec3 zcm::trunc(const zcm::vec3& x)
{
    return { zcm::trunc(x.x), zcm::trunc(x.y), zcm::trunc(x.z)};
}

zcm::vec4 zcm::trunc(const zcm::vec4& x)
{
    return { zcm::trunc(x.x), zcm::trunc(x.y), zcm::trunc(x.z), zcm::trunc(x.w) };
}
