#include <iostream>
#include <vector>
#include "../lib/student.hpp"

student::student(std::string name) {
  this->name = name;

  std::cout << "Creating: " << this << std::endl;
}

student::~student() {
  std::cout << "Destroying: " << this << std::endl;
}

float student::calculate_average() {
  double sum = 0.0;
  for (auto &c : courses) {
    sum += c->getGrade();
  }

  return (double) (sum / courses.size());
}

// Overflow ostream operator
std::ostream& operator<<(std::ostream& os, student& s) {
  os << "Name: " << s.name << std::endl;
  for (auto &c : s.courses) {
    os << "\t" << *c << std::endl;
  }
  os << "\tAverage Grade: " << s.calculate_average();

  return os;
}

// Overflow istream operator
std::istream& operator>>(std::istream& is, student& s) {
  std::string course_name;
  double grade;

  for (;;) {
    std::cout << "Give course name: ";
    is >> course_name;

    std::cout << "Give grade: ";
    is >> grade;

    s.courses.push_back(new course(course_name, grade));

    char prompt;
    std::cout << "Continue? y/n: ";
    is >> prompt;

    if (prompt == 'n') break;
  }

  return is;
}