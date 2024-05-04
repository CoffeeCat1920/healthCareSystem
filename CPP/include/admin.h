#ifndef  ADMIN_H
#define ADMIN_H 

#include<iostream>
#include <string>

#include "class.h"
#include "list.h"
#include "helper.h"

class Admin {
private:

  LinkedList<Patient> patientList;
  LinkedList<Doctor> doctorList;
  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  
public:

  Admin() {
    medicineList.pushFront(Medicine("Panadol", 5));
  }

  Medicine AddMedicine() {

    std::string name;
    Assign("name of the Medicine", name);

    int price;
    Assign("price of the Medicine", price);

    Medicine medicine = Medicine(name, price);

    medicineList.pushFront(medicine);

    return medicine;

  } 

  Disease AddDisease() {
     
    std::string name;
    Assign("name of the Disease", name);

    Medicine medicine;    

    int choice = choose("Medicine");

    if (choice == 1) {
      medicine = medicineList.chooseNode();
    }
    else if (choice == 2) {
      medicine = AddMedicine();
    }
    else {
      AddDisease();
    }

    Disease disease = Disease(name, medicine);

    diseseList.pushFront(disease);

    return disease;

  }

  Doctor AddDoctor() {

    std::string name;
    Assign("Name of Doctor", name);

    Date date;
    std::cout << "\nEnter the date of joining\n";
    date = date.AddDate();

  }

};
#endif // DEBUG
