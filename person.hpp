#pragma once
#include <array>
#include <iostream>
#include <string>

using pesel = std::array<size_t, 11>;
using indexNo = std::array<size_t, 6>;

enum class Sex {
    male,
    female
};

class Person {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    pesel pesel_;
    Sex sex_;

public:
    bool validatePESEL(pesel pesel);
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    pesel getPESEL() const;
    Sex getSex() const;

    void setName(std::string name);
    void setSurname(std::string surname);
    void setAddress(std::string address);
    void setPESEL(pesel PESEL);
    void setSex(Sex sex);

    virtual void displaySex(const Sex& sex) const;
    void displayPESEL(const pesel& pesel) const;

    Person(std::string name, std::string surname, std::string address, pesel pesel, Sex sex);
};