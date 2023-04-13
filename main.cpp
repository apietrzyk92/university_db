#include "generator.hpp"
#include "university.hpp"

int main() {
    auto pUni = std::make_shared<University>();
    Generator gen(pUni);
    gen.generatePeople(10);
    std::shared_ptr<Student> test = gen.generateStudent();
    std::shared_ptr<Employee> test2 = gen.generateEmployee();
    pUni->addPerson(test);
    pUni->addPerson(test2);
    pUni->displayBase();
    std::string pesel = test->getPESEL();
    std::string surname = test->getSurname();
    std::cout << "Find PESEL " << pesel << " :\n";
    pUni->findPESEL(pesel);
    std::cout << "Find surname " << surname << " :\n";
    pUni->findSurname(surname);
    std::cout << "Sort by PESEL:\n";
    pUni->sortByPESEL();
    pUni->displayBase();
    std::cout << "Sort by surname:\n";
    pUni->sortBySurname();
    pUni->displayBase();
    std::cout << "Remove " << test->getSurname() << ":\n";
    pUni->removePerson(pesel);
    pUni->displayBase();
    std::cout << "Add once again " << test->getSurname() << ":\n";
    pUni->addPerson(test);
    pUni->displayBase();
    std::cout << "Remove " << test->getSurname() << " using index number:\n";
    std::string index = test->getIndex();
    pUni->removeStudent(index);
    pUni->displayBase();
    pesel = test2->getPESEL();
    std::cout << "Modify salary for " << test2->getSurname() << " " << test2->getName() << "\n";
    float salary = 10000.93f;
    pUni->modifySalary(pesel, salary);
    pUni->displayBase();
    pesel.at(2) = 7u;
    try {
        pUni->modifySalary(pesel, salary);
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }
    pUni->displayBase();
    std::cout << "Sorted by salary:\n";
    pUni->sortBySalary();
    pUni->displayBase();
    try {
        std::shared_ptr<Person> person(new Person("Wrong", "Pesel", "Person 1 00-001 Test", "12345678900", Sex::male));
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }
    std::shared_ptr<Employee> emp1 = gen.generateEmployee();
    std::string pesel2 = "12345678900";
    try {
        emp1->setPESEL(pesel2);
    } catch (std::invalid_argument const& inv_arg) {
        std::cout << inv_arg.what() << '\n';
    }
    pUni->saveBase();
    pUni->readBase("StudentBase.txt");
    pUni->displayBase();
    return 0;
}