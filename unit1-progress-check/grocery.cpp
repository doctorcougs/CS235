//
// Created by docto on 1/28/2025.
//
#include <iostream>
using std::cout, std::cin, std::endl, std::getline, std::istream;
#include <vector>
using std::vector;
#include <string>
using std::string;

istream& input(string prompt, string& line) {
  cout << prompt;
  return getline(cin, line);
}

void get_grocery_list(vector<string> & grocery_list) {
  string line;
  while (input ("item: ", line) && line != "") {
    grocery_list.push_back(line);
  }
}

void print_grocery_list(vector<string> const& grocery_list) {
  for (auto const& grocery : grocery_list) {
    cout << "- " << grocery << endl;
  }
}

int main() {
  vector<string> grocery_list;
  get_grocery_list(grocery_list);
  print_grocery_list(grocery_list);
}