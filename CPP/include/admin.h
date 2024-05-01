#ifndef  ADMIN_H
#define ADMIN_H 

#include<iostream>
#include <string>

#include "class.h"
#include "link.h"
#include "list.h"


class Admin {
private:

  LinkedList<Patient> patientList;
  LinkedList<Doctor> doctorList;
  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  
  template<typename T>
  void Assign(std::string name, const T& value, T& target) {
    std::cout << "\n Enter the data for " << name << "\n";
    target = value;
  } 

public:
  Admin() {}
  void AddPatient() {
    std::string name, sex;
    int age;
  }
};

#endif // DEBUG
