#include "database.hpp"

void database::addStudent(student person) {
    base_.push_front(person);
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
    for (auto& el : base_) {
        displayStudent(el);
    }
}
void database::findPESEL(std::array<size_t, 11> PESEL) const {
    size_t counter = 0;
    for (auto& el : base_) {
        if (el.getPESEL() == PESEL) {
            displayStudent(el);
            counter++;
            break;
        }
    }
    if (counter == 0) {
        std::cout << "PESEL not found!\n";
    }
}
void database::findSurname(std::string surname) const {
    size_t counter = 0;
    for (auto& el : base_) {
        if (el.getSurname() == surname) {
            displayStudent(el);
            counter++;
        }
    }
    if (counter == 0) {
        std::cout << surname << " not found!\n";
    }
}
void database::sortByPESEL() {
    auto comparePESELS = [](student lhs, student rhs) {
        return (lhs.getPESEL() < rhs.getPESEL());
    };
    base_.sort(comparePESELS);
}
void database::sortBySurname() {
    auto compareSurnames = [](student lhs, student rhs) {
        return (lhs.getSurname() < rhs.getSurname());
    };
    base_.sort(compareSurnames);
}
void database::removeStudent(std::array<size_t, 11> PESEL) {
    auto it = base_.before_begin();
    for (auto& el : base_) {
        if (el.getPESEL() == PESEL) {
            base_.erase_after(it);
            break;
        }
        it = std::next(it);
    }
}