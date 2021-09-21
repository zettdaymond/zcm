#include <cmath>
#include <zcm/exponential.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/quat.hpp>


float zcm::sqrt(float x) noexcept
{
    return sqrtf(x);
}

zcm::vec2 zcm::sqrt(const zcm::vec2& x) noexcept
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y) };
}

zcm::vec3 zcm::sqrt(const zcm::vec3& x) noexcept
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y), zcm::sqrt(x.z)};
}

zcm::vec4 zcm::sqrt(const zcm::vec4& x) noexcept
{
    return { zcm::sqrt(x.x), zcm::sqrt(x.y), zcm::sqrt(x.z), zcm::sqrt(x.w)};
}

zcm::quat zcm::sqrt(const zcm::quat &x) noexcept
{
    return {zcm::sqrt(x.w), zcm::sqrt(x.x), zcm::sqrt(x.y), zcm::sqrt(x.z)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::pow(float x, float y) noexcept
{
    return powf(x,y);
}

zcm::vec2 zcm::pow(const zcm::vec2& x, const zcm::vec2& y) noexcept
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y) };
}

zcm::vec3 zcm::pow(const zcm::vec3& x, const zcm::vec3& y) noexcept
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y),  zcm::pow(x.z, y.z)};
}

zcm::vec4 zcm::pow(const zcm::vec4& x, const zcm::vec4& y) noexcept
{
    return { zcm::pow(x.x, y.x), zcm::pow(x.y, y.y),  zcm::pow(x.z, y.z), zcm::pow(x.w, y.w)};
}

zcm::quat zcm::pow(const zcm::quat &x, float y) noexcept
{
    return { zcm::pow(x.w, y), zcm::pow(x.x, y), zcm::pow(x.y, y),  zcm::pow(x.z, y)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::log(float x) noexcept
{
    return logf(x);
}

zcm::vec2 zcm::log(const zcm::vec2& x) noexcept
{
    return { zcm::log(x.x), zcm::log(x.y) };
}

zcm::vec3 zcm::log(const zcm::vec3& x) noexcept
{
    return { zcm::log(x.x), zcm::log(x.y), zcm::log(x.z) };
}

zcm::vec4 zcm::log(const zcm::vec4& x) noexcept
{
    return { zcm::log(x.x), zcm::log(x.y), zcm::log(x.z), zcm::log(x.w) };
}


zcm::quat zcm::log(const zcm::quat &x) noexcept
{
    return { zcm::log(x.w), zcm::log(x.x), zcm::log(x.y), zcm::log(x.z), };
}


//-----------------------------------------------------------------------------------------------------


float zcm::log2(float x) noexcept
{
    return log2f(x);
}

zcm::vec2 zcm::log2(const zcm::vec2& x) noexcept
{
    return { zcm::log2(x.x), zcm::log2(x.y) };
}

zcm::vec3 zcm::log2(const zcm::vec3& x) noexcept
{
    return { zcm::log2(x.x), zcm::log2(x.y), zcm::log2(x.z) };
}

zcm::vec4 zcm::log2(const zcm::vec4& x) noexcept
{
    return { zcm::log2(x.x), zcm::log2(x.y), zcm::log2(x.z), zcm::log2(x.w) };
}


zcm::quat zcm::log2(const zcm::quat &x) noexcept
{
    return { zcm::log2(x.w), zcm::log2(x.x), zcm::log2(x.y), zcm::log2(x.z) };
}


//-----------------------------------------------------------------------------------------------------


float zcm::inversesqrt(float x) noexcept
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec2 zcm::inversesqrt(const zcm::vec2& x) noexcept
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec3 zcm::inversesqrt(const zcm::vec3& x) noexcept
{
    return 1.0f / zcm::sqrt(x);
}

zcm::vec4 zcm::inversesqrt(const zcm::vec4& x) noexcept
{
    return 1.0f / zcm::sqrt(x);
}

zcm::quat zcm::inversesqrt(const zcm::quat &x) noexcept
{
    return 1.0f / zcm::sqrt(x);
}


//-----------------------------------------------------------------------------------------------------


float zcm::exp(float x) noexcept
{
    return expf(x);
}

zcm::vec2 zcm::exp(const zcm::vec2& x) noexcept
{
    return {zcm::exp(x.x), zcm::exp(x.y)};
}

zcm::vec3 zcm::exp(const zcm::vec3& x) noexcept
{
    return {zcm::exp(x.x), zcm::exp(x.y), zcm::exp(x.z)};
}

zcm::vec4 zcm::exp(const zcm::vec4& x) noexcept
{
    return {zcm::exp(x.x), zcm::exp(x.y), zcm::exp(x.z), zcm::exp(x.w)};
}

zcm::quat zcm::exp(const zcm::quat &x) noexcept
{
    return {zcm::exp(x.w), zcm::exp(x.x), zcm::exp(x.y), zcm::exp(x.z)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::exp2(float x) noexcept
{
    return expf(x);
}

zcm::vec2 zcm::exp2(const zcm::vec2& x) noexcept
{
    return {zcm::exp2(x.x),zcm::exp2(x.y)};
}

zcm::vec3 zcm::exp2(const zcm::vec3& x) noexcept
{
    return {zcm::exp2(x.x),zcm::exp2(x.y), zcm::exp2(x.z)};
}

zcm::vec4 zcm::exp2(const zcm::vec4& x) noexcept
{
    return {zcm::exp2(x.x),zcm::exp2(x.y), zcm::exp2(x.z), zcm::exp2(x.w)};
}

zcm::quat zcm::exp2(const zcm::quat &x) noexcept
{
    return {zcm::exp2(x.w), zcm::exp2(x.x),zcm::exp2(x.y), zcm::exp2(x.z)};
}


//-----------------------------------------------------------------------------------------------------


float zcm::cbrt(float x) noexcept
{
	return cbrtf(x);
}

zcm::vec2 zcm::cbrt(vec2 x) noexcept
{
	return {zcm::cbrt(x.x), zcm::cbrt(x.y)};
}

zcm::vec3 zcm::cbrt(vec3 x) noexcept
{
	return {zcm::cbrt(x.x), zcm::cbrt(x.y), zcm::cbrt(x.z)};
}

zcm::vec4 zcm::cbrt(vec4 x) noexcept
{
	return {zcm::cbrt(x.x), zcm::cbrt(x.y), zcm::cbrt(x.z), zcm::cbrt(x.w)};
}

zcm::quat zcm::cbrt(quat x) noexcept
{
	return {zcm::cbrt(x.w), zcm::cbrt(x.x), zcm::cbrt(x.y), zcm::cbrt(x.z)};
}
