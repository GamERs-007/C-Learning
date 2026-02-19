//
// Created by 15165 on 2026/2/19.
//

#ifndef WEEK6TUT_EMPLOYEE_H
#define WEEK6TUT_EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee {
protected:
    string name;

public:
    Employee(string n);  // constructor

    virtual double calculateSalary() = 0;  // pure virtual

    virtual void display() const;  // virtual function

    virtual ~Employee() = default;
};

#endif //WEEK6TUT_EMPLOYEE_H