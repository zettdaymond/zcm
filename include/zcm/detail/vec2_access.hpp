#pragma once

namespace zcm {
namespace detail {

template<typename T, int index>
struct scalar_accessor_2
{
    T _data[2];

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
struct scalar_accessor_2i : public scalar_accessor_2<T, index>
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
struct shuffle_accessor_2
{
    T _data[2];

    operator V() const noexcept;
};

#endif // ZCM_DISABLE_SWIZZLE
}
}
