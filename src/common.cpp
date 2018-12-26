#include <zcm/common.hpp>

//FIXME: Do not use stl or libc
#include <cmath>
#include <algorithm>

#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/bvec2.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/bvec4.hpp>


float zcm::abs(float x)
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


float zcm::ceil(float x)
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


float zcm::clamp(float x, float minVal, float maxVal)
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


float zcm::floor(float x)
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


float zcm::fma(float a, float b, float c)
{
    return std::fma(a, b, c);
}

zcm::vec2 zcm::fma(const zcm::vec2 &a, const zcm::vec2 &b, const zcm::vec2 &c)
{
    return vec2{fma(a.x, b.x, c.x), fma(a.y, b.y, c.y)};
}

zcm::vec3 zcm::fma(const zcm::vec3 &a, const zcm::vec3 &b, const zcm::vec3 &c)
{
    return vec3{fma(a.x, b.x, c.x), fma(a.y, b.y, c.y), fma(a.z, b.z, c.z)};
}

zcm::vec4 zcm::fma(const zcm::vec4 &a, const zcm::vec4 &b, const zcm::vec4 &c)
{
    return vec4{fma(a.x, b.x, c.x), fma(a.y, b.y, c.y), fma(a.z, b.z, c.z), fma(a.w, b.w, c.w)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::fract(float x)
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


float zcm::max(float x, float y)
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


float zcm::min(float x, float y)
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


float zcm::mod(float x, float y)
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

zcm::vec2 zcm::mod(const zcm::vec2 &x, float y)
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y) };
}

zcm::vec3 zcm::mod(const zcm::vec3 &x, float y)
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y), zcm::mod(x.z, y) };
}

zcm::vec4 zcm::mod(const zcm::vec4 &x, float y)
{
    return { zcm::mod(x.x, y), zcm::mod(x.y, y), zcm::mod(x.z, y), zcm::mod(x.w, y) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::round(float x)
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


float zcm::roundEven(float x)
{
    return std::nearbyint(x * 0.5f) * 2.0f;
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


float zcm::sign(float x)
{
    if(x == 0.0f) {
        return 0.0f;
    }
    if(x > 0.0f) {
        return 1.0f;
    }
    return -1.0f;
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


float zcm::trunc(float x)
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


//-----------------------------------------------------------------------------------------------------


float zcm::smoothstep(float edge0, float edge1, float x)
{
    float const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}

zcm::vec2 zcm::smoothstep(const zcm::vec2& edge0, const zcm::vec2& edge1, const zcm::vec2& x)
{
    vec2 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}

zcm::vec3 zcm::smoothstep(const zcm::vec3& edge0, const zcm::vec3& edge1, const zcm::vec3& x)
{
    vec3 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}


zcm::vec4 zcm::smoothstep(const zcm::vec4& edge0, const zcm::vec4& edge1, const zcm::vec4& x)
{
    vec4 const tmp(clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f));
    return tmp * tmp * (3.f - 2.f * tmp);
}


//-----------------------------------------------------------------------------------------------------


float zcm::step(float edge, float x)
{
    return x < edge ? 0.0f : 1.0f;
}

zcm::vec2 zcm::step(const zcm::vec2 &edge, const zcm::vec2 & t)
{
    return vec2(step(edge.x, t.x), step(edge.y, t.y));
}

zcm::vec3 zcm::step(const zcm::vec3 &edge, const zcm::vec3 & t)
{
    return vec3(step(edge.x, t.x), step(edge.y, t.y), step(edge.z, t.z));
}

zcm::vec4 zcm::step(const zcm::vec4 &edge, const zcm::vec4 & t)
{
    return vec4(step(edge.x, t.x), step(edge.y, t.y), step(edge.z, t.z), step(edge.w, t.w));
}


//-----------------------------------------------------------------------------------------------------


float zcm::mix(float x, float y, float t)
{
    return x + t * (y - x);
}

zcm::vec2 zcm::mix(const zcm::vec2 &x, const zcm::vec2 &y, const zcm::vec2 &t)
{
    return vec2{mix(x.x, y.x, t.x), mix(x.y, y.y, t.y)};
}

zcm::vec3 zcm::mix(const zcm::vec3 &x, const zcm::vec3 &y, const zcm::vec3 &t)
{
    return vec3{mix(x.x, y.x, t.x), mix(x.y, y.y, t.y), mix(x.z, y.z, t.z)};
}

zcm::vec4 zcm::mix(const zcm::vec4 &x, const zcm::vec4 &y, const zcm::vec4 &t)
{
    return vec4{mix(x.x, y.x, t.x), mix(x.y, y.y, t.y), mix(x.z, y.z, t.z), mix(x.w, y.w, t.w)};
}


//-----------------------------------------------------------------------------------------------------


bool zcm::isinf(float x)
{
    return std::isinf(x);
}

zcm::bvec2 zcm::isinf(const zcm::vec2 &x)
{
    return { isinf(x.x), isinf(x.y) };
}

zcm::bvec3 zcm::isinf(const zcm::vec3 &x)
{
    return { isinf(x.x), isinf(x.y), isinf(x.z) };
}

zcm::bvec4 zcm::isinf(const zcm::vec4 &x)
{
    return { isinf(x.x), isinf(x.y), isinf(x.z), isinf(x.w) };
}


//-----------------------------------------------------------------------------------------------------


bool zcm::isnan(float x)
{
    return std::isnan(x);
}

zcm::bvec2 zcm::isnan(const zcm::vec2 &x)
{
    return { isnan(x.x), isnan(x.y) };
}

zcm::bvec3 zcm::isnan(const zcm::vec3 &x)
{
    return { isnan(x.x), isnan(x.y), isnan(x.z) };
}

zcm::bvec4 zcm::isnan(const zcm::vec4 &x)
{
    return { isnan(x.x), isnan(x.y), isnan(x.z), isnan(x.w) };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::lessThan(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x < y.x, x.y < y.y };
}

zcm::bvec3 zcm::lessThan(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x < y.x, x.y < y.y, x.z < y.z };
}

zcm::bvec4 zcm::lessThan(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x < y.x, x.y < y.y, x.z < y.z, x.w < y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::lessThanEqual(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x <= y.x, x.y <= y.y };
}

zcm::bvec3 zcm::lessThanEqual(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x <= y.x, x.y <= y.y, x.z <= y.z };
}

zcm::bvec4 zcm::lessThanEqual(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x <= y.x, x.y <= y.y, x.z <= y.z, x.w <= y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::greaterThan(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x > y.x, x.y > y.y };
}

zcm::bvec3 zcm::greaterThan(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x > y.x, x.y > y.y, x.z > y.z };
}

zcm::bvec4 zcm::greaterThan(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x > y.x, x.y > y.y, x.z > y.z, x.w > y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::greaterThanEqual(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x >= y.x, x.y >= y.y };
}

zcm::bvec3 zcm::greaterThanEqual(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x >= y.x, x.y >= y.y, x.z >= y.z };
}

zcm::bvec4 zcm::greaterThanEqual(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x >= y.x, x.y >= y.y, x.z >= y.z, x.w >= y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::equal(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x == y.x, x.y == y.y };
}

zcm::bvec3 zcm::equal(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x == y.x, x.y == y.y, x.z == y.z };
}

zcm::bvec4 zcm::equal(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x == y.x, x.y == y.y, x.z == y.z, x.w == y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::equal(const zcm::bvec2 &x, const zcm::bvec2 &y)
{
    return { x.x == y.x, x.y == y.y };
}

zcm::bvec3 zcm::equal(const zcm::bvec3 &x, const zcm::bvec3 &y)
{
    return { x.x == y.x, x.y == y.y, x.z == y.z };
}

zcm::bvec4 zcm::equal(const zcm::bvec4 &x, const zcm::bvec4 &y)
{
    return { x.x == y.x, x.y == y.y, x.z == y.z, x.w == y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::notEqual(const zcm::vec2 &x, const zcm::vec2 &y)
{
    return { x.x != y.x, x.y != y.y };
}

zcm::bvec3 zcm::notEqual(const zcm::vec3 &x, const zcm::vec3 &y)
{
    return { x.x != y.x, x.y != y.y, x.z != y.z };
}

zcm::bvec4 zcm::notEqual(const zcm::vec4 &x, const zcm::vec4 &y)
{
    return { x.x != y.x, x.y != y.y, x.z != y.z, x.w != y.w };
}


//-----------------------------------------------------------------------------------------------------


zcm::bvec2 zcm::notEqual(const zcm::bvec2 &x, const zcm::bvec2 &y)
{
    return { x.x != y.x, x.y != y.y };
}

zcm::bvec3 zcm::notEqual(const zcm::bvec3 &x, const zcm::bvec3 &y)
{
    return { x.x != y.x, x.y != y.y, x.z != y.z };
}

zcm::bvec4 zcm::notEqual(const zcm::bvec4 &x, const zcm::bvec4 &y)
{
    return { x.x != y.x, x.y != y.y, x.z != y.z, x.w != y.w };
}


//-----------------------------------------------------------------------------------------------------

bool zcm::all(const zcm::bvec2 &x)
{
    return x.x && x.y;
}

bool zcm::all(const zcm::bvec3 &x)
{
    return x.x && x.y && x.z;
}

bool zcm::all(const zcm::bvec4 &x)
{
    return x.x && x.y && x.z && x.w;
}


//-----------------------------------------------------------------------------------------------------


bool zcm::any(const zcm::bvec2 &x)
{
    return x.x || x.y;
}

bool zcm::any(const zcm::bvec3 &x)
{
    return  x.x || x.y || x.z;
}

bool zcm::any(const zcm::bvec4 &x)
{
    return x.x || x.y || x.z || x.w;
}


//-----------------------------------------------------------------------------------------------------


float zcm::select(bool t, float x, float y)
{
    return t ? x : y;
}

zcm::vec2 zcm::select(zcm::bvec2 t, zcm::vec2 x, zcm::vec2 y)
{
    return { select(t.x, x.x, y.x),  select(t.y, x.y, y.y) };
}

zcm::vec3 zcm::select(zcm::bvec3 t, zcm::vec3 x, zcm::vec3 y)
{
    return { select(t.x, x.x, y.x),  select(t.y, x.y, y.y), select(t.z, x.z, y.z) };
}

zcm::vec4 zcm::select(zcm::bvec4 t, zcm::vec4 x, zcm::vec4 y)
{
    return { select(t.x, x.x, y.x),  select(t.y, x.y, y.y), select(t.z, x.z, y.z), select(t.w, x.w, y.w) };
}
