#pragma once

namespace zcm
{
    class vec2;
    class vec3;
    class vec4;

    float abs (const float x);
    vec2  abs (const vec2& x);
    vec3  abs (const vec3& x);
    vec4  abs (const vec4& x);

    float ceil (const float x);
    vec2  ceil (const vec2& x);
    vec3  ceil (const vec3& x);
    vec4  ceil (const vec4& x);

    float clamp (const float x, const float minVal, const float maxVal);
    vec2  clamp (const vec2& x, const vec2& minVal, const vec2& maxVal);
    vec3  clamp (const vec3& x, const vec3& minVal, const vec3& maxVal);
    vec4  clamp (const vec4& x, const vec4& minVal, const vec4& maxVal);


    //TODO: genIType 	floatBitsToInt (genType const &value);
    //TODO: genUType 	floatBitsToUint (genType const &value)

    float floor (const float x);
    vec2  floor (const vec2& x);
    vec3  floor (const vec3& x);
    vec4  floor (const vec4& x);

    //TODO:    genType 	fma (genType const &a, genType const &b, genType const &c)

    float fract (const float x);
    vec2  fract (const vec2& x);
    vec3  fract (const vec3& x);
    vec4  fract (const vec4& x);

    //TODO: genType 	frexp (genType const &x, genIType &exp)

    //TODO: genType 	intBitsToFloat (genIType const &value)

    //TODO: genType::bool_type 	isinf (genType const &x)

    //TODO: genType::bool_type 	isnan (genType const &x)

    //TODO: genType 	ldexp (genType const &x, genIType const &exp)

    float max (const float x,const float y);
    vec2  max (const vec2& x,const vec2& y);
    vec3  max (const vec3& x,const vec3& y);
    vec4  max (const vec4& x,const vec4& y);

    float min (const float x,const float y);
    vec2  min (const vec2& x,const vec2& y);
    vec3  min (const vec3& x,const vec3& y);
    vec4  min (const vec4& x,const vec4& y);



    //TODO: genTypeT 	mix (genTypeT const &x, genTypeT const &y, genTypeU const &a)

    float mod (const float x,const float y);
    vec2  mod (const vec2& x,const vec2& y);
    vec3  mod (const vec3& x,const vec3& y);
    vec4  mod (const vec4& x,const vec4& y);

    //TODO: genType 	mod (genType const &x, typename genType::value_type const &y)

    //TODO: genType 	modf (genType const &x, genType &i)

    float round (const float x);
    vec2  round (const vec2& x);
    vec3  round (const vec3& x);
    vec4  round (const vec4& x);

    float roundEven (const float x);
    vec2  roundEven (const vec2& x);
    vec3  roundEven (const vec3& x);
    vec4  roundEven (const vec4& x);

    float sign (const float x);
    vec2  sign (const vec2& x);
    vec3  sign (const vec3& x);
    vec4  sign (const vec4& x);


    float smoothstep (const float edge0, const float edge1, const float x);
    vec2  smoothstep (const vec2& edge0, const vec2& edge1, const vec2& x);
    vec3  smoothstep (const vec3& edge0, const vec3& edge1, const vec3& x);
    vec4  smoothstep (const vec4& edge0, const vec4& edge1, const vec4& x);

    float step (const float& edge, const float & x);
//    vec2  step (const vec2& edge, const vec2 & x);
//    vec3  step (const vec3& edge, const vec3 & x);
//    vec4  step (const vec4& edge, const vec4 & x);

    float trunc (const float x);
    vec2  trunc (const vec2& x);
    vec3  trunc (const vec3& x);
    vec4  trunc (const vec4& x);

    //TODO: genType 	uintBitsToFloat (genUType const &value);

}
