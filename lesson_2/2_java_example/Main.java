package example;

import example.Student;
import example.Course;

public class Main {
  public static void main(String[] args) {
    var student = new Student("John");
    var course1 = new Course("Math", 100);
    var course2 = new Course("English", 200);

    student.addCourse(course1);
    student.addCourse(course2);

    System.out.println(student);
  }
}