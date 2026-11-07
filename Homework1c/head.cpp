#include <iostream>
using std::cout, std::cin, std::endl, std::getline, std::istream;
#include <string>
using std::string, std::stoi;
#include <fstream>
using std::ifstream;


void line_reading(istream& infile, int const& n) {
  string line;
  for (int i = 0; i < n; i++) {
      getline(infile, line);
      cout << line << endl;
  }
}

void line_count(istream& infile, int& n) {
  int line_count = 0;
  string line;
  while (getline(infile, line)) {
    line_count++;
  }
  infile.clear();
  infile.seekg(0);
  if (line_count < n) {
    n = line_count;
  }
  line_reading(infile, n);
}

int main(int argc, char const * argv[]) {
  string holding_cell;
  if (argc > 1) {
    holding_cell = argv[1];
    if (holding_cell[0] == '-') {
      holding_cell = holding_cell.substr(1);
    }
  }
  int n;
  string filename;
  ifstream infile;
  if (argc == 1) {
      n = 10;
      line_reading(cin, n);
  } else if (argc == 2) {
    filename = holding_cell;
    try {
      n = stoi(filename);
      line_reading(cin, n);
    } catch (std::invalid_argument const& e) {
      n = 10;
      ifstream infile(filename);
      if (!infile.is_open()) {
        return 1;
      }
      line_count(infile, n);
    } catch (std::out_of_range const& e) {
      n = 10;
      ifstream infile(filename);
      if (!infile.is_open()) {
        return 1;
      }
      line_count(infile, n);
      infile.close();
    }
  } else if (argc == 3) {
    n = stoi(holding_cell);
    filename = argv[2];
    ifstream infile(filename);
    if (!infile.is_open()) {
      return 1;
    }
    line_count(infile, n);
    infile.close();
  }
  return 0;
}