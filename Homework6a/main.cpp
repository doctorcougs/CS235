//
// Created by docto on 4/4/2025.
//
#include <iostream>
using std::cout, std::endl;
#include "HashSet.h"
#include <string>

int main(int argc, char const* argv[]) {
    HashSet<int> set;
    cout << set.contains(1) << endl;
    cout << set.insert(1) << endl;
    cout << set.contains(1) << endl;
    cout << set.remove(1) << endl;
    cout << set.contains(1) << endl;

}