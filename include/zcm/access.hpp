#pragma once

namespace zcm {

    template<int index, int count>
    struct _scalar_accessor
    {
        float _data[count];

        void operator +=(float s) noexcept;
        void operator -=(float s) noexcept;
        void operator *=(float s) noexcept;
        void operator /=(float s) noexcept;
        void operator  =(float s) noexcept;
        operator float() const noexcept;
    };

    template<typename T, int... indices>
    struct _shuffle_accessor
    {
        float _data[sizeof...(indices)];

        operator T() const noexcept;
    };
}
