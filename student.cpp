#include "student.hpp"

indexNo Student::getIndex() const {
    return Student::index_;
}

void Student::setIndex(indexNo index) {
    Student::index_ = index;
}

void Student::displayIndex(const indexNo& index) const {
    for (auto& el : index) {
        std::cout << el;
    }
}

Student::Student(std::string name,
                 std::string surname,
                 std::string address,
                 pesel pesel,
                 indexNo index,
                 sex sex)
    : Person(name, surname, address, pesel, sex), index_(index) {
}
