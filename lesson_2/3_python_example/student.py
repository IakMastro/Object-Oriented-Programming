# Define a class consisting of a student name and a list of courses.
class Student:
  def __init__(self, name, courses):
    self.name = name
    self.courses = courses

  def __str__(self):
    return f'Name: {self.name}\tCourses: {self.courses}'

  def add_course(self, course):
    self.courses.append(course)

  def calculate_average_grade(self):
    total_grade = 0
    for course in self.courses:
      total_grade += course.grade
    return total_grade / len(self.courses)
