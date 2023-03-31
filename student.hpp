#pragma once
#include "person.hpp"

class Student : public Person {
private:
    std::string index_;

public:
    std::string getIndex() const;

    // void displayIndex(const std::string& index) const;

    void setIndex(std::string index);

    Student(std::string name, std::string surname, std::string address, std::string PESEL, std::string index, Sex sex);
};