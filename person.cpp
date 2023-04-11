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

std::string Person::getPESEL() const {
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

void Person::setPESEL(std::string pesel) {
    if (validatePESEL(pesel)) {
        pesel_ = pesel;
    } else {
        throw std::invalid_argument{"PESEL validation failed!"};
    }
}

void Person::setSex(Sex sex) {
    sex_ = sex;
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

bool Person::validatePESEL(std::string pesel) {
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    size_t S = 0;
    for (size_t i = 0; i < 10; i++) {
        S += (size_t)(pesel[i] - '0') * w[i];
    }
    S = S % 10;
    if (S == 0) {
        return ((size_t)(pesel[10] - '0') == 0);
    } else {
        return ((size_t)(pesel[10] - '0') == (10u - S));
    }
}

Person::Person(std::string name, std::string surname, std::string address, std::string pesel, Sex sex)
    : name_(name), surname_(surname), address_(address), sex_(sex) {
    setPESEL(pesel);
}
