#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

#include "class.h"
#include "helper.h"
#include "list.h"

class Doctor : public Person {
private: 

  std::string qualification;
  std::string password;
  Date joinDate;
  LinkedList<Patient> shedule;

public:

  Doctor() : Person(), qualification("0"), joinDate(Date()), password("123") {}

  Doctor(Person person, std::string qualification, Date joinDate, std::string password) : Person(person), qualification(qualification), joinDate(joinDate), password(password) {
    shedule.pushFront(Patient());
  }

  bool operator==(const Doctor& other) const {
    return (Person::operator==(other) && qualification == other.qualification && joinDate == other.joinDate);   
  }

  bool IsOccupied() {
    return (shedule.count() >= 2); 
  }

  bool ShedulePatient(Patient patient) {
    shedule.pushFront(patient);
    return (IsOccupied());
  }

  void ListShedule() {
    std::cout << "==== Shedule ====" << std::endl;
    shedule.printList();
    std::cout << "=================" << std::endl;
  }

  void DashBoard() {

    int choice;
    bool quit = false;

    while (!quit) {

      clearScreen();

      std::cout << "=== Dashboard ===\n";
      std::cout << "0. Quit" << std::endl;
      std::cout << "1. See Shedule" << std::endl;
      Assign("Enter your choice", choice);

      switch (choice) {
        case 0:
          quit = true;
          break;
        case 1:
          ListShedule();
          DashBoard();
          quit = true;
          break;
        default:
          std::cout << "\nInvalid input.\n\n";
      }

    } 

  }

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + qualification + "  " +  joinDate.GetData(); 
    return statement;
  }

  bool IsPassword(std::string password) {
    return (this->password == password);
  }

};

#endif // !DOCTOR_H
