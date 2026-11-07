#include <cstdlib>  // atof
#include <iostream>
using namespace std;
using std::abs;  

const double EPSILON = 0.0001;

int main (int argc, const char * argv[])
  {
  const double input = stod(argv[1]);
  if (input < 0)
    {
    cout << "Input must be greater than 0" << endl;
    return 1;
    }
  double upnum = input;
  double lownum = 0;
  double val = upnum / 2;
  while (abs((val * val) - input) > EPSILON)
    {
    if (val * val > input)
      {
      upnum = val;
      }
    if (val * val < input)
      {
      lownum = val;
      }
    cout << val << " (" << val * val << ")" << endl;
    val = (upnum + lownum) / 2;
    }
  cout << val << " (" << val * val << ")" << endl;
  }

// :)
