#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>

namespace zcm {
namespace detail {

template<int index>
void scalar_accessor_3<index>::operator +=(float s) noexcept
{
	_data[index] += s;
}

template<int index>
void scalar_accessor_3<index>::operator -=(float s) noexcept
{
	_data[index] -= s;
}

template<int index>
void scalar_accessor_3<index>::operator *=(float s) noexcept
{
	_data[index] *= s;
}

template<int index>
void scalar_accessor_3<index>::operator /=(float s) noexcept
{
	_data[index] /= s;
}

template<int index>
void scalar_accessor_3<index>::operator =(float s) noexcept
{
	_data[index] = s;
}

template<int index>
scalar_accessor_3<index>::operator float() const noexcept
{
	return _data[index];
}

#define ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(x) \
    template scalar_accessor_3<x>::operator float() const noexcept; \
    template void scalar_accessor_3<x>::operator=(float) noexcept;  \
    template void scalar_accessor_3<x>::operator+=(float) noexcept; \
    template void scalar_accessor_3<x>::operator-=(float) noexcept; \
    template void scalar_accessor_3<x>::operator*=(float) noexcept; \
    template void scalar_accessor_3<x>::operator/=(float) noexcept; \

ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(1)
ZCM_VEC3_TEMPLATE_SCALAR_ACCESSOR(2)


#ifndef ZCM_DISABLE_SWIZZLE

template<typename T, int... indices>
shuffle_accessor_3<T, indices...>::operator T() const noexcept
{
	return T{_data[indices]...};
}

#define ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
    template shuffle_accessor_3<vec2, x, y>::operator vec2() const noexcept;

#define ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
    template shuffle_accessor_3<vec3, x, y, z>::operator vec3() const noexcept;


ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 2)

ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 0)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 1)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 2)
ZCM_VEC3_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 2)
#endif // ZCM_DISABLE_SWIZZLE

}
}
