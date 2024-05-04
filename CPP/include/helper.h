#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>

template<typename T>
void Assign(std::string name, T& target) {
  T value;
  std::cout << "\n Enter the data for " << name << ": "; 
  std::cin >> value;

  if (!std::cin) {
    std::cout << "\n Invalid Input Error \n";
    std::cin.clear();
    std::cin.ignore();
    Assign(name, target);
  }

  std::cout << "\n";
  target = value;
} 

int choose(std::string name) {
  std::string statement = "Choose from List(1) or enter new " + name + "(2) or 0 to quit: ";
  std::cout << statement; 
  int choice;
  std::cin >> choice;
  if (choice == 1) return 1;
  else if (choice == 2) return 2;
  else return 0;
}

#endif // !HELPER_H
