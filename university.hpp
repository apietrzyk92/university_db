#pragma once
#include <algorithm>
#include <fstream>
#include <memory>
#include <vector>
#include "employee.hpp"
#include "student.hpp"

class University {
private:
    std::vector<std::shared_ptr<Person>> base_;

    void displayPerson(std::shared_ptr<Person> person) const;
    void removeBase();

public:
    void addPerson(std::shared_ptr<Person> person);
    void displayBase() const;
    void findPESEL(pesel& PESEL) const;
    void findSurname(std::string& surname) const;
    void sortByPESEL();
    void sortBySurname();
    void removePerson(const pesel& PESEL);
    void removeStudent(const indexNo& index);
    void modifySalary(pesel& pesel, float& salary);
    void sortBySalary();
    /*
      void saveBase();
      void readBase(std::string fileName);
    */
};
