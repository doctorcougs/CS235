#include <iostream>
using std::cout, std::endl, std::cin, std::getline;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;
#include <unordered_map>
using std::unordered_map;

void add(priority_queue<int> & prioqueue, unordered_map<int, string> & prio_name){
  string name;
  string prio;
  int real_prio;
  cout << "Name: ";
  getline(cin, name);
  cout << "Priority: ";
  getline(cin, prio);
  real_prio = stoi(prio);
  prio_name[real_prio] = name;
  prioqueue.push(real_prio);
}

void take(priority_queue<int> & prioqueue, unordered_map<int, string> & prio_name) {
  int prio = prioqueue.top();
  prioqueue.pop();
  string name = prio_name[prio];
  if (prio < 10) {
    cout << "0" << prio << " - " << name << endl;
    return;
  }
  cout << prio << " - " << name << endl;
}

int main(int argc, char const* argv[]) {
  // Write your code here
  unordered_map <int, string> matches;
  priority_queue<int> order;
  while (true) {
    string doing;
    cout << "What do you want to do? ";
    getline(cin, doing);
    if (doing == "") {
      break;
    }
    if (doing == "add") {
      add(order, matches);
    } else {
      if (order.size() == 0) {
        cout << "There are no more people in line" << endl;
        continue;
      }
      take(order, matches);
    }
  }
  return 0;
}
