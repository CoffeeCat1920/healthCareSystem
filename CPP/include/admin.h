#ifndef  ADMIN_H
#define ADMIN_H 

#include<iostream>
#include <string>

#include "helper.h"
#include "class.h"
#include "list.h"

class Admin {
private:

  LinkedList<Patient> patientList;
  LinkedList<Doctor> doctorList;
  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  

public:

  Admin() {
    medicineList.pushFront(Medicine("Panadol", 5));
    diseseList.pushFront(Disease("General Fever", 12, medicineList.getNode(0)));
    patientList.pushFront(Patient(Person("Ali", "Male", 12), diseseList.getNode(0), Date(3, "May", 2024), Date(4, "May", 2024), 100));
    Doctor();
  }

  Medicine AddMedicine() {

    std::string name;
    Assign("Name", name);

    int price;
    Assign("Price", price);
     
    return Medicine(name, price);

  }

};
#endif // DEBUG
