#include <zcm/vec2.hpp>
#include <zcm/accessor_impl.hpp>

namespace zcm {

#define ZCM_TEMPLATE_SCALAR_ACCESSOR(x) \
    template _scalar_accessor<x, 2>::operator float() const noexcept; \
    template void _scalar_accessor<x, 2>::operator=(float) noexcept;  \
    template void _scalar_accessor<x, 2>::operator+=(float) noexcept; \
    template void _scalar_accessor<x, 2>::operator-=(float) noexcept; \
    template void _scalar_accessor<x, 2>::operator*=(float) noexcept; \
    template void _scalar_accessor<x, 2>::operator/=(float) noexcept; \

#define ZCM_TEMPLATE_SHUFFLE_ACCESSOR(x, y) \
    template  _shuffle_accessor<vec2, x, y>::operator vec2() const noexcept;

ZCM_TEMPLATE_SCALAR_ACCESSOR(0)
ZCM_TEMPLATE_SCALAR_ACCESSOR(1)

ZCM_TEMPLATE_SHUFFLE_ACCESSOR(0, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(0, 1)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(1, 0)
ZCM_TEMPLATE_SHUFFLE_ACCESSOR(1, 1)

}
