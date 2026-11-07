#include "test_utils.h"

#include "stack.h"
#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;


TEST(initial_size_is_0, 20) {
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0, "Stack size should be 0")
}

TEST(add_items_changes_size, 20) {
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0, "Stack size starts at 0")
    for (int i = 1; i < 6; i++) {
        NOISY(stack, push, i)
        ASSERT_EQ(stack.size(), i, "Stack size should match push count")
    }
}

TEST(remove_items_changes_size, 20) {
    Stack<int> stack;
    for (int i = 1; i < 6; i++) {
        NOISY(stack, push, i)
    }
    ASSERT_EQ(stack.size(), 5, "Stack size should be 5")
    for (int i = 4; i > -1; i--) {
        NOISY(stack, pop)
        ASSERT_EQ(stack.size(), i, "Stack size should reduce when pop is called")
    }
}

TEST(top_returns_correct_item, 20) {
    Stack<int> stack;
    for (int i = 0; i < 5; i++) {
        NOISY(stack, push, i)
    }
}

TEST(add_remove_add_items, 20) {
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0, "Stack size should be 0")
    for (int i = 0; i < 100; i++) {
        NOISY(stack, push, i)
    }
    ASSERT_EQ(stack.size(), 100, "Stack size should be 100")
    for (int i = 0; i < 50; i++) {
        NOISY(stack, pop)
    }
    ASSERT_EQ(stack.size(), 50, "Stack size should be 50")
    for (int i = 0; i < 100; i++) {
        NOISY(stack, push, i)
    }
    ASSERT_EQ(stack.size(), 150, "Stack size should be 150")
}

TEST_MAIN()
