#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "list.h"
#include "helper.h"
#include "admin.h"
#include "class.h"

class System {
private:

  LinkedList<Medicine> medicineList;
  LinkedList<Disease> diseseList;
  LinkedList<Doctor> doctorList;
  LinkedList<Patient> patientList;
  LinkedList<Shedule> sheduleList;

  Admin admin = Admin("admin", medicineList, diseseList, doctorList, patientList, sheduleList);

  void AdminDash() {
    admin.DashBoard();
  }  

  void AdminLogin() {

    std::string passsword;
    Assign("passsword for admin", passsword);

    if (admin.IsPassword(passsword)) {
      AdminDash();
    }
    else {
      std::cout << "\n INVALID PASSWORD \n";
      return;
    }
    
  }

  void DoctorDash(Doctor doctor) {

    doctor.DashBoard();

  }

  void DoctorLogin() {

    Doctor doctor;
    doctor = doctorList.chooseNode();

    std::string passsword;
    Assign("passsword for doctor", passsword);

    if (doctor.IsPassword(passsword)) {
      DoctorDash(doctor);
    }
    else {
      std::cout << "\n INVALID PASSWORD \n";
      return;
    }

  }

public:

  void Login() {
   
    clearScreen();
    std::cout << "=== Login ====\n";
    int choice;
    bool quit = false;

    while (!quit) {
      std::cout << "Choose Account Type: \n0. Quit \n1. Admin \n2. Doctor \n";
      std::cout << "=============\n";
      Assign("choice", choice);
      switch (choice) {        
        case 0:
          quit = true;
          break;
        case 1:
          AdminLogin();
          Login();
          quit = true;
          break;
         case 2:
          DoctorLogin();
          Login();
          quit = true;
          break;
         default:
          std::cout << "Invalid\n";
          break; 
      }
    }

  }


};

#endif // !SYSTEM_H
