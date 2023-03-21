#include "student.hpp"

std::string student::getName() const {
    return student::name_;
}
std::string student::getSurname() const {
    return student::surname_;
}
std::string student::getAddress() const {
    return student::address_;
}
std::array<size_t, 11> student::getPESEL() const {
    return student::PESEL_;
}
std::array<size_t, 6> student::getIndex() const {
    return student::index_;
}
sex student::getSex() const {
    return student::sex_;
}

void student::setName(std::string name) {
    student::name_ = name;
}
void student::setSurname(std::string surname) {
    student::surname_ = surname;
}
void student::setAddress(std::string address) {
    student::address_ = address;
}
void student::setPESEL(std::array<size_t, 11> PESEL) {
    student::PESEL_ = PESEL;
}
void student::setIndex(std::array<size_t, 6> index) {
    student::index_ = index;
}
void student::setSex(sex sex) {
    student::sex_ = sex;
}
void student::displayPESEL(const std::array<size_t, 11>& PESEL) const {
    for (auto& el : PESEL) {
        std::cout << el;
    }
}
void student::displayIndex(const std::array<size_t, 6>& index) const {
    for (auto& el : index) {
        std::cout << el;
    }
}
void student::displaySex(const sex& sex) const {
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
student::student(std::string name, std::string surname, std::string address, std::array<size_t, 11> PESEL, std::array<size_t, 6> index, sex sex)
    : name_(name), surname_(surname), address_(address), index_(index), PESEL_(PESEL), sex_(sex) {}
