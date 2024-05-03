#ifndef  CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include "helper.h"

enum Gender {
  Male=1,
  Female=2,
  X=3
};

struct Date {
  int day;
  std::string month;
  int year;
  
  std::string monthArr[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};  
  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  Date() : day(1), month("Jan"), year(1969) {}
  Date(int day, std::string month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  std::string GetData() {
    std::string statement = std::to_string(day) + "/" + month + "/" + std::to_string(year); 
    return statement;
  }

  bool operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
  }

  Date AddDate() {

    int day;
    Assign("Day (1-31)", day);


    while (day>=1 && day<=daysInMonth[day]) {
      std::cout << "\nINVALID Day"; 
      Assign("Day (1-31)", day);
    }

    int month;
    Assign("Month (1-12)", month);

    while (month>=12 && month<=0) {
      std::cout << "\nINVALID Month"; 
      Assign("Month (1-12)", month);
    }

    int year;
    Assign("Year (without 20)", year);

    while (month>=12 && month<=0) {
      std::cout << "\nINVALID Year"; 
      Assign("Year (without 20)", year);
    }

    return Date(day, monthArr[month], year);

  }

};

struct Medicine {
  std::string name;
  int price;
  Medicine() : name("ERROR NO NAME"), price(0) {}
  Medicine(std::string name, int price) : name(name), price(price) {}

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(price) + "Rs"; 
    return statement;
  }

  bool operator==(const Medicine& other) const {
    return (name == other.name && price == other.price);
  }

  Medicine AddMedicine() {

    std::string name;
    Assign("Name", name);

    int price;
    Assign("Price", price);
     
    return Medicine(name, price);

  }

};

struct Disease {
  std::string name;
  int level;
  Medicine medicine; 

  Disease() : name("ERROR NO NAME"), level(0), medicine(Medicine()) {};
  Disease(std::string name, int level, Medicine medicine) {
    this->name = name;
    this->level = level;
    this->medicine = medicine;
  }

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(level) + medicine.name;
    return statement;
  } 

};

class Person {
private:

  std::string name; 
  std::string sex;
  int age;

public:

  Person() : name("ERROR NO NAME"), sex("0"), age(0) {}
  Person(std::string name, std::string sex, int age) {
    this->name = name;
    this->sex = sex;
    this->age = age;
  }

  std::string GetData() {
    std::string statement = name + "  " + std::to_string(age) + "  " + sex; 
    return statement;
  }

};

class Doctor : public Person {
private: 
  std::string qualification, specilization;
  Date joinDate;
  int experience;
public:

  Doctor() : Person(), qualification("0"), specilization("0"), joinDate(Date()), experience(0) {}

  Doctor(Person person, std::string qualification, std::string specialization, Date joinDate, int experience) : Person(person), qualification(qualification), specilization(specialization), joinDate(joinDate), experience(experience) {}

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + qualification + "  " +  joinDate.GetData() + std::to_string(experience);
    return statement;
  }

};

class Patient : public Person {
private:
  Disease disease;
  Date admitDate;
  Date dischageDate; 
  int price;
public: 

  Patient() : Person(), disease(Disease()), admitDate(Date()), dischageDate(Date()), price(0) {}
  Patient(Person person, Disease disease, Date admitDate, Date dischageDate, int price) : Person(person), disease(disease), admitDate(admitDate), dischageDate(dischageDate), price(price)  {} 

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + disease.GetData() + "  " + admitDate.GetData() + "  " + dischageDate.GetData() + "  " + std::to_string(price); 
    return statement;
  }

};

#endif // ! CLASS_H
