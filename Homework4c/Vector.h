#pragma once

template<class T>
class Vector {
size_t _capacity;
T* _data;
size_t _size;
void _grow() {
  T* temp = _data;
  _capacity *= 2;
  _data = new T[_capacity];
  for (size_t i = 0; i < _size; i++) {
    _data[i] = temp[i];
  }
  delete[] temp;
  return;
}

public:
    Vector() {
      _capacity = 10;
      _data = new T[_capacity];
      _size = 0;
    }

    ~Vector() {
      delete[] _data;
    }

    void push_back(T const& item) {
        // implement push_back here
        if (_size == _capacity) {
          _grow();
        }
        _data[_size] = item;
        _size++;
        return;
    }

    void pop_back() {
      if (_size == 0) {
        return;
      }
          _size--;
      return;
    }

    void insert(T const& item, size_t position) {
        // implement insert here
        if (_size == _capacity) {
          _grow();
        }
        for (size_t i = _size; i > position; i--) {
          _data[i] = _data[i - 1];
        }
        _data[position] = item;
        _size++;
        return;
    }

    void remove(size_t position) {
        // implement remove here
        for (size_t i = position; i < (_size - 1); i++) {
          _data[i] = _data[i+1];
        }
        _size--;
        return;
    }

    T& operator[](size_t index) {
        // implement operator[] here
        return _data[index];
    }

    size_t size() const {
        // implement size here
        return _size;
    }

    void clear() {
        // implement clear here
        _size = 0;
    }
};
