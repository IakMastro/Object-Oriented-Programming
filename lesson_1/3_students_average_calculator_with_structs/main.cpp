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

    for (;;) {
      std::string course_name;
      std::cout << "Give course name: ";
      std::cin >> course_name;

      double grade;
      std::cout << "Give grade: ";
      std::cin >> grade;

      // Add course to the student's courses list
      students[students.size() - 1]->courses.push_back(new course(course_name, grade));

      char prompt;
      std::cout << "Continue? y/n: ";
      std::cin >> prompt;

      if (prompt == 'n') break;
    }

    char prompt;
    std::cout << "Add more students? y/n: ";
    std::cin >> prompt;

    if (prompt == 'n') break;
  }

  for (auto &s : students) {
    std::cout << "Student name: " << s->name << "\tAverage: " << s->calculate_average() << std::endl;
    delete s; // Delete from the buffer (works like free in C)
  }

  return 0;
}