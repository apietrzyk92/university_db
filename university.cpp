#include "university.hpp"

void University::addPerson(std::shared_ptr<Person> person) {
    pesel pesel = person->getPESEL();
    if (person->validatePESEL(pesel)) {
        base_.push_back(person);
    } else {
        std::cout << "Unable to add person with incorrect PESEL!\n";
    }
}

void University::displayPerson(std::shared_ptr<Person> person) const {
    person->displayPESEL(person->getPESEL());
    std::cout << " " << person->getName() << " " << person->getSurname() << " " << person->getAddress() << " ";
    person->displaySex(person->getSex());
    std::cout << ' ';
    if (auto student = dynamic_cast<Student*>(person.get())) {
        std::cout << "ID: ";
        student->displayIndex(student->getIndex());
    }
    if (auto employee = dynamic_cast<Employee*>(person.get())) {
        char str[10];
        sprintf(str, "%.2f", employee->getSalary());
        std::cout << str << " PLN";
    }
    std::cout << '\n';
}

void University::displayBase() const {
    for (auto& el : base_) {
        displayPerson(el);
    }
}

void University::findPESEL(pesel& PESEL) const {
    size_t counter = 0;
    for (auto el : base_) {
        if (el->getPESEL() == PESEL) {
            displayPerson(el);
            counter++;
            break;
        }
    }
    if (counter == 0) {
        std::cout << "PESEL not found!\n";
    }
}

void University::findSurname(std::string& surname) const {
    size_t counter = 0;
    for (auto el : base_) {
        if (el->getSurname() == surname) {
            displayPerson(el);
            counter++;
        }
    }
    if (counter == 0) {
        std::cout << surname << " not found!\n";
    }
}

void University::sortByPESEL() {
    auto comparePESELS = [](std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs) {
        return (lhs->getPESEL() < rhs->getPESEL());
    };
    std::sort(base_.begin(), base_.end(), comparePESELS);
}

void University::sortBySurname() {
    auto compareSurnames = [](std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs) {
        if (lhs->getSurname() == rhs->getSurname()) {
            return (lhs->getName() < rhs->getName());
        } else {
            return (lhs->getSurname() < rhs->getSurname());
        }
    };
    std::sort(base_.begin(), base_.end(), compareSurnames);
}

void University::removePerson(const pesel& PESEL) {
    for (auto el : base_) {
        if (el->getPESEL() == PESEL) {
            base_.erase(std::remove(base_.begin(), base_.end(), el), base_.end());
            break;
        }
    }
}

void University::removeStudent(const indexNo& index) {
    auto findAndRemoveStudent = [index](auto person) {
        auto student = dynamic_cast<Student*>(person.get());
        return student && student->getIndex() == index;
    };
    base_.erase(std::remove_if(base_.begin(), base_.end(), findAndRemoveStudent), base_.end());
}

void University::modifySalary(pesel& pesel, float& salary) {
    bool isSet = false;
    for (auto el : base_) {
        auto employee = dynamic_cast<Employee*>(el.get());
        if (employee && employee->getPESEL() == pesel) {
            employee->setSalary(salary);
            isSet = true;
            break;
        }
    }
    if (!isSet) {
        std::cout << "Cannot modify salary!\n";
    }
}

void University::sortBySalary() {
    auto compareSalary = [](std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs) {
        auto employeeLHS = dynamic_cast<Employee*>(lhs.get());
        auto employeeRHS = dynamic_cast<Employee*>(rhs.get());
        if (employeeLHS && employeeRHS) {
            return employeeLHS->getSalary() < employeeRHS->getSalary();
        } else if (!employeeLHS && employeeRHS) {
            return true;
        } else {
            return false;
        }
    };
    std::sort(base_.begin(), base_.end(), compareSalary);
}
/*
void University::saveBase() {
    std::ofstream file;
    file.open("StudentBase.txt");
    file << "Index, Name, Surname, Address, PESEL, sex\n";
    for (auto& el : base_) {
        std::array<size_t, 6> index = el.getIndex();
        for (size_t i = 0; i < 6; i++) {
            file << index[i];
        }
        file << ',' << el.getName() << ',' << el.getSurname() << ','
             << el.getAddress() << ',';
        std::array<size_t, 11> PESEL = el.getPESEL();
        for (size_t i = 0; i < 11; i++) {
            file << PESEL[i];
        }
        file << ',';
        if (el.getSex() == sex::male) {
            file << "male\n";
        } else {
            file << "female\n";
        }
    }
    file.close();
}

void University::readBase(std::string fileName) {
    removeBase();
    std::string line;
    std::string name;
    std::string surname;
    std::string address;
    std::string tmp;
    std::array<size_t, 6> index;
    std::array<size_t, 11> pesel;
    sex sex;
    std::ifstream file(fileName);
    auto it = base_.before_begin();
    if (file.is_open()) {
        getline(file, line);  // extracting column's headers
        while (getline(file, line)) {
            size_t pos = line.find(",");
            tmp = line.substr(0, pos);
            for (size_t i = 0; i < 6; i++) {
                index[i] = (size_t)(tmp[i] - '0');
            }
            line = line.substr(pos + 1);
            pos = line.find(",");
            name = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find(",");
            surname = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find(",");
            address = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find(",");
            tmp = line.substr(0, pos);
            for (size_t i = 0; i < 11; i++) {
                pesel[i] = (size_t)(tmp[i] - '0');
            }
            line = line.substr(pos + 1);
            if (line == "male") {
                sex = sex::male;
            } else {
                sex = sex::female;
            }
            Student record(name, surname, address, pesel, index, sex);
            base_.push_back(record);
            ++it;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << fileName << "!\n";
    }
}
*/
void University::removeBase() {
    base_.erase(base_.begin(), base_.end());
}