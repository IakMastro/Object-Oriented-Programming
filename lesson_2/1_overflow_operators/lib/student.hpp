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
  float calculate_average();

  // Getters/Setters
  std::string getName() { return this->name; }
  void setName(std::string name) { this->name = name; }

  // Overflow ostream operator
  friend std::ostream& operator<<(std::ostream&, student&);

  // Overflow istream operator
  friend std::istream& operator>>(std::istream&, student&);
};