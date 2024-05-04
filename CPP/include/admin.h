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
    medicineList.pushFront(Medicine("Panadol", 12)); 
    medicineList.pushFront(Medicine("Panadol", 12)); 
  }

  Medicine AddMedicine() {

    std::string name;
    Assign("Name", name);

    int price;
    Assign("Price", price);

    return Medicine(name, price);

  }

  void List() {
    medicineList.printList(); 
  }

};
#endif // DEBUG
