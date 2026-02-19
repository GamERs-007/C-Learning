//
// Created by 15165 on 2026/2/19.
//

#include "Employee.h"
#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(string n, double rate, int hours): Employee(n), hourlyRate(rate), hoursWorked(hours) {}

double PartTimeEmployee::calculateSalary() {
    return hourlyRate * hoursWorked;
}

