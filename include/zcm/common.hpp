#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;

    float abs (float x);
    vec2  abs (const vec2& x);
    vec3  abs (const vec3& x);
    vec4  abs (const vec4& x);

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

    //TODO: genType 	intBitsToFloat (genIType const &value)

    //TODO: genType::bool_type 	isinf (genType const &x)

    //TODO: genType::bool_type 	isnan (genType const &x)

    //TODO: genType 	ldexp (genType const &x, genIType const &exp)

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

    //TODO: genType 	uintBitsToFloat (genUType const &value);

}
