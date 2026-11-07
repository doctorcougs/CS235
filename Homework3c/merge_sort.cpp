//
// Created by docto on 2/25/2025.
//
#include <iostream>
using std::cout, std::cin, std::endl, std::getline;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::istream, std::ifstream;

void merge(vector<int> left, vector<int> right, vector<int>& final_result) {
  size_t i = 0, j =0;
  while(i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      final_result.push_back(left[i]);
      i++;
    } else if (left[i] > right[j]) {
      final_result.push_back(right[j]);
      j++;
    } else {
      final_result.push_back(left[i]);
      final_result.push_back(right[j]);
      i++;
      j++;
    }
  }
  while (i < left.size()) {
    final_result.push_back(left[i]);
    i++;
  }
  while (j < right.size()) {
    final_result.push_back(right[j]);
    j++;
  }
  return;
}

vector<int> sort(vector <int>&data) {
  if (data.size() < 2) {
    return data;
  }
  int midpoint = data.size() / 2;
  vector<int> left;
  vector<int> right;
  for (int i = 0; i < midpoint; i++) {
    left.push_back(data[i]);
  }
  for (size_t i = midpoint; i < data.size(); i++) {
    right.push_back(data[i]);
  }
  left = sort(left);
  right = sort(right);
  vector<int> final_result;
  merge(left, right, final_result);
  return final_result;
}


int main(int argc, char const * argv[]) {
    vector<int> input;
    for (int i = 1; i < argc; i++) {
      input.push_back(std::atoi(argv[i]));
    }
    vector<int> final_result = sort(input);
    for (size_t i = 0; i < final_result.size(); i++) {
      cout << final_result[i] << endl;
    }
    return 0;
}