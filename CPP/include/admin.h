#ifndef  ADMIN_H
#define ADMIN_H 

#include<iostream>
#include <string>

#include "helper.h"
#include "class.h"
#include "list.h"
#include "helper.h"

class Admin {
private:

  LinkedList<Patient> patientList;
  LinkedList<Doctor> doctorList;
  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  
  Medicine AddMedicine() {

    clearScreen();

    std::cout << "===  Adding Medicine ===" << std::endl;  

    std::string name;
    Assign("name of the Medicine", name);

    int price;
    Assign("price of the Medicine", price);

    Medicine medicine = Medicine(name, price);

    medicineList.pushFront(medicine);

    std::cout << "=====================" << std::endl;

    return medicine;

  } 

  Disease AddDisease() {

    clearScreen();
    
    std::cout << "===  Adding Disease ===" << std::endl;  

    std::string name;
    Assign("name of the Disease", name);

    Medicine medicine;    

    bool entry = false;
    int choice;
    
    while (!entry) {
      choice = choose("Medicine");
      if (choice == 1) {
        medicine = medicineList.chooseNode();
        entry = true;
      }
      else if (choice == 2) {
        medicine = AddMedicine();
        entry = true;
      }
    }

    Disease disease = Disease(name, medicine);

    diseseList.pushFront(disease);

    std::cout << "=====================" << std::endl;

    return disease;

  }

  Doctor AddDoctor() {

    clearScreen();

    std::cout << "===  Adding Doctor ===" << std::endl;

    std::string name;
    Assign("Name of Doctor", name);

    std::string sex;
    Assign("Gender of the Doctor", sex);

    int age;
    Assign("Age of the Doctor", age);

    Date date;
    std::cout << "\nEnter the date of joining\n";
    date = date.AddDate();

    std::string qualification;
    Assign("Qualification", qualification);

    Doctor doctor = Doctor(Person(name, sex, age), qualification, date);

    doctorList.pushFront(doctor);

    std::cout << "=====================" << std::endl;

    return doctor;
    
  }

  Patient AddPatient() {

    clearScreen();

    std::cout << "===  Adding Patient ===" << std::endl;

    std::string name;
    Assign("Name of Patient", name);

    std::string sex;
    Assign("Gender of the Patient", sex);

    int age;
    Assign("Age of the Patient", age);

    Disease disease;
   
    bool entry = false;
    int choice = 0; 

    while (!entry) {
      choice = choose("Disease");
      if (choice == 1) {
        disease = diseseList.chooseNode();
        entry = true;
      }
      else if (choice == 2) {
        disease = AddDisease();
        entry = true;
      }
    }

    Date date;
    std::cout << "\nEnter Admit date for the Patient:\n";
    date = date.AddDate();

    int price = 0;
    Assign("Payable amout by the patient", price);

    Patient patient = Patient(Person(name, sex, age), disease, date, price);

    std::cout << "=====================" << std::endl;

    return patient;

  }

  void AddMenu() {
    clearScreen();
    int choice;
    while (choice != 0) {
      clearScreen();
      std::cout << "=== Add Menu ===" << std::endl;
      std::cout << "0. Quit" << std::endl;
      std::cout << "1. Add Medicine" << std::endl;
      std::cout << "2. Add Disease" << std::endl;
      std::cout << "3. Add Doctor" << std::endl;
      std::cout << "4. Add Patient" << std::endl;
      Assign("choice", choice);

      switch (choice) {
        case 1:
        AddMedicine();
        break;
        case 2:
        AddDisease();
        break;
       case 3:
        AddDoctor();
        break;
       case 4:
        AddPatient();
        break;
        case 0:
          std::cout << "Quit\n";
          break;
       default:
        std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        break;
      }
    }
  } 


  void ListMenu() {

    clearScreen(); 

    std::cout << "=== List Menu ===" << std::endl;

    int choice;
    while (choice != 0) {
      std::cout << "0. Quit" << std::endl;
      std::cout << "1. Medicine List" << std::endl;
      std::cout << "2. Disease List" << std::endl;
      std::cout << "3. Doctor List" << std::endl;
      std::cout << "4. Patient List" << std::endl;
      Assign("choice", choice);

      switch (choice) {
        case 0:
          std::cout << "Quit\n";
          break;
        case 1:
          std::cout << "=== Medicine List ===" << std::endl;
          medicineList.printList(); 
          std::cout << "=====================" << std::endl;
          break;
        case 2:
          std::cout << "=== Disease List ===" << std::endl;
          diseseList.printList();        
          std::cout << "=====================" << std::endl;
          break;
        case 3:
          std::cout << "=== Doctor List ===" << std::endl;
          doctorList.printList();
          std::cout << "=====================" << std::endl;
          break;
        case 4:
          std::cout << "=== Patient List ===" << std::endl;
          patientList.printList();
          std::cout << "=====================" << std::endl;
          break;
        default:
          std::cout << "\nInvalid\n\n"; 
          break;
      }
      
    }
    
  }

public:

  Admin() {}

  void DashBoard() {

    clearScreen();

    int choice = -1;

    while (choice != 0) {
     clearScreen();     
      std::cout << "===== DashBoard =====\n";
      std::cout << "0. Quit \n1. Add Elements \n2. Add List";
      Assign("choice", choice);
      
      switch (choice) {
        case 0:
          std::cout << "Bye Bye\n";
          break;
        case 1:
          AddMenu();
          break;
        case 2:
          ListMenu();
          break;
        default:
          std::cout << "\nInvalid input.\n\n";
      }

    }

  }

};
#endif // DEBUG
