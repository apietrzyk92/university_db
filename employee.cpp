#include "employee.hpp"

float Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(float salary) {
    salary_ = salary;
}

Employee::Employee(std::string name, std::string surname, std::string address, pesel PESEL, float salary, Sex sex)
    : Person(name, surname, address, PESEL, sex), salary_(salary) {}
