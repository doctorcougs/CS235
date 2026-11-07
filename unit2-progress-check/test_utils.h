#pragma once
/*
    TEST UTILS
*/
#include <iostream>
#include <vector>
#include <cstring>

// Overload operator<< for std::vector<T>
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

// So you can use commas as well as left-shifts to print to an ostream
// (so our __VA_ARGS__ expansion works in NOISY)
template <typename T>
std::ostream& operator,(std::ostream& out, const T& t) {
  out << t;
  return out;
}

std::vector<void(*)(int)> tests;
void register_test(void(*test)(int)) {
    tests.push_back(test);
}

struct FailedTest {};

#define TEST(name, points_possible) \
    void _##name(); \
    void name(int which) {\
        std::cout << endl << "TEST #" << which << " " << #name << endl; \
        try { \
            _##name(); \
            std::cout << "RESULT|PASSED|" << #name << "|" << #points_possible << "|" << #points_possible << endl; \
        } catch (FailedTest) { \
            std::cout << "RESULT|FAILED|" << #name << "|" << #points_possible << "|" << 0 << endl; \
        } \
    } \
    struct name##_registrar { \
        name##_registrar() { register_test(name); } \
    } name##_registrar_instance; \
    void _##name()

#define CONCAT_DETAIL(x, y) x##y
#define CONCAT(x, y) CONCAT_DETAIL(x, y)
#define NOISY(obj, method, ...) std::cout << #obj << "." << #method << "(" , ##__VA_ARGS__; cout << ");" << std::endl; obj.method(__VA_ARGS__);
#define ASSERT_EQ(expr, val, ...) auto CONCAT(_val, __LINE__) = expr; std::cout << "ASSERT: " << #expr << " == " << val << std::endl; if (CONCAT(_val, __LINE__) != val) { std::cout << "ERROR: " << CONCAT(_val, __LINE__) << " != " << val << " ", ##__VA_ARGS__; std::cout << std::endl; throw FailedTest(); }

#define TEST_MAIN() \
int main(int argc, char *argv[]) \
{ \
    if (argc < 2 || strcmp("all", argv[1]) == 0) { \
        for (int i = 0; i < tests.size(); i++) { \
            tests[i](i); \
        } \
    } else { \
        int which = atoi(argv[1]); \
        tests[which](which); \
    } \
} \

/*
    END TEST UTILS
*/