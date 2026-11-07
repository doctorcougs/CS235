#pragma once
#include <cstdlib>
#include <functional>
#include <iostream>
using std::cout, std::endl;


template <typename T>
class BST
{
public:
  struct Node {
    Node* left;
    Node* right;
    T value;

    Node(T item) : left(nullptr), right(nullptr), value(item) {}

  };

    Node* root;
    int _size;

    BST() : root(nullptr), _size(0) {}

    ~BST()
    {
      clear();
    }

    bool insert(T const &value)
    {
      if (root == nullptr) {
        root = new Node(value);
        _size++;
        return true;
      }
      if (insert_helper(value, root)) {
        _size++;
        return true;
      }
      return false;
    }

    bool insert_helper(T const &value, Node*& node)
    {
      if (node == nullptr) {
        node = new Node(value);
        return true;
      }
      if (value == node->value) {
        return false;
      }
      if (value < node->value) {
        return insert_helper(value, node->left);
      }
      if (value > node->value) {
        return insert_helper(value, node->right);
      }
      return false;
    }

    bool contains(T const &value)
    {
      return contains_helper(value, root);
    }

    bool contains_helper(T const &value, Node*& node) {
      if (node == nullptr) {
        return false;
      }
      if (value == node->value) {
        return true;
      }
      if (value < node->value) {
        return contains_helper(value, node->left);
      }
      if (value > node->value) {
        return contains_helper(value, node->right);
      }
      return false;
    }

    bool remove(T const &value)
    {
      if (root == nullptr) {
        return false;
      }
      if (remove_helper(value, root)) {
        _size--;
        return true;
      }
      return false;
    }

    bool remove_helper(T const &value, Node*& node) {
      if (node == nullptr) {
        return false;
      }
      bool result = false;
      if (value < node->value) {
        result = remove_helper(value, node->left);
      }
      else if (value > node->value) {
        result = remove_helper(value, node->right);
      }
      else {
        result = true;
        if (node->left == nullptr && node->right == nullptr) {
          delete node;
          node = nullptr;
        }
        else if (node->right == nullptr) {
          Node* temp = node;
          node = node->left;
          delete temp;
        }
        else if (node->left == nullptr) {
          Node* temp = node;
          node = node->right;
          delete temp;
        }
        else {
          Node* temp = successor(node);
          node->value = temp->value;
          remove_helper(node->value, node->left);
        }
      }
      return result;
    }


    Node* successor (Node*& node) {
      Node* temp = node->left;
      while (temp->right != nullptr) {
        temp = temp->right;
      }
      return temp;
    }

    void inorder_helper(Node* node, std::function<void(T)> visit) const {
      if (node == nullptr) {
        return;
      }
      inorder_helper(node->left, visit);
      visit(node->value);
      inorder_helper(node->right, visit);
    }

    void inorder_traversal(std::function<void(T)> visit) const
    {
      inorder_helper(root, visit);
    }

    void preorder_helper(Node* node, std::function<void(T)> visit) const {
      if (node == nullptr) {
        return;
      }
      visit(node->value);
      preorder_helper(node->left, visit);
      preorder_helper(node->right, visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const
    {
      preorder_helper(root, visit);
    }

    void postorder_helper(Node* node, std::function<void(T)> visit) const {
      if (node == nullptr) {
        return;
      }
      postorder_helper(node->left, visit);
      postorder_helper(node->right, visit);
      visit(node->value);
    }

    void postorder_traversal(std::function<void(T)> visit) const
    {
      postorder_helper(root, visit);
    }

    int size() const
    {
      return _size;
    }

    void clear_helper(Node*& node) {
      if (node == nullptr) {
        return;
      }
      clear_helper(node->left);
      clear_helper(node->right);
      delete node;
      node = nullptr;
    }

    void clear()
    {
      _size = 0;
      clear_helper(root);
    }

};
