#include <zcm/common.hpp>

//FIXME: Do not use stl or libc
#include <cmath>
#include <algorithm>

#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec4.hpp>
#include <zcm/bvec2.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/bvec4.hpp>
#include <zcm/quat.hpp>


float zcm::abs(float x) noexcept
{
    return fabsf(x);
}

zcm::vec2 zcm::abs(const zcm::vec2& x) noexcept
{
    return { zcm::abs(x.x), zcm::abs(x.y) };
}

zcm::vec3 zcm::abs(const zcm::vec3& x) noexcept
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z) };
}

zcm::vec4 zcm_vectorcall zcm::abs(zcm::vec4 x) noexcept
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z), zcm::abs(x.w) };
}

int zcm::abs(int x) noexcept
{
    return std::abs(x);
}

zcm::ivec2 zcm::abs(const zcm::ivec2 &x) noexcept
{
    return { abs(x.x), abs(x.y) };
}

zcm::ivec3 zcm::abs(const zcm::ivec3 &x) noexcept
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z) };
}

zcm::ivec4 zcm::abs(const zcm::ivec4 &x) noexcept
{
    return { zcm::abs(x.x), zcm::abs(x.y), zcm::abs(x.z), zcm::abs(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::ceil(float x) noexcept
{
    return ceilf(x);
}

zcm::vec2 zcm::ceil(const zcm::vec2& x) noexcept
{
    return { zcm::ceil(x.x), zcm::ceil(x.y) };
}

zcm::vec3 zcm::ceil(const zcm::vec3& x) noexcept
{
    return { zcm::ceil(x.x), zcm::ceil(x.y), zcm::ceil(x.z) };
}

zcm::vec4 zcm_vectorcall zcm::ceil(zcm::vec4 x) noexcept
{
    return { zcm::ceil(x.x), zcm::ceil(x.y), zcm::ceil(x.z), zcm::ceil(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::clamp(float x, float minVal, float maxVal) noexcept
{
   return min(max(x, minVal), maxVal);
}

zcm::vec2 zcm::clamp(const zcm::vec2& x, const zcm::vec2& minVal, const zcm::vec2& maxVal) noexcept
{
   return min(max(x, minVal), maxVal);
}

zcm::vec3 zcm::clamp(const zcm::vec3& x, const zcm::vec3& minVal, const zcm::vec3& maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}

zcm::vec4 zcm_vectorcall zcm::clamp(zcm::vec4 x, zcm::vec4 minVal, zcm::vec4 maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}

int zcm::clamp(int x, int minVal, int maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}

zcm::ivec2 zcm::clamp(const zcm::ivec2 &x, const zcm::ivec2 &minVal, const zcm::ivec2 &maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}

zcm::ivec3 zcm::clamp(const zcm::ivec3 &x, const zcm::ivec3 &minVal, const zcm::ivec3 &maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}

zcm::ivec4 zcm::clamp(const zcm::ivec4 &x, const zcm::ivec4 &minVal, const zcm::ivec4 &maxVal) noexcept
{
    return min(max(x, minVal), maxVal);
}


//-----------------------------------------------------------------------------------------------------


float zcm::floor(float x) noexcept
{
    return floorf(x);
}

zcm::vec2 zcm::floor(const zcm::vec2& x) noexcept
{
    return { zcm::floor(x.x), zcm::floor(x.y) };
}

zcm::vec3 zcm::floor(const zcm::vec3& x) noexcept
{
    return { zcm::floor(x.x), zcm::floor(x.y), zcm::floor(x.z) };
}

zcm::vec4 zcm_vectorcall zcm::floor(zcm::vec4 x) noexcept
{
    return { zcm::floor(x.x), zcm::floor(x.y), zcm::floor(x.z), zcm::floor(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::fma(float a, float b, float c) noexcept
{
    return std::fma(a, b, c);
}

zcm::vec2 zcm::fma(const zcm::vec2 &a, const zcm::vec2 &b, const zcm::vec2 &c) noexcept
{
    return {fma(a.x, b.x, c.x), fma(a.y, b.y, c.y)};
}

zcm::vec3 zcm::fma(const zcm::vec3 &a, const zcm::vec3 &b, const zcm::vec3 &c) noexcept
{
    return {fma(a.x, b.x, c.x), fma(a.y, b.y, c.y), fma(a.z, b.z, c.z)};
}

zcm::vec4 zcm_vectorcall zcm::fma(zcm::vec4 a, zcm::vec4 b, zcm::vec4 c) noexcept
{
    return {fma(a.x, b.x, c.x), fma(a.y, b.y, c.y), fma(a.z, b.z, c.z), fma(a.w, b.w, c.w)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::fract(float x) noexcept
{
    return x - floor(x);
}

zcm::vec2 zcm::fract(const zcm::vec2& x) noexcept
{
    return x - floor(x);
}

zcm::vec3 zcm::fract(const zcm::vec3& x) noexcept
{
    return x - floor(x);
}

zcm::vec4 zcm_vectorcall zcm::fract(zcm::vec4 x) noexcept
{
    return x - floor(x);
}


//-----------------------------------------------------------------------------------------------------


float zcm::max(float x, float y) noexcept
{
    return x < y ? y : x; // glsl spec (returns x if y is NAN)
}

zcm::vec2 zcm::max(const zcm::vec2& x, const zcm::vec2& y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y) };
}

zcm::vec3 zcm::max(const zcm::vec3& x, const zcm::vec3& y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z) };
}

zcm::vec4 zcm_vectorcall zcm::max(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z), zcm::max(x.w, y.w) };
}

int zcm::max(int x, int y) noexcept
{
    return x < y ? y : x;
}

zcm::ivec2 zcm::max(const zcm::ivec2 &x, const zcm::ivec2 &y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y) };
}

zcm::ivec3 zcm::max(const zcm::ivec3 &x, const zcm::ivec3 &y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z) };
}

zcm::ivec4 zcm::max(const zcm::ivec4 &x, const zcm::ivec4 &y) noexcept
{
    return { zcm::max(x.x, y.x), zcm::max(x.y, y.y), zcm::max(x.z, y.z), zcm::max(x.w, y.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::min(float x, float y) noexcept
{
    return y < x ? y : x; // glsl spec (returns x if y is NAN)
}

zcm::vec2 zcm::min(const zcm::vec2& x, const zcm::vec2& y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y) };
}

zcm::vec3 zcm::min(const zcm::vec3& x, const zcm::vec3& y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z) };
}

zcm::vec4 zcm_vectorcall zcm::min(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z), zcm::min(x.w, y.w) };
}

int zcm::min(int x, int y) noexcept
{
    return y < x ? y : x;
}

zcm::ivec2 zcm::min(const zcm::ivec2 &x, const zcm::ivec2 &y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y) };
}

zcm::ivec3 zcm::min(const zcm::ivec3 &x, const zcm::ivec3 &y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z) };
}

zcm::ivec4 zcm::min(const zcm::ivec4 &x, const zcm::ivec4 &y) noexcept
{
    return { zcm::min(x.x, y.x), zcm::min(x.y, y.y), zcm::min(x.z, y.z), zcm::min(x.w, y.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::mod(float x, float y) noexcept
{
    return x - y * floor(x/y);
}

zcm::vec2 zcm::mod(const zcm::vec2& x, const zcm::vec2& y) noexcept
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y) };
}

zcm::vec3 zcm::mod(const zcm::vec3& x, const zcm::vec3& y) noexcept
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y), zcm::mod(x.z, y.z) };
}

zcm::vec4 zcm_vectorcall zcm::mod(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { zcm::mod(x.x, y.x), zcm::mod(x.y, y.y), zcm::mod(x.z, y.z), zcm::mod(x.w, y.w) };
}

zcm::vec2 zcm::mod(const zcm::vec2 &x, float y) noexcept
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y) };
}

zcm::vec3 zcm::mod(const zcm::vec3 &x, float y) noexcept
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y), zcm::mod(x.z, y) };
}

zcm::vec4 zcm_vectorcall zcm::mod(zcm::vec4 x, float y) noexcept
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y), zcm::mod(x.z, y), zcm::mod(x.w, y) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::round(float x) noexcept
{
    return roundf(x);
}

zcm::vec2 zcm::round(const zcm::vec2& x) noexcept
{
    return { zcm::round(x.x), zcm::round(x.y) };
}

zcm::vec3 zcm::round(const zcm::vec3& x) noexcept
{
    return { zcm::round(x.x), zcm::round(x.y), zcm::round(x.z)};
}

zcm::vec4 zcm_vectorcall zcm::round(zcm::vec4 x) noexcept
{
    return { zcm::round(x.x), zcm::round(x.y), zcm::round(x.z), zcm::round(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::roundEven(float x) noexcept
{
    return std::nearbyint(x * 0.5f) * 2.0f;
}

zcm::vec2 zcm::roundEven(const zcm::vec2& x) noexcept
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y) };
}

zcm::vec3 zcm::roundEven(const zcm::vec3& x) noexcept
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y), zcm::roundEven(x.z)};
}

zcm::vec4 zcm_vectorcall zcm::roundEven(zcm::vec4 x) noexcept
{
    return { zcm::roundEven(x.x), zcm::roundEven(x.y), zcm::roundEven(x.z), zcm::roundEven(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::sign(float x) noexcept
{
    if(x == 0.0f) {
        return 0.0f;
    }
    if(x > 0.0f) {
        return 1.0f;
    }
    return -1.0f;
}

zcm::vec2 zcm::sign(const zcm::vec2& x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y) };
}

zcm::vec3 zcm::sign(const zcm::vec3& x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z)};
}

zcm::vec4 zcm_vectorcall zcm::sign(zcm::vec4 x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z), zcm::sign(x.w) };
}

int zcm::sign(int x) noexcept
{
    if(x == 0) {
        return 0;
    }
    if(x > 0) {
        return 1;
    }
    return -1;
}

zcm::ivec2 zcm::sign(const zcm::ivec2 &x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y) };
}

zcm::ivec3 zcm::sign(const zcm::ivec3 &x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z)};
}

zcm::ivec4 zcm::sign(const zcm::ivec4 &x) noexcept
{
    return { zcm::sign(x.x), zcm::sign(x.y), zcm::sign(x.z), zcm::sign(x.w) };
}

float zcm::signNotZero(float x) noexcept
{
    return x >= 0.0f ? +1.0f : -1.0f;
}

zcm::vec2 zcm::signNotZero(const zcm::vec2 &x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y) };
}

zcm::vec3 zcm::signNotZero(const zcm::vec3 &x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y), signNotZero(x.z) };
}

zcm::vec4 zcm_vectorcall zcm::signNotZero(zcm::vec4 x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y), signNotZero(x.z), signNotZero(x.w) };
}

int zcm::signNotZero(int x) noexcept
{
    return x >= 0 ? 1 : -1;
}

zcm::ivec2 zcm::signNotZero(const zcm::ivec2 &x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y) };
}

zcm::ivec3 zcm::signNotZero(const zcm::ivec3 &x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y), signNotZero(x.z) };
}

zcm::ivec4 zcm::signNotZero(const zcm::ivec4 &x) noexcept
{
    return { signNotZero(x.x), signNotZero(x.y), signNotZero(x.z), signNotZero(x.w) };
}



//-----------------------------------------------------------------------------------------------------


float zcm::trunc(float x) noexcept
{
    return truncf(x);
}

zcm::vec2 zcm::trunc(const zcm::vec2& x) noexcept
{
    return { zcm::trunc(x.x), zcm::trunc(x.y) };
}

zcm::vec3 zcm::trunc(const zcm::vec3& x) noexcept
{
    return { zcm::trunc(x.x), zcm::trunc(x.y), zcm::trunc(x.z)};
}

zcm::vec4 zcm_vectorcall zcm::trunc(zcm::vec4 x) noexcept
{
    return { zcm::trunc(x.x), zcm::trunc(x.y), zcm::trunc(x.z), zcm::trunc(x.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::smoothstep(float edge0, float edge1, float x) noexcept
{
    float const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}

zcm::vec2 zcm::smoothstep(const zcm::vec2& edge0, const zcm::vec2& edge1, const zcm::vec2& x) noexcept
{
    vec2 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}

zcm::vec3 zcm::smoothstep(const zcm::vec3& edge0, const zcm::vec3& edge1, const zcm::vec3& x) noexcept
{
    vec3 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}


zcm::vec4 zcm_vectorcall zcm::smoothstep(zcm::vec4 edge0, zcm::vec4 edge1, zcm::vec4 x) noexcept
{
    vec4 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}


//-----------------------------------------------------------------------------------------------------


float zcm::step(float edge, float x) noexcept
{
    return x < edge ? 0.0f : 1.0f;
}

zcm::vec2 zcm::step(const zcm::vec2 &edge, const zcm::vec2 & t) noexcept
{
    return { step(edge.x, t.x), step(edge.y, t.y) };
}

zcm::vec3 zcm::step(const zcm::vec3 &edge, const zcm::vec3 & t) noexcept
{
    return { step(edge.x, t.x), step(edge.y, t.y), step(edge.z, t.z) };
}

zcm::vec4 zcm_vectorcall zcm::step(zcm::vec4 edge, zcm::vec4 t) noexcept
{
    return { step(edge.x, t.x), step(edge.y, t.y), step(edge.z, t.z), step(edge.w, t.w) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::mix(float x, float y, float t) noexcept
{
    return x + t * (y - x);
}

zcm::vec2 zcm::mix(const zcm::vec2 &x, const zcm::vec2 &y, const zcm::vec2 &t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y) };
}

zcm::vec3 zcm::mix(const zcm::vec3 &x, const zcm::vec3 &y, const zcm::vec3 &t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y),
             mix(x.z, y.z, t.z) };
}

zcm::vec4 zcm_vectorcall zcm::mix(zcm::vec4 x, zcm::vec4 y, zcm::vec4 t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y),
             mix(x.z, y.z, t.z),
             mix(x.w, y.w, t.w) };
}


zcm::vec2 zcm::mix(const zcm::vec2 &x, const zcm::vec2 &y, float t) noexcept
{
    return { mix(x.x, y.x, t),
             mix(x.y, y.y, t) };
}

zcm::vec3 zcm::mix(const zcm::vec3 &x, const zcm::vec3 &y, float t) noexcept
{
    return { mix(x.x, y.x, t),
             mix(x.y, y.y, t),
             mix(x.z, y.z, t) };
}

zcm::vec4 zcm_vectorcall zcm::mix(zcm::vec4 x, zcm::vec4 y, float t) noexcept
{
    return { mix(x.x, y.x, t),
             mix(x.y, y.y, t),
             mix(x.z, y.z, t),
             mix(x.w, y.w, t) };
}

//-----------------------------------------------------------------------------------------------------


float zcm::mix(float x, float y, bool t) noexcept
{
    return t ? y : x;
}

zcm::vec2 zcm::mix(const zcm::vec2 &x, const zcm::vec2 &y, const zcm::bvec2 &t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y) };
}

zcm::vec3 zcm::mix(const zcm::vec3 &x, const zcm::vec3 &y, const zcm::bvec3 &t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y),
             mix(x.z, y.z, t.z) };
}

zcm::vec4 zcm_vectorcall zcm::mix(zcm::vec4 x, zcm::vec4 y, const zcm::bvec4 &t) noexcept
{
    return { mix(x.x, y.x, t.x),
             mix(x.y, y.y, t.y),
             mix(x.z, y.z, t.z),
             mix(x.w, y.w, t.w) };
}


//-----------------------------------------------------------------------------------------------------


bool zcm::isinf(float x) noexcept
{
    return std::isinf(x);
}

zcm::bvec2 zcm::isinf(const zcm::vec2 &x) noexcept
{
    return { isinf(x.x), isinf(x.y) };
}

zcm::bvec3 zcm::isinf(const zcm::vec3 &x) noexcept
{
    return { isinf(x.x), isinf(x.y), isinf(x.z) };
}

zcm::bvec4 zcm_vectorcall zcm::isinf(zcm::vec4 x) noexcept
{
    return { isinf(x.x), isinf(x.y), isinf(x.z), isinf(x.w) };
}

zcm::bvec4 zcm::isinf(const zcm::quat &x) noexcept
{
    return { isinf(x.x), isinf(x.y), isinf(x.z), isinf(x.w) };
}


//-----------------------------------------------------------------------------------------------------


bool zcm::isnan(float x) noexcept
{
    return std::isnan(x);
}

zcm::bvec2 zcm::isnan(const zcm::vec2 &x) noexcept
{
    return { isnan(x.x), isnan(x.y) };
}

zcm::bvec3 zcm::isnan(const zcm::vec3 &x) noexcept
{
    return { isnan(x.x), isnan(x.y), isnan(x.z) };
}

zcm::bvec4 zcm_vectorcall zcm::isnan(zcm::vec4 x) noexcept
{
    return { isnan(x.x), isnan(x.y), isnan(x.z), isnan(x.w) };
}

zcm::bvec4 zcm::isnan(const zcm::quat &x) noexcept
{
    return { isnan(x.x), isnan(x.y), isnan(x.z), isnan(x.w) };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::lessThan(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x < y.x, x.y < y.y };
}

zcm::bvec3 zcm::lessThan(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x < y.x, x.y < y.y, x.z < y.z };
}

zcm::bvec4 zcm_vectorcall zcm::lessThan(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x < y.x, x.y < y.y, x.z < y.z, x.w < y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::lessThanEqual(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x <= y.x, x.y <= y.y };
}

zcm::bvec3 zcm::lessThanEqual(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x <= y.x, x.y <= y.y, x.z <= y.z };
}

zcm::bvec4 zcm_vectorcall zcm::lessThanEqual(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x <= y.x, x.y <= y.y, x.z <= y.z, x.w <= y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::greaterThan(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x > y.x, x.y > y.y };
}

zcm::bvec3 zcm::greaterThan(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x > y.x, x.y > y.y, x.z > y.z };
}

zcm::bvec4 zcm_vectorcall zcm::greaterThan(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x > y.x, x.y > y.y, x.z > y.z, x.w > y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::greaterThanEqual(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x >= y.x, x.y >= y.y };
}

zcm::bvec3 zcm::greaterThanEqual(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x >= y.x, x.y >= y.y, x.z >= y.z };
}

zcm::bvec4 zcm_vectorcall zcm::greaterThanEqual(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x >= y.x, x.y >= y.y, x.z >= y.z, x.w >= y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::equal(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x == y.x, x.y == y.y };
}

zcm::bvec3 zcm::equal(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x == y.x, x.y == y.y, x.z == y.z };
}

zcm::bvec4 zcm_vectorcall zcm::equal(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x == y.x, x.y == y.y, x.z == y.z, x.w == y.w };
}

zcm::bvec4 zcm::equal(const zcm::quat &x, const zcm::quat &y) noexcept
{
    return { x.x == y.x, x.y == y.y, x.z == y.z, x.w == y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::equal(zcm::bvec2 x, zcm::bvec2 y) noexcept
{
    return { x.x == y.x, x.y == y.y };
}

zcm::bvec3 zcm::equal(zcm::bvec3 x, zcm::bvec3 y) noexcept
{
    return { x.x == y.x, x.y == y.y, x.z == y.z };
}

zcm::bvec4 zcm::equal(zcm::bvec4 x, zcm::bvec4 y) noexcept
{
    return { x.x == y.x, x.y == y.y, x.z == y.z, x.w == y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::notEqual(const zcm::vec2 &x, const zcm::vec2 &y) noexcept
{
    return { x.x != y.x, x.y != y.y };
}

zcm::bvec3 zcm::notEqual(const zcm::vec3 &x, const zcm::vec3 &y) noexcept
{
    return { x.x != y.x, x.y != y.y, x.z != y.z };
}

zcm::bvec4 zcm_vectorcall zcm::notEqual(zcm::vec4 x, zcm::vec4 y) noexcept
{
    return { x.x != y.x, x.y != y.y, x.z != y.z, x.w != y.w };
}

zcm::bvec4 zcm::notEqual(const zcm::quat &x, const zcm::quat &y) noexcept
{
    return { x.x != y.x, x.y != y.y, x.z != y.z, x.w != y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::notEqual(zcm::bvec2 x, zcm::bvec2 y) noexcept
{
    return { x.x != y.x, x.y != y.y };
}

zcm::bvec3 zcm::notEqual(zcm::bvec3 x, zcm::bvec3 y) noexcept
{
    return { x.x != y.x, x.y != y.y, x.z != y.z };
}

zcm::bvec4 zcm::notEqual(zcm::bvec4 x, zcm::bvec4 y) noexcept
{
    return { x.x != y.x, x.y != y.y, x.z != y.z, x.w != y.w };
}


//-----------------------------------------------------------------------------------------------------

bool zcm::all(zcm::bvec2 x) noexcept
{
    return x.x && x.y;
}

bool zcm::all(zcm::bvec3 x) noexcept
{
    return x.x && x.y && x.z;
}

bool zcm::all(zcm::bvec4 x) noexcept
{
    return x.x && x.y && x.z && x.w;
}


//-----------------------------------------------------------------------------------------------------


bool zcm::any(zcm::bvec2 x) noexcept
{
    return x.x || x.y;
}

bool zcm::any(zcm::bvec3 x) noexcept
{
    return  x.x || x.y || x.z;
}

bool zcm::any(bvec4 x) noexcept
{
    return x.x || x.y || x.z || x.w;
}

