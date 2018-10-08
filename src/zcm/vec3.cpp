#include "vec3.h"
#include "common.h"

zcm::vec3 zcm::operator +(const zcm::vec3& first, const zcm::vec3& second)
{
    return vec3{ first.x + second.x,
                 first.y + second.y,
                 first.z + second.z };
}

zcm::vec3 zcm::operator -(const zcm::vec3& first, const vec3& second)
{
    return vec3{ first.x - second.x,
                 first.y - second.y,
                 first.z - second.z };
}

zcm::vec3 zcm::operator -(const zcm::vec3& first)
{
    return vec3{ -first.x,
                 -first.y,
                 -first.z};
}

zcm::vec3 zcm::operator *(const zcm::vec3& vec, const float scalar)
{
    return vec3{ vec.x * scalar,
                 vec.y * scalar,
                 vec.z * scalar };
}

zcm::vec3 zcm::operator /(const zcm::vec3& vec, const float scalar)
{
    return vec3{ vec.x / scalar,
                 vec.y / scalar,
                 vec.z / scalar };
}

zcm::vec3 zcm::operator *(const zcm::vec3& first, const zcm::vec3& second)
{
    return {first.x * second.x, first.y * second.y, first.z * second.z};
}

zcm::vec3 zcm::operator *(const float scalar, const zcm::vec3& vec)
{
    return { scalar * vec.x,
             scalar * vec.y,
             scalar * vec.z };
}

zcm::vec3 zcm::operator /(const float scalar, const zcm::vec3& vec)
{
    return { scalar / vec.x,
             scalar / vec.y,
             scalar / vec.z };
}
