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
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = distance(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec3(1.124f, 65.465f, 0.124f);\n"
    "auto b = vec3(5.454f, 6.44f, 1.41f);\n"
    "auto c = normalize(a);\n"
    "}\n",

    //----------------------------------------------------------------------

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.1114);\n"
    "auto c = dot(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.1114);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.1114);\n"
    "auto c = a+b-a/0.262f*(b*1.1f);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.1114);\n"
    "auto c = distance(a,b);\n"
    "}\n",

    "{\n"
    "auto a = vec4(1.124f, 65.465f, 0.124f, 0.1114);\n"
    "auto b = vec4(5.454f, 6.44f, 1.41f, 0.1114);\n"
    "auto c = normalize(a) + normalize(b);\n"
    "}\n",


};

/*
 * const std::function<std::string()> snippents[] = {
    []() -> std::string {

    }
};

*/
