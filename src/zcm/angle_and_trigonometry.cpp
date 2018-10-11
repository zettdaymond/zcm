#include "angle_and_trigonometry.h"

#include "cmath"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#include "detail/utils.hpp"

namespace zcm
{
    namespace detail
    {
        float degreesf(float radians)
        {
            return radians * 57.2957795130823f;
        }

        float radiansf(float degrees)
        {
            return degrees * 0.01745329251994f;
        }
    }
}


float zcm::cos(const float angle)
{
    return detail::applyOp(angle,cosf);
}

zcm::vec2 zcm::cos(const zcm::vec2& angle)
{
    return detail::applyOp(angle,cosf);
}

zcm::vec3 zcm::cos(const zcm::vec3& angle)
{
    return detail::applyOp(angle,cosf);
}

zcm::vec4 zcm::cos(const zcm::vec4& angle)
{
    return detail::applyOp(angle,cosf);
}

//---------------------------------------------------------------------------------------------------

float zcm::sin(float angle)
{
    return detail::applyOp(angle,sinf);
}

zcm::vec2 zcm::sin(const zcm::vec2& angle)
{
    return detail::applyOp(angle,sinf);
}

zcm::vec3 zcm::sin(const zcm::vec3& angle)
{
    return detail::applyOp(angle,sinf);
}

zcm::vec4 zcm::sin(const zcm::vec4& angle)
{
    return detail::applyOp(angle,sinf);
}

//---------------------------------------------------------------------------------------------------


float zcm::acos(const float x)
{
    return detail::applyOp(x,acosf);
}

zcm::vec2 zcm::acos(const zcm::vec2& x)
{
    return detail::applyOp(x,acosf);
}

zcm::vec3 zcm::acos(const zcm::vec3& x)
{
    return detail::applyOp(x,acosf);
}

zcm::vec4 zcm::acos(const zcm::vec4& x)
{
    return detail::applyOp(x,acosf);
}

//---------------------------------------------------------------------------------------------------


float zcm::acosh(const float x)
{
    return detail::applyOp(x,acoshf);
}

zcm::vec2 zcm::acosh(const zcm::vec2& x)
{
    return detail::applyOp(x,acoshf);
}

zcm::vec3 zcm::acosh(const zcm::vec3& x)
{
    return detail::applyOp(x,acoshf);
}

zcm::vec4 zcm::acosh(const zcm::vec4& x)
{
    return detail::applyOp(x,acoshf);
}

//---------------------------------------------------------------------------------------------------



float zcm::asin(const float x)
{
    return detail::applyOp(x,asinf);
}

zcm::vec2 zcm::asin(const zcm::vec2& x)
{
    return detail::applyOp(x,asinf);
}

zcm::vec3 zcm::asin(const zcm::vec3& x)
{
    return detail::applyOp(x,asinf);
}

zcm::vec4 zcm::asin(const zcm::vec4& x)
{
    return detail::applyOp(x,asinf);
}

//---------------------------------------------------------------------------------------------------

float zcm::asinh(const float x)
{
    return detail::applyOp(x,asinhf);
}

zcm::vec2 zcm::asinh(const zcm::vec2& x)
{
    return detail::applyOp(x,asinhf);
}

zcm::vec3 zcm::asinh(const zcm::vec3& x)
{
    return detail::applyOp(x,asinhf);
}

zcm::vec4 zcm::asinh(const zcm::vec4& x)
{
    return detail::applyOp(x,asinhf);
}

//---------------------------------------------------------------------------------------------------

float zcm::atan(const float y, const float x)
{
    return atan2f(y,x);
}

zcm::vec2 zcm::atan(const zcm::vec2& y, const zcm::vec2& x)
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]) };
}

zcm::vec3 zcm::atan(const zcm::vec3& y, const zcm::vec3& x)
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]), atan2f(y[2], x[2]) };
}

zcm::vec4 zcm::atan(const zcm::vec4& y, const zcm::vec4& x)
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]), atan2f(y[2], x[2]), atan2f(y[3], x[3]) };
}

//---------------------------------------------------------------------------------------------------


float zcm::atanh(const float x)
{
    return detail::applyOp(x,atanhf);
}

zcm::vec2 zcm::atanh(const zcm::vec2& x)
{
    return detail::applyOp(x,atanhf);
}

zcm::vec3 zcm::atanh(const zcm::vec3& x)
{
    return detail::applyOp(x,atanhf);
}

zcm::vec4 zcm::atanh(const zcm::vec4& x)
{
    return detail::applyOp(x,atanhf);
}

//---------------------------------------------------------------------------------------------------



float zcm::cosh(const float angle)
{
    return detail::applyOp(angle,coshf);
}

zcm::vec2 zcm::cosh(const zcm::vec2& angle)
{
    return detail::applyOp(angle,coshf);
}

zcm::vec3 zcm::cosh(const zcm::vec3& angle)
{
    return detail::applyOp(angle,coshf);
}

zcm::vec4 zcm::cosh(const zcm::vec4& angle)
{
    return detail::applyOp(angle,coshf);
}

//---------------------------------------------------------------------------------------------------

float zcm::degrees(const float radians)
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec2 zcm::degrees(const zcm::vec2& radians)
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec3 zcm::degrees(const zcm::vec3& radians)
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec4 zcm::degrees(const zcm::vec4& radians)
{
    return detail::applyOp(radians, detail::degreesf);
}

//---------------------------------------------------------------------------------------------------

float zcm::radians(const float degrees)
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec2 zcm::radians(const zcm::vec2& degrees)
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec3 zcm::radians(const zcm::vec3& degrees)
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec4 zcm::radians(const zcm::vec4& degrees)
{
    return detail::applyOp(degrees, detail::radiansf);
}

//---------------------------------------------------------------------------------------------------


float zcm::sinh(const float angle)
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec2 zcm::sinh(const zcm::vec2& angle)
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec3 zcm::sinh(const zcm::vec3& angle)
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec4 zcm::sinh(const zcm::vec4& angle)
{
    return detail::applyOp(angle, sinhf);
}


//---------------------------------------------------------------------------------------------------


float zcm::tan(const float angle)
{
    return detail::applyOp(angle, tanf);
}

zcm::vec2 zcm::tan(const zcm::vec2& angle)
{
    return detail::applyOp(angle, tanf);
}

zcm::vec3 zcm::tan(const zcm::vec3& angle)
{
    return detail::applyOp(angle, tanf);
}

zcm::vec4 zcm::tan(const zcm::vec4& angle)
{
    return detail::applyOp(angle, tanf);
}


//---------------------------------------------------------------------------------------------------


float zcm::tanh(const float angle)
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec2 zcm::tanh(const zcm::vec2& angle)
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec3 zcm::tanh(const zcm::vec3& angle)
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec4 zcm::tanh(const zcm::vec4& angle)
{
    return detail::applyOp(angle, tanhf);
}


//---------------------------------------------------------------------------------------------------
