#include <iostream>

#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

int main() {
    Employee* e1 = new PartTimeEmployee("Jack", 20, 100);
    Employee* e2 = new FullTimeEmployee("Alex", 3000);


    e1->display();
    cout << "Salary: $" << e1->calculateSalary() << "\n\n";

    e2->display();
    cout << "Salary: $" << e2->calculateSalary() << "\n";

    return 0;
}
