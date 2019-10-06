#pragma once
namespace zcm {
namespace detail {

template<typename T, int index>
struct scalar_accessor_3
{
    T _data[3];

    void operator +=(T s) noexcept;
    void operator -=(T s) noexcept;
    void operator *=(T s) noexcept;
    void operator /=(T s) noexcept;
    void operator  =(T s) noexcept;
    operator T() const noexcept;
};


#ifndef ZCM_DISABLE_SWIZZLE
template<typename T, typename V, int... indices>
struct shuffle_accessor_3
{
    T _data[3];

    operator V() const noexcept;
};


#endif // ZCM_DISABLE_SWIZZLE

}
}
