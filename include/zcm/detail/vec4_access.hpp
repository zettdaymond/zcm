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
    T& operator++()    noexcept;
    T  operator++(int) noexcept;
    T& operator--()    noexcept;
    T  operator--(int) noexcept;
    operator T() const noexcept;
};

template <typename T, int index>
struct scalar_accessor_4i : public scalar_accessor_4<T, index>
{
    void operator %=(T s) noexcept;
    void operator |=(T s) noexcept;
    void operator &=(T s) noexcept;
    void operator ^=(T s) noexcept;
    void operator<<=(T s) noexcept;
    void operator>>=(T s) noexcept;
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
