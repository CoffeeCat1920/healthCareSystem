#ifndef LIST_H 
#define LIST_H

#include <iostream>
#include <string>

// sorry I have to use it ｡ﾟ･ (>﹏<) ･ﾟ｡
#include <optional>

template<typename T>
struct Node {
  T data;
  Node* next;

  Node(T data) : data(data), next(nullptr) {}

  std::string GetData() {
    return data.GetData();
  }

};

template<typename T>
class LinkedList {
private:
  Node<T>* head;

  void clearScreen() { 
    std::cout << "\033[2J\033[1;1H";
  }

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
    deleteDuplicate();
  }

  T pushFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    this->deleteDuplicate();
    return data;
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
    if (head == NULL) {
      std::cout << "\nNo Entry\n";
    }
    Node<T>* temp = head;
    int index = 1;
    while (temp != nullptr) {
      std::cout << index;
      std::cout << ". " << temp->GetData() << "\n"; 
      index++;
      temp = temp->next;
    }
  }

  T getNode(int index) const {
    if (index < 0 || index >= count()) {
      return T();
    }
    Node<T>* temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp->data;
  }


  T chooseNode() const {
    int choose; 
    printList();
    std::cout << "\n Choose 1-" << this->count() << " (0 to quit)" << ": ";
    std::cin >> choose;
    if (choose == 0) {
      return T(); 
    }
    else {
      while (choose > this->count() && choose != 0) {
        std::cout << " \n Error, maximum level exceeded \n";
        std::cout << "\n Choose 1-" << this->count() << " (0 to quit)" << ": ";
        std::cin >> choose;
      }
      return getNode(choose-1);
    }
  }

  void deleteDuplicate() {
    if (head==NULL) {
      return;
    }
    else {
      Node<T>* temp1 = head, *temp2 = head;
      int n = 0, m;
      while (temp1!=NULL) {
        temp2 = temp1->next;
        m = n;
        while (temp2!=NULL) {
          m++;
          if (temp1->data==temp2->data) {
            std::cout << "\nDuplicate Entry. Deleting ......\n" << std::endl;
            deleteNode(m);
            return;
          }
          temp2 = temp2->next;
        }
        temp1 = temp1->next;
        n++;
      }
    }
  }

};

#endif // !LIST_H
