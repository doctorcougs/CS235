//
// Created by docto on 4/22/2025.
//
#include <iostream>
using std::cout, std::endl;
#include "BST.h"
int main() {
  BST<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  cout << tree.contains(10)<< endl;
  tree.remove(10);
  cout << tree.contains(10)<< endl;
  cout << tree.contains(20)<< tree.contains(5) << endl;


  return 0;
}