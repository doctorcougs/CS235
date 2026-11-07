#include <iostream>
using std::cout, std::cin, std::endl, std::istream, std::getline;
#include <string>
using std::string;
#include <unordered_set>
using std::unordered_set;
#include <fstream>
using std::ifstream;

void file_reader(istream& infile, unordered_set<string> &exclusives) {
  string line;
  while (getline(infile, line)) {
    auto repeat_check = exclusives.insert(line);
    if (repeat_check.second) {
      cout << line << endl;
    }
  }
}

void file_opener(string &filename, ifstream& infile) {
  infile.open(filename);
  if (!infile.is_open()) {
    cout << "file didn't open" << endl;
    exit(0);
  }
}

int main(int argc, char const* argv[]) {
  // Write your code here
  unordered_set<string> exclusives;
  if (argc == 2) {
    string filename = argv[1];;
    ifstream infile;
    file_opener(filename, infile);
    file_reader(infile, exclusives);
    infile.close();
  }else {
    file_reader(cin, exclusives);
  }
  return 0;
}
