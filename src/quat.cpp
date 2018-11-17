#include <cassert>
#include <type_traits>
#include <zcm/quat.hpp>

static_assert(std::is_standard_layout<zcm::quat>::value, "");

zcm::quat::quat() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
zcm::quat::quat(float _x, float _y, float _z, float _w) :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{}
