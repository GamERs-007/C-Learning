/*
 * Student.h
 *
 *  Created on: Jan. 22, 2025
 *      Author: umroot
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm> // For std::find_if


// Define a class
class Student {

friend int compareStudents(const void* a, const void* b);

public:



    // step1 : new address;
    // step2 : copy content from the source address;
    // NO DIRECT ASSIGNMENT BETWEEN POINTERS

    Student():id(0), name(new char[50]){
    	++instanceCount;
    }

    Student (const Student& other) : id(other.id), name(new char[50]){
    	//name = new char[50];
    	strcpy(name, other.name); //element wise copy
    	++instanceCount;
    }


//    Student(int i, const char *n) :id(i), name(n)  //zero marks;

    Student(int i, const char *n) :id(i), name(new char[50]){
    	//element-wise copy
        strcpy(name, n);
        ++instanceCount;
    }

    ~Student(){
    	delete[] name;
    	--instanceCount;
    	std::cout << "\n" <<instanceCount<< std::endl;

    }

    static int getCount(){
    	return instanceCount;
    }

private:
    static int instanceCount; //class level variable;

    int id;
       //char name[50];
       //string name;
       char * name;

};

//initalization is outside the class definiton;

int Student::instanceCount{0};


// Comparison function for qsort
int compareStudents(const void* a, const void* b) { //stand alone
    const Student *studentA = static_cast<const Student*>(a);
    const Student *studentB = static_cast<const Student*>(b);
    return strcmp(studentA->name, studentB->name); // Sort by name
}

void testStudentSort() {

    Student students[] = {
    	{104,"Dophie"},
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };

    std::cout<< "Number of Student Objects " <<Student::getCount() << std::endl;

    int n = sizeof(students) / sizeof(students[0]);

    // Sort the array
    qsort(students, n, sizeof(students[0]), compareStudents);

    // Display sorted students
    for (int i = 0; i < n; ++i) {
     //   std::cout << students[i].id << " " << students[i].name << std::endl;
    }

//    // Search an element 6
//    auto it = find_if(students, students + n, [&](const Student& s) {
//        return strcmp(s.name, "Bob") == 0; // Compare names
//    });
//        // Print index
//    std::cout << distance(students, it);

}




#endif /* STUDENT_H_ */



/*
 * #include <iostream>
#include <vector>
#include <cstring> // For strcmp
#include <algorithm> // For std::find_if

// Student class definition
class Student {
public:
    int id;
    char name[50];

    Student(int i, const char *n) {
        id = i;
        strcpy(name, n);
    }

    ~Student() {}
};

// Function to find a student by name
Student* findStudentByName(const std::vector<Student>& students, const std::string& name) {
    // Use std::find_if to search for a student with the given name
    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return strcmp(s.name, name.c_str()) == 0; // Compare names
    });

    // Check if the student was found
    if (it != students.end()) {
        return const_cast<Student*>(&(*it)); // Return a pointer to the found Student
    }

    return nullptr; // Return nullptr if not found
}

int main() {
    // Example usage
    std::vector<Student> students = {
        Student(1, "Alice"),
        Student(2, "Bob"),
        Student(3, "Charlie")
    };

    std::string nameToFind = "Bob";
    Student* foundStudent = findStudentByName(students, nameToFind);

    if (foundStudent) {
        std::cout << "Student found: ID = " << foundStudent->id << ", Name = " << foundStudent->name << std::endl;
    } else {
        std::cout << "Student with name " << nameToFind << " not found." << std::endl;
    }

    return 0;
}
 *
 */
