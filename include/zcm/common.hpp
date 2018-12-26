#pragma once

namespace zcm
{
    class bvec2;
    class bvec3;
    class bvec4;
    class vec2;
    class vec3;
    class vec4;

    float abs (float x);
    vec2  abs (const vec2& x);
    vec3  abs (const vec3& x);
    vec4  abs (const vec4& x);

    bool  all (const bvec2& x);
    bool  all (const bvec3& x);
    bool  all (const bvec4& x);

    bool  any (const bvec2& x);
    bool  any (const bvec3& x);
    bool  any (const bvec4& x);

    float ceil (float x);
    vec2  ceil (const vec2& x);
    vec3  ceil (const vec3& x);
    vec4  ceil (const vec4& x);

    float clamp (float x, float minVal, float maxVal);
    vec2  clamp (const vec2& x, const vec2& minVal, const vec2& maxVal);
    vec3  clamp (const vec3& x, const vec3& minVal, const vec3& maxVal);
    vec4  clamp (const vec4& x, const vec4& minVal, const vec4& maxVal);

    //TODO: genIType 	floatBitsToInt (genType const &value);
    //TODO: genUType 	floatBitsToUint (genType const &value)
    //TODO: genType 	intBitsToFloat (genIType const &value)
    //TODO: genType 	uintBitsToFloat (genUType const &value);

    float floor (float x);
    vec2  floor (const vec2& x);
    vec3  floor (const vec3& x);
    vec4  floor (const vec4& x);

    float fma   (float a, float b, float c);
    vec2  fma   (const vec2& a, const vec2& b, const vec2& c);
    vec3  fma   (const vec3& a, const vec3& b, const vec3& c);
    vec4  fma   (const vec4& a, const vec4& b, const vec4& c);

    float fract (float x);
    vec2  fract (const vec2& x);
    vec3  fract (const vec3& x);
    vec4  fract (const vec4& x);

    //TODO: genType 	frexp (genType const &x, genIType &exp)
    //TODO: genType 	ldexp (genType const &x, genIType const &exp)

    bool  isinf (float x);
    bvec2 isinf (const vec2& x);
    bvec3 isinf (const vec3& x);
    bvec4 isinf (const vec4& x);

    bool  isnan (float x);
    bvec2 isnan (const vec2& x);
    bvec3 isnan (const vec3& x);
    bvec4 isnan (const vec4& x);

    float max (float x, float y);
    vec2  max (const vec2& x, const vec2& y);
    vec3  max (const vec3& x, const vec3& y);
    vec4  max (const vec4& x, const vec4& y);

    float min (float x, float y);
    vec2  min (const vec2& x, const vec2& y);
    vec3  min (const vec3& x, const vec3& y);
    vec4  min (const vec4& x, const vec4& y);

    float mod (float x, float y);
    vec2  mod (const vec2& x, const vec2& y);
    vec3  mod (const vec3& x, const vec3& y);
    vec4  mod (const vec4& x, const vec4& y);

    vec2  mod (const vec2& x, float y);
    vec3  mod (const vec3& x, float y);
    vec4  mod (const vec4& x, float y);

    float round (float x);
    vec2  round (const vec2& x);
    vec3  round (const vec3& x);
    vec4  round (const vec4& x);

    float roundEven (float x);
    vec2  roundEven (const vec2& x);
    vec3  roundEven (const vec3& x);
    vec4  roundEven (const vec4& x);

    float sign (float x);
    vec2  sign (const vec2& x);
    vec3  sign (const vec3& x);
    vec4  sign (const vec4& x);

    float mix (float x, float y, float t);
    vec2  mix (const vec2& x, const vec2& y, const vec2& t);
    vec3  mix (const vec3& x, const vec3& y, const vec3 &t);
    vec4  mix (const vec4& x, const vec4& y, const vec4 &t);

    float step (float edge, float x);
    vec2  step (const vec2& edge, const vec2 & x);
    vec3  step (const vec3& edge, const vec3 & x);
    vec4  step (const vec4& edge, const vec4 & x);

    float smoothstep (float edge0, float edge1, float x);
    vec2  smoothstep (const vec2& edge0, const vec2& edge1, const vec2& x);
    vec3  smoothstep (const vec3& edge0, const vec3& edge1, const vec3& x);
    vec4  smoothstep (const vec4& edge0, const vec4& edge1, const vec4& x);

    float trunc (float x);
    vec2  trunc (const vec2& x);
    vec3  trunc (const vec3& x);
    vec4  trunc (const vec4& x);


    // relational functions

    bvec2 lessThan (const vec2& x, const vec2& y);
    bvec3 lessThan (const vec3& x, const vec3& y);
    bvec4 lessThan (const vec4& x, const vec4& y);

    bvec2 lessThanEqual (const vec2& x, const vec2& y);
    bvec3 lessThanEqual (const vec3& x, const vec3& y);
    bvec4 lessThanEqual (const vec4& x, const vec4& y);

    bvec2 greaterThan (const vec2& x, const vec2& y);
    bvec3 greaterThan (const vec3& x, const vec3& y);
    bvec4 greaterThan (const vec4& x, const vec4& y);

    bvec2 greaterThanEqual (const vec2& x, const vec2& y);
    bvec3 greaterThanEqual (const vec3& x, const vec3& y);
    bvec4 greaterThanEqual (const vec4& x, const vec4& y);

    bvec2 equal (const bvec2& x, const bvec2& y);
    bvec3 equal (const bvec3& x, const bvec3& y);
    bvec4 equal (const bvec4& x, const bvec4& y);

    bvec2 equal (const vec2& x, const vec2& y);
    bvec3 equal (const vec3& x, const vec3& y);
    bvec4 equal (const vec4& x, const vec4& y);

    bvec2 notEqual (const bvec2& x, const bvec2& y);
    bvec3 notEqual (const bvec3& x, const bvec3& y);
    bvec4 notEqual (const bvec4& x, const bvec4& y);

    bvec2 notEqual (const vec2& x, const vec2& y);
    bvec3 notEqual (const vec3& x, const vec3& y);
    bvec4 notEqual (const vec4& x, const vec4& y);

    // simd extension
    float select (bool t, float x, float y);
    vec2  select (bvec2 t, vec2 x, vec2 y);
    vec3  select (bvec3 t, vec3 x, vec3 y);
    vec4  select (bvec4 t, vec4 x, vec4 y);



}
