//
// Created by docto on 1/23/2025.
//
#include <string>
using std::string;
#include <iostream>
using std::istream, std::cin, std::getline, std::cout, std::endl;
#include <fstream>
using std::ifstream;

bool substring_in_line_at_pos(string const& substring, string const&line, int pos) {
  for (int i = 0; i < substring.size(); i++) {
    if (substring[i] != line[i+pos]) {
      return true;
    }
  }
  return false;
}

bool substring_in_line(string const& substring, string const& line) {
  if (substring.size() > line.size()) {
    return false;
  }
  for (int i = 0; i < line.size() - substring.size() + 1; i++) {
    if (substring
  }
  return false;
}


void greper(string const& substring, istream& input) {
  string line;
  while (getline(input, line)) {
    if (substring_in_line(substring, line)) {
      cout << line << endl;
    }
  }
}


int main(int argc, char *argv[]) {
    string substring = argv[1];
    if (argc < 3) {
      greper(substring, cin);
    } else {
      ifstream input(argv[2]);
      if (!input.is_open()) {
        return 1;
      }
      greper(substring, input);
      input.close();
    }
}