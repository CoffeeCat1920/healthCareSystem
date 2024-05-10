#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>

template<typename T>
void Assign(std::string name, T& target) {
  T value;
  std::cout << "\n Enter the " << name << ": "; 
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

void KeyPress() {
  int i;
  bool close = false;
  while (!close) {
    Assign("0 to go back", i);
    if (i == 0) close = true;
  }
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


void clearScreen() { 
  std::cout << "\033[2J\033[1;1H";
}

#endif // !HELPER_H
