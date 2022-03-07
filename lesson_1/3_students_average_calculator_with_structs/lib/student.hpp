#include <string>
#include <vector>
#include "course.hpp"

struct student {
  // Attributes
  std::string name;
  std::vector<course*> courses;

  // Constructor and Destructor
  student(std::string);
  ~student(); // Very rarely used

  // Methods
  float calculate_average();
};