#include "university.hpp"

int main() {
    University base;
    base.generatePeople(2);
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
    base.modifySalary(pesel, salary);
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