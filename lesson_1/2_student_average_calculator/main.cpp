/**
 * @file main.cpp
 * @author Iakovos Mastrogiannopoulos (iakmastro@sexycoders.org)
 * @brief This is a simple average calculator for one student.
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
*/
#include <iostream>

int main(int argc, char **argv) {
  std::string student_name;
  std::cout << "Give student name: ";
  std::cin >> student_name;

  // Variables initializations
  double sum = 0.0; // Keep sum of grades
  int total = 0; // Keep total number of courses

  // Infinite loop to get courses data
  for (;;) {
    std::string course_name;
    std::cout << "Give course name: ";
    std::cin >> course_name;

    double grade;
    std::cout << "Give grade: ";
    std::cin >> grade;

    sum += grade; // Add grade to sum
    total++; // Increment total courses

    char prompt;
    std::cout << "Continue? y/n: ";
    std::cin >> prompt;

    if (prompt == 'n') break;
  }

  // Average calculation
  std::cout << "Average: " << (float) (sum / total) << std::endl;

  return 0;
}