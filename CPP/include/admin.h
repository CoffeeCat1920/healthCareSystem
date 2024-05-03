#ifndef  ADMIN_H
#define ADMIN_H 

#include<iostream>
#include <string>

#include "class.h"
#include "list.h"

class Admin {
private:

  LinkedList<Patient> patientList;
  LinkedList<Doctor> doctorList;
  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  
  template<typename T>
  void Assign(std::string name, T& target) {
    T value;
    std::cout << "\n Enter the data for " << name << ": "; 
    std::cin >> value;
    std::cout << "\n";
    target = value;
  } 

public:

  Admin() {
    medicineList.pushFront(Medicine("Panadol", 5));
    diseseList.pushFront(Disease("General Fever", 12, medicineList.getNode(0)));
    patientList.pushFront(Patient(Person("Ali", "Male", 12), diseseList.getNode(0), Date(3, "May", 2024), Date(4, "May", 2024), 100));
    Doctor();
  }
};
#endif // DEBUG
