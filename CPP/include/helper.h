#ifndef HELPER_H
#define HELPER_H

#include <iostream>

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

#endif // !HELPER_H
