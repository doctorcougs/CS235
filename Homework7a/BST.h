#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    Node* root;
    int node_count;

    BST() : root(nullptr), node_count(0) {
        // implement the contructor here
    }

    ~BST() {
        // implement the destructor here
        clear();
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
          node_count++;
          return true;
        }
        Node* temp = root;
        Node* prev_node = nullptr;
        while (temp != nullptr) {
            prev_node = temp;
            if (item == temp->value) {
                return false;
            }else if (item < temp->value) {
                temp = temp->left;
            }else if (item > temp->value) {
              temp = temp->right;
            }
        }
        if (item < prev_node->value) {
          prev_node->left = new Node(item);
        } else {
          prev_node->right = new Node(item);
        }
        node_count++;
        return true;
    }


    Node* in_order(Node* node) { //to find the inorder successor must be given the node to the left
      while (node->right != nullptr) {
        node = node->right;
      }
      return node;
    }


    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree

        if (root == nullptr) {
            return false;
        }
        Node* temp = root;
        Node* prev_node = root;
        while (temp != nullptr && temp->value != item) {
            prev_node = temp;
            if (item < temp->value) {
                temp = temp->left;
            } else if (item > temp->value) {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
          return false;
        }
        if (temp->left == nullptr && temp->right == nullptr) {
            if (temp == root) {
              root = nullptr;
            }
            if (item < prev_node->value) {
              prev_node->left = nullptr;
            } else {
              prev_node->right = nullptr;
            }
            delete temp;
        } else if (temp->right == nullptr) {
            if (temp == root) {
              root = temp->left;
            } else {
                if (item < prev_node->value) {
                    prev_node->left = temp->left;
                } else {
                    prev_node->right = temp->left;
                }
            }
            delete temp;
        } else if (temp->left == nullptr) {
            if (temp == root) {
                root = temp->right;
            } else {
                if (item < prev_node->value) {
                    prev_node->left = temp->right;
                } else {
                    prev_node->right = temp->right  ;
                }
            }
            delete temp;
        } else {
          Node* successor = in_order(temp->left);
          T value = successor->value;
          remove(value);
          temp->value = value;
        }
        node_count--;
        return true;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        if (root == nullptr) {
          return false;
        }
        Node* temp = root;
        while (temp != nullptr) {
            if (item == temp->value) {
              return true;
            } else if (item < temp->value) {
                temp = temp->left;
            } else if (item > temp->value) {
                temp = temp->right;
            }
        }
        return false;
    }
    void recursive_clear (Node* node) {
        if (node == nullptr) {
          return;
        }
        recursive_clear(node->left);
        recursive_clear(node->right);
        delete node;
    }
    void clear() {
        // implement clear here
        // remove all nodes from the tree
        recursive_clear(root);
        node_count = 0;
        root = nullptr;
        return;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return node_count;
    }
};
