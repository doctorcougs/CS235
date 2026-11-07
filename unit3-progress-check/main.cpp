//
// Created by docto on 3/3/2025.
//

#include <vector>
using std::vector, std::size_t;
#include <iostream>
using std::cout, std::endl;

template <typename T>
void merge(vector<T>& items, vector<T>& left, vector<T>& right) {
  items.clear();
  size_t i = 0, j = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      items.push_back(left[i]);
      i++;
    } else if (left[i] > right[j]) {
      items.push_back(right[j]);
      j++;
    }
  }
  while (i < left.size()) {
    items.push_back(left[i]);
    i++;
  }
  while (j < right.size()) {
    items.push_back(right[j]);
    j++;
  }
  return;
}
template <typename T>
void split(const vector<T>&items, vector<T> &left, vector<T> &right) {
  int size = items.size();
  int halfSize = size / 2;
  for (int i = 0; i < halfSize; i++) {
    left.push_back(items[i]);
  }
  for (int i = halfSize; i < size; i++) {
    right.push_back(items[i]);
  }
  return;
}
template <typename T>
void sort(vector<T>& items) {
  if (items.size() < 2) {
    return;
  }
  vector<T> left, right;
  split(items, left, right);
  sort(left);
  sort(right);
  merge(items, left, right);
}
int main() {
  vector<int> data = {1, 3, 5, 7, 2, 4, 6, 8, 11, 10, 9};
  sort(data);
  for (auto i : data) {
    cout << i << " ";
  } cout << endl;
  return 0;
}