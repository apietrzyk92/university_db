#include "addons.hpp"
#include <random>

size_t generateNumber(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(a, b);
    return (size_t)distrib(gen);
}

std::array<size_t, 11> generatePESEL() {
    std::array<size_t, 11> output;
    // year:
    size_t year = generateNumber(0, 99);
    if (year < 51) {
        year /= 10;
    }
    output.at(0) = year / 10;
    output.at(1) = year % 10;
    // month:
    size_t month = generateNumber(1, 12);
    output.at(2) = month / 10;
    output.at(3) = month % 10;
    // day:
    size_t day = 0;
    if (month == 2) {
        day = generateNumber(1, 28);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        day = generateNumber(1, 30);
    } else {
        day = generateNumber(1, 31);
    }
    output.at(4) = day / 10;
    output.at(5) = day % 10;
    if (output.at(0) == 0) {
        output.at(2) += 2;
    }
    for (size_t i = 6; i < 10; i++) {
        output.at(i) = generateNumber(0, 9);
    }
    size_t S = 0;
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    for (size_t i = 0; i < 10; i++) {
        S += output[i] * w[i];
    }
    S = S % 10;
    if (S == 0) {
        output[10] = 0;
    } else {
        output[10] = 10 - S;
    }
    return output;
}
std::array<size_t, 6> generateIndex() {
    std::array<size_t, 6> output;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    for (size_t i = 0; i < 6; i++) {
        output[i] = (size_t)distrib(gen);
    }
    return output;
}
sex generateSex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    int sex = (int)distrib(gen);
    if (sex == 0) {
        return sex::male;
    } else {
        return sex::female;
    }
}
std::string generateName(sex sex) {
    std::array<std::string, 10> maleNames = {"Antoni", "Jan", "Aleksander",
                                             "Franciszek", "Nikodem", "Jakub",
                                             "Leon", "Stanisław", "Mikołaj",
                                             "Szymon"};
    std::array<std::string, 10> femaleNames = {"Zofia", "Zuzanna", "Hanna",
                                               "Maja", "Laura", "Julia",
                                               "Oliwia", "Alicja", "Lena",
                                               "Pola"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int idx = (int)distrib(gen);
    if (sex == sex::male) {
        return maleNames[idx];
    } else {
        return femaleNames[idx];
    }
}
std::string generateSurname(sex sex) {
    std::array<std::string, 10> maleSurnames = {"Nowak", "Kowalski",
                                                "Wiśniewski", "Wójcik",
                                                "Kowalczyk", "Kamiński",
                                                "Lewandowski", "Zieliński",
                                                "Szymański", "Wójcik"};
    std::array<std::string, 10> femaleSurnames = {"Nowak", "Kowalska",
                                                  "Wiśniewska", "Wójcik",
                                                  "Kowalczyk", "Kamińska",
                                                  "Lewandowska", "Zielińska",
                                                  "Szymańska", "Wójcik"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int idx = (int)distrib(gen);
    if (sex == sex::male) {
        return maleSurnames[idx];
    } else {
        return femaleSurnames[idx];
    }
}
std::string generateAddress() {
    std::array<std::string, 10> streetNames = {"Polna", "Leśna", "Słoneczna",
                                               "Krótka", "Szkolna", "Ogrodowa",
                                               "Lipowa", "Brzozowa", "Łąkowa",
                                               "Kwiatowa"};
    std::array<std::string, 10> buildingNo = {"24", "17/4", "67/8", "5a",
                                              "96/54", "4/176", "96b", "2/134",
                                              "12", "5/3"};
    std::array<std::string, 10> postCodes = {"00-581", "30-1650", "52-120",
                                             "91-065", "61-833", "80-734",
                                             "71-015", "85-163", "20-425",
                                             "15-424"};
    std::array<std::string, 10> cityNames = {"Warszawa", "Kraków", "Wrocław",
                                             "Łódź", "Poznań", "Gdańsk",
                                             "Szczecin", "Bydgoszcz", "Lublin",
                                             "Białystok"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    return "ul. " + streetNames[distrib(gen)] + " " + buildingNo[distrib(gen)] +
           " " + postCodes[distrib(gen)] + " " + cityNames[distrib(gen)];
}
Student generateStudent() {
    sex sex = generateSex();
    std::string name = generateName(sex);
    std::string surname = generateSurname(sex);
    std::string address = generateAddress();
    std::array<size_t, 11> pesel = generatePESEL();
    std::array<size_t, 6> index = generateIndex();
    Student generated(name, surname, address, pesel, index, sex);
    return generated;
}