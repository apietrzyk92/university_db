#include "person.hpp"

std::string Person::getName() const {
    return Person::name_;
}

std::string Person::getSurname() const {
    return Person::surname_;
}

std::string Person::getAddress() const {
    return Person::address_;
}

pesel Person::getPESEL() const {
    return Person::pesel_;
}

sex Person::getSex() const {
    return Person::sex_;
}

void Person::setName(std::string name) {
    Person::name_ = name;
}

void Person::setSurname(std::string surname) {
    Person::surname_ = surname;
}

void Person::setAddress(std::string address) {
    Person::address_ = address;
}

void Person::setPESEL(pesel pesel) {
    if (validatePESEL(pesel)) {
        Person::pesel_ = pesel;
    } else {
        std::cout << "Incorrect PESEL!\n";
    }
}

void Person::setSex(sex sex) {
    Person::sex_ = sex;
}

void Person::displayPESEL(const pesel& pesel) const {
    for (auto& el : pesel) {
        std::cout << el;
    }
}

void Person::displaySex(const sex& sex) const {
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

Person::Person(std::string name, std::string surname, std::string address, pesel pesel, sex sex)
    : name_(name), surname_(surname), address_(address), pesel_(pesel), sex_(sex) {
    if (validatePESEL(pesel)) {
        pesel_ = pesel;
    } else {
        std::cout << "Person created, but PESEL is incorrect!\n";
        pesel_ = pesel;
    }
}
