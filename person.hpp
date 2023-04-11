#pragma once
#include <array>
#include <iostream>
#include <stdexcept>
#include <string>

enum class Sex {
    male,
    female
};

class Person {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    Sex sex_;

public:
    bool validatePESEL(std::string pesel);
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getPESEL() const;
    Sex getSex() const;

    // czy setery są potrzebne?
    void setName(std::string name);
    void setSurname(std::string surname);
    void setAddress(std::string address);
    void setPESEL(std::string PESEL);
    void setSex(Sex sex);

    virtual void displaySex(const Sex& sex) const;

    Person(std::string name, std::string surname, std::string address, std::string pesel, Sex sex);
};