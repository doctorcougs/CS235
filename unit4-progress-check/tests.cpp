#include <iostream>

#include "Devector.h"

template <typename T>
std::ostream &operator<<(std::ostream &os, const Devector<T> &vec)
{
    os << "{";
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        os << vec[i] << ", ";
    }
    os << vec[vec.size() - 1] << "}";
    return os;
}

#include "test_utils.h"
#include "timer.h"

TEST(constructor_destructor_const_size_empty, 5)
{
    const Devector<float> vec;
    ASSERT_EQ(vec.size(), 0);
}

TEST(push_pop_front_size, 5)
{
    Devector<int> vec;
    ASSERT_EQ(vec.size(), 0);
    vec.push_front(1);
    vec.push_front(2);
    ASSERT_EQ(vec.size(), 2);
    vec.pop_front();
    ASSERT_EQ(vec.size(), 1);
    vec.pop_front();
    ASSERT_EQ(vec.size(), 0);
}

TEST(push_pop_back_size, 5)
{
    Devector<int> vec;
    ASSERT_EQ(vec.size(), 0);
    vec.push_back(1);
    vec.push_back(2);
    ASSERT_EQ(vec.size(), 2);
    vec.pop_back();
    ASSERT_EQ(vec.size(), 1);
    vec.pop_back();
    ASSERT_EQ(vec.size(), 0);
}

TEST(push_back_contents, 10)
{
    Devector<int> vec;
    std::vector<int> exp;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
        exp.push_back(i);
    }
    ASSERT_VEQ(vec, exp);
}

TEST(push_front_contents, 10)
{
    Devector<int> vec;
    std::vector<int> exp;
    for (int i = 0; i < 5; i++)
    {
        vec.push_front(i);
        exp.push_back(4 - i);
    }
    ASSERT_VEQ(vec, exp);
}

TEST(push_back_grow_contents, 10)
{
    Devector<int> vec;
    std::vector<int> exp;
    for (int i = 0; i < 64; i++)
    {
        vec.push_back(i);
        exp.push_back(i);
    }
    ASSERT_VEQ(vec, exp);
}

TEST(push_front_grow_contents, 10)
{
    Devector<int> vec;
    std::vector<int> exp;
    for (int i = 0; i < 64; i++)
    {
        vec.push_front(i);
        exp.push_back(63 - i);
    }
    ASSERT_VEQ(vec, exp);
}

TEST(front_back_grow_clear_size, 10)
{
    Devector<int> vec;
    ASSERT_EQ(vec.size(), 0);
    size_t N = 100000;
    for (size_t i = 0; i < N; i++)
    {
        vec.push_back(i);
        vec.push_front(i);
    }
    ASSERT_EQ(vec.size(), N * 2);
    vec.clear();
    ASSERT_EQ(vec.size(), 0);
}

TEST(operator_bracket_assignment, 10)
{
    Devector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    vec[0] = 7;
    vec[4] = 8;
    std::vector<int> exp = {7, 1, 2, 3, 8};
    ASSERT_VEQ(vec, exp);
}

TEST(push_pop_contents, 15)
{
    Devector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.pop_front();
    vec.pop_front();

    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_front(1);

    std::vector<int> exp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_VEQ(vec, exp);

    vec.push_front(0);
    vec.push_front(-1);
    vec.push_front(-2);
    vec.push_front(-3);
    vec.pop_back();
    vec.pop_back();

    exp = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
    ASSERT_VEQ(vec, exp);

    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    exp = {-3, -2, -1, 0, 1, 2, 3, 4};
    ASSERT_VEQ(vec, exp);
}

TEST(performance, 20)
{
    Timer timer;
    size_t N = 1000;
    size_t n_rounds = 5;
    Devector<int> vec;

    for (size_t round = 1; round <= n_rounds; round++)
    {
        N *= 10;
        std::cout << "Round " << round << ": N = " << N << std::endl;

        timer.start();
        for (size_t i = 0; i < N; i++)
        {
            vec.push_front(i);
        }

        for (size_t i = 0; i < N; i++)
        {
            vec[i]++;
        }

        while (vec.size() > 0)
        {
            vec.pop_back();
        }

        std::cout << "Time: " << timer.milliseconds() << " ms" << std::endl;
        if (timer.seconds() > 20)
        {
            PARTIAL_CREDIT(round / n_rounds);
        }
    }
}

TEST_MAIN()
