//
// Created by 15165 on 2026/2/19.
//

#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(string n, double salary): Employee(n), monthlySalary(salary) {}

double FullTimeEmployee::calculateSalary() {
    return monthlySalary;
}
