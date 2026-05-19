// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template<typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
    explicit Node(const T& v) : value(v), count(1), left(nullptr), right(nullptr) {}
  };

 private:
  Node* root;

  void insert(Node*& node, const T& value) {
    if (!node) {
      node = new Node(value);
    } else if (value < node->value) {
      insert(node->left, value);
    } else if (value > node->value) {
      insert(node->right, value);
    } else {
      node->count++;
    }
  }

  int depth(Node* node) const {
    if (!node) return -1;
    int l = depth(node->left);
    int r = depth(node->right);
    return 1 + (l > r ? l : r);
  }

  int search(Node* node, const T& value) const {
    if (!node) return 0;
    if (value == node->value) return node->count;
    if (value < node->value) return search(node->left, value);
    return search(node->right, value);
  }

  void destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
  }

 public:
  BST() : root(nullptr) {}
  ~BST() { destroy(root); }

  void insert(const T& value) { insert(root, value); }

  int depth() const { return depth(root); }

  int search(const T& value) const { return search(root, value); }

  Node* getRoot() const { return root; }
};

#endif  // INCLUDE_BST_H_
