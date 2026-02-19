//
// Created by 15165 on 2026/2/19.
//

#ifndef WEEK6TUT_FULLTIMEEMPLOYEE_H
#define WEEK6TUT_FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(string n, double salary);

    double calculateSalary() override;
};

#endif //WEEK6TUT_FULLTIMEEMPLOYEE_H