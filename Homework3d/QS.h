#pragma once

#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::cin, std::getline;
#include <algorithm>
using std::swap;
template <class T>
int median_of_three(int left, int right, vector<T>& array) {
  int mid = (left + right) / 2;
  if (array[left] > array[mid]) {
    swap(array[left], array[mid]);
  }
  if (array[mid] > array[right]) {
    swap(array[mid], array[right]);
  }
  if (array[left] > array[mid]) {
    swap(array[left], array[mid]);
  }
  return mid;
}

template <class T>
int partition(vector<T> & array, int left, int right, int pivoti) {
  swap(array[pivoti], array[left]);
  int up = left + 1, down = right;
  do {
    while ((array[up] <= array[left]) && (up <= right)) {
      up++;
    }
    while ((array[down] > array[left]) && (down > left)) {
      down--;
    }
    if (up < down) {
      swap(array[up], array[down]);
    }
  }while (up < down);
  swap (array[left], array[down]);
  return down;
}

template <class T>
void helper_sort(vector<T>& array, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = median_of_three(left, right, array);
  pivot = partition(array, left, right, pivot);
  helper_sort(array, left, pivot -1);
  helper_sort(array, pivot + 1, right);
}

template <class T>
void sort(vector<T> &array)
{
  helper_sort(array, 0, array.size() - 1);
  // implement sort here
  // hint: you'll probably want to make a recursive sort_helper function
}