#pragma once
#include "person.hpp"

class Employee : public Person {
private:
    float salary_;

public:
    float getSalary() const;
    void setSalary(float salary);

    Employee(std::string name, std::string surname, std::string address, pesel PESEL, float salary, sex sex);
}