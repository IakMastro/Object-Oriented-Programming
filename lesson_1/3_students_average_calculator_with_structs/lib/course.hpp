#include <string>

struct course {
  // Attributes
  std::string name;
  double grade;

  // Contructor and Destructor
  course(std::string, double);
  ~course();
};