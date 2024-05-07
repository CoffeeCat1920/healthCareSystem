#ifndef  CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include "helper.h"
#include "list.h"

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

    int month;
    Assign("Month (1-12)", month);
    while (month > 12 || month < 1) {
      std::cout << "\nINVALID Month"; 
      Assign("Month (1-12)", month);
    }

    int day;
    Assign("Day (1-31)", day);
    while (day < 1 || day > daysInMonth[month]){
      std::cout << "\nINVALID Day"; 
      Assign("Day (1-31)", day);
    }

    int year;
    Assign("Year (without 20)", year);

    while (year > 99) {
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


};

struct Disease {
  std::string name;
  Medicine medicine; 

  Disease() : name("ERROR NO NAME"), medicine(Medicine()) {};
  Disease(std::string name, Medicine medicine) : medicine(medicine), name(name) {}

  bool operator==(const Disease& other) const {
    return (name == other.name && medicine == other.medicine);
  }

  std::string GetData() {
    std::string statement = name + "  " + medicine.GetData();
    return statement;
  } 

};

class Shedule {
private:
  LinkedList<Patient()> list;
  int limit;
public:
  Shedule() : limit(2) {}
  Shedule(int limit) : limit(limit) {}
  bool isFree() {
    return (list.count() < limit);
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

  bool operator==(const Person& other) const {
    return (name == other.name && sex == other.sex && age == other.age);
  }

};

class Patient : public Person {
private:
  Disease disease;
  Date admitDate;
  int price;
public: 

  Patient() : Person(), disease(Disease()), admitDate(Date()), price(0) {}
  Patient(Person person, Disease disease, Date admitDate, int price) : Person(person), disease(disease), admitDate(admitDate), price(price)  {} 

  bool operator==(const Patient& other) {
    return (Person::operator==(other) && disease == other.disease && admitDate == other.admitDate && price == other.price);
  }

  std::string GetData() {
    std::string statement = Person::GetData() + "  " + disease.GetData() + "  " + admitDate.GetData(); 
    return statement;
  }

};

#endif // ! CLASS_H
