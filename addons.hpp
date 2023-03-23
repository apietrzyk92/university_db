#pragma once
#include <random>
#include "student.hpp"

pesel generatePESEL();
indexNo generateIndex();
sex generateSex();
std::string generateName(sex sex);
std::string generateSurname(sex sex);
std::string generateAddress();
Student generateStudent();

size_t generateNumber(int a, int b);