#include <string>

struct course {
private:
  // Attributes
  std::string name;
  double grade;

public:
  // Contructor and Destructor
  course(std::string, double);
  ~course();

  // Getters/Setters
  std::string getName() { return this->name; }
  double getGrade() { return this->grade; }

  void setName(std::string name) { this->name = name; }
  void setGrade(double grade) { this->grade = grade; }

  // Overflow ostream operator
  friend std::ostream& operator<<(std::ostream&, course&);
};