#pragma once
#include <algorithm>
#include <fstream>
#include <memory>
#include <random>
#include <vector>
#include "employee.hpp"
#include "student.hpp"

class University {
private:
    std::vector<std::shared_ptr<Person>> base_;

    void displayPerson(std::shared_ptr<Person> person) const;
    void removeBase();
    std::string generatePESEL();
    std::string generateIndex();
    Sex generateSex();
    std::string generateName(Sex sex);
    std::string generateSurname(Sex sex);
    std::string generateAddress();
    size_t generateNumber(int a, int b);
    float generateSalary();

public:
    void addPerson(std::shared_ptr<Person> person);
    void displayBase() const;
    void findPESEL(std::string& PESEL) const;
    void findSurname(std::string& surname) const;
    void sortByPESEL();
    void sortBySurname();
    void removePerson(const std::string& PESEL);
    void removeStudent(const std::string& index);
    void modifySalary(std::string& pesel, float& salary);
    void sortBySalary();
    /*
      void saveBase();
      void readBase(std::string fileName);
    */
    std::shared_ptr<Student> generateStudent();
    std::shared_ptr<Employee> generateEmployee();
    void generatePeople(size_t n);
};
