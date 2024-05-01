#ifndef  CLASS_H
#define CLASS_H

#include <iostream>
#include <string>

enum Gender {
  Male=1,
  Female=2,
  X=3
};

struct Date {
  int day;
  std::string month;
  int year;
  Date(int day, std::string month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }
};

struct Medicine {
  std::string name;
  int price;
};

struct Disease {
  std::string name;
  int level;
  Medicine medicine; 
  Disease(std::string name, int level, Medicine medicine) {
    this->name = name;
    this->level = level;
    this->medicine = medicine;
  }
};

class Person {
private:
  std::string name; 
  std::string sex;
  int age;
public:
  Person(std::string name, std::string sex, int age) {
    this->name = name;
    this->sex = sex;
    this->age = age;
  }
};

class Doctor : public Person {
private: 
  std::string qualification, specilization;
  Date joinDate;
  int experience;
public:
Doctor(std::string name, std::string sex, int age, std::string qualification, std::string specialization, Date joinDate, int experience)
    : Person(name, sex, age), qualification(qualification), specilization(specilization), joinDate(joinDate), experience(experience) {}
};

class Patient : public Person {
private:
  Disease disease;
  Date admitDate;
  Date dischageDate; 
  int price;
public: 
  Patient(std::string name, std::string sex, int age, Disease disease, Date admitDate, Date dischageDate) : Person(name, sex, age), disease(disease), admitDate(admitDate), dischageDate(dischageDate)  {} 

};

#endif // ! CLASS_H
