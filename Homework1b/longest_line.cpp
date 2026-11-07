//  :-)
#include <fstream>
using std::endl, std::ifstream, std:: ofstream, std::getline;
#include<string>
using std::string, std::stoi, std::stod;
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;


int main(int argc, const char * argv[]) {
  string userinfile = argv[1];
  ifstream infile(userinfile);
  if (!infile.is_open()) {
    return 1;
  }
  string line;
  string largest_line;
  size_t largest_length = 0;
  while (getline(infile, line)) {
    string s;
    stringstream ss(line);
    vector<string> v;
    while (getline(ss, s, ' ')) {
      v.push_back(s);
    }
    if (v.size() > largest_length) {
      largest_length = v.size();
      largest_line = line;
    }
  }
  cout << largest_line << endl;
}