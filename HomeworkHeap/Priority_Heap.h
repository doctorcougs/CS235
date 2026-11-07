#pragma once
// add removing from an item     DONE
// add being able to assign any priority to anything -- array of boxes       DONE
// maybe add a swap       DONE
#include <iostream>
using std::cout, std::endl;

template<class T>
class Priority_Heap {
public:

  struct Box {
      Box() : value(), priority(0) {}
      Box(T item, int priority) : value(item), priority(priority) {}

      ~Box() {}

      T value;
      int priority;
  };

    Priority_Heap() : _size(0), _capacity(8) {
        _data = new Box[_capacity];
    }

    ~Priority_Heap() {
        delete[] _data;
    }

    void insert(T item, int priority) {
        if (_size == _capacity) {
            _grow();
        }
        _data[_size] = Box(item, priority);
        adjust_up(_size);
        _size++;
    }

    T queue_remove() {
        if (_size == 0) {
            cout << "empty queue" << endl;
            return 0;
        }
        T value = _data[0].value;
        _data[0] = _data[_size - 1];
        adjust_down(0);
        _size--;
        return value;
    }

    bool remove(T item) {
        if (_size == 0) {
            return false;
        }
        bool doneit = false;
        for (int i = 0; i < _size; i++) {
            while (_data[i].value == item) {
                _data[i] = _data[_size - 1];
                adjust_down(i);
                _size--;
                doneit = true;
            }
        }
        adjust_down(0);
        return doneit;
    }

    T &operator[](int index) {
        return _data[index].value;
    }

    void print() {
        for (int i = 0; i < _size; i++) {
            cout << _data[i].value << endl;
        }
    }

    void clear() {
        delete[] _data;
        _size = 0;
        _capacity = 8;
        _data = new Box[_capacity];
    }

    int size() {
        return _size;
    }

    int _size;

private:
    int _capacity;
    Box* _data;

    void _grow() {
        Box* temp = _data;
        _capacity *= 2;
        _data = new Box[_capacity];
        for (int i = 0; i < _size; i++) {
            _data[i] = temp[i];
        }
        delete[] temp;
    }

    void swap(int i, int j) {
        Box temp = _data[i];
        _data[i] = _data[j];
        _data[j] = temp;
    }

    void adjust_up(int index) {
        while (_data[index].priority < _data[(index - 1) / 2].priority) {
            swap((index - 1) / 2, index);
            index = (index - 1) / 2;
        }
    }

    void adjust_down(int index) {
        while (true) {
            int left = (index * 2) + 1;
            int right = (index * 2) + 2;
            if (left >= _size || right >= _size) {
                return;
            } else if (_data[index].priority > _data[left].priority) {
                swap(left, index);
                index = left;
            } else if (_data[index].priority > _data[right].priority) {
                swap(right, index);
                index = right;
            } else {
                return;
            }
        }
    }
};