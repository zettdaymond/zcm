#pragma once

namespace zcm
{
    struct bvec3;
    struct bvec2;
    struct bvec4
    {
        bvec4 ();
        bvec4 (bool value);
        bvec4 (bool x, bool y, bool z, bool w);

        bvec4 (bvec3 xyz, bool w);
        bvec4 (bool x, bvec3 yzw);

        bvec4 (bvec2 xy, bvec2 zw);
        bvec4 (bvec2 xy, bool z, bool w);
        bvec4 (bool x, bvec2 yz, bool w);
        bvec4 (bool x, bool y, bvec2 zw);

        bool& operator[](unsigned val);
        bool operator[](unsigned val) const;

        bool x;
        bool y;
        bool z;
        bool w;
    };

    bool operator ==(bvec4 first, bvec4 second);
    bool operator !=(bvec4 first, bvec4 second);

    bvec4 operator ! (bvec4 first);

    bvec4 operator &&(bvec4 first, bvec4 second);
    bvec4 operator ||(bvec4 first, bvec4 second);
    bvec4 operator ^ (bvec4 first, bvec4 second);

    bvec4 operator &&(bvec4 first, bool scalar);
    bvec4 operator ||(bvec4 first, bool scalar);
    bvec4 operator ^ (bvec4 first, bool scalar);

    bvec4 operator &&(bool scalar, bvec4 first);
    bvec4 operator ||(bool scalar, bvec4 first);
    bvec4 operator ^ (bool scalar, bvec4 first);

}
