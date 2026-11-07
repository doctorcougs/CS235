#include <iostream>
using std::cout, std::cin, std::endl, std::getline;
#include <fstream>
using std::ifstream, std::istream;
#include <string>
using std::string;
#include <vector>
using std::vector;

void sortamf(vector<string>& list) {
  for (size_t i = 0; i < list.size(); i++) { //cycles through the big list
    for (size_t j = i; j > 0; j--) { //cycles through sorted list backwards from the newest thing added
      if (list[j] < list[j - 1]) {
        string temp = list[j - 1];
        list[j - 1] = list[j];
        list[j] = temp;
      } else {
        break;
      }
    }
  }
}

void into_vector(istream& input, vector<string>& result) {
  string line;
  while (getline(input, line) && !line.empty()) {
    result.push_back(line);
  }
}

int main(int argc, char const* argv[]) {
  vector<string> result;
  if (argc == 1) {
    into_vector(cin, result);
  }
  if (argc == 2) {
    ifstream input(argv[1]);
    if (!input.is_open()) {
      return 1;
    }
    into_vector(input, result);
  }
  sortamf(result);
  for (size_t i = 0; i < result.size(); i ++) {
    cout << result[i] << endl;
  }
  return 0;
}