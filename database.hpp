#include <list>
#include "student.hpp"

class database {
private:
    std::list<student> base_;
    void displayStudent(student person) const;

public:
    void addStudent(student person);
    void displayBase() const;
    void findPESEL(std::array<size_t, 11> PESEL) const;
    void findSurname(std::string surname) const;
};
