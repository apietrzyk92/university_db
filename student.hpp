#pragma once
#include "person.hpp"

class Student : public Person {
private:
    indexNo index_;

public:
    indexNo getIndex() const;

    void displayIndex(const indexNo& index) const;

    void setIndex(indexNo index);

    Student(std::string name, std::string surname, std::string address, pesel PESEL, indexNo index, sex sex);
};