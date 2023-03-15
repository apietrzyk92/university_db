#include "database.hpp"

void database::addStudent(student person) {
    base.push_back(person);
}
void database::displayStudent(student person) const {
    person.displayIndex(person.getIndex());
    std::cout << " " << person.getName() << " " << person.getSurname() << " ";
    person.displayPESEL(person.getPESEL());
    std::cout << " " << person.getAddress() << " ";
    person.displaySex(person.getSex());
    std::cout << '\n';
}
void database::displayBase() const {
    for (auto& el : base) {
        displayStudent(el);
    }
}