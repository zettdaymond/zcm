#include <zcm/color_space.hpp>
#include <zcm/common.hpp>
#include <zcm/exponential.hpp>
#include <zcm/bvec3.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>

zcm::vec4 zcm::convertLinearToSRGB(zcm::vec4 ColorLinear, float Gamma) noexcept
{
	return {convertLinearToSRGB(ColorLinear.rgb, Gamma), ColorLinear.a};
}

zcm::vec3 zcm::convertLinearToSRGB(zcm::vec3 colorLinear, float Gamma) noexcept
{
	auto ClampedColor = clamp(colorLinear, vec3{0}, vec3{1});
	return mix(pow(ClampedColor, vec3(Gamma)) * 1.055f - 0.055f,
	           ClampedColor * 12.92f,
	           lessThan(ClampedColor, vec3(0.0031308f)));
}

zcm::vec3 zcm::convertLinearToSRGB(zcm::vec3 colorLinear) noexcept
{
	// Based on Ian Taylor http://chilliant.blogspot.fr/2012/08/srgb-approximations-for-hlsl.html
	vec3 S1 = sqrt(colorLinear);
	vec3 S2 = sqrt(S1);
	vec3 S3 = sqrt(S2);
	return 0.662002687f * S1 + 0.684122060f * S2 - 0.323583601f * S3 - 0.0225411470f * colorLinear;
}

zcm::vec4 zcm::convertLinearToSRGB(zcm::vec4 colorLinear) noexcept
{
	return {convertLinearToSRGB(colorLinear.rgb), colorLinear.a};
}


zcm::vec3 zcm::convertSRGBToLinear(zcm::vec3 ColorSRGB, float Gamma) noexcept
{
	return mix(pow((ColorSRGB + 0.055f) * 0.94786729857819905213270142180095f, vec3(Gamma)),
	           ColorSRGB * 0.07739938080495356037151702786378f,
	           lessThanEqual(ColorSRGB, vec3(0.04045f)));
}

zcm::vec4 zcm::convertSRGBToLinear(zcm::vec4 ColorSRGB, float Gamma) noexcept
{
	return {convertSRGBToLinear(ColorSRGB.rgb, Gamma), ColorSRGB.a};
}

zcm::vec3 zcm::convertSRGBToLinear(zcm::vec3 ColorSRGB) noexcept
{
    return convertSRGBToLinear(ColorSRGB, 2.4f);
}

zcm::vec4 zcm::convertSRGBToLinear(zcm::vec4 ColorSRGB) noexcept
{
    return {convertSRGBToLinear(ColorSRGB.rgb, 2.4f), ColorSRGB.a};
}
