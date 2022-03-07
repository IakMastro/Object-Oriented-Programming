#include <string>
#include <vector>
#include "course.hpp"

class student {
private:
  // Attributes
  std::string name;
  std::vector<course*> courses;

public:
  // Constructor and Destructor
  student(std::string);
  ~student(); // Very rarely used

  // Methods
  void insert_course(std::string, double);
  float calculate_average();

  // Getters/Setters
  std::string getName() { return this->name; }
  void setName(std::string name) { this->name = name; }
};