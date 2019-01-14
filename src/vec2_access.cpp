#include <zcm/vec2.hpp>

namespace zcm {
namespace detail {

template<int index>
void scalar_accessor_2<index>::operator +=(float s) noexcept
{
	_data[index] += s;
}

template<int index>
void scalar_accessor_2<index>::operator -=(float s) noexcept
{
	_data[index] -= s;
}

template<int index>
void scalar_accessor_2<index>::operator *=(float s) noexcept
{
	_data[index] *= s;
}

template<int index>
void scalar_accessor_2<index>::operator /=(float s) noexcept
{
	_data[index] /= s;
}

template<int index>
void scalar_accessor_2<index>::operator =(float s) noexcept
{
	_data[index] = s;
}

template<int index>
scalar_accessor_2<index>::operator float() const noexcept
{
	return _data[index];
}

template<typename T, int... indices>
shuffle_accessor_2<T, indices...>::operator T() const noexcept
{
	return T{_data[indices]...};
}


#define ZCM_TEMPLATE_SCALAR_ACCESSOR(x) \
    template scalar_accessor_2<x>::operator float() const noexcept; \
    template void scalar_accessor_2<x>::operator=(float) noexcept;  \
    template void scalar_accessor_2<x>::operator+=(float) noexcept; \
    template void scalar_accessor_2<x>::operator-=(float) noexcept; \
    template void scalar_accessor_2<x>::operator*=(float) noexcept; \
    template void scalar_accessor_2<x>::operator/=(float) noexcept; \

#define ZCM_TEMPLATE_SHUFFLE_ACCESSOR(x, y) \
    template shuffle_accessor_2<vec2, x, y>::operator vec2() const noexcept;

ZCM_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_TEMPLATE_SCALAR_ACCESSOR(1)

ZCM_TEMPLATE_SHUFFLE_ACCESSOR(0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(1, 1)

}
}
