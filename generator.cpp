#include "generator.hpp"

size_t Generator::generateNumber(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(a, b);
    return (size_t)distrib(gen);
}

std::string Generator::generatePESEL() {
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

std::string Generator::generateIndex() {
    std::string output;
    for (size_t i = 0; i < 6; i++) {
        output += std::to_string(generateNumber(0, 9));
    }
    return output;
}

Sex Generator::generateSex() {
    size_t sex = generateNumber(0, 1);
    if (sex == 0) {
        return Sex::male;
    } else {
        return Sex::female;
    }
}

std::string Generator::generateName(Sex sex) {
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

std::string Generator::generateSurname(Sex sex) {
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

std::string Generator::generateAddress() {
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

std::shared_ptr<Student> Generator::generateStudent() {
    Sex sex = generateSex();
    std::shared_ptr<Student> student(new Student(generateName(sex),
                                                 generateSurname(sex),
                                                 generateAddress(),
                                                 generatePESEL(),
                                                 generateIndex(), sex));
    return student;
}

std::shared_ptr<Employee> Generator::generateEmployee() {
    Sex sex = generateSex();
    std::shared_ptr<Employee> employee(new Employee(generateName(sex),
                                                    generateSurname(sex),
                                                    generateAddress(),
                                                    generatePESEL(),
                                                    generateSalary(),
                                                    sex));
    return employee;
}

float Generator::generateSalary() {
    return (float)(generateNumber(349000, 1559999)) / 100;
}

void Generator::generatePeople(size_t n) {
    std::shared_ptr<Person> person;
    for (size_t i = 0; i < n; i++) {
        if (generateNumber(0, 1) > 0) {
            person = generateStudent();
        } else {
            person = generateEmployee();
        }
        pUni_->addPerson(person);
    }
}

Generator::Generator(std::shared_ptr<University>& pUni)
    : pUni_(pUni) {}