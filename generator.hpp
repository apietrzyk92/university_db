#pragma once
#include <algorithm>
#include <memory>
#include <random>
#include "university.hpp"

class Generator {
private:
    std::shared_ptr<University> pUni_;

    std::string generatePESEL();
    std::string generateIndex();
    Sex generateSex();
    std::string generateName(Sex sex);
    std::string generateSurname(Sex sex);
    std::string generateAddress();
    size_t generateNumber(int a, int b);
    float generateSalary();

public:
    std::shared_ptr<Student> generateStudent();
    std::shared_ptr<Employee> generateEmployee();
    void generatePeople(size_t n);
    Generator(std::shared_ptr<University>& pUni);
};