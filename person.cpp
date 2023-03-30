#include "person.hpp"

std::string Person::getName() const {
    return name_;
}

std::string Person::getSurname() const {
    return surname_;
}

std::string Person::getAddress() const {
    return address_;
}

pesel Person::getPESEL() const {
    return pesel_;
}

Sex Person::getSex() const {
    return sex_;
}

void Person::setName(std::string name) {
    name_ = name;
}

void Person::setSurname(std::string surname) {
    surname_ = surname;
}

void Person::setAddress(std::string address) {
    address_ = address;
}

void Person::setPESEL(pesel pesel) {
    if (validatePESEL(pesel)) {
        pesel_ = pesel;
    } else {
        std::cout << "Incorrect PESEL!\n";
    }
}

void Person::setSex(Sex sex) {
    sex_ = sex;
}

void Person::displayPESEL(const pesel& pesel) const {
    for (auto& el : pesel) {
        std::cout << el;
    }
}

void Person::displaySex(const Sex& sex) const {
    switch (sex) {
    case Sex::female:
        std::cout << "female";
        break;
    case Sex::male:
        std::cout << "male";
        break;
    default:
        std::cout << "undefined";
    }
}

bool Person::validatePESEL(pesel pesel) {
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    size_t S = 0;
    for (size_t i = 0; i < 10; i++) {
        S += pesel[i] * w[i];
    }
    S = S % 10;
    if (S == 0) {
        return (pesel[10] == 0);
    } else {
        return (pesel[10] == (10 - S));
    }
}

Person::Person(std::string name, std::string surname, std::string address, pesel pesel, Sex sex)
    : name_(name), surname_(surname), address_(address), pesel_(pesel), sex_(sex) {
    if (validatePESEL(pesel)) {
        pesel_ = pesel;
    } else {
        std::cout << "Person created, but PESEL is incorrect!\n";
        pesel_ = pesel;
    }
}
