#pragma once

namespace zcm {

	struct vec3;
	struct vec4;

	/// Convert a linear color to sRGB color using a standard gamma correction.
	/// IEC 61966-2-1:1999 specification https://www.w3.org/Graphics/Color/srgb
	vec3 convertLinearToSRGB(vec3 colorLinear) noexcept;
	vec4 convertLinearToSRGB(vec4 colorLinear) noexcept; // alpha not modified

	/// Convert a linear color to sRGB color using a custom gamma correction.
	/// IEC 61966-2-1:1999 specification https://www.w3.org/Graphics/Color/srgb
	vec3 convertLinearToSRGB(vec3 ColorLinear, float Gamma) noexcept;
	vec4 convertLinearToSRGB(vec4 ColorLinear, float Gamma) noexcept; // alpha not modified

	/// Convert a sRGB color to linear color using a standard gamma correction.
	/// IEC 61966-2-1:1999 specification https://www.w3.org/Graphics/Color/srgb
	vec3 convertSRGBToLinear(vec3 ColorSRGB) noexcept;
	vec4 convertSRGBToLinear(vec4 ColorSRGB) noexcept; // alpha not modified

	/// Convert a sRGB color to linear color using a custom gamma correction.
	// IEC 61966-2-1:1999 specification https://www.w3.org/Graphics/Color/srgb
	vec3 convertSRGBToLinear(vec3 ColorSRGB, float Gamma) noexcept;
	vec4 convertSRGBToLinear(vec4 ColorSRGB, float Gamma) noexcept; // alpha not modified
}
