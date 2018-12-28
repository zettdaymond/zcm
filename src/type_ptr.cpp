#include <zcm/type_ptr.hpp>
#include <zcm/bvec2.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/bvec4.hpp>
#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>
#include <zcm/quat.hpp>
#include <zcm/mat2.hpp>
#include <zcm/mat3.hpp>
#include <zcm/mat4.hpp>

// non-const
bool *zcm::value_ptr(zcm::bvec2 &val) noexcept
{
    return &val.x;
}

bool *zcm::value_ptr(zcm::bvec3 &val) noexcept
{
    return &val.x;
}

bool *zcm::value_ptr(zcm::bvec4 &val) noexcept
{
    return &val.x;
}

float *zcm::value_ptr(zcm::vec2 &val) noexcept
{
    return &val.x;
}

float *zcm::value_ptr(zcm::vec3 &val) noexcept
{
    return &val.x;
}

float *zcm::value_ptr(zcm::vec4 &val) noexcept
{
    return &val.x;
}

float *zcm::value_ptr(zcm::quat &val) noexcept
{
    return &val.x;
}

float *zcm::value_ptr(zcm::mat2 &val) noexcept
{
    return &val._columns[0].x;
}

float *zcm::value_ptr(zcm::mat3 &val) noexcept
{
    return &val._columns[0].x;
}

float *zcm::value_ptr(zcm::mat4 &val) noexcept
{
    return &val._columns[0].x;
}


// const

const bool *zcm::value_ptr(const zcm::bvec2 &val) noexcept
{
    return &val.x;
}

const bool *zcm::value_ptr(const zcm::bvec3 &val) noexcept
{
    return &val.x;
}

const bool *zcm::value_ptr(const zcm::bvec4 &val) noexcept
{
    return &val.x;
}

const float *zcm::value_ptr(const zcm::vec2 &val) noexcept
{
    return &val.x;
}

const float *zcm::value_ptr(const zcm::vec3 &val) noexcept
{
    return &val.x;
}

const float *zcm::value_ptr(const zcm::vec4 &val) noexcept
{
    return &val.x;
}

const float *zcm::value_ptr(const zcm::quat &val) noexcept
{
    return &val.x;
}

const float *zcm::value_ptr(const zcm::mat2 &val) noexcept
{
    return &val._columns[0].x;
}

const float *zcm::value_ptr(const zcm::mat3 &val) noexcept
{
    return &val._columns[0].x;
}

const float *zcm::value_ptr(const zcm::mat4 &val) noexcept
{
    return &val._columns[0].x;
}

