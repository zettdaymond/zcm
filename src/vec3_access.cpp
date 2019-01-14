#include <zcm/vec3.hpp>
#include <zcm/vec2.hpp>
#include <zcm/accessor_impl.hpp>

namespace zcm {

#define ZCM_TEMPLATE_SCALAR_ACCESSOR(x) \
    template _scalar_accessor<x, 3>::operator float() const noexcept; \
    template void _scalar_accessor<x, 3>::operator=(float) noexcept;  \
    template void _scalar_accessor<x, 3>::operator+=(float) noexcept; \
    template void _scalar_accessor<x, 3>::operator-=(float) noexcept; \
    template void _scalar_accessor<x, 3>::operator*=(float) noexcept; \
    template void _scalar_accessor<x, 3>::operator/=(float) noexcept; \

#define ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(x, y) \
    template  _shuffle_accessor<vec2, x, y>::operator vec2() const noexcept;

#define ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(x, y, z) \
    template  _shuffle_accessor<vec3, x, y, z>::operator vec3() const noexcept;

ZCM_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_TEMPLATE_SCALAR_ACCESSOR(1)
ZCM_TEMPLATE_SCALAR_ACCESSOR(2)

ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(0, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(1, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_2(2, 2)

ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 0, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 0, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 0, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 1, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 1, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 1, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(0, 2, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(1, 2, 2)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR_3(2, 2, 2)

}