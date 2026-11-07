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
  const string userinfile = argv[1]; // declaring variables
  const string useroutfile = argv[2];
  ifstream infile(userinfile);
  ofstream outfile(useroutfile);
  if (!infile.is_open()) { // checking if my files are actually open
    return 1;
  }
  if (!outfile.is_open()) {
    return 1;
  }
  string line;
  while (getline(infile, line)) { //reads each line in the infile and puts it in my string line variable
    string s;
  	stringstream ss(line);
  	vector<string> v;
	while (getline(ss, s, ' ')) { //this splits the line by spaces and then adds it to a vector (like a list but c++ version)
      v.push_back(s);
	}
    int points = stoi(v[2]);
    double factor = stod(v[3]);
    outfile << v[1] << ", " << v[0] << ": " << points * factor << endl;
  }
  infile.close();
  outfile.close();
}