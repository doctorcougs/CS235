#pragma once

template <class T>
class stack_again {
  T* data[];
  size_t size;
  capacity;
  public:
    stack_again() : size(0), capacity(10) {
      data = new T[capacity];
    }
    ~stack_again() {
      delete[] data;
    }
    bool insert(T item) {
      if (size == capacity) {
        grow();
      }
      data[size] = item;
      size++;
      return true;
    }

    T remove() {
      if (size == 0) {
        return 0;
      }
      size--;
      T value = data[size];
      return value

    }

    size_t size() {
      return size;
    }

    void clear() {
      size = 0;
      capacity = 10;
      delete[] data;
      data = new T[capacity];
    }

    void grow() {
      capacity *= 2;
      T* old_data = data;
      data = new T[capacity];
      for (size_t i = 0; i < size; i++) {
        data[i] = old_data[i];
      }
      delete[] old_data;
    }
};