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
            return false;
        } else {
            return true;
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
size_t University::generateNumber(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(a, b);
    return (size_t)distrib(gen);
}

std::string University::generatePESEL() {
    std::string output;
    size_t year = generateNumber(0, 99);
    if (year < 51) {
        year /= 10;
    }
    output = std::to_string(year / 10);
    output += std::to_string(year % 10);
    size_t month = generateNumber(1, 12);
    output += std::to_string(month / 10);
    output += std::to_string(month % 10);
    size_t day = 0;
    if (month == 2) {
        day = generateNumber(1, 28);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        day = generateNumber(1, 30);
    } else {
        day = generateNumber(1, 31);
    }
    output += std::to_string(month / 10);
    output += std::to_string(month % 10);
    if (output.at(0) == '0') {
        output.at(2) += (char)2;
    }
    for (size_t i = 6; i < 10; i++) {
        output += std::to_string(generateNumber(0, 9));
    }
    size_t S = 0;
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    for (size_t i = 0; i < 10; i++) {
        S += (size_t)(output[i] - '0') * w[i];
    }
    S = S % 10;
    if (S == 0) {
        output += "0";
    } else {
        output += std::to_string(10 - S);
    }
    return output;
}

std::string University::generateIndex() {
    std::string output;
    for (size_t i = 0; i < 6; i++) {
        output += std::to_string(generateNumber(0, 9));
    }
    return output;
}

Sex University::generateSex() {
    size_t sex = generateNumber(0, 1);
    if (sex == 0) {
        return Sex::male;
    } else {
        return Sex::female;
    }
}

std::string University::generateName(Sex sex) {
    std::array<std::string, 10> maleNames = {"Antoni", "Jan", "Aleksander", "Franciszek", "Nikodem", "Jakub", "Leon",
                                             "Stanisław", "Mikołaj", "Szymon"};
    std::array<std::string, 10> femaleNames = {"Zofia", "Zuzanna", "Hanna", "Maja", "Laura", "Julia", "Oliwia",
                                               "Alicja", "Lena", "Pola"};
    size_t idx = generateNumber(0, 9);
    if (sex == Sex::male) {
        return maleNames[idx];
    } else {
        return femaleNames[idx];
    }
}

std::string University::generateSurname(Sex sex) {
    std::array<std::string, 10> maleSurnames = {"Nowak", "Kowalski", "Wiśniewski", "Wójcik", "Kowalczyk", "Kamiński",
                                                "Lewandowski", "Zieliński", "Szymański", "Wójcik"};
    std::array<std::string, 10> femaleSurnames = {"Nowak", "Kowalska", "Wiśniewska", "Wójcik", "Kowalczyk", "Kamińska",
                                                  "Lewandowska", "Zielińska", "Szymańska", "Wójcik"};
    size_t idx = generateNumber(0, 9);
    if (sex == Sex::male) {
        return maleSurnames[idx];
    } else {
        return femaleSurnames[idx];
    }
}

std::string University::generateAddress() {
    std::array<std::string, 10> streetNames = {"Polna", "Leśna", "Słoneczna", "Krótka", "Szkolna", "Ogrodowa",
                                               "Lipowa", "Brzozowa", "Łąkowa", "Kwiatowa"};
    std::array<std::string, 10> buildingNo = {"24", "17/4", "67/8", "5a", "96/54", "4/176", "96b", "2/134", "12", "5/3"};
    std::array<std::string, 10> postCodes = {"00-581", "30-1650", "52-120", "91-065", "61-833", "80-734", "71-015",
                                             "85-163", "20-425", "15-424"};
    std::array<std::string, 10> cityNames = {"Warszawa", "Kraków", "Wrocław", "Łódź", "Poznań", "Gdańsk", "Szczecin",
                                             "Bydgoszcz", "Lublin", "Białystok"};
    return "ul. " + streetNames[generateNumber(0, 9)] + " " + buildingNo[generateNumber(0, 9)] + " " +
           postCodes[generateNumber(0, 9)] + " " + cityNames[generateNumber(0, 9)];
}

std::shared_ptr<Student> University::generateStudent() {
    Sex sex = generateSex();
    std::shared_ptr<Student> student(new Student(generateName(sex),
                                                 generateSurname(sex),
                                                 generateAddress(),
                                                 generatePESEL(),
                                                 generateIndex(), sex));
    return student;
}

std::shared_ptr<Employee> University::generateEmployee() {
    Sex sex = generateSex();
    std::shared_ptr<Employee> employee(new Employee(generateName(sex),
                                                    generateSurname(sex),
                                                    generateAddress(),
                                                    generatePESEL(),
                                                    generateSalary(),
                                                    sex));
    return employee;
}

float University::generateSalary() {
    return (float)(generateNumber(349000, 1559999)) / 100;
}

void University::generatePeople(size_t n) {
    std::shared_ptr<Person> person;
    for (size_t i = 0; i < n; i++) {
        if (generateNumber(0, 1) > 0) {
            person = generateStudent();
        } else {
            person = generateEmployee();
        }
        addPerson(person);
    }
}