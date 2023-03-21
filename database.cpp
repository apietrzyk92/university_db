#include "database.hpp"

void database::addStudent(student& person) {
    if (validatePESEL(person.getPESEL())) {
        base_.push_front(person);
    } else {
        std::cout << "PESEL validation failed!\n";
    }
}
void database::displayStudent(const student& person) const {
    person.displayIndex(person.getIndex());
    std::cout << " " << person.getName() << " " << person.getSurname() << " ";
    person.displayPESEL(person.getPESEL());
    std::cout << " " << person.getAddress() << " ";
    person.displaySex(person.getSex());
    std::cout << '\n';
}
void database::displayBase() const {
    for (auto& el : base_) {
        displayStudent(el);
    }
}
void database::findPESEL(std::array<size_t, 11>& PESEL) const {
    size_t counter = 0;
    for (auto& el : base_) {
        if (el.getPESEL() == PESEL) {
            displayStudent(el);
            counter++;
            break;
        }
    }
    if (counter == 0) {
        std::cout << "PESEL not found!\n";
    }
}
void database::findSurname(std::string& surname) const {
    size_t counter = 0;
    for (auto& el : base_) {
        if (el.getSurname() == surname) {
            displayStudent(el);
            counter++;
        }
    }
    if (counter == 0) {
        std::cout << surname << " not found!\n";
    }
}
void database::sortByPESEL() {
    auto comparePESELS = [](student& lhs, student& rhs) {
        return (lhs.getPESEL() < rhs.getPESEL());
    };
    base_.sort(comparePESELS);
}
void database::sortBySurname() {
    auto compareSurnames = [](student& lhs, student& rhs) {
        return (lhs.getSurname() < rhs.getSurname());
    };
    base_.sort(compareSurnames);
}
void database::removeStudent(std::array<size_t, 11>& PESEL) {
    auto it = base_.before_begin();
    for (auto& el : base_) {
        if (el.getPESEL() == PESEL) {
            base_.erase_after(it);
            break;
        }
        it = std::next(it);
    }
}
bool database::validatePESEL(std::array<size_t, 11> PESEL) {
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    size_t S = 0;
    for (size_t i = 0; i < 10; i++) {
        S += PESEL[i] * w[i];
    }
    S = S % 10;
    if (S == 0) {
        return (PESEL[10] == 0);
    } else {
        return (PESEL[10] == (10 - S));
    }
}

void database::saveBase() {
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
void database::readBase(std::string fileName) {
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
            student record(name, surname, address, pesel, index, sex);
            base_.insert_after(it, record);
            ++it;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << fileName << "!\n";
    }
}
void database::removeBase() {
    base_.clear();
}