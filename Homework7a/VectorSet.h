#pragma once
#include<vector>
using std::vector, std::swap;

template<class T>
class VectorSet {
    vector<T> things;
public:
    bool contains(T item) const {
        // implement contains here
        for (int i = 0; i < size(); i++) {
            if (things[i] == item) {
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (contains(item)) {
            return false;
        }
        things.push_back(item);
        return true;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        for (size_t i = 0; i < size(); i++) {
            if (things[i] == item) {
                swap(things[i], things.back());
                things.pop_back();
                return true;
            }
        }
        return false;

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return things.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (size() == 0) {
            return true;
        }
        return false;
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        while(!empty()){
            things.pop_back();
        }
        // remove all items from the set
    }
};
