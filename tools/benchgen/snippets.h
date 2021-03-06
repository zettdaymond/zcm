#pragma once

#include <string>

//TODO: lambdas
const std::string snippents[] = {
    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = dot(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = cross(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = dot(a,b);\n"
    "auto d = clamp(a, b, vec3(c));\n"
    "auto e = min(max(a, b), c);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "auto d = faceforward(a, b, c);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = length(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = distance(a,vec3(b));\n" //TODO: why zcm is compiled????? //Because zcm has implicit constructor to vec3 from 1 float
    "auto d = reflect(a, vec3(c));\n"
    "auto r = refract(a, vec3(c), 0.343f);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = exp2(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = sign(mod(a,b));\n"
    "}\n",

    "{\n"
    "auto a = abs(vec3(1.124f, -65.465f, 0.124f));\n"
    "auto b = inversesqrt(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = trunc(a);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = sqrt(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = floor(a);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec3(1.124f, 65.465f, -0.124f));\n"
    "auto b = pow(vec3(5.454f, 6.44f, 1.41f), a);\n"
    "auto c = round(a);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = ceil(a);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = roundEven(floor(a));\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = trunc(a);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = normalize(a);\n"
    "}\n",

    "{\n"
    "auto a = cos(vec3(1.124f, 65.465f, 0.124f));\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = sin(b);\n"
    "}\n",

    "{\n"
    "auto a = tan(vec3(1.124f, 65.465f, 0.124f));\n"
    "auto b = atan(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = exp(asin(tan(b)));\n"
    "}\n",

    "{\n"
    "auto a = degrees(radians(vec3(1.124f, 65.465f, 0.124f)));\n"
    "auto b = asinh(sinh(tanh(vec3(5.454f, 6.44f, 1.41f))));\n"
    "auto c = acosh(exp2(cosh(b)));\n"
    "}\n",

    //----------------------------------------------------------------------

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 41.114f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 2.78f);\n"
    "auto c = dot(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 201.1114f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 335.11f);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "auto d = clamp(a, b, c);\n"
    "auto e = sign(min(max(a, b), c));\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 123.14f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.4f);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "auto d = faceforward(a, b, c);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114f);\n"
    "auto b = length(vec4(5.454f, 6.44f, 1.41f, 0.1114f));\n"
    "auto c = distance(a,vec4(b));\n"
    "auto d = reflect(a, vec4(c));\n"
    "auto r = refract(a, vec4(c), 0.343f);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 615.465f, 0.124f, 0.1114f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.413f, 1.1114f);\n"
    "auto c = mod(a,b);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = vec4(5.454f, 6.44f, 1.413f, 1.1114f);\n"
    "auto c = trunc(a);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = inversesqrt(vec4(5.454f, 6.44f, 1.413f, 1.1114f));\n"
    "auto c = roundEven(floor(a));\n"
    "}\n",


    "{\n"
    "auto a = sqrt(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = pow(vec4(5.454f, 6.44f, 1.413f, 1.1114f), a);\n"
    "auto c = round(a);\n"
    "}\n",

    "{\n"
    "auto a = log2(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = log(vec4(5.454f, 6.44f, 1.413f, 1.1114f));\n"
    "auto c = ceil(a);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 346.1114f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 89.1114f);\n"
    "auto c = normalize(a) + normalize(b);\n"
    "}\n",

    "{\n"
    "auto a = sin(vec4(1.124f, 65.465f, 0.124f, 75.1114f));\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 123.4f);\n"
    "auto c = tan(a) + cos(b);\n"
    "}\n",

    "{\n"
    "auto a = tan(vec4(1.124f, 214.5f, 65.465f, 0.124f));\n"
    "auto b = atan(vec4(5.454f, 938.34f, 6.44f, 1.41f));\n"
    "auto c = exp(asin(tan(b)));\n"
    "}\n",

    "{\n"
    "auto a = degrees(radians(vec4(1.124f, 65.465f, 1242.f, 0.124f)));\n"
    "auto b = asinh(sinh(tanh(vec4(5.454f, 6.44f, 23423.f, 1.41f))));\n"
    "auto c = acosh(exp2(cosh(b)));\n"
    "}\n",


    //---------------------------------------------------------------------------------------------------
    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = a + b / 3.25f - mat4(1.6f);\n"
    "}\n",

    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    //Temporary =>
    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    "{\n"
    "auto a = mat4(1.0f);\n"
    "auto b = mat4(5.0f);\n"
    "auto c = (transpose(a + b) / 3.25f - mat4(1.6f)) * mat4(2.56f);\n"
    "}\n",

    //-------------------------------------------------------------------------------------------------------------------

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = mat3(5.0f);\n"
    "auto c = a + b / 3.25f - mat3(1.6f);\n"
    "}\n",

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    //Teporary =>

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    "{\n"
    "auto a = mat3(1.0f);\n"
    "auto b = transpose(mat3(5.0f));\n"
    "auto c = a + b / 3.25f - transpose(mat3(1.6f));\n"
    "}\n",

    //----------------------------QUATERNION------------------------------------------
    "{\n"
    "auto a = quat(1.3f, 0.7f, 2.8f, 3.2f);\n"
    "auto b = normalize(a);\n"
    "float L = length(b);\n"
    "float A = angle(b);\n"
    "}\n",

    "{\n"
    "quat q(1.0, 0.0, 0.0, 1.0);\n"
    "auto Roll = roll(q);\n"
    "auto Pitch = pitch(q);\n"
    "auto Yaw = yaw(q);\n"
    "auto Angles = eulerAngles(q);\n"
    "}\n",

    "{\n"
    "quat q(1.0, 0.0, 0.0, 1.0);\n"
    "auto k = mat3_cast(q);\n"
    "auto j = mat4_cast(q);\n"
    "}\n",

    "{\n"
    "mat3 a(1.0);\n"
    "mat4 b(1.0);\n"
    "auto q1 = quat_cast(a);\n"
    "auto q2 = quat_cast(b);\n"
    "}\n",

    //doubled

    "{\n"
    "auto a = quat(1.3f, 0.7f, 2.8f, 3.2f);\n"
    "auto b = normalize(a);\n"
    "float L = length(b);\n"
    "float A = angle(b);\n"
    "}\n",

    "{\n"
    "quat q(1.0, 0.0, 0.0, 1.0);\n"
    "auto Roll = roll(q);\n"
    "auto Pitch = pitch(q);\n"
    "auto Yaw = yaw(q);\n"
    "auto Angles = eulerAngles(q);\n"
    "}\n",

    "{\n"
    "quat q(1.0, 0.0, 0.0, 1.0);\n"
    "auto k = mat3_cast(q);\n"
    "auto j = mat4_cast(q);\n"
    "}\n",

    "{\n"
    "mat3 a(1.0);\n"
    "mat4 b(1.0);\n"
    "auto q1 = quat_cast(a);\n"
    "auto q2 = quat_cast(b);\n"
    "}\n",

};

/*
 * const std::function<std::string()> snippents[] = {
    []() -> std::string {

    }
};

*/
