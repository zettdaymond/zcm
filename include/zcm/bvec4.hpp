#pragma once

namespace zcm
{
    struct bvec3;
    struct bvec2;
    struct bvec4
    {
        bvec4 () noexcept;
        explicit bvec4 (bool value) noexcept;
        bvec4 (bool x, bool y, bool z, bool w) noexcept;

        bvec4 (bvec3 xyz, bool w) noexcept;
        bvec4 (bool x, bvec3 yzw) noexcept;

        bvec4 (bvec2 xy, bvec2 zw) noexcept;
        bvec4 (bvec2 xy, bool z, bool w) noexcept;
        bvec4 (bool x, bvec2 yz, bool w) noexcept;
        bvec4 (bool x, bool y, bvec2 zw) noexcept;

        bool& operator[] (unsigned val) noexcept;
        bool  operator[] (unsigned val) const noexcept;

        void operator &= (bool scalar) noexcept;
        void operator |= (bool scalar) noexcept;
        void operator ^= (bool scalar) noexcept;

        void operator &= (bvec4 other) noexcept;
        void operator |= (bvec4 other) noexcept;
        void operator ^= (bvec4 other) noexcept;

        bool x;
        bool y;
        bool z;
        bool w;
    };

    zcm::bvec4 make_bvec4(const bool* ptr) noexcept;

    bool  operator == (bvec4 first, bvec4 second) noexcept;
    bool  operator != (bvec4 first, bvec4 second) noexcept;

    bvec4 operator !  (bvec4 first) noexcept;

    bvec4 operator && (bvec4 first, bvec4 second) noexcept;
    bvec4 operator || (bvec4 first, bvec4 second) noexcept;
    bvec4 operator ^  (bvec4 first, bvec4 second) noexcept;

    bvec4 operator && (bvec4 first, bool scalar) noexcept;
    bvec4 operator || (bvec4 first, bool scalar) noexcept;
    bvec4 operator ^  (bvec4 first, bool scalar) noexcept;

    bvec4 operator && (bool scalar, bvec4 first) noexcept;
    bvec4 operator || (bool scalar, bvec4 first) noexcept;
    bvec4 operator ^  (bool scalar, bvec4 first) noexcept;

}
