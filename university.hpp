#include <forward_list>
#include <fstream>
#include "student.hpp"

class University {
private:
    std::forward_list<Student> base_;
    void displayStudent(const Student& person) const;
    void removeBase();

public:
    void addStudent(Student& person);
    void displayBase() const;
    void findPESEL(std::array<size_t, 11>& PESEL) const;
    void findSurname(std::string& surname) const;
    void sortByPESEL();
    void sortBySurname();
    void removeStudent(const std::array<size_t, 11>& PESEL);
    void removeStudent(const std::array<size_t, 6>& index);
    void saveBase();
    void readBase(std::string fileName);
};
