#include <gtest/gtest.h>

#include <zcm/vec2.hpp>
#include <zcm/vec3.hpp>
#include <zcm/vec4.hpp>

#include <zcm/geometric.hpp>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/geometric.hpp>

using namespace zcm;

const auto a1 = 1.66564118f;
const auto b1 = 9.45687f;

const auto a2 = 65.4578f;
const auto b2 = 12.15787f;

const auto a3 = 4.4568f;
const auto b3 = 32.12478f;

const auto a4 = 0.1247f;
const auto b4 = 78.4577f;


//
// Usage tests
//

TEST(geometric, dot)
{
    ASSERT_FLOAT_EQ(dot(a1,b1),   glm::dot(a1,b1));
    ASSERT_FLOAT_EQ(dot(vec2(a1, a2),vec2(b1, b2)),
                    glm::dot(glm::vec2(a1, a2),glm::vec2(b1, b2)));
    ASSERT_FLOAT_EQ(dot(vec3(a1, a2, a3), vec3(b1, b2, b3)),
                    glm::dot(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3)));

    ASSERT_FLOAT_EQ(dot(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4)),
                    glm::dot(glm::vec4(a1, a2, a3, a4),glm::vec4(b1, b2, b3, b4)));
}

TEST(geometric, distance)
{
    ASSERT_FLOAT_EQ(distance(a1,b1),   glm::distance(a1,b1));

    ASSERT_FLOAT_EQ(distance(vec2(a1, a2),vec2(b1, b2)),
                    glm::distance(glm::vec2(a1, a2),glm::vec2(b1, b2)));

    ASSERT_FLOAT_EQ(distance(vec3(a1, a2, a3), vec3(b1, b2, b3)),
                    glm::distance(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3)));

    ASSERT_FLOAT_EQ(distance(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4)),
                    glm::distance(glm::vec4(a1, a2, a3, a4),glm::vec4(b1, b2, b3, b4)));
}

TEST(geometric, length)
{
    ASSERT_FLOAT_EQ(length(a1),   glm::length(a1));

    ASSERT_FLOAT_EQ(length(vec2(a1, a2)),
                    glm::length(glm::vec2(a1, a2)));

    ASSERT_FLOAT_EQ(length(vec3(a1, a2, a3)),
                    glm::length(glm::vec3(a1, a2, a3)));

    ASSERT_FLOAT_EQ(length(vec4(a1, a2, a3, a4)),
                    glm::length(glm::vec4(a1, a2, a3, a4)));
}

TEST(geometric, normalize)
{
    {
        auto zcmVal = normalize(vec2(a1, a2));
        auto glmVal = glm::normalize(glm::vec2(a1, a2));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
    }

    {
        auto zcmVal = normalize(vec3(a1, a2, a3));
        auto glmVal = glm::normalize(glm::vec3(a1, a2, a3));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
    }

    {
        auto zcmVal = normalize(vec4(a1, a2, a3, a4));
        auto glmVal = glm::normalize(glm::vec4(a1, a2, a3, a4));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
        ASSERT_FLOAT_EQ(zcmVal.w, glmVal.w);
    }
}

TEST(geometric, reflect)
{
    ASSERT_FLOAT_EQ(reflect(a1,b1),   glm::reflect(a1,b1));

    {
        auto zcmVal = reflect(vec2(a1, a2),vec2(b1, b2));
        auto glmVal = glm::reflect(glm::vec2(a1, a2),glm::vec2(b1, b2));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
    }

    {
        auto zcmVal = reflect(vec3(a1, a2, a3), vec3(b1, b2, b3));
        auto glmVal = glm::reflect(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
    }

    {
        auto zcmVal = reflect(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4));
        auto glmVal = glm::reflect(glm::vec4(a1, a2, a3, a4), glm::vec4(b1, b2, b3, b4));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
        ASSERT_FLOAT_EQ(zcmVal.w, glmVal.w);
    }
}

TEST(geometric, refract)
{
    const auto eta = 0.5f;

    ASSERT_FLOAT_EQ(refract(a1,b1,eta),   glm::refract(a1,b1,eta));

    {
        auto zcmVal = refract(vec2(a1, a2),vec2(b1, b2), eta);
        auto glmVal = glm::refract(glm::vec2(a1, a2),glm::vec2(b1, b2),eta);

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
    }

    {
        auto zcmVal = refract(vec3(a1, a2, a3), vec3(b1, b2, b3),eta);
        auto glmVal = glm::refract(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3),eta);

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
    }

    {
        auto zcmVal = refract(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4),eta);
        auto glmVal = glm::refract(glm::vec4(a1, a2, a3, a4), glm::vec4(b1, b2, b3, b4),eta);

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
        ASSERT_FLOAT_EQ(zcmVal.w, glmVal.w);
    }
}

TEST(geometric, faceforward)
{
    float c1 = 1.1278, c2 = 0.157, c3 = 0.5487, c4 = 4.455;

    ASSERT_FLOAT_EQ(faceforward(a1,b1,c1),   glm::faceforward(a1,b1,c1));

    {
        auto zcmVal = faceforward(vec2(a1, a2),vec2(b1, b2), vec2(c1,c2));
        auto glmVal = glm::faceforward(glm::vec2(a1, a2),glm::vec2(b1, b2), glm::vec2(c1,c2));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
    }

    {
        auto zcmVal = faceforward(vec3(a1, a2, a3), vec3(b1, b2, b3), {c1,c2, c3});
        auto glmVal = glm::faceforward(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3), {c1,c2, c3});

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
    }

    {
        auto zcmVal = faceforward(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4), {c1,c2, c3, c4});
        auto glmVal = glm::faceforward(glm::vec4(a1, a2, a3, a4), glm::vec4(b1, b2, b3, b4), {c1,c2, c3, c4});

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
        ASSERT_FLOAT_EQ(zcmVal.w, glmVal.w);
    }
}

//
// Special cases
//

//TODO: What GLSL spec sad about normalize(vec(0.0f)) ??????
TEST(geometric, norm_null)
{
    {
        auto zcmVal = normalize(vec2(0.0f));
        auto glmVal = glm::normalize(glm::vec2(0.0f));

        ASSERT_EQ(std::isnan(zcmVal.x), std::isnan(glmVal.x));
        ASSERT_EQ(std::isnan(zcmVal.y), std::isnan(glmVal.y));
    }

    {
        auto zcmVal = normalize(vec3(0.0f));
        auto glmVal = glm::normalize(glm::vec3(0.0f));

        ASSERT_EQ(std::isnan(zcmVal.x), std::isnan(glmVal.x));
        ASSERT_EQ(std::isnan(zcmVal.y), std::isnan(glmVal.y));
        ASSERT_EQ(std::isnan(zcmVal.z), std::isnan(glmVal.z));
    }

    {
        auto zcmVal = normalize(vec4(0.0f));
        auto glmVal = glm::normalize(glm::vec4(0.0f));

        ASSERT_EQ(std::isnan(zcmVal.x), std::isnan(glmVal.x));
        ASSERT_EQ(std::isnan(zcmVal.y), std::isnan(glmVal.y));
        ASSERT_EQ(std::isnan(zcmVal.z), std::isnan(glmVal.z));
        ASSERT_EQ(std::isnan(zcmVal.w), std::isnan(glmVal.w));
    }
}


TEST(geometric, faceforward_dot_less_zero)
{
    float c1 = -1.1278, c2 = -0.157, c3 = -0.5487, c4 = -4.455;

    ASSERT_FLOAT_EQ(faceforward(a1,b1, c1),   glm::faceforward(a1,b1,c1));

    {
        auto zcmVal = faceforward(vec2(a1, a2),vec2(b1, b2), vec2(c1,c2));
        auto glmVal = glm::faceforward(glm::vec2(a1, a2),glm::vec2(b1, b2), glm::vec2(c1,c2));

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
    }

    {
        auto zcmVal = faceforward(vec3(a1, a2, a3), vec3(b1, b2, b3), {c1,c2, c3});
        auto glmVal = glm::faceforward(glm::vec3(a1, a2, a3), glm::vec3(b1, b2, b3), {c1,c2, c3});

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
    }

    {
        auto zcmVal = faceforward(vec4(a1, a2, a3, a4), vec4(b1, b2, b3, b4), {c1,c2, c3, c4});
        auto glmVal = glm::faceforward(glm::vec4(a1, a2, a3, a4), glm::vec4(b1, b2, b3, b4), {c1,c2, c3, c4});

        ASSERT_FLOAT_EQ(zcmVal.x, glmVal.x);
        ASSERT_FLOAT_EQ(zcmVal.y, glmVal.y);
        ASSERT_FLOAT_EQ(zcmVal.z, glmVal.z);
        ASSERT_FLOAT_EQ(zcmVal.w, glmVal.w);
    }
}

TEST(geometric, refract_k_less_zero)
{
    //TODO;
}
