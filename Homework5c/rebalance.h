#pragma once

typedef struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
} Node;

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int update_height(Node*& node) {
    if (node == nullptr) {
      return 0;
    }
    int left_height = update_height(node->left);
    int right_height = update_height(node->right);
    node->height = max(left_height, right_height) + 1;
    return node->height;
}

void promote_left(Node*& root) {
    // implement promote_left here
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
    update_height(root->right);
    update_height(root);
}

void promote_right(Node*& root) {
    // implement promote_right here
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
    update_height(root->left);
    update_height(root);
}

void balance(int& v, Node*& root) {
  v = update_height(root->right) - update_height(root->left);
  return;
}

void rebalance(Node*& root) {
    // implement rebalance here
    if (root == nullptr) {
      return;
    }
    int balance_state;
    balance(balance_state, root);
    if (balance_state == 0 || balance_state == 1 || balance_state == -1) { // balanced tree
      return;
    }
    if (balance_state >= 2) {
      balance(balance_state, root->right);
      if (balance_state >= 0) { // right right tree
        promote_right(root);
      } else { // right left tree
        promote_left(root->right);
        promote_right(root);
      }
    } else if (balance_state <= -2) {
      balance(balance_state, root->left);
      if (balance_state <= 0) { // left left tree
        promote_left(root);
      } else { // left right tree
        promote_right(root->left);
        promote_left(root);
      }
    }

}
