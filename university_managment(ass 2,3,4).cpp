#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string fullName;
    int age;
    string idNumber;
    string contactInfo;

public:
    Person(string name = "", int a = 18, string id = "", string contact = "")
    {
        setName(name);
        setAge(a);
        idNumber = id;
        contactInfo = contact;
    }

    virtual void displayDetails()
    {
        cout << "Name: " << fullName << ", Age: " << age
             << ", ID: " << idNumber << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() { return 0.0; }

    void setName(string name) { fullName = name.empty() ? "Unknown" : name; }
    void setAge(int a) { age = (a > 0 && a < 100) ? a : 18; }
    string getName() { return fullName; }
    int getAge() { return age; }
};

class Student : public Person
{
    string programName;
    string enrollmentYear;
    float gpa;

public:
    Student(string name = "", int a = 18, string id = "", string contact = "",
            string enroll = "", string program = "", float gradePoint = 0.0f)
        : Person(name, a, id, contact), enrollmentYear(enroll), programName(program)
    {
        setGPA(gradePoint);
    }

    void setGPA(float gradePoint) { gpa = (gradePoint >= 0.0f && gradePoint <= 4.0f) ? gradePoint : 0.0f; }

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Program: " << programName << ", GPA: " << gpa << endl;
    }

    double calculatePayment() override { return 1000.0; }
};

class Professor : public Person
{
    string departmentName;
    string areaOfExpertise;
    string hiringDate;

public:
    Professor(string name = "", int a = 30, string id = "", string contact = "",
              string dept = "", string spec = "", string hire = "")
        : Person(name, a, id, contact), departmentName(dept), areaOfExpertise(spec), hiringDate(hire) {}

    void displayDetails() override
    {
        Person::displayDetails();
        cout << "Department: " << departmentName << ", Specialization: " << areaOfExpertise << endl;
    }

    double calculatePayment() override { return 5000.0; }
};

class Course
{
    string courseCode, courseTitle, courseDescription;
    int creditHours;

public:
    Course(string code = "", string title = "", int credits = 3, string desc = "")
        : courseCode(code), courseTitle(title), courseDescription(desc)
    {
        setCredits(credits);
    }

    void setCredits(int credits) { creditHours = (credits > 0) ? credits : 1; }

    void display()
    {
        cout << "Course: " << courseCode << " - " << courseTitle << ", Credits: " << creditHours << endl;
    }
};

class Department
{
    string departmentName, buildingLocation;
    float departmentBudget;

public:
    Department(string name = "", string location = "", float budget = 0.0f)
        : departmentName(name), buildingLocation(location), departmentBudget(budget) {}

    void display()
    {
        cout << "Department: " << departmentName << ", Location: " << buildingLocation
             << ", Budget: ₹" << departmentBudget << endl;
    }
};

class GradeBook
{
    string studentIDs[10];
    float studentGrades[10];
    int gradeCount = 0;

public:
    void addGrade(string id, float grade)
    {
        if (gradeCount < 10)
        {
            studentIDs[gradeCount] = id;
            studentGrades[gradeCount++] = grade;
        }
    }

    float calculateAverageGrade()
    {
        float total = 0;
        for (int i = 0; i < gradeCount; i++)
            total += studentGrades[i];
        return gradeCount ? total / gradeCount : 0.0f;
    }

    float getHighestGrade()
    {
        float max = 0;
        for (int i = 0; i < gradeCount; i++)
            if (studentGrades[i] > max)
                max = studentGrades[i];
        return max;
    }

    void getFailingStudents()
    {
        cout << "Failing students (grade < 50):\n";
        for (int i = 0; i < gradeCount; i++)
            if (studentGrades[i] < 50)
                cout << studentIDs[i] << " with grade " << studentGrades[i] << endl;
    }
};

class EnrollmentManager
{
    string courseIDs[10], studentIDs[10];
    int enrollmentCount = 0;

public:
    void enrollStudent(string courseID, string studentID)
    {
        if (enrollmentCount < 10)
        {
            courseIDs[enrollmentCount] = courseID;
            studentIDs[enrollmentCount++] = studentID;
        }
    }

    void dropStudent(string studentID)
    {
        for (int i = 0; i < enrollmentCount; i++)
        {
            if (studentIDs[i] == studentID)
            {
                courseIDs[i] = courseIDs[enrollmentCount - 1];
                studentIDs[i] = studentIDs[enrollmentCount - 1];
                enrollmentCount--;
                break;
            }
        }
    }

    int getEnrollmentCount() { return enrollmentCount; }
};

int main()
{
    Student student1("Aarav Sharma", 20, "S101", "aarav@mail.com", "2023", "Computer Science", 3.6f);
    Student student2("Priya Mehta", 21, "S102", "priya@mail.com", "2023", "Electronics", 3.2f);

    // Professors
    Professor professor1("Dr. Vinay Joshi", 45, "P201", "vinay@uni.edu", "CS", "Machine Learning", "2008");
    Professor professor2("Dr. Kavita Rao", 50, "P202", "kavita@uni.edu", "Math", "Applied Math", "2005");

    Course course1("CS101", "Intro to Programming", 4, "Learn programming basics");
    Department dept1("Engineering", "Block B", 75000.0f);

    student1.displayDetails();
    student2.displayDetails();
    professor1.displayDetails();
    professor2.displayDetails();
    course1.display();
    dept1.display();

    GradeBook gradeBook;
    gradeBook.addGrade("S101", 78);
    gradeBook.addGrade("S102", 44);
    cout << "Average Grade: " << gradeBook.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gradeBook.getHighestGrade() << endl;
    gradeBook.getFailingStudents();

    EnrollmentManager enrollmentManager;
    enrollmentManager.enrollStudent("CS101", "S101");
    enrollmentManager.enrollStudent("CS101", "S102");
    cout << "Enrolled Students: " << enrollmentManager.getEnrollmentCount() << endl;
    enrollmentManager.dropStudent("S102");
    cout << "After drop: " << enrollmentManager.getEnrollmentCount() << endl;

    Person *people[2] = {&student1, &professor1};
    for (int i = 0; i < 2; i++)
    {
        people[i]->displayDetails();
        cout << "Calculated Payment: ₹" << people[i]->calculatePayment() << "\n\n";
    }

    return 0;
}