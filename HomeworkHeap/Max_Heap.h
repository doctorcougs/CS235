#pragma once
// add removing a value -- this means that we can only have one of each value in the heap
// add being able to assign any priority to anything -- array of boxes
#include <iostream>
using std::cout, std::endl;

template<class T>
class Max_Heap {
public:
  Max_Heap() : _size(0), _capacity(8) {
    _data = new T[_capacity];
  }

  ~Max_Heap() {
    delete[] _data;
  }

  void insert(T item) {
    if (_size == _capacity) {
      _grow();
    }
    _data[_size] = item;
    int temp_spot = _size;
    while (_data[temp_spot] > _data[(temp_spot - 1) / 2]) {
      T temp = _data[temp_spot];
      _data[temp_spot] = _data[(temp_spot - 1) / 2];
      _data[(temp_spot - 1) / 2] = temp;
      temp_spot = (temp_spot - 1) / 2;
    }
    _size++;
  }

  T remove() {
    if (_size == 0) {
      return 0;
    }
    T value = _data[0];
    _data[0] = _data[_size];
    int temp_index = 0;
    while (_data[temp_index] < _data[(2 * temp_index) + 1] || _data[temp_index] < _data[(2*temp_index) + 2]) {
      if (_data[temp_index] < _data[(2 * temp_index) + 1]) {
        T temp = _data[temp_index];
        _data[temp_index] = _data[(2 * temp_index) + 1];
        _data[(2 * temp_index) + 1] = temp;
        temp_index = (2 * temp_index) + 1;
      } else {
        T temp = _data[(2 * temp_index) + 2];
        _data[temp_index] = _data[(2 * temp_index) + 2];
        _data[(2 * temp_index) + 2] = temp;
        temp_index = (2 * temp_index) + 2;
      }
    }
    _size--;
    return value;
  }

  T &operator[](int index) {
    return _data[index];
  }

  void print() {
    for (int i = 0; i < _size; i++) {
      cout << _data[i] << endl;
    }
  }

  void clear() {
    delete[] _data;
    _size = 0;
    _capacity = 8;
    _data = new T[_capacity];
  }

  int size() {
    return _size;
  }

private:
  int _size;
  int _capacity;
  T* _data;

  void _grow() {
    T* temp = _data;
    _capacity *= 2;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
      _data[i] = temp[i];
    }
    delete[] temp;
  }
};