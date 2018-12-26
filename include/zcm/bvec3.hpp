#pragma once

namespace zcm
{

    struct bvec2;
    struct bvec3
    {
        bvec3();
        bvec3(bool value);
        bvec3(bool x, bool y, bool z);

        bvec3(bvec2 xy, bool z);
        bvec3(bool x, bvec2 yz);

        bool& operator[](unsigned val);
        bool operator[](unsigned val) const;

        bool x;
        bool y;
        bool z;
    };

    bool operator ==(bvec3 first, bvec3 second);
    bool operator !=(bvec3 first, bvec3 second);

    bvec3 operator ! (bvec3 first);

    bvec3 operator &&(bvec3 first, bvec3 second);
    bvec3 operator ||(bvec3 first, bvec3 second);
    bvec3 operator ^ (bvec3 first, bvec3 second);

    bvec3 operator &&(bvec3 first, bool scalar);
    bvec3 operator ||(bvec3 first, bool scalar);
    bvec3 operator ^ (bvec3 first, bool scalar);

    bvec3 operator &&(bool scalar, bvec3 first);
    bvec3 operator ||(bool scalar, bvec3 first);
    bvec3 operator ^ (bool scalar, bvec3 first);

}
