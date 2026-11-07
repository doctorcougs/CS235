#pragma once
#include <cstdlib>
#include <functional>


template <typename T>
class BST
{
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    Node* root;
    size_t tree_size;

    BST() : root(nullptr), tree_size(0){}

    ~BST()
    {
      clear();
    }

    bool _insert_helper(Node*& node, T const &value)
    {
      if (node == nullptr) {
        node = new Node(value);
        return true;
      }
      if (value == node->value) {
        return false;
      }
      if (value < node->value) {
        return _insert_helper(node->left, value);
      }
      if (value > node->value) {
        return _insert_helper(node->right, value);
      }
      return false;
    }

    bool insert(T const &value)
    {
      if (root == nullptr) {
        root = new Node(value);
        tree_size++;
        return true;
      }
      else if (_insert_helper(root, value)) {
        tree_size++;
        return true;
      }
      return false;
    }

    bool _contains_helper(Node*& node, T const & value) {
      if (node == nullptr) {
        return false;
      }
      if (value == node->value) {
        return true;
      }
      if (value < node->value) {
        return _contains_helper(node->left, value);
      }
      if (value > node->value) {
        return _contains_helper(node->right, value);
      }
      return false;
    }

    bool contains(T const &value)
    {
      if (root == nullptr) {
        return false;
      } else {
        return _contains_helper(root, value);
      }
    }

    Node* _successor(Node* node) {
        node = node->left;
        while (node->right != nullptr) {
          node = node->right;
        }
        return node;
    }

    bool _remove_helper(Node*& node, T const &value) {
      if (node == nullptr) {
        return false;
      }

      bool result = false;
      if (value < node->value) {
        result = _remove_helper(node->left, value);
      }
      else if (value > node->value) {
        result = _remove_helper(node->right, value);
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
          Node*successor = _successor(node);
          node->value = successor->value;
          _remove_helper(node->left, node->value);
        }
      }
      return result;
    }

    bool remove(T const &value)
    {
      if (root == nullptr) {
        return false;
      }
      else if (_remove_helper(root, value)) {
        tree_size--;
        return true;
      }
      return false;
    }

    void _inorder_helper(Node* node, std::function<void(T)> visit) const{
        if (node == nullptr) {
          return;
        }
        _inorder_helper(node->left, visit);
        visit(node->value);
        _inorder_helper(node->right, visit);
    }

    void inorder_traversal(std::function<void(T)> visit) const
    {
      _inorder_helper(root, visit);
    }

    void _preorder_helper(Node* node, std::function<void(T)> visit) const{
      if (node == nullptr) {
        return;
      }
      visit(node->value);
      _preorder_helper(node->left, visit);
      _preorder_helper(node->right, visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const
    {
      _preorder_helper(root, visit);
    }

    void _postorder_helper(Node* node, std::function<void(T)> visit) const{
      if (node == nullptr) {
        return;
      }
      _postorder_helper(node->left, visit);
      _postorder_helper(node->right, visit);
      visit(node->value);
    }

    void postorder_traversal(std::function<void(T)> visit) const
    {
      _postorder_helper(root, visit);
    }

    size_t size() const
    {
      return tree_size;
    }

    void _clear_helper(Node*& node) {
      if (node == nullptr) {
        return;
      }
      _clear_helper(node->left);
      _clear_helper(node->right);
      delete node;
      node = nullptr;
    }

    void clear()
    {
      _clear_helper(root);
      tree_size = 0;
      root = nullptr;
    }

};
