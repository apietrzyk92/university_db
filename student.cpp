#include "student.hpp"

std::string Student::getIndex() const {
    return index_;
}

void Student::setIndex(std::string index) {
    index_ = index;
}

/*void Student::displayIndex(const std::String& index) const {
    for (auto& el : index) {
        std::cout << el;
    }
} */

Student::Student(std::string name,
                 std::string surname,
                 std::string address,
                 std::string pesel,
                 std::string index,
                 Sex sex)
    : Person(name, surname, address, pesel, sex), index_(index) {
}
