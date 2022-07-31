#include "gtest/gtest.h"
#include "vec2.hpp"
#include "vec3.hpp"
#include "utility.hpp"

#include <cmath>
namespace GothEngine::math::tests
{
    TEST(test_math, vec2_create)
    {
        auto vec3 = vector::vec3_t{1.1, 2.2, 3.3};
        EXPECT_FLOAT_EQ(vec3.x(), 1.1);
        EXPECT_FLOAT_EQ(vec3.y(), 2.2);
        EXPECT_FLOAT_EQ(vec3.z(), 3.3);
    }

    TEST(test_math, vec3_create)
    {
        auto vec3 = vector::vec3_t{1.1, 2.2, 3.3};
        EXPECT_FLOAT_EQ(vec3.x(), 1.1);
        EXPECT_FLOAT_EQ(vec3.y(), 2.2);
        EXPECT_FLOAT_EQ(vec3.z(), 3.3);
    }

    TEST(test_math, vec2_negate)
    {
        auto test_vec = vector::vec2_t{1, 2};
        test_vec.negate();
        EXPECT_TRUE((test_vec == vector::vec2_t{-1, -2}));
    }

    TEST(test_math, vec3_negate)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        test_vec.negate();
        EXPECT_TRUE((test_vec == vector::vec3_t{-1, -2, -3}));
    }

    TEST(test_math, vec2_add)
    {
        auto test_vec = vector::vec2_t{1, 2};
        test_vec += vector::vec2_t{2, 3};

        EXPECT_TRUE((test_vec == vector::vec2_t{3, 5}));
    }

    TEST(test_math, vec3_add)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        test_vec += vector::vec3_t{2, 3, 4};

        EXPECT_TRUE((test_vec == vector::vec3_t{3, 5, 7}));
    }

    TEST(test_math, vec2_substraction)
    {
        auto test_vec = vector::vec2_t{1, 3};
        test_vec -= vector::vec2_t{2, 3};

        EXPECT_TRUE((test_vec == vector::vec2_t{-1, 0}));
    }

    TEST(test_math, vec3_substraction)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        test_vec -= vector::vec3_t{2, 2, -14};

        EXPECT_TRUE((test_vec == vector::vec3_t{-1, 0, 17}));
    }

    TEST(test_math, vec2_multiply)
    {
        auto test_vec = vector::vec2_t{1, 2};
        test_vec *= 2;

        EXPECT_TRUE((test_vec == vector::vec2_t{2, 4}));
    }

    TEST(test_math, vec3_multiply)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        test_vec *= 2;

        EXPECT_TRUE((test_vec == vector::vec3_t{2, 4, 6}));
    }

    TEST(test_math, vec2_division)
    {
        auto test_vec = vector::vec2_t{1, 2};
        test_vec /= 2;

        EXPECT_TRUE((test_vec == vector::vec2_t{0.5, 1}));
    }

    TEST(test_math, vec3_division)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        test_vec /= 2;

        EXPECT_TRUE((test_vec == vector::vec3_t{0.5, 1, 1.5}));
    }

    TEST(test_math, vec2_length)
    {
        auto test_vec = vector::vec2_t{3, 4};
        EXPECT_FLOAT_EQ(test_vec.length(), 5);
    }

    TEST(test_math, vec3_length)
    {
        auto test_vec = vector::vec3_t{1, 2, 3};
        EXPECT_FLOAT_EQ(test_vec.length(), utility::fast_sqrt(14));
    }

    TEST(test_math, vec2_unit_vec)
    {
        auto test_vec = vector::vec2_t{3, 4};
        auto unit_vec = unit_vector(test_vec);

        EXPECT_TRUE((unit_vec == vector::vec2_t{0.6, 0.8}));
    }

    TEST(test_math, vec3_unit_vec)
    {
        auto test_vec = vector::vec3_t{0, 0, 1};
        auto unit_vec = unit_vector(test_vec);

        EXPECT_TRUE((unit_vec == vector::vec3_t{0, 0, 1}));
    }

    TEST(test_math, vec2_distance)
    {
        auto start = vector::vec2_t{5, 0};
        auto end = vector::vec2_t{-1, 8};

        EXPECT_FLOAT_EQ(distance(start, end), 10);
    }

    TEST(test_math, vec3_distance)
    {
        auto start = vector::vec3_t{5, 0, 0};
        auto end = vector::vec3_t{-1, 8, 0};

        EXPECT_FLOAT_EQ(distance(start, end), 10);
    }

    TEST(test_math, vec2_dot)
    {
        auto u = vector::vec2_t{4, 6};
        auto v = vector::vec2_t{-3, 7};

        EXPECT_FLOAT_EQ(dot(u, v), 30);
    }

    TEST(test_math, vec3_dot)
    {
        auto u = vector::vec3_t{3, -2, 7};
        auto v = vector::vec3_t{0, 4, -1};

        EXPECT_FLOAT_EQ(dot(u, v), -15);
    }

    TEST(test_math, vec3_cross)
    {
        auto u = vector::vec3_t{1, 3, 4};
        auto v = vector::vec3_t{2, -5, 8};

        EXPECT_TRUE((cross(u, v) == vector::vec3_t{44, 0, -11}));
    }

    TEST(test_math, sqrt)
    {
        EXPECT_FLOAT_EQ(utility::fast_sqrt(100), std::sqrt(100));
    }
}