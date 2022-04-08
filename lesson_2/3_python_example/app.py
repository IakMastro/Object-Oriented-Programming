import course
import student

if __name__ == '__main__':
  # Create a student object.
  student_1 = student.Student('John', [])
  # Create a course object.
  course_1 = course.Course('Python', 10)
  # Add the course to the student object.
  student_1.add_course(course_1)
  # Print the student object.
  print(student_1)
  # Print the average grade of the student.
  print(student_1.calculate_average_grade())
