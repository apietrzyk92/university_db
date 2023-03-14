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