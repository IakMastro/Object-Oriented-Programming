# Define a class consisting of a course name and the grade of the course.
class Course:
  def __init__(self, name, grade):
    self.name = name
    self.grade = grade

  def __str__(self):
    return f'Name: {self.name}\tGrade: {self.grade}'