#include <zcm/color_space.hpp>
#include <zcm/common.hpp>
#include <zcm/exponential.hpp>
#include <zcm/bvec4.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>

zcm::vec4 zcm::convertLinearToSRGB(zcm::vec4 ColorLinear, float Gamma)
{
    auto ClampedColor = clamp(ColorLinear, vec4(0), vec4(1));

    return mix(pow(ClampedColor, vec4(Gamma)) * 1.055f - 0.055f,
               ClampedColor * 12.92f,
               lessThan(ClampedColor, vec4(0.0031308f)));
}

zcm::vec3 zcm::convertLinearToSRGB(zcm::vec3 colorLinear, float Gamma)
{
    auto r = convertLinearToSRGB(vec4(colorLinear, 0.0f), Gamma);
    return vec3(r.x, r.y, r.z);
}

zcm::vec3 zcm::convertLinearToSRGB(zcm::vec3 colorLinear)
{
    // Based on Ian Taylor http://chilliant.blogspot.fr/2012/08/srgb-approximations-for-hlsl.html
    vec3 S1 = sqrt(colorLinear);
    vec3 S2 = sqrt(S1);
    vec3 S3 = sqrt(S2);
    return 0.662002687f * S1 + 0.684122060f * S2 - 0.323583601f * S3 - 0.0225411470f * colorLinear;
}

zcm::vec4 zcm::convertLinearToSRGB(zcm::vec4 colorLinear)
{
    return convertLinearToSRGB(colorLinear, 0.41666f);
}

zcm::vec3 zcm::convertSRGBToLinear(zcm::vec3 ColorSRGB, float Gamma)
{
    auto r = convertSRGBToLinear(vec4(ColorSRGB, 0.0f), Gamma);
    return vec3(r.x, r.y, r.z);
}

zcm::vec4 zcm::convertSRGBToLinear(zcm::vec4 ColorSRGB, float Gamma)
{
    return mix(pow((ColorSRGB + 0.055f) * 0.94786729857819905213270142180095f, vec4(Gamma)),
               ColorSRGB * 0.07739938080495356037151702786378f,
               lessThanEqual(ColorSRGB, vec4(0.04045)));
}

zcm::vec3 zcm::convertSRGBToLinear(zcm::vec3 ColorSRGB)
{
    return convertSRGBToLinear(ColorSRGB, 2.4f);
}

zcm::vec4 zcm::convertSRGBToLinear(zcm::vec4 ColorSRGB)
{
    return convertSRGBToLinear(ColorSRGB, 2.4f);
}
