#include <iostream>
#include <vector>
#include "../lib/student.hpp"

student::student(std::string name) {
  this->name = name;

  std::cout << "Creating: " << this << std::endl;
}

student::~student() {
  for (auto &c: courses) {
    delete c;
  }

  std::cout << "Destroying: " << this << std::endl;
}

float student::calculate_average() {
  double sum = 0.0;
  for (auto &c : courses) {
    sum += c->grade;
  }

  return (double) (sum / courses.size());
}