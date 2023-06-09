#pragma once
#include <array>
#include <iostream>
#include <string>

using Name = std::string;
enum class sex {
    male,
    female
};

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::array<size_t, 11> PESEL_;
    sex sex_;
    std::array<size_t, 6> index_;

public:
    bool validatePESEL(std::array<size_t, 11> PESEL);
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::array<size_t, 11> getPESEL() const;
    std::array<size_t, 6> getIndex() const;
    sex getSex() const;
    void displayPESEL(const std::array<size_t, 11>& PESEL) const;
    void displayIndex(const std::array<size_t, 6>& index) const;
    void displaySex(const sex& sex) const;

    void setName(std::string name);
    void setSurname(std::string surname);
    void setAddress(std::string address);
    void setPESEL(std::array<size_t, 11> PESEL);
    void setIndex(std::array<size_t, 6> index);
    void setSex(sex sex);

    Student(Name name, std::string surname, std::string address, std::array<size_t, 11> PESEL, std::array<size_t, 6> index, sex sex);
};