#include "student.hpp"

std::string Student::getName() const {
    return Student::name_;
}

std::string Student::getSurname() const {
    return Student::surname_;
}

std::string Student::getAddress() const {
    return Student::address_;
}

std::array<size_t, 11> Student::getPESEL() const {
    return Student::PESEL_;
}

std::array<size_t, 6> Student::getIndex() const {
    return Student::index_;
}

sex Student::getSex() const {
    return Student::sex_;
}

void Student::setName(std::string name) {
    Student::name_ = name;
}

void Student::setSurname(std::string surname) {
    Student::surname_ = surname;
}

void Student::setAddress(std::string address) {
    Student::address_ = address;
}

void Student::setPESEL(std::array<size_t, 11> PESEL) {
    if (validatePESEL(PESEL)) {
        Student::PESEL_ = PESEL;
    } else {
        std::cout << "Incorrect PESEL!\n";
    }
}

void Student::setIndex(std::array<size_t, 6> index) {
    Student::index_ = index;
}

void Student::setSex(sex sex) {
    Student::sex_ = sex;
}

void Student::displayPESEL(const std::array<size_t, 11>& PESEL) const {
    for (auto& el : PESEL) {
        std::cout << el;
    }
}

void Student::displayIndex(const std::array<size_t, 6>& index) const {
    for (auto& el : index) {
        std::cout << el;
    }
}

void Student::displaySex(const sex& sex) const {
    switch (sex) {
    case sex::female:
        std::cout << "female";
        break;
    case sex::male:
        std::cout << "male";
        break;
    default:
        std::cout << "undefined";
    }
}

bool Student::validatePESEL(std::array<size_t, 11> PESEL) {
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    size_t S = 0;
    for (size_t i = 0; i < 10; i++) {
        S += PESEL[i] * w[i];
    }
    S = S % 10;
    if (S == 0) {
        return (PESEL[10] == 0);
    } else {
        return (PESEL[10] == (10 - S));
    }
}

Student::Student(Name name,
                 std::string surname,
                 std::string address,
                 std::array<size_t, 11> PESEL,
                 std::array<size_t, 6> index,
                 sex sex)
    : name_(name), surname_(surname), address_(address), index_(index), sex_(sex) {
    if (validatePESEL(PESEL)) {
        PESEL_ = PESEL;
    } else {
        std::cout << "Student created, but PESEL is incorrect!\n";
        PESEL_ = PESEL;
    }
}
