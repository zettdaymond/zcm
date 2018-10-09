#pragma once


#if defined(BENCH_GLM)

#define NAMESPACE glm

#define VEC2_INCLUDE <glm/vec2.hpp>
#define VEC3_INCLUDE <glm/vec3.hpp>
#define VEC4_INCLUDE <glm/vec4.hpp>
#define MAT3_INCLUDE <glm/mat3x3.hpp>
#define MAT4_INCLUDE <glm/mat4x4.hpp>
#define MATRIX_OPS_INCLUDE <glm/matrix.hpp>
#define MATRIX_TRANSFORM_INCLUDE <glm/gtc/matrix_transform.hpp>
#define COMMON_INCLIDE <glm/common.hpp>

#elif defined(BENCH_ZCM)

#define NAMESPACE zcm

#define VEC2_INCLUDE "zcm/vec2.h"
#define VEC3_INCLUDE "zcm/vec3.h"
#define VEC4_INCLUDE "zcm/vec4.h"
#define MAT3_INCLUDE "zcm/mat3.h"
#define MAT4_INCLUDE "zcm/mat4.h"
#define MATRIX_OPS_INCLUDE "zcm/matrix.h"
#define MATRIX_TRANSFORM_INCLUDE "zcm/matrixtransform.h"
#define COMMON_INCLIDE "zcm/common.h"


#endif
