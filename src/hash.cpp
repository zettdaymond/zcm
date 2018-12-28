#include <zcm/hash.hpp>
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
#include <cstring>

static size_t float_hash(float f) noexcept
{
    static_assert (sizeof(float) == sizeof(unsigned), "Float and unsigned must have same size!");
    unsigned ui;
    std::memcpy(&ui, &f, sizeof(float));
    return ui;
}

size_t zcm::hash(float f) noexcept
{
    auto h = float_hash(f);
    return ((~h) << (sizeof(unsigned) * 8)) | h;
}

size_t zcm::hash(const zcm::vec2 &v) noexcept
{
    auto hx = float_hash(v.x);
    auto hy = float_hash(v.y);
    return ((hx) << (sizeof(unsigned) * 8)) | hy;
}

size_t zcm::hash(const zcm::vec3 &v) noexcept
{
    auto hx = float_hash(v.x);
    auto hy = float_hash(v.y);
    auto hz = float_hash(v.z);
    return (((hx) << (sizeof(unsigned) * 8)) | hy) ^ ((hz) << (sizeof(unsigned) * 4));
}

size_t zcm::hash(const zcm::vec4 &v) noexcept
{
    auto hx = float_hash(v.x);
    auto hy = float_hash(v.y);
    auto hz = float_hash(v.z);
    auto hw = float_hash(v.w);
    return (((hx) << (sizeof(unsigned) * 8)) | hy) ^ ((hz) << (sizeof(unsigned) * 4)) ^ hw;
}

size_t zcm::hash(const zcm::quat &v) noexcept
{
    auto hx = float_hash(v.x);
    auto hy = float_hash(v.y);
    auto hz = float_hash(v.z);
    auto hw = float_hash(v.w);
    return (((hx) << (sizeof(unsigned) * 8)) | hy) ^ ((hz) << (sizeof(unsigned) * 4)) ^ hw;
}

size_t zcm::hash(const zcm::mat2 &m) noexcept
{
    return hash(m[0]) ^ hash(m[1]);
}

size_t zcm::hash(const zcm::mat3 &m) noexcept
{
    return hash(m[0]) ^ hash(m[1]) ^ hash(m[2]);
}

size_t zcm::hash(const zcm::mat4 &m) noexcept
{
    return hash(m[0]) ^ hash(m[1]) ^ hash(m[1]) ^ hash(m[3]);
}
