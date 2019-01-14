#pragma once

namespace zcm {

template<int index, int count>
struct _scalar_accessor
{
    float _data[count];

    void operator +=(float s) noexcept
    {
	_data[index] += s;
    }
    void operator -=(float s) noexcept
    {
	_data[index] -= s;
    }
    void operator *=(float s) noexcept
    {
	_data[index] *= s;
    }
    void operator /=(float s) noexcept
    {
	_data[index] /= s;
    }
    void operator  =(float s) noexcept
    {
	_data[index] = s;
    }
    operator float() const noexcept
    {
	return _data[index];
    }
};

template<typename T, int... indices>
struct _shuffle_accessor
{
    float _data[sizeof...(indices)];

    operator T() const noexcept
    {
	return T{_data[indices]...};
    }
};

}
