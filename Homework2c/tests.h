#include <iostream>
#include <string>
#include <vector>
using std::vector;
template <typename T>
class priority_queue {
    vector<T> data;

public:
    void pop() {
        size_t largest_pos = _find_largest_pos();
        _remove(largest_pos);
    }
    T top() const {
        size_t largest_pos = _find_largest_pos();
        return data[largest_pos];
    }
    bool empty() const {
        return data.empty();
    }
    void push(T const& thing) {
        data.push_back(thing);
    }
    size_t size() const {
        return data.size();
    }
private:
    size_t _find_largest_pos() const {
        size_t pos = 0;
        for (size_t i = 1; i < data.size(); i++) {
            if (data[i] > data[i + 1]) {
                pos = i;
            }
        }
        return pos;
    }
    void _remove(size_t pos) {
        data[pos] = data.back();
        data.pop_back();
    }
};
