#pragma once

template <class T>
class Devector
{

public:
	size_t _capacity;
	size_t _size;
	size_t _front;
	T* _data;

	void _grow() {
		T* temp = _data;
		size_t old_cap = _capacity;
		_capacity *= 2;
		_data = new T[_capacity];
		for(int i = 0; i < _size; i++) {
			_data[i] = temp[(i + _front) % old_cap];
		}
		_front = 0;
		delete[] temp;
	}

    Devector() : _capacity(10), _size(0), _front(0), _data(new T[_capacity]) {}

    ~Devector()
    {
		delete[] _data;
    }

    void push_back(T const &item)
    {
		if (_size == _capacity) {
			_grow();
		}
		size_t insert_spot = (_front+_size) % _capacity;
        _size++;
        _data[insert_spot] = item;
    }

    void pop_back()
    {
		if (_size == 0) {
			return;
		}
		_size--;
    }

    void push_front(T const &item)
    {
		if (_size == _capacity) {
			_grow();
		}
		_front = (_front - 1 + _capacity) % _capacity;
		_data[_front] = item;
		_size++;
    }

    void pop_front()
    {
		if (_size == 0) {
			return;
		}
		_size--;
		_front = (_front + 1) % _capacity;
    }

    T &operator[](size_t index)
    {
		return _data[(index + _front) % _capacity];
    }

    size_t size() const
    {
		return _size;
    }

    void clear()
    {
		_front = 0;
		_size = 0;
    }
};
