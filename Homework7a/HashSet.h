#pragma once
#include <functional>
using std::hash;

template<class T>
class HashSet {
public:

    class Box {
    public:
        bool used;
        bool deleted;
        T value;
        Box() : used(false), deleted(false), value(){}

        ~Box() {}
    };

    HashSet() : _size(0), _capacity(8), _absolute_size(0){
      _data = new Box[_capacity];
    }

    ~HashSet() {
      delete[] _data;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (_absolute_size >= _capacity * 0.75) { // might need to recast variables
          _grow();
        }
        if (contains(item)) {
            return false;
        }
        size_t index = _hasher(item) % _capacity;
        while (_data[index].used || _data[index].deleted) {
          index = (index + 1) % _capacity;
        }
        _data[index].value = item;
        _data[index].used = true;
        _size++, _absolute_size++;
        return true;
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        size_t index = _hasher(item) % _capacity;
        if (contains(item)) {
            while (_data[index].used || _data[index].deleted) {
                if (_data[index].value == item) {
                    _data[index].used = false;
                    _data[index].deleted = true;
                    _size--;
                    return true;
                }
                index = (index + 1) % _capacity;
            }
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t index = _hasher(item) % _capacity;
        size_t start_point = index;
        while (_data[index].used || _data[index].deleted) {
            if (_data[index].value == item && _data[index].used && !_data[index].deleted) {
                return true;
            }
            index = (index + 1) % _capacity;
            if (index == start_point) {
              break;
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        delete[] _data;
        _size = 0;
        _absolute_size = 0;
        _capacity = 8;
        _data = new Box[_capacity];
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return _size;
    }
private:
    Box* _data;
    int _size;
    int _capacity;
    int _absolute_size;
    hash<T> _hasher;

    void _grow() {
        int temp_cap = _capacity;
        Box* temp = _data;
        _capacity *= 2;
        _data = new Box[_capacity];
        _size = _absolute_size = 0;
        for (int i = 0; i < temp_cap; i++) {
            if (temp[i].used && !temp[i].deleted) {
                insert(temp[i].value);
            }
        }
        delete[] temp;
    }
};
