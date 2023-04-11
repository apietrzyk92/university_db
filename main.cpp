#include "university.hpp"

int main() {
    University base;
    base.generatePeople(10);
    std::shared_ptr<Student> test = base.generateStudent();
    std::shared_ptr<Employee> test2 = base.generateEmployee();
    base.addPerson(test);
    base.addPerson(test2);
    base.displayBase();
    std::string pesel = test->getPESEL();
    std::string surname = test->getSurname();
    std::cout << "Find PESEL " << pesel << " :\n";
    base.findPESEL(pesel);
    std::cout << "Find surname " << surname << " :\n";
    base.findSurname(surname);
    std::cout << "Sort by PESEL:\n";
    base.sortByPESEL();
    base.displayBase();
    std::cout << "Sort by surname:\n";
    base.sortBySurname();
    base.displayBase();
    std::cout << "Remove " << test->getSurname() << ":\n";
    base.removePerson(pesel);
    base.displayBase();
    std::cout << "Add once again " << test->getSurname() << ":\n";
    base.addPerson(test);
    base.displayBase();
    std::cout << "Remove " << test->getSurname() << " using index number:\n";
    std::string index = test->getIndex();
    base.removeStudent(index);
    base.displayBase();
    pesel = test2->getPESEL();
    std::cout << "Modify salary for " << test2->getSurname() << " " << test2->getName() << "\n";
    float salary = 10000.93f;
    base.modifySalary(pesel, salary);
    base.displayBase();
    pesel.at(2) = 7u;
    try {
        base.modifySalary(pesel, salary);
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }
    base.displayBase();
    std::cout << "Sorted by salary:\n";
    base.sortBySalary();
    base.displayBase();
    try {
        std::shared_ptr<Person> person(new Person("Wrong", "Pesel", "Person 1 00-001 Test", "12345678900", Sex::male));
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }
    std::shared_ptr<Employee> emp1 = base.generateEmployee();
    std::string pesel2 = "12345678900";
    try {
        emp1->setPESEL(pesel2);
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }

    return 0;
}