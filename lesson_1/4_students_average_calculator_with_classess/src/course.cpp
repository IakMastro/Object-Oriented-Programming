#include <iostream>
#include "../lib/course.hpp"

course::course(std::string name, double grade) {
  this->name = name;
  this->grade = grade;

  std::cout << "Creating: " << this << std::endl;
}

course::~course() {
  std::cout << "Destroying: " << this << std::endl;
}