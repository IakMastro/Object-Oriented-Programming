/**
 * @file main.cpp
 * @author Iakovos Mastrogiannopoulos (iakmastro@sexycoders.org)
 * @brief This is a calculator that finds the average in a list of students.
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
*/
#include <iostream>
#include <vector>
#include "lib/student.hpp"

int main(int argc, char **argv) {
  // Initialize student list
  std::vector<student*> students;

  for (;;) {
    std::string student_name;
    std::cout << "Give student name: ";
    std::cin >> student_name;

    // Add student to the list
    // Keyword new allocates memory like how malloc does in C
    students.push_back(new student(student_name));

    std::cin >> *students[students.size() - 1];

    char prompt;
    std::cout << "Add more students? y/n: ";
    std::cin >> prompt;

    if (prompt == 'n') break;
  }

  for (auto &s : students) {
    std::cout << *s << std::endl;
    delete s;
  }

  return 0;
}