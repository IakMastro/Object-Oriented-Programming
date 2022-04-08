package example;

public class Course {
  private String name;
  private double grade;

  public Course(String name, double grade) {
    this.name = name;
    this.grade = grade;
  }

  public String getName() {
    return name;
  }

  public double getGrade() {
    return grade;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setGrade(double grade) {
    this.grade = grade;
  }

  public String toString() {
    return "Name: " + name + "\tGrade: " + grade;
  }
}