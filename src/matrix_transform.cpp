#include <zcm/matrix_transform.hpp>
#include <zcm/geometric.hpp>
#include <zcm/angle_and_trigonometry.hpp>
#include <zcm/vec3.hpp>
#include <zcm/mat4.hpp>
#include <zcm/mat3.hpp>
#include <zcm/quat.hpp>
#include <zcm/exponential.hpp>
#include <zcm/common.hpp>
#include <limits>
#include <cassert>

zcm::mat4 zcm::translate(const zcm::mat4& m, const zcm::vec3& v) noexcept
{
    mat4 Result{m};
    Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
    return Result;
}

zcm::mat4 zcm::rotate(const zcm::mat4& m, float angle, const zcm::vec3& v) noexcept
{
    auto const a = angle;
    auto const c = zcm::cos(a);
    auto const s = zcm::sin(a);

    vec3 axis(normalize(v));
    vec3 temp((1.0f - c) * axis);

    mat3 Rotate{zcm::no_init_t{}};
    Rotate[0][0] = c + temp[0] * axis[0];
    Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
    Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

    Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
    Rotate[1][1] = c + temp[1] * axis[1];
    Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

    Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
    Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
    Rotate[2][2] = c + temp[2] * axis[2];

    mat4 Result{zcm::no_init_t{}};
    Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
    Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
    Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
    Result[3] = m[3];
    return Result;
}

zcm::mat4 zcm::scale(const zcm::mat4& m, const zcm::vec3& v) noexcept
{
    mat4 Result{zcm::no_init_t{}};
    Result[0] = m[0] * v[0];
    Result[1] = m[1] * v[1];
    Result[2] = m[2] * v[2];
    Result[3] = m[3];
    return Result;
}

zcm::mat4 zcm::lookAtRH(const zcm::vec3& eye, const zcm::vec3& center, const zcm::vec3& up) noexcept
{
    vec3 const f(normalize(center - eye));
    vec3 const s(normalize(cross(f, up)));
    vec3 const u(cross(s, f));

    mat4 Result(1);
    Result[0][0] = s.x;
    Result[1][0] = s.y;
    Result[2][0] = s.z;
    Result[0][1] = u.x;
    Result[1][1] = u.y;
    Result[2][1] = u.z;
    Result[0][2] =-f.x;
    Result[1][2] =-f.y;
    Result[2][2] =-f.z;
    Result[3][0] =-dot(s, eye);
    Result[3][1] =-dot(u, eye);
    Result[3][2] = dot(f, eye);
    return Result;
}

zcm::mat4 zcm::lookAtLH(const zcm::vec3& eye, const zcm::vec3& center, const zcm::vec3& up) noexcept
{
    vec3 const f(normalize(center - eye));
    vec3 const s(normalize(cross(up, f)));
    vec3 const u(cross(f, s));

    mat4 Result(1);
    Result[0][0] = s.x;
    Result[1][0] = s.y;
    Result[2][0] = s.z;
    Result[0][1] = u.x;
    Result[1][1] = u.y;
    Result[2][1] = u.z;
    Result[0][2] = f.x;
    Result[1][2] = f.y;
    Result[2][2] = f.z;
    Result[3][0] = -dot(s, eye);
    Result[3][1] = -dot(u, eye);
    Result[3][2] = -dot(f, eye);
    return Result;
}

zcm::mat4 zcm::ortho(float left, float right, float bottom, float top) noexcept
{
    mat4 Result(1.0f);
    Result[0][0] = 2.0f / (right - left);
    Result[1][1] = 2.0f / (top - bottom);
    Result[2][2] = - 1.0f;
    Result[3][0] = - (right + left) / (right - left);
    Result[3][1] = - (top + bottom) / (top - bottom);
    return Result;
}

zcm::mat4 zcm::orthoLH_ZO(float left, float right, float bottom, float top, float zNear, float zFar) noexcept
{
    mat4 Result(1.0f);
    Result[0][0] = (2.0f) / (right - left);
    Result[1][1] = (2.0f) / (top - bottom);
    Result[2][2] = (1.0f) / (zFar - zNear);
    Result[3][0] = - (right + left) / (right - left);
    Result[3][1] = - (top + bottom) / (top - bottom);
    Result[3][2] = - zNear / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::orthoRH_ZO(float left, float right, float bottom, float top, float zNear, float zFar) noexcept
{
    mat4 Result(1.0f);
    Result[0][0] = (2.0f) / (right - left);
    Result[1][1] = (2.0f) / (top - bottom);
    Result[2][2] = - (1.0f) / (zFar - zNear);
    Result[3][0] = - (right + left) / (right - left);
    Result[3][1] = - (top + bottom) / (top - bottom);
    Result[3][2] = - zNear / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::orthoLH_NO(float left, float right, float bottom, float top, float zNear, float zFar) noexcept
{
    mat4 Result(1.0f);
    Result[0][0] = (2.0f) / (right - left);
    Result[1][1] = (2.0f) / (top - bottom);
    Result[2][2] = (2.0f) / (zFar - zNear);
    Result[3][0] = - (right + left) / (right - left);
    Result[3][1] = - (top + bottom) / (top - bottom);
    Result[3][2] = - (zFar + zNear) / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::orthoRH_NO(float left, float right, float bottom, float top, float zNear, float zFar) noexcept
{
    mat4 Result(1);
    Result[0][0] = (2) / (right - left);
    Result[1][1] = (2) / (top - bottom);
    Result[2][2] = - (2) / (zFar - zNear);
    Result[3][0] = - (right + left) / (right - left);
    Result[3][1] = - (top + bottom) / (top - bottom);
    Result[3][2] = - (zFar + zNear) / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::perspectiveRH_ZO(float fovy, float aspect, float zNear, float zFar)
{
    assert(zcm::abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);

    float const tanHalfFovy = zcm::tan(fovy * 0.5f);

    zcm::mat4 Result(0.0f);
    Result[0][0] = 1.0f / (aspect * tanHalfFovy);
    Result[1][1] = 1.0f / (tanHalfFovy);
    Result[2][2] = zFar / (zNear - zFar);
    Result[2][3] = -1.0f;
    Result[3][2] = -(zFar * zNear) / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::perspectiveRH_NO(float fovy, float aspect, float zNear, float zFar)
{
    assert(abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);

    float const tanHalfFovy = zcm::tan(fovy * 0.5f);

    zcm::mat4 Result(0.0f);
    Result[0][0] = 1.0f / (aspect * tanHalfFovy);
    Result[1][1] = 1.0f / (tanHalfFovy);
    Result[2][2] = - (zFar + zNear) / (zFar - zNear);
    Result[2][3] = - 1.0f;
    Result[3][2] = - (2.0f * zFar * zNear) / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::perspectiveLH_ZO(float fovy, float aspect, float zNear, float zFar)
{
    assert(abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);

    float const tanHalfFovy = zcm::tan(fovy * 0.5f);

    zcm::mat4 Result(0.0f);
    Result[0][0] = 1.0f / (aspect * tanHalfFovy);
    Result[1][1] = 1.0f / (tanHalfFovy);
    Result[2][2] = zFar / (zFar - zNear);
    Result[2][3] = 1.0f;
    Result[3][2] = -(zFar * zNear) / (zFar - zNear);
    return Result;
}

zcm::mat4 zcm::perspectiveLH_NO(float fovy, float aspect, float zNear, float zFar)
{
    assert(abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);

    float const tanHalfFovy = zcm::tan(fovy * 0.5f);

    zcm::mat4 Result(0.0f);
    Result[0][0] = 1.0f / (aspect * tanHalfFovy);
    Result[1][1] = 1.0f / (tanHalfFovy);
    Result[2][2] = (zFar + zNear) / (zFar - zNear);
    Result[2][3] = 1.0f;
    Result[3][2] = - (2.0f * zFar * zNear) / (zFar - zNear);
    return Result;
}

void zcm::decompose_orthogonal(const zcm::mat4& model_mat,
                               zcm::vec3& scale,
                               zcm::quat& orientation,
                               zcm::vec3& translation) noexcept
{
	translation = zcm::vec3(model_mat[3].x, model_mat[3].y, model_mat[3].z);

	zcm::vec3 Row[3];

	// Now get scale and shear.
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			Row[i][j] = model_mat[i][j];

	// Compute X scale factor and normalize first row.
	scale.x = zcm::length(Row[0]);
	Row[0] /= scale.x;

	// Now, compute Y scale and normalize 2nd row.
	scale.y = zcm::length(Row[1]);
	Row[1] /= scale.y;

	// Next, get Z scale and normalize 3rd row.
	scale.z = zcm::length(Row[2]);
	Row[2] /= scale.z;

	// At this point, the matrix (in rows[]) is orthonormal.
	// Check for a coordinate system flip.  If the determinant
	// is -1, then negate the matrix and the scaling factors.
	if(zcm::dot(Row[0], zcm::cross(Row[1], Row[2])) < 0) {
		for(int i = 0; i < 3; i++) {
			scale[i] *= -1.f;
			Row[i] *= -1.f;
		}
	}

	// Now, get the rotations out, as described in the gem.

	int i, j, k = 0;
	float root, trace = Row[0].x + Row[1].y + Row[2].z;
	if(trace > 0.f) {
		root = zcm::sqrt(trace + 1.0f);
		orientation.w = 0.5f * root;
		root = 0.5f / root;
		orientation.x = root * (Row[1].z - Row[2].y);
		orientation.y = root * (Row[2].x - Row[0].z);
		orientation.z = root * (Row[0].y - Row[1].x);
	} else {
		static int Next[3] = {1, 2, 0};
		i = 0;
		if(Row[1].y > Row[0].x) i = 1;
		if(Row[2].z > Row[i][i]) i = 2;
		j = Next[i];
		k = Next[j];

		root = zcm::sqrt(Row[i][i] - Row[j][j] - Row[k][k] + 1.0f);

		orientation[i] = 0.5f * root;
		root = 0.5f / root;
		orientation[j] = root * (Row[i][j] + Row[j][i]);
		orientation[k] = root * (Row[i][k] + Row[k][i]);
		orientation.w = root * (Row[j][k] - Row[k][j]);
	}
}
