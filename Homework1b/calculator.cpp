//  :)
#include<string>
using std::string;
#include <iostream>
using std::cout, std::cin, std::endl, std::getline, std::stoi;
int main() {
  while (1) {
    string operation, left, right;
    cout << "operation: ";
    getline(cin, operation);
    if (operation == "") {
      return 0;
    }
    if (operation != "add" && operation != "subtract" && operation != "multiply" && operation != "divide" && operation != "mod") {
      cout << operation << " isn't a valid operation" << endl;
      continue;
    }
    cout << "left operand: ";
    getline(cin, left);
    int leftint = stod(left);
    cout << "right operand: ";
    getline(cin, right);
    int rightint = stod(right);
    if (operation == "add") {
      cout << leftint + rightint << endl;
    }else if (operation == "subtract") {
      cout << leftint - rightint << endl;
    }else if (operation == "multiply") {
      cout << leftint * rightint << endl;
    }else if (operation == "divide") {
      cout << leftint / rightint << endl;
    }else{
      cout << leftint % rightint << endl;
    }
  }
}
