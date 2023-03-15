#include <list>
#include "student.hpp"

class database {
private:
    std::list<student> base;
    void displayStudent(student person) const;

public:
    void addStudent(student person);
    void displayBase() const;
};
