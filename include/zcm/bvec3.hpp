#pragma once

namespace zcm
{

    struct bvec2;
    struct bvec3
    {
        bvec3 () noexcept;
        explicit bvec3(bool value) noexcept;
        bvec3 (bool x, bool y, bool z) noexcept;

        bvec3 (bvec2 xy, bool z) noexcept;
        bvec3 (bool x, bvec2 yz) noexcept;

        bool& operator[] (unsigned val) noexcept;
        bool  operator[] (unsigned val) const noexcept;

        void operator &= (bool scalar) noexcept;
        void operator |= (bool scalar) noexcept;
        void operator ^= (bool scalar) noexcept;

        void operator &= (bvec3 other) noexcept;
        void operator |= (bvec3 other) noexcept;
        void operator ^= (bvec3 other) noexcept;

        bool x;
        bool y;
        bool z;
    };

    bool  operator == (bvec3 first, bvec3 second) noexcept;
    bool  operator != (bvec3 first, bvec3 second) noexcept;

    bvec3 operator !  (bvec3 first) noexcept;

    bvec3 operator && (bvec3 first, bvec3 second) noexcept;
    bvec3 operator || (bvec3 first, bvec3 second) noexcept;
    bvec3 operator ^  (bvec3 first, bvec3 second) noexcept;

    bvec3 operator && (bvec3 first, bool scalar) noexcept;
    bvec3 operator || (bvec3 first, bool scalar) noexcept;
    bvec3 operator ^  (bvec3 first, bool scalar) noexcept;

    bvec3 operator && (bool scalar, bvec3 first) noexcept;
    bvec3 operator || (bool scalar, bvec3 first) noexcept;
    bvec3 operator ^  (bool scalar, bvec3 first) noexcept;

}
