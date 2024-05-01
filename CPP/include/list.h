#ifndef LIST_H 
#define LIST_H

#include <iostream>

template<typename T>
struct Node {
  T data;
  Node* next;

  Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
  Node<T>* head;

public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() {
    while (head != nullptr) {
      Node<T>* temp = head;
      head = head->next;
      delete temp;
    }
  }

  int count() const {
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    return count;
  }

  void pushBack(T data) {
    if (head == nullptr) {
      head = new Node<T>(data);
    } else {
      Node<T>* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = new Node<T>(data);
    }
  }

  void pushFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(int index) {
    if (index <= 0 || head == nullptr) {
      return;
    }
    if (index == 1) {
      Node<T>* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    for (int i = 1; curr != nullptr && i < index; i++) {
      prev = curr;
      curr = curr->next;
    }
    if (curr != nullptr) {
      prev->next = curr->next;
      delete curr;
    }
  }

  void printList() const {
    Node<T>* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << std::endl;
      temp = temp->next;
    }
  }

  Node<T>* getNode(int index) const {
    if (index < 0 || index >= count()) {
      return nullptr;
    }
    Node<T>* temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp;
  }
};

#endif // !LIST_H
