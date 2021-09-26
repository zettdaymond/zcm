#include <zcm/component_wise.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec4.hpp>
#include <zcm/common.hpp>


float zcm::compAdd(const zcm::vec2& v) noexcept
{
    return v.x + v.y;
}

float zcm::compAdd(const zcm::vec3& v) noexcept
{
    return v.x + v.y + v.z;
}

float zcm_vectorcall zcm::compAdd(zcm::vec4 v) noexcept
{
    return v.x + v.y + v.z + v.w;
}

int zcm::compAdd(const zcm::ivec2& v) noexcept
{
    return v.x + v.y;
}

int zcm::compAdd(const zcm::ivec3& v) noexcept
{
    return v.x + v.y + v.z;
}

int zcm::compAdd(const zcm::ivec4& v) noexcept
{
    return v.x + v.y + v.z + v.w;
}

float zcm::compMul(const zcm::vec2& v) noexcept
{
    return v.x * v.y;
}

float zcm::compMul(const zcm::vec3& v) noexcept
{
    return v.x * v.y * v.z;
}

float zcm_vectorcall zcm::compMul(zcm::vec4 v) noexcept
{
    return v.x * v.y * v.z * v.w;
}

int zcm::compMul(const zcm::ivec2& v) noexcept
{
    return v.x * v.y;
}

int zcm::compMul(const zcm::ivec3& v) noexcept
{
    return v.x * v.y * v.z;
}

int zcm::compMul(const zcm::ivec4& v) noexcept
{
    return v.x * v.y * v.z * v.w;
}

float zcm::compMin(const zcm::vec2& v) noexcept
{
    return min(v.x, v.y);
}

float zcm::compMin(const zcm::vec3& v) noexcept
{
    return min(v.x, min(v.y, v.z));
}

float zcm_vectorcall zcm::compMin(zcm::vec4 v) noexcept
{
    return min(min(v.x, v.y), min(v.z, v.w));
}

int zcm::compMin(const zcm::ivec2& v) noexcept
{
    return min(v.x, v.y);
}

int zcm::compMin(const zcm::ivec3& v) noexcept
{
    return min(v.x, min(v.y, v.z));
}

int zcm::compMin(const zcm::ivec4& v) noexcept
{
    return min(min(v.x, v.y), min(v.z, v.w));
}

float zcm::compMax(const zcm::vec2& v) noexcept
{
    return max(v.x, v.y);
}

float zcm::compMax(const zcm::vec3& v) noexcept
{
    return max(v.x, max(v.y, v.z));
}

float zcm_vectorcall zcm::compMax(zcm::vec4 v) noexcept
{
    return max(max(v.x, v.y), max(v.z, v.w));
}

int zcm::compMax(const zcm::ivec2& v) noexcept
{
    return max(v.x, v.y);
}

int zcm::compMax(const zcm::ivec3& v) noexcept
{
    return max(v.x, max(v.y, v.z));
}

int zcm::compMax(const zcm::ivec4& v) noexcept
{
    return max(max(v.x, v.y), max(v.z, v.w));
}
