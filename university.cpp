#include "university.hpp"

void University::addPerson(std::shared_ptr<Person> person) {
    base_.push_back(person);
}

void University::displayPerson(std::shared_ptr<Person> person) const {
    std::cout << person->getPESEL() << " " << person->getName() << " " << person->getSurname() << " " << person->getAddress() << " ";
    person->displaySex(person->getSex());
    std::cout << ' ';
    if (auto student = dynamic_cast<Student*>(person.get())) {
        std::cout << "ID: " << student->getIndex();
    }
    if (auto employee = dynamic_cast<Employee*>(person.get())) {
        char str[8];
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

void University::findPESEL(std::string& PESEL) const {
    size_t counter = 0;
    for (auto& el : base_) {
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
    auto comparePESELs = [](std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs) {
        return (lhs->getPESEL() < rhs->getPESEL());
    };
    std::sort(base_.begin(), base_.end(), comparePESELs);
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

void University::removePerson(const std::string& PESEL) {
    for (auto el : base_) {
        if (el->getPESEL() == PESEL) {
            base_.erase(std::remove(base_.begin(), base_.end(), el), base_.end());
            break;
        }
    }
}

void University::removeStudent(const std::string& index) {
    auto findAndRemoveStudent = [index](auto person) {
        auto student = dynamic_cast<Student*>(person.get());
        return student && student->getIndex() == index;
    };
    base_.erase(std::remove_if(base_.begin(), base_.end(), findAndRemoveStudent), base_.end());
}

void University::modifySalary(std::string& pesel, float& salary) {
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
        throw std::invalid_argument{"Cannot modify salary for provided PESEL!"};
    }
}

void University::sortBySalary() {
    auto compareSalary = [](std::shared_ptr<Person> lhs, std::shared_ptr<Person> rhs) {
        auto employeeLHS = dynamic_cast<Employee*>(lhs.get());
        auto employeeRHS = dynamic_cast<Employee*>(rhs.get());
        if (employeeLHS && employeeRHS) {
            return employeeLHS->getSalary() < employeeRHS->getSalary();
        } else if (!employeeLHS && employeeRHS) {
            return false;
        } else {
            return true;
        }
    };
    std::sort(base_.begin(), base_.end(), compareSalary);
}

void University::saveBase() {
    std::ofstream file;
    file.open("StudentBase.txt");
    file << "PESEL\tName\tSurname\tAddress\tsex\tSalary\tIndex\t\n";
    for (auto& el : base_) {
        file << el->getPESEL() << '\t' << el->getName() << '\t' << el->getSurname() << '\t' << el->getAddress() << '\t';
        if (el->getSex() == Sex::male) {
            file << "male\t";
        } else {
            file << "female\t";
        }
        auto employee = dynamic_cast<Employee*>(el.get());
        auto student = dynamic_cast<Student*>(el.get());
        if (employee) {
            float salary = employee->getSalary();
            char str[8];
            sprintf(str, "%.2f", employee->getSalary());
            file << str << "\t\t\n";
        } else if (student) {
            file << "\t" << student->getIndex() << "\t\n";
        } else {
            file << "\t\t\n";
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
    std::string index;
    std::string pesel;
    Sex sex;
    std::ifstream file(fileName);
    if (file.is_open()) {
        getline(file, line);  // extracting column's headers
        while (getline(file, line)) {
            size_t pos = line.find('\t');
            pesel = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find('\t');
            name = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find('\t');
            surname = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find('\t');
            address = line.substr(0, pos);
            line = line.substr(pos + 1);
            pos = line.find('\t');
            tmp = line.substr(0, pos);
            if (tmp == "male") {
                sex = Sex::male;
            } else {
                sex = Sex::female;
            }
            line = line.substr(pos + 1);
            pos = line.find('\t');
            tmp = line.substr(0, pos);
            if (tmp.length() > 0) {
                float salary = std::stof(tmp);
                std::shared_ptr<Employee> employee(new Employee(name, surname, address, pesel, salary, sex));
                addPerson(employee);
            }
            line = line.substr(pos + 1);
            pos = line.find('\t');
            tmp = line.substr(0, pos);
            if (tmp.length() > 0) {
                index = tmp;
                std::shared_ptr<Student> student(new Student(name, surname, address, pesel, index, sex));
                addPerson(student);
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << fileName << "!\n";
    }
}

void University::removeBase() {
    base_.erase(base_.begin(), base_.end());
}
