#include "addons.hpp"
#include "university.hpp"

int main() {
    University base;
    sex sex = sex::male;
    std::shared_ptr<Student> test = generateStudent();
    std::shared_ptr<Employee> test2 = generateEmployee();
    base.addPerson(test);
    base.addPerson(test2);
    base.displayBase();
    pesel pesel = test->getPESEL();
    std::string surname = test->getSurname();
    std::cout << "Find PESEL:\n";
    base.findPESEL(pesel);
    std::cout << "Find surname:\n";
    base.findSurname(surname);
    std::cout << "Sort by PESEL:\n";
    base.sortByPESEL();
    base.displayBase();
    std::cout << "Sort by surname:\n";
    base.sortBySurname();
    base.displayBase();
    std::cout << "Remove first created student:\n";
    base.removePerson(pesel);
    base.displayBase();
    std::cout << "Add once again student:\n";
    base.addPerson(test);
    base.displayBase();
    std::cout << "Remove student using index number:\n";
    indexNo index = test->getIndex();
    base.removeStudent(index);
    base.displayBase();
    pesel = test2->getPESEL();
    std::cout << "Modify salary for " << test2->getSurname() << " " << test2->getName() << "\n";
    float salary = 10000.93f;
    base.modifySalary(pesel, salary);
    base.displayBase();
    pesel.at(2) = generateNumber(4, 9);
    base.modifySalary(pesel, salary);
    base.displayBase();
    std::cout << "Adding some employees for testing sort by salary:\n";
    std::shared_ptr<Employee> test3(new Employee(generateName(sex), generateSurname(sex), generateAddress(), generatePESEL(), 5432.11, sex));
    sex = sex::female;
    std::shared_ptr<Employee> test4(new Employee(generateName(sex), generateSurname(sex), generateAddress(), generatePESEL(), 9876.21, sex));
    std::shared_ptr<Employee> test5(new Employee(generateName(sex), generateSurname(sex), generateAddress(), generatePESEL(), 2137.11, sex));
    base.addPerson(test);
    base.addPerson(test3);
    base.addPerson(test4);
    base.addPerson(test5);
    base.displayBase();
    std::cout << "Sorted by salary:\n";
    base.sortBySalary();
    base.displayBase();
    /*
    for (size_t i = 0; i < 10; i++) {
        Student tmp = generateStudent();
        base.addStudent(tmp);
    }
    base.displayBase();
    sex sex = generateSex();
    std::string name = generateName(sex);
    std::string surname = generateSurname(sex);
    std::string address = generateAddress();
    std::array<size_t, 11> pesel = {9, 7, 3, 4, 1, 3, 9, 1, 7, 6, 3};
    std::array<size_t, 6> index = generateIndex();
    std::cout << "\nGenerate student with incorrect pesel and add to base:\n";
    Student tester(name, surname, address, pesel, index, sex);
    base.addStudent(tester);
    base.displayBase();
    pesel = {6, 9, 9, 2, 9, 6, 3, 8, 2, 9, 7};
    Student tester2(name, surname, address, pesel, index, sex);
    base.addStudent(tester2);
    std::cout << "\nTry to find existing and non-existing student via PESEL:\n";
    base.findPESEL(pesel);
    std::array<size_t, 11> pesel2 = generatePESEL();
    base.findPESEL(pesel2);
    std::cout << "\nTry to find surnames: Kowalski and Dupa\n";
    surname = "Kowalski";
    base.findSurname(surname);
    surname = "Dupa";
    base.findSurname(surname);
    std::cout << "\nSort by PESEL:\n";
    base.sortByPESEL();
    base.displayBase();
    std::cout << "\nSort by Surname:\n";
    base.sortBySurname();
    base.displayBase();
    std::cout << "\nRemove student via PESEL:\n";
    base.removeStudent(pesel);
    base.displayBase();
    std::cout << "\nSave database to file and read from file:\n";
    base.saveBase();
    base.readBase("StudentBase.txt");
    std::cout << "\nLoaded University is: \n";
    base.displayBase();
    */
    return 0;
}