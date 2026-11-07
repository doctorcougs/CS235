// :)
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  int num = atoi(argv[1]);
  while (num > 1) {
      if (num % 2 == 0) {
        cout << num << endl;
        num = num / 2;
        } else {
          cout << num << endl;
          num = (num * 3) + 1;
          }
      }
  cout << num << endl;
  }