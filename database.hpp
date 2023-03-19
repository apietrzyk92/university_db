#include <forward_list>
#include "student.hpp"

class database {
private:
    std::forward_list<student> base_;
    void displayStudent(student person) const;
    bool validatePESEL(std::array<size_t, 11> PESEL);

public:
    void addStudent(student person);
    void displayBase() const;
    void findPESEL(std::array<size_t, 11> PESEL) const;
    void findSurname(std::string surname) const;
    void sortByPESEL();
    void sortBySurname();
    void removeStudent(std::array<size_t, 11> PESEL);
};
