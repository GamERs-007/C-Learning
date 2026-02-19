//
// Created by 15165 on 2026/2/19.
//

#include "Employee.h"

Employee::Employee(string n) : name(n) {}

void Employee::display() const {
    cout << "Employee Name: " << name << endl;
}