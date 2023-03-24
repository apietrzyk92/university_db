#include "employee.hpp"

float Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(float salary) {
    salary_ = salary;
}

Employee::Employee(std::string name, std::string surname, std::string address, pesel PESEL, float salary, sex sex)
    : Person(name, surname, address, pesel, sex), salary_(salary) {}
