#pragma once

#include "string"

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
    "auto d = clamp(a, b, c);\n"
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
    "auto c = distance(a,b);\n"
    "auto d = reflect(a, c);\n"
    "auto r = refract(a, c, 0.343f);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = exp2(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = sign(mod(a,b));\n"
    "}\n",

    "{\n"
    "auto a = abs(vec3(1.124f, -65.465f, 0.124f));\n"
    "auto b = inversesqrt(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = trunc(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = sqrt(vec3(5.454f, 6.44f, 1.41f));\n"
    "auto c = floor(a,b);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec3(1.124f, 65.465f, -0.124f));\n"
    "auto b = pow(vec3(5.454f, 6.44f, 1.41f), a);\n"
    "auto c = round(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = ceil(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = roundEven(floor(a,b));\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = trunc(a,b);\n"
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
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.4ff);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "auto d = faceforward(a, b, c);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114f);\n"
    "auto b = length(vec4(5.454f, 6.44f, 1.41f, 0.1114f));\n"
    "auto c = distance(a,b);\n"
    "auto d = reflect(a, c);\n"
    "auto r = refract(a, c, 0.343f);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 615.465f, 0.124f, 0.1114f);\n"
    "auto b = vec4(5.454f, 6.44f, 1.413f, 1.1114f);\n"
    "auto c = mod(a,b);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = vec4(5.454f, 6.44f, 1.413f, 1.1114f);\n"
    "auto c = trunc(a,b);\n"
    "}\n",

    "{\n"
    "auto a = abs(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = inversesqrt(vec4(5.454f, 6.44f, 1.413f, 1.1114f));\n"
    "auto c = roundEven(floor(a,b));\n"
    "}\n",


    "{\n"
    "auto a = sqrt(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = pow(vec4(5.454f, 6.44f, 1.413f, 1.1114f), a);\n"
    "auto c = round(a,b);\n"
    "}\n",

    "{\n"
    "auto a = log2(vec4(1.124f, 615.465f, 0.124f, 0.1114f));\n"
    "auto b = log(vec4(5.454f, 6.44f, 1.413f, 1.1114f));\n"
    "auto c = ceil(a,b);\n"
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


};

/*
 * const std::function<std::string()> snippents[] = {
    []() -> std::string {

    }
};

*/
