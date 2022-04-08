package example;

import example.Course;
import java.util.ArrayList;

public class Student {
  private String name;
  private ArrayList<Course> courses;

  public Student(String name) {
    this.name = name;
    this.courses = new ArrayList<Course>();
  }

  public String getName() {
    return name;
  }

  public ArrayList<Course> getCourses() {
    return courses;
  }

  public void addCourse(Course course) {
    courses.add(course);
  }

  public void removeCourse(Course course) {
    courses.remove(course);
  }

  public String toString() {
    var stringBuilder = new StringBuilder();

    stringBuilder.append("Name: " + name + "\tCourses: ");

    for (var course : courses) {
      stringBuilder.append("\t" + course.toString() + "\n");
    }

    return stringBuilder.toString();
  }
}