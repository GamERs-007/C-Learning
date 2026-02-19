//
// Created by 15165 on 2026/2/19.
//

#ifndef WEEK6TUT_PARTTIMEEMPLOYEE_H
#define WEEK6TUT_PARTTIMEEMPLOYEE_H

#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string n, double rate, int hours);

    double calculateSalary() override;
};

#endif //WEEK6TUT_PARTTIMEEMPLOYEE_H