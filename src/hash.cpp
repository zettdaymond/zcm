#include <zcm/hash.hpp>
#include <zcm/bvec2.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/bvec4.hpp>
#include <zcm/ivec2.hpp>
#include <zcm/ivec3.hpp>
#include <zcm/ivec4.hpp>
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
    return zcm::hash(ui);
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

size_t zcm_vectorcall zcm::hash(zcm::vec4 v) noexcept
{
    auto hx = float_hash(v.x);
    auto hy = float_hash(v.y);
    auto hz = float_hash(v.z);
    auto hw = float_hash(v.w);
    return (((hx) << (sizeof(unsigned) * 8)) | hy) ^ ((hz) << (sizeof(unsigned) * 4)) ^ hw;
}

size_t zcm_vectorcall zcm::hash(zcm::quat v) noexcept
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

size_t zcm::hash(const zcm::bvec2 &b) noexcept
{
    return hash(b.x) ^ hash(b.y);
}

size_t zcm::hash(const zcm::bvec3 &b) noexcept
{
    return hash(b.x) ^ hash(b.y) ^ hash(b.z);
}

size_t zcm::hash(const zcm::bvec4 &b) noexcept
{
    return hash(b.x) ^ hash(b.y) ^ hash(b.z) ^ hash(b.w);
}

size_t zcm::hash(const zcm::ivec2 &v) noexcept
{
    return hash(v.x) ^ hash(v.y);
}

size_t zcm::hash(const zcm::ivec3 &v) noexcept
{
    return hash(v.x) ^ hash(v.y) ^ hash(v.z);
}

size_t zcm::hash(const zcm::ivec4 &v) noexcept
{
    return hash(v.x) ^ hash(v.y) ^ hash(v.z) ^ hash(v.w);
}

size_t zcm::hash(bool x) noexcept
{
    return x ? 14946564255682567559ull : 9039655308336254491ull;
}

size_t zcm::hash(int val) noexcept
{
    return val * 1273103906433186827ull;
}

size_t zcm::hash(unsigned val) noexcept
{
    return val * 1273103906433186827ull;
}
