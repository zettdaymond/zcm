#pragma once

namespace zcm
{
    struct bvec2
    {
        bvec2();
        bvec2(bool value);
        bvec2(bool x, bool y);

        bool& operator[](unsigned val);
        bool operator[](unsigned val) const;

        bool x;
        bool y;
    };

    bool operator ==(bvec2 first, bvec2 second);
    bool operator !=(bvec2 first, bvec2 second);

    bvec2 operator ! (bvec2 first);

    bvec2 operator &&(bvec2 first, bvec2 second);
    bvec2 operator ||(bvec2 first, bvec2 second);
    bvec2 operator ^ (bvec2 first, bvec2 second);

    bvec2 operator &&(bvec2 first, bool scalar);
    bvec2 operator ||(bvec2 first, bool scalar);
    bvec2 operator ^ (bvec2 first, bool scalar);

    bvec2 operator &&(bool scalar, bvec2 first);
    bvec2 operator ||(bool scalar, bvec2 first);
    bvec2 operator ^ (bool scalar, bvec2 first);

}
