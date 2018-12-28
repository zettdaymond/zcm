#pragma once

namespace zcm
{
    class bvec2;
    class bvec3;
    class bvec4;
    class vec2;
    class vec3;
    class vec4;

    float abs (float x) noexcept;
    vec2  abs (const vec2& x) noexcept;
    vec3  abs (const vec3& x) noexcept;
    vec4  abs (const vec4& x) noexcept;

    bool  all (const bvec2& x) noexcept;
    bool  all (const bvec3& x) noexcept;
    bool  all (const bvec4& x) noexcept;

    bool  any (const bvec2& x) noexcept;
    bool  any (const bvec3& x) noexcept;
    bool  any (const bvec4& x) noexcept;

    float ceil (float x) noexcept;
    vec2  ceil (const vec2& x) noexcept;
    vec3  ceil (const vec3& x) noexcept;
    vec4  ceil (const vec4& x) noexcept;

    float clamp (float x, float minVal, float maxVal) noexcept;
    vec2  clamp (const vec2& x, const vec2& minVal, const vec2& maxVal) noexcept;
    vec3  clamp (const vec3& x, const vec3& minVal, const vec3& maxVal) noexcept;
    vec4  clamp (const vec4& x, const vec4& minVal, const vec4& maxVal) noexcept;

    //TODO: genIType 	floatBitsToInt (genType const &value);
    //TODO: genUType 	floatBitsToUint (genType const &value)
    //TODO: genType 	intBitsToFloat (genIType const &value)
    //TODO: genType 	uintBitsToFloat (genUType const &value);

    float floor (float x) noexcept;
    vec2  floor (const vec2& x) noexcept;
    vec3  floor (const vec3& x) noexcept;
    vec4  floor (const vec4& x) noexcept;

    float fma   (float a, float b, float c) noexcept;
    vec2  fma   (const vec2& a, const vec2& b, const vec2& c) noexcept;
    vec3  fma   (const vec3& a, const vec3& b, const vec3& c) noexcept;
    vec4  fma   (const vec4& a, const vec4& b, const vec4& c) noexcept;

    float fract (float x) noexcept;
    vec2  fract (const vec2& x) noexcept;
    vec3  fract (const vec3& x) noexcept;
    vec4  fract (const vec4& x) noexcept;

    //TODO: genType 	frexp (genType const &x, genIType &exp)
    //TODO: genType 	ldexp (genType const &x, genIType const &exp)

    bool  isinf (float x) noexcept;
    bvec2 isinf (const vec2& x) noexcept;
    bvec3 isinf (const vec3& x) noexcept;
    bvec4 isinf (const vec4& x) noexcept;

    bool  isnan (float x) noexcept;
    bvec2 isnan (const vec2& x) noexcept;
    bvec3 isnan (const vec3& x) noexcept;
    bvec4 isnan (const vec4& x) noexcept;

    float max (float x, float y) noexcept;
    vec2  max (const vec2& x, const vec2& y) noexcept;
    vec3  max (const vec3& x, const vec3& y) noexcept;
    vec4  max (const vec4& x, const vec4& y) noexcept;

    float min (float x, float y) noexcept;
    vec2  min (const vec2& x, const vec2& y) noexcept;
    vec3  min (const vec3& x, const vec3& y) noexcept;
    vec4  min (const vec4& x, const vec4& y) noexcept;

    float mod (float x, float y) noexcept;
    vec2  mod (const vec2& x, const vec2& y) noexcept;
    vec3  mod (const vec3& x, const vec3& y) noexcept;
    vec4  mod (const vec4& x, const vec4& y) noexcept;

    vec2  mod (const vec2& x, float y) noexcept;
    vec3  mod (const vec3& x, float y) noexcept;
    vec4  mod (const vec4& x, float y) noexcept;

    float round (float x) noexcept;
    vec2  round (const vec2& x) noexcept;
    vec3  round (const vec3& x) noexcept;
    vec4  round (const vec4& x) noexcept;

    float roundEven (float x) noexcept;
    vec2  roundEven (const vec2& x) noexcept;
    vec3  roundEven (const vec3& x) noexcept;
    vec4  roundEven (const vec4& x) noexcept;

    float sign (float x) noexcept;
    vec2  sign (const vec2& x) noexcept;
    vec3  sign (const vec3& x) noexcept;
    vec4  sign (const vec4& x) noexcept;

    float mix (float x, float y, float t) noexcept;
    vec2  mix (const vec2& x, const vec2& y, const vec2& t) noexcept;
    vec3  mix (const vec3& x, const vec3& y, const vec3 &t) noexcept;
    vec4  mix (const vec4& x, const vec4& y, const vec4 &t) noexcept;

    float mix (float x, float y, bool t) noexcept;
    vec2  mix (const vec2& x, const vec2& y, const bvec2& t) noexcept;
    vec3  mix (const vec3& x, const vec3& y, const bvec3 &t) noexcept;
    vec4  mix (const vec4& x, const vec4& y, const bvec4 &t) noexcept;

    float step (float edge, float x) noexcept;
    vec2  step (const vec2& edge, const vec2 & x) noexcept;
    vec3  step (const vec3& edge, const vec3 & x) noexcept;
    vec4  step (const vec4& edge, const vec4 & x) noexcept;

    float smoothstep (float edge0, float edge1, float x) noexcept;
    vec2  smoothstep (const vec2& edge0, const vec2& edge1, const vec2& x) noexcept;
    vec3  smoothstep (const vec3& edge0, const vec3& edge1, const vec3& x) noexcept;
    vec4  smoothstep (const vec4& edge0, const vec4& edge1, const vec4& x) noexcept;

    float trunc (float x) noexcept;
    vec2  trunc (const vec2& x) noexcept;
    vec3  trunc (const vec3& x) noexcept;
    vec4  trunc (const vec4& x) noexcept;


    // relational functions

    bvec2 lessThan (const vec2& x, const vec2& y) noexcept;
    bvec3 lessThan (const vec3& x, const vec3& y) noexcept;
    bvec4 lessThan (const vec4& x, const vec4& y) noexcept;

    bvec2 lessThanEqual (const vec2& x, const vec2& y) noexcept;
    bvec3 lessThanEqual (const vec3& x, const vec3& y) noexcept;
    bvec4 lessThanEqual (const vec4& x, const vec4& y) noexcept;

    bvec2 greaterThan (const vec2& x, const vec2& y) noexcept;
    bvec3 greaterThan (const vec3& x, const vec3& y) noexcept;
    bvec4 greaterThan (const vec4& x, const vec4& y) noexcept;

    bvec2 greaterThanEqual (const vec2& x, const vec2& y) noexcept;
    bvec3 greaterThanEqual (const vec3& x, const vec3& y) noexcept;
    bvec4 greaterThanEqual (const vec4& x, const vec4& y) noexcept;

    bvec2 equal (const bvec2& x, const bvec2& y) noexcept;
    bvec3 equal (const bvec3& x, const bvec3& y) noexcept;
    bvec4 equal (const bvec4& x, const bvec4& y) noexcept;

    bvec2 equal (const vec2& x, const vec2& y) noexcept;
    bvec3 equal (const vec3& x, const vec3& y) noexcept;
    bvec4 equal (const vec4& x, const vec4& y) noexcept;

    bvec2 notEqual (const bvec2& x, const bvec2& y) noexcept;
    bvec3 notEqual (const bvec3& x, const bvec3& y) noexcept;
    bvec4 notEqual (const bvec4& x, const bvec4& y) noexcept;

    bvec2 notEqual (const vec2& x, const vec2& y) noexcept;
    bvec3 notEqual (const vec3& x, const vec3& y) noexcept;
    bvec4 notEqual (const vec4& x, const vec4& y) noexcept;





}
