#include <iostream>
using namespace std;

class Student
{

private:
    int id;

public:
    Student(int id): id(id)
    {
        cout << "Student constructed (ID = " << id << ")\n";
    }

    ~Student()
    {
        cout << "Student destroyed (ID = " << id << ")\n";
    }

    friend bool sameStudent(const Student& s1, const Student& s2);
    friend class Professor;

};

bool sameStudent(const Student& s1, const Student& s2)
{
    return s1.id == s2.id;
}

class Course
{
private:
    Student student;

public:
    Course(int studentID) : student(studentID) {
        cout << "Course constructed\n";
    }

    ~Course() {
        cout << "Course droped\n";
    }
};

class Professor
{
public:
    void printStudentID(const Student& s)
    {
        cout << "Professor accessing Student ID: " << s.id << endl;
    }
    ~Professor()
    {
        cout << "Professor fired\n";
    }
};

int main() {
    cout << "---- Creating Students ----\n";
    Student s1(128);
    Student s2(128);
    Student s3(512);

    cout << "\n---- Comparing Students ----\n";
    cout << "s1 and s2 same? " << (sameStudent(s1, s2) ? "Yes" : "No") << endl;
    cout << "s1 and s3 same? " << (sameStudent(s1, s3) ? "Yes" : "No") << endl;

    cout << "\n---- Friend Class Access ----\n";
    Professor prof;
    prof.printStudentID(s1);

    cout << "\n---- Course Composition ----\n";
    Course c1(303);

    cout << "\n---- CLEANING MENMORY ----\n";
    return 0;
}