#pragma once
#include <memory>
#include <random>
#include "employee.hpp"
#include "student.hpp"

pesel generatePESEL();
indexNo generateIndex();
sex generateSex();
std::string generateName(sex sex);
std::string generateSurname(sex sex);
std::string generateAddress();
std::shared_ptr<Student> generateStudent();

size_t generateNumber(int a, int b);

std::shared_ptr<Employee> generateEmployee();
float generateSalary();