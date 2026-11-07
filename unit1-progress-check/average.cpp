// :)
#include <iostream>
using std::cout, std::endl;

int main(int argc, const char * argv[]) {
  float holding_cell;
  float total = 0;
  for (int i = 1; i < argc; i++) {
    holding_cell = atof(argv[i]);
    total += holding_cell;
  }
  total = total / (argc - 1);
  cout << total << endl;
}