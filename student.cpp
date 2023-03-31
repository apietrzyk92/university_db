#include "student.hpp"

indexNo Student::getIndex() const {
    return index_;
}

void Student::setIndex(indexNo index) {
    index_ = index;
}

void Student::displayIndex(const indexNo& index) const {
    for (auto& el : index) {
        std::cout << el;
    }
}

Student::Student(std::string name,
                 std::string surname,
                 std::string address,
                 std::string pesel,
                 indexNo index,
                 Sex sex)
    : Person(name, surname, address, pesel, sex), index_(index) {
}
