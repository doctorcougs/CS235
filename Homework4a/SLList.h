#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : head(nullptr) {}

    ~SLList() {
      clear();
    }

    Node* head;

    const Node* get_head() const {
        // implement get_head here
        return head;

    }

    void push_back(T item) {
        // implement push_back here
        Node* new_node = new Node(item);
        if (!head) {
          head = new_node;
          return;
        }
        Node* temp = head;
        while (temp->next) {
          temp = temp->next;
        }
        temp->next = new_node;
    }

    void pop_back() {
        // implement pop_back here
        if (!head) { // nothing here
          return;
        }
        if (!head->next) { // one thing in the list
          delete head;
          head = nullptr;
          return;
        }
        Node* temp = head;
        while (temp->next->next) { // more than one thing in the list
          temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return;
    }

    const T& front() const {
        // implement front here
        if (!head) {
          return T();
        }
        return head->value;
    }

    int size() const {
        // implement size here
        if (!head) {
          return 0;
        } else if (!head->next) {
          return 1;
        }
        int count = 0;
        Node* temp = head;
        while (temp->next) {
          temp = temp->next;
          count++;
        }
        count++;
        return count;
    }

    void clear() {
        // implement clear here
        while(head) {
          pop_back();
        }
    }
};
