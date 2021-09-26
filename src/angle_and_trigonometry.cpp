#include <cmath>
#include <zcm/angle_and_trigonometry.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include "detail/utils.hpp"

namespace zcm
{
    namespace detail
    {
        namespace  {

            float degreesf(float radians) noexcept
            {
                return radians * 57.2957795130823f;
            }

            float radiansf(float degrees) noexcept
            {
                return degrees * 0.01745329251994f;
            }

        }
    }
}


float zcm::cos(float angle) noexcept
{
    return detail::applyOp(angle,cosf);
}

zcm::vec2 zcm::cos(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle,cosf);
}

zcm::vec3 zcm::cos(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle,cosf);
}

zcm::vec4 zcm_vectorcall zcm::cos(vec4 angle) noexcept
{
    return detail::applyOp(angle,cosf);
}

//---------------------------------------------------------------------------------------------------

float zcm::sin(float angle) noexcept
{
    return detail::applyOp(angle,sinf);
}

zcm::vec2 zcm::sin(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle,sinf);
}

zcm::vec3 zcm::sin(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle,sinf);
}

zcm::vec4 zcm_vectorcall zcm::sin(vec4 angle) noexcept
{
    return detail::applyOp(angle,sinf);
}

//---------------------------------------------------------------------------------------------------


float zcm::acos(float x) noexcept
{
    return detail::applyOp(x,acosf);
}

zcm::vec2 zcm::acos(const zcm::vec2& x) noexcept
{
    return detail::applyOp(x,acosf);
}

zcm::vec3 zcm::acos(const zcm::vec3& x) noexcept
{
    return detail::applyOp(x,acosf);
}

zcm::vec4 zcm_vectorcall zcm::acos(vec4 x) noexcept
{
    return detail::applyOp(x,acosf);
}

//---------------------------------------------------------------------------------------------------


float zcm::acosh(float x) noexcept
{
    return detail::applyOp(x,acoshf);
}

zcm::vec2 zcm::acosh(const zcm::vec2& x) noexcept
{
    return detail::applyOp(x,acoshf);
}

zcm::vec3 zcm::acosh(const zcm::vec3& x) noexcept
{
    return detail::applyOp(x,acoshf);
}

zcm::vec4 zcm_vectorcall zcm::acosh(vec4 x) noexcept
{
    return detail::applyOp(x,acoshf);
}

//---------------------------------------------------------------------------------------------------



float zcm::asin(float x) noexcept
{
    return detail::applyOp(x,asinf);
}

zcm::vec2 zcm::asin(const zcm::vec2& x) noexcept
{
    return detail::applyOp(x,asinf);
}

zcm::vec3 zcm::asin(const zcm::vec3& x) noexcept
{
    return detail::applyOp(x,asinf);
}

zcm::vec4 zcm_vectorcall zcm::asin(vec4 x) noexcept
{
    return detail::applyOp(x,asinf);
}

//---------------------------------------------------------------------------------------------------

float zcm::asinh(float x) noexcept
{
    return detail::applyOp(x,asinhf);
}

zcm::vec2 zcm::asinh(const zcm::vec2& x) noexcept
{
    return detail::applyOp(x,asinhf);
}

zcm::vec3 zcm::asinh(const zcm::vec3& x) noexcept
{
    return detail::applyOp(x,asinhf);
}

zcm::vec4 zcm_vectorcall zcm::asinh(vec4 x) noexcept
{
    return detail::applyOp(x,asinhf);
}

//---------------------------------------------------------------------------------------------------

float zcm::atan(float y, float x) noexcept
{
    return atan2f(y,x);
}

zcm::vec2 zcm::atan(const zcm::vec2& y, const zcm::vec2& x) noexcept
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]) };
}

zcm::vec3 zcm::atan(const zcm::vec3& y, const zcm::vec3& x) noexcept
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]), atan2f(y[2], x[2]) };
}

zcm::vec4 zcm_vectorcall zcm::atan(vec4 y, vec4 x) noexcept
{
    return { atan2f(y[0],x[0]), atan2f(y[1], x[1]), atan2f(y[2], x[2]), atan2f(y[3], x[3]) };
}

//---------------------------------------------------------------------------------------------------

float zcm::atan(float y_over_x) noexcept
{
    return detail::applyOp(y_over_x,atanf);
}

zcm::vec2 zcm::atan(const zcm::vec2& y_over_x) noexcept
{
    return detail::applyOp(y_over_x,atanf);
}

zcm::vec3 zcm::atan(const zcm::vec3& y_over_x) noexcept
{
    return detail::applyOp(y_over_x,atanf);
}

zcm::vec4 zcm_vectorcall zcm::atan(vec4 y_over_x) noexcept
{
    return detail::applyOp(y_over_x,atanf);
}

//---------------------------------------------------------------------------------------------------


float zcm::atanh(float x) noexcept
{
    return detail::applyOp(x,atanhf);
}

zcm::vec2 zcm::atanh(const zcm::vec2& x) noexcept
{
    return detail::applyOp(x,atanhf);
}

zcm::vec3 zcm::atanh(const zcm::vec3& x) noexcept
{
    return detail::applyOp(x,atanhf);
}

zcm::vec4 zcm_vectorcall zcm::atanh(vec4 x) noexcept
{
    return detail::applyOp(x,atanhf);
}

//---------------------------------------------------------------------------------------------------



float zcm::cosh(float angle) noexcept
{
    return detail::applyOp(angle,coshf);
}

zcm::vec2 zcm::cosh(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle,coshf);
}

zcm::vec3 zcm::cosh(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle,coshf);
}

zcm::vec4 zcm_vectorcall zcm::cosh(vec4 angle) noexcept
{
    return detail::applyOp(angle,coshf);
}

//---------------------------------------------------------------------------------------------------

float zcm::degrees(float radians) noexcept
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec2 zcm::degrees(const zcm::vec2& radians) noexcept
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec3 zcm::degrees(const zcm::vec3& radians) noexcept
{
    return detail::applyOp(radians, detail::degreesf);
}

zcm::vec4 zcm_vectorcall zcm::degrees(vec4 radians) noexcept
{
    return detail::applyOp(radians, detail::degreesf);
}

//---------------------------------------------------------------------------------------------------

float zcm::radians(float degrees) noexcept
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec2 zcm::radians(const zcm::vec2& degrees) noexcept
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec3 zcm::radians(const zcm::vec3& degrees) noexcept
{
    return detail::applyOp(degrees, detail::radiansf);
}

zcm::vec4 zcm_vectorcall zcm::radians(vec4 degrees) noexcept
{
    return detail::applyOp(degrees, detail::radiansf);
}

//---------------------------------------------------------------------------------------------------


float zcm::sinh(float angle) noexcept
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec2 zcm::sinh(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec3 zcm::sinh(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle, sinhf);
}

zcm::vec4 zcm_vectorcall zcm::sinh(vec4 angle) noexcept
{
    return detail::applyOp(angle, sinhf);
}


//---------------------------------------------------------------------------------------------------


float zcm::tan(float angle) noexcept
{
    return detail::applyOp(angle, tanf);
}

zcm::vec2 zcm::tan(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle, tanf);
}

zcm::vec3 zcm::tan(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle, tanf);
}

zcm::vec4 zcm_vectorcall zcm::tan(vec4 angle) noexcept
{
    return detail::applyOp(angle, tanf);
}


//---------------------------------------------------------------------------------------------------


float zcm::tanh(float angle) noexcept
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec2 zcm::tanh(const zcm::vec2& angle) noexcept
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec3 zcm::tanh(const zcm::vec3& angle) noexcept
{
    return detail::applyOp(angle, tanhf);
}

zcm::vec4 zcm_vectorcall zcm::tanh(vec4 angle) noexcept
{
    return detail::applyOp(angle, tanhf);
}


//---------------------------------------------------------------------------------------------------
