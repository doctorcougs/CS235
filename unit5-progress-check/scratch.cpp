#include <iostream>

#include "BST.h"

void print(BST<int>& tree) {
    std::cout << "Inorder: ";
    tree.inorder_traversal([](int value) { std::cout << value << " "; });
    std::cout << std::endl;
    return;
}

int main() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.insert(1);
    print(tree);
    tree.remove(1);
    print(tree);
    tree.remove(5);
    print(tree);

    return 0;
}
