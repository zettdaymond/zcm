#pragma once

#include <zcm/access.hpp>

template<int index, int count>
void zcm::_scalar_accessor<index, count>::operator +=(float s) noexcept
{
	_data[index] += s;
}

template<int index, int count>
void zcm::_scalar_accessor<index, count>::operator -=(float s) noexcept
{
	_data[index] -= s;
}

template<int index, int count>
void zcm::_scalar_accessor<index, count>::operator *=(float s) noexcept
{
	_data[index] *= s;
}

template<int index, int count>
void zcm::_scalar_accessor<index, count>::operator /=(float s) noexcept
{
	_data[index] /= s;
}

template<int index, int count>
void zcm::_scalar_accessor<index, count>::operator =(float s) noexcept
{
	_data[index] = s;
}

template<int index, int count>
zcm::_scalar_accessor<index, count>::operator float() const noexcept
{
	return _data[index];
}

template<typename T, int... indices>
zcm::_shuffle_accessor<T, indices...>::operator T() const noexcept
{
	return T{_data[indices]...};
}
