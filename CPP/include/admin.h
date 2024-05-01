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
  void Assign(std::string name, T& target) {
    T value;
    std::cout << "\n Enter the data for " << name << ": "; 
    std::cin >> value;
    std::cout << "\n";
    target = value;
  } 

public:

  Admin() {}

  Medicine AddMedicine() {

    std::cout << "\nEnter the info for Medicine:\n";

    std::string name;
    Assign("name", name);

    int price;
    Assign("price", price);


    Medicine medicine(name, price);
    medicineList.pushFront(medicine);

    return medicine;

  }

  Disease AddDisease() {
    std::cout << "Enter the info for Disease: \n";

    std::string name;
    Assign("name", name);

    int level;
    Assign("level", level);

    Medicine medicine = medicineList.chooseNode();
    
    Disease disease;
    diseseList.pushFront(disease);

    return disease;

  }

  void AddPatient() {

    std::cout << "\nEnter the info for Patient:\n";

    std::string name; 
    Assign("name", name);

    int age;
    Assign("age", age);

    std::string sex;
    Assign("sex", sex);

  }
};

#endif // DEBUG
