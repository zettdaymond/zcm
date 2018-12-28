#pragma once

namespace zcm
{
    struct bvec2
    {
        bvec2() noexcept;
        bvec2(bool value) noexcept;
        bvec2(bool x, bool y) noexcept;

        bool& operator[](unsigned val) noexcept;
        bool operator[](unsigned val) const noexcept;

        void operator &=(bool scalar) noexcept;
        void operator |=(bool scalar) noexcept;
        void operator ^=(bool scalar) noexcept;

        void operator &=(bvec2 other) noexcept;
        void operator |=(bvec2 other) noexcept;
        void operator ^=(bvec2 other) noexcept;

        bool x;
        bool y;
    };

    bool operator ==(bvec2 first, bvec2 second) noexcept;
    bool operator !=(bvec2 first, bvec2 second) noexcept;

    bvec2 operator ! (bvec2 first) noexcept;

    bvec2 operator &&(bvec2 first, bvec2 second) noexcept;
    bvec2 operator ||(bvec2 first, bvec2 second) noexcept;
    bvec2 operator ^ (bvec2 first, bvec2 second) noexcept;

    bvec2 operator &&(bvec2 first, bool scalar) noexcept;
    bvec2 operator ||(bvec2 first, bool scalar) noexcept;
    bvec2 operator ^ (bvec2 first, bool scalar) noexcept;

    bvec2 operator &&(bool scalar, bvec2 first) noexcept;
    bvec2 operator ||(bool scalar, bvec2 first) noexcept;
    bvec2 operator ^ (bool scalar, bvec2 first) noexcept;

}
