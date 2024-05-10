#ifndef  ADMIN_H
#define ADMIN_H 

#include <cstdio>
#include <iostream>
#include <string>

#include "helper.h"
#include "class.h"
#include "list.h"
#include "helper.h"

class Admin {
private:

  std::string name, password;

  LinkedList<Patient>& patientList;
  LinkedList<Doctor>& doctorList;
  LinkedList<Medicine>& medicineList;
  LinkedList<Disease>& diseseList;
  LinkedList<Shedule>& sheduleList;


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

    bool quit = false;
    int choice;
    
    while (!quit) {
      choice = choose("Medicine");
      if (choice == 1) {
        medicine = medicineList.chooseNode();
        quit = true;
      }
      else if (choice == 2) {
        medicine = AddMedicine();
        quit = true;
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

    std::string password;
    Assign("password", password); 

    Doctor doctor = Doctor(Person(name, sex, age), qualification, date, &sheduleList, password);

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

    patientList.pushFront(patient);

    std::cout << "=====================" << std::endl;

    return patient;

  }

  void AddMenu() {
    clearScreen();

    int choice;
    bool entry = false; 


    while (!entry) {
      clearScreen();
      std::cout << "=== Add Menu ===" << std::endl;
      std::cout << "0. Quit" << std::endl;
      std::cout << "1. Add Medicine" << std::endl;
      std::cout << "2. Add Disease" << std::endl;
      std::cout << "3. Add Doctor" << std::endl;
      std::cout << "4. Add Patient" << std::endl;
      std::cout << "5. Add Shedule" << std::endl;
      Assign("choice", choice);

      switch (choice) {
        case 0:
          std::cout << "Exit Menu.";
          entry = true;
          break;
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
       case 5:
        AddShedule();
        break;
       default:
        std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        break;
      }
    }
  } 

  Shedule AddShedule() {


    std::cout << "==== Add Shedule ====" << std::endl;

    Doctor doctor;
    doctor = doctorList.chooseNode();

    std::cout << "\n";

    Patient patient;
    patient = patientList.chooseNode();

    std::cout << "Add Date of Shedule" << std::endl;

    Date date;
    date = date.AddDate();

    std::cout << "=====================" << std::endl;

    Shedule shedule = Shedule(doctor, patient, date);
    sheduleList.pushFront(shedule);

    return shedule;

  }

  void ListMenu() {

    clearScreen(); 

    std::cout << "=== List Menu ===" << std::endl;

    int choice;
    bool quit = false;
    while (!quit) {
      std::cout << "0. Quit" << std::endl;
      std::cout << "1. Medicine List" << std::endl;
      std::cout << "2. Disease List" << std::endl;
      std::cout << "3. Doctor List" << std::endl;
      std::cout << "4. Patient List" << std::endl;
      std::cout << "5. Shedule List" << std::endl;
      Assign("choice", choice);

      switch (choice) {
        case 0:
          std::cout << "Quit\n";
          quit = true;
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
        case 5:
          std::cout << "=== Shedule List ===" << std::endl;
          sheduleList.printList();
          std::cout << "=====================" << std::endl;
          break;
        default:
          std::cout << "\nInvalid\n\n"; 
          break;
      }
      
    }
    
  }

  void DeleteMenu() {

    clearScreen();

    int choice, index;
    bool quit = false;
    
    while (!quit) {

      std::cout << "0. Quit \n1. Delete Medicine \n2. Delete Disease \n3. Delete Doctor \n4. Delete Patient \n";
      Assign("choice", choice);

      switch (choice) {
        case 0:
        std::cout << "Quit\n";
        quit = true;
        break;
        case 1:
        std::cout << "=== Medicine List ===" << std::endl;
        medicineList.printList();
        std::cout << "=====================" << std::endl;
        std::cout << "\n";
        Assign("index", index);
        medicineList.deleteNode(index);
        break;
        case 2:
        std::cout << "=== Disease List ===" << std::endl;
        diseseList.printList();
        std::cout << "====================" << std::endl;
        std::cout << "\n";
        Assign("index", index);
        diseseList.deleteNode(index);
        break;
        case 3:
        std::cout << "=== Doctor List ===" << std::endl;
        doctorList.printList();
        std::cout << "===================" << std::endl;
        std::cout << "\n";
        Assign("index", index);
        doctorList.deleteNode(index);
        break;
        case 4:
        std::cout << "=== Patient List ===" << std::endl;
        patientList.printList();
        std::cout << "====================" << std::endl;
        std::cout << "\n";
        Assign("index", index);
        patientList.deleteNode(index);
        break;
        default:
        std::cout << "Invalid\n";
        break;
      }
    }

  }

public:

  

  Admin(std::string password, LinkedList<Medicine>& medicineList, LinkedList<Disease>& diseseList, LinkedList<Doctor>& doctorList, LinkedList<Patient>& patientList, LinkedList<Shedule>& sheduleList) : medicineList(medicineList), diseseList(diseseList), patientList(patientList), doctorList(doctorList), sheduleList(sheduleList), password(password) {

    medicineList.pushFront(Medicine("Panadol", 5));
    diseseList.pushFront(Disease("Fever", medicineList.getNode(0)));
    doctorList.pushFront(Doctor(Person ("Ali", "Mail", 29), "PhD", Date (1, 1, 21), &sheduleList, "123"));
    patientList.pushFront(Patient(Person("Ahmad", "Mail", 35), Disease(diseseList.getNode(0)), Date(1, 1, 21), 12) );

  }

  bool IsPassword (std::string password) {
    return (this->password == password);
  }

  void DashBoard() {

    clearScreen();

    int choice = 1;
    bool running = true;

    while (running) {
      clearScreen();     
      std::cout << "===== DashBoard =====\n";
      std::cout << "0. Quit \n1. Add Elements \n2. List Elements \n3. Delete Elements";
      int choice;
      Assign("Enter your choice", choice);
      
      switch (choice) {
        case 0:
          std::cout << "Bye Bye\n";
          running = false;
          break;
        case 1:
          AddMenu();
          break;
        case 2:
          ListMenu();
          break;
        case 3:
          DeleteMenu();
          break;
        default:
          std::cout << "\nInvalid input.\n\n";
      }

    }

  }

};
#endif // DEBUG
