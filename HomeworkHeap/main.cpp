#include <iostream>
using std::cout, std::endl;
#include "Max_Heap.h"
#include "Priority_Heap.h"

int main(int argc, const char* argv[]) {
    Max_Heap<int> heap;
    Priority_Heap<int> prio_heap;
    for (int i = 0; i < 10; i++) {
        prio_heap.insert(i, i);
    }
    prio_heap.print();
    cout << endl;
    cout << "size should be 10: " << prio_heap.size() << endl;

    cout << "remove should give me a 0: "  << prio_heap.queue_remove() << endl;
    cout << "size should be a 9: " << prio_heap.size() << endl;
    prio_heap.print();
    cout << endl;
    for (int i = 0; i < 4; i++) {
        prio_heap.insert(1, i * 2);
    }
    cout << "added four ones" << endl;
    prio_heap.print();
    cout << endl;

    cout << "should be true (removed all the ones): " << prio_heap.remove(1) << endl;
    cout << "should be false: " << prio_heap.remove(11) << endl;
    prio_heap.print();
    cout << endl;

    prio_heap.clear();
    cout << "size should be 0: " << prio_heap.size() << endl;
    for (int i = 0; i < 10; i++) {
        prio_heap.insert(i, i);
    }
    prio_heap.print();
}