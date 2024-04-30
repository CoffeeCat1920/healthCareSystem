#ifndef LIST_H 
#define LIST_H

#include <iostream>
#include "./class.h"

struct PatientNode {
  int data; 
  PatientNode* next;
  PatientNode(int data) {
    this->data = data; 
    next = NULL;
  }
};

struct DoctorNode {
  int data; 
  DoctorNode* next;
  DoctorNode(int data) {
    this->data = data; 
    next = NULL;
  }
};


class PatientList {
private:
  PatientNode*head;

public:

  // A function to give total number of nodes in a list
  int count() {
    if (head == nullptr) {
      return 0;
    } else {
      PatientNode* temp = head;
      int count = 0;
      while (temp != nullptr) {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }

  // insert a node
  void pushBack(int data) {
    if (head == nullptr) {
      head = new PatientNode(data);
      return;
    } else {
      PatientNode* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = new PatientNode(data);
      return;
    }
  }

  void pushFront(int data) {
    PatientNode* temp = head;
    PatientNode* newNode = new PatientNode(data);
    head = newNode;
    newNode->next = temp;
    return;
  }

  // Delete a PatientNode
  void deletePatientNode(int index) {
    if (head == nullptr) {
      return;
    } else if (index == 1) {
      PatientNode* temp = head;
      PatientNode* next = temp->next;
      delete temp;
      head = next;
      return;
    } else if (count() == index) {
      PatientNode* temp = head;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
      return;
    } else if (count() < index) {
      return;
    } else {
      PatientNode* temp = head;
      for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
      }
      PatientNode* next = temp->next->next;
      PatientNode* previous = temp;
      delete temp->next;
      previous->next = next;
    }
  }
  
  // Print a List
  void printList() {
    if (head == nullptr) {
      return;
    } else {
      PatientNode* temp = head;
      while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
      }
    }
    return;
  }

  PatientNode* getElement(int index) {
    if (count()<=index) {
      return NULL;
    }
    else {
      PatientNode* temp = head;
      for (int i=0; i<index; i++) {
        temp = temp->next;
      }
      return temp;
    }
    
  } 

};

class DoctorList {
private:
  DoctorNode*head;

public:

  // A function to give total number of nodes in a list
  int count() {
    if (head == nullptr) {
      return 0;
    } else {
      DoctorNode* temp = head;
      int count = 0;
      while (temp != nullptr) {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }

  // insert a node
  void pushBack(int data) {
    if (head == nullptr) {
      head = new DoctorNode(data);
      return;
    } else {
      DoctorNode* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = new DoctorNode(data);
      return;
    }
  }

  void pushFront(int data) {
    DoctorNode* temp = head;
    DoctorNode* newNode = new DoctorNode(data);
    head = newNode;
    newNode->next = temp;
    return;
  }

  // Delete a PatientNode
  void deletePatientNode(int index) {
    if (head == nullptr) {
      return;
    } else if (index == 1) {
      DoctorNode* temp = head;
      DoctorNode* next = temp->next;
      delete temp;
      head = next;
      return;
    } else if (count() == index) {
      DoctorNode* temp = head;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
      return;
    } else if (count() < index) {
      return;
    } else {
      DoctorNode* temp = head;
      for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
      }
      DoctorNode* next = temp->next->next;
      DoctorNode* previous = temp;
      delete temp->next;
      previous->next = next;
    }
  }
  
  // Print a List
  void printList() {
    if (head == nullptr) {
      return;
    } else {
      DoctorNode* temp = head;
      while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
      }
    }
    return;
  }

  DoctorNode* getElement(int index) {
    if (count()<=index) {
      return NULL;
    }
    else {
      DoctorNode* temp = head;
      for (int i=0; i<index; i++) {
        temp = temp->next;
      }
      return temp;
    }
    
  } 

};

#endif // !LIST_H
