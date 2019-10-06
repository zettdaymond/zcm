#pragma once

namespace zcm {

    struct vec2;
    struct vec3;
    struct vec4;

namespace detail {

template<typename T, int index>
struct scalar_accessor_4
{
    T _data[4];

    void operator +=(T s) noexcept;
    void operator -=(T s) noexcept;
    void operator *=(T s) noexcept;
    void operator /=(T s) noexcept;
    void operator  =(T s) noexcept;
    operator T() const noexcept;
};



#ifndef ZCM_DISABLE_SWIZZLE
template<typename T, typename V, int... indices>
struct shuffle_accessor_4
{
    T _data[4];
    operator V() const noexcept;
};

#endif // ZCM_DISABLE_SWIZZLE

}
}
