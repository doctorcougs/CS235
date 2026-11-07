// :)
#include <iostream>
using std::cout, std::cin, std::endl, std::istream, std::getline, std::ostream;
#include <fstream>
using std::ifstream, std::ofstream;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
#include <cstdlib>
using std::rand, std::srand;
#include <ctime>
using std::ctime;

unordered_map<string, vector<string>> matching (istream& in) {
  string line;
  string previous = "";
  string current;
  unordered_map<string, vector<string>> matches;
  while (in >> line) {
    current = line;
    matches[previous].push_back(line);
    previous = current;
  }
  return matches;
}

void generator (unordered_map<string, vector<string>> matches, string start, int wordnum) {
  srand(time(0));
  vector <string> words;
  words.push_back(start);
  for (int i = 0; i < wordnum; i++) {
    int random_index = rand() % matches[start].size();
    words.push_back(matches[start][random_index]);
    start = matches[start][random_index];
  }
  for (auto const & word : words) {
    cout << word << " ";
  }
  cout << endl;
}

int main(int argc, char const * argv[]) {
  ifstream file(argv[1]);
  auto matches = matching(file);
  string start = "";
  int wordnum = atoi(argv[2]);
  generator(matches, start, wordnum);
}