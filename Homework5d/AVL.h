#pragma once

template<class T>
class AVL {

public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    Node* root;
    int _AVL_size;

    AVL() : root(nullptr), _AVL_size(0) {
        // implement the contructor here
    }

    ~AVL() {
        // implement the destructor here
        clear();
    }

    int _max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    void _update_height(Node*& node) {
        if (node == nullptr) {
            return;
        }
        int left_height = (node->left != nullptr) ? node->left->height : 0;
        int right_height = (node->right != nullptr) ? node->right->height : 0;
        node->height = _max(left_height, right_height) + 1;
    }

    void _promote_left (Node*& node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
        _update_height(node->right);
        _update_height(node);
    }

    void _promote_right (Node*& node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
        _update_height(node->left);
        _update_height(node);
    }
    int _balance (Node*& node) {
        if (node == nullptr) {
          return 0;
        }
        int right_height = (node->right != nullptr) ? node->right->height : 0;
        int left_height = (node->left != nullptr) ? node->left->height : 0;
        return right_height - left_height;
    }

    void _rebalance (Node*& node) {
        if (node == nullptr) {
          return;
        }
        int balance_state = _balance(node);
        if (balance_state < -1) {
            if (_balance(node->left) > 0) {
                _promote_right(node->left);
            }
            _promote_left(node);
        }
        else if (balance_state > 1) {
            if (_balance(node->right) < 0) {
                _promote_left(node->right);
            }
            _promote_right(node);
        }
    }

    bool _insert_helper (Node*& node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            _AVL_size++;
            return true;
        }
        bool result = false;
        if (item < node->value) {
            if (_insert_helper(node->left, item)) {
                result = true;
            }
        }
        else if (item > node->value) {
            if (_insert_helper(node->right, item)) {
                result = true;
            }
        } else {
            result = false;
        }
        _update_height(node);
        _rebalance(node);
        return result;
    }

    bool _contains_helper(const Node* node, T item) const{
      if (node == nullptr) {
        return false;
      }
      if (item == node->value) {
        return true;
      }
      if (item < node->value) {
        return _contains_helper(node->left, item);
      }
      if (item > node->value) {
        return _contains_helper(node->right, item);
      }
      return false;
    }

    Node* _inorder_successor (Node* node) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    bool _remove_helper(Node*& node, T item) {
      if (node == nullptr) {
        return false;
      }
      bool result = false;
      if (item < node->value) {
        result = _remove_helper(node->left, item);
      }
      else if (item > node->value) {
        result = _remove_helper(node->right, item);
      } else {
        result = true;
        if (node->left == nullptr && node->right == nullptr) {
          delete node;
          node = nullptr;
        } else if (node->left == nullptr) {
          Node* temp = node;
          node = node->right;
          delete temp;
        } else if (node->right == nullptr) {
          Node* temp = node;
          node = node->left;
          delete temp;
        } else {
          Node* temp = _inorder_successor(node);
          node->value = temp->value;
          _remove_helper(node->left, node->value);
        }
      }
      if (node != nullptr) {
          _update_height(node);
          _rebalance(node);
      }
      return result;
    }

    void _clear_helper(Node* node) {
      if (node == nullptr) {
        return;
      }
      _clear_helper(node->left);
      _clear_helper(node->right);
      delete node;
      node = nullptr;
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        if (root == nullptr) {
          root = new Node(item);
          _AVL_size++;
          return true;
        }
        return _insert_helper(root, item);
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        if (_remove_helper(root, item)) {
          _AVL_size--;
          return true;
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return _contains_helper(root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        _clear_helper(root);
        _AVL_size = 0;
        root = nullptr;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return _AVL_size;
    }
};
