#pragma once

template<class T>
class DLList {
public:
    // **Important**
    // Normally you would make the Node struct PRIVATE
    // but for this assignment it is important to keep it 
    // PUBLIC
    // Also, the declaration of Node needs to come 
    // before everything else in the class, so leave it here
    // at the beginning.
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

private:
    // Put your private fields/methods here

public:
    DLList() : head(nullptr), tail(nullptr){}

    ~DLList() {
      clear();
    }

    Node* head;
    Node* tail;


    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_front(T item) {
        // implement push_front here
        Node* new_node = new Node(item);
        if (!head) {
            tail = new_node;
            head = new_node;
            return;
        }
        Node* temp = head;
        head = new_node;
        head->next = temp;
        temp->prev = new_node;
        return;
    }
    void push_back(T item) {
        // implement push_back here
        Node* new_node = new Node(item);
        if (!head) {
          head = new_node;
          tail = new_node;
          return;
        }
        Node* temp = head;
        while (temp->next) {
          temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
        tail = new_node;
        return;
    }
    void insert(T item, int position) {
        // implement insert here
        if (position > size()) {
          return;
        }
        Node* new_node = new Node(item);
        if (position == 0) {
          if (head) {
            new_node->next = head;
            head->prev = new_node;
          }
          head = new_node;
          if (!tail) {
            tail = new_node;
          }
          return;
        }
        if (position == size()) {
          tail->next = new_node;
          new_node->prev = tail;
          tail = new_node;
          return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
          temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
        return;
    }

    void pop_front() {
        // implement pop_front here
        if (!head) {
          return;
        }
        if (!head->next) {
          delete head;
          head = nullptr;
          tail = nullptr;
          return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }
    void pop_back() {
        // implement pop_back here
        if (!head) {
          return;
        }
        if (!head->next) {
          delete head;
          head = nullptr;
          tail = nullptr;
          return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return;
    }
    void remove(int position) {
        // implement remove here
        if (position > size()) {
          return;
        }
        if (position == 0) {
          pop_front();
          return;
        }
        if (position == size() - 1) {
          pop_back();
          return;
        }
        Node* temp = head;
        for (int i = 0; i < position; i++) {
          temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;

    }

    const T& front() const {
        // implement front here
        return head->value;
    }
    const T& back() const {
        // implement back here
        return tail->value;
    }
    const T& at(int index) const {
        // implement at here
        Node* temp = head;
        for (int i = 0; i < index; i++) {
          temp = temp->next;
        }
        return temp->value;
    }

    bool contains(const T& item) const {
        // implement contains here
        Node* temp = head;
        if (temp->value == item) {
          return true;
        }
        while (temp->next) {
          temp = temp->next;
          if (temp->value == item) {
            return true;
          }
        }
        return false;
    }

    int size() const {
        // implement size here
        if (!head) {
          return 0;
        } else if (!head->next) {
          return 1;
        } else {
          int count = 1;
          Node* temp = head;
          while (temp->next) {
            temp = temp->next;
            count++;
          }
          return count;
        }
    }

    void clear() {
        // implement clear here
        while(head) {
          pop_front();
        }
        return;
    }
};
