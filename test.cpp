#include "generator.hpp"
#include "gtest/gtest.h"
#include "university.hpp"

Person createAdam() {
    std::string name = "Adam";
    std::string surname = "Adamski";
    std::string address = "ul. Testowa 12/34 56-789 Testowo";
    std::string pesel = "79040405973";
    Sex sex = Sex::male;
    auto person = Person(name, surname, address, pesel, sex);
    return person;
}

Student createStudent() {
    std::string name = "Katarzyna";
    std::string surname = "Kowalska";
    std::string address = "ul. Przykładowa 10a 01-234 Default City";
    std::string pesel = "85090944715";
    std::string index = "000001";
    Sex sex = Sex::female;
    auto student = Student(name, surname, address, pesel, index, sex);
    return student;
}
Employee createEmployee() {
    std::string pesel = "65080831874";
    std::string name = "Mikołaj";
    std::string surname = "Wiśniewski";
    std::string address = "ul. Łąkowa 24 20-425 Bydgoszcz";
    Sex sex = Sex::male;
    float salary = 10000.01f;
    auto employee = Employee(name, surname, address, pesel, salary, sex);
    return employee;
}

TEST(PersonTests, GettersShouldWork) {
    std::string name = "Adam";
    std::string surname = "Adamski";
    std::string address = "ul. Testowa 12/34 56-789 Testowo";
    std::string pesel = "79040405973";
    Sex sex = Sex::male;
    auto person = createAdam();
    EXPECT_EQ(person.getName(), name);
    EXPECT_EQ(person.getSurname(), surname);
    EXPECT_EQ(person.getAddress(), address);
    EXPECT_EQ(person.getPESEL(), pesel);
    EXPECT_EQ(person.getSex(), sex);
}

TEST(PersonTests, SettersShouldWork) {
    auto person = createAdam();
    std::string name = "Katarzyna";
    std::string surname = "Kowalska";
    std::string address = "ul. Przykładowa 10a 01-234 Default City";
    std::string pesel = "85090944715";
    Sex sex = Sex::female;
    person.setName(name);
    person.setSurname(surname);
    person.setAddress(address);
    person.setPESEL(pesel);
    person.setSex(sex);
    EXPECT_EQ(person.getName(), name);
    EXPECT_EQ(person.getSurname(), surname);
    EXPECT_EQ(person.getAddress(), address);
    EXPECT_EQ(person.getPESEL(), pesel);
    EXPECT_EQ(person.getSex(), sex);
}

TEST(PersonTests, validatePeselShouldWork) {
    auto person = createAdam();
    EXPECT_TRUE(person.validatePESEL(person.getPESEL()));
    std::string pesel = person.getPESEL();
    pesel.at(10) = '7';
    EXPECT_FALSE(person.validatePESEL(pesel));
    EXPECT_ANY_THROW(person.setPESEL(pesel));
}

TEST(StudentTests, getIndexShouldWork) {
    auto student = createStudent();
    EXPECT_EQ(student.getIndex(), "000001");
}

TEST(StudentTests, setIndexShouldWorks) {
    auto student = createStudent();
    student.setIndex("010101");
    EXPECT_EQ(student.getIndex(), "010101");
}

TEST(EmployeeTests, getSalaryShouldWork) {
    auto employee = createEmployee();
    EXPECT_EQ(employee.getSalary(), 10000.01f);
}

TEST(EmployeeTests, setSalaryShouldWork) {
    auto employee = createEmployee();
    employee.setSalary(15000.32f);
    EXPECT_EQ(employee.getSalary(), 15000.32f);
}

TEST(GeneratorTests, generateEmployeeShouldWork) {
    auto pUni = std::make_shared<University>();
    Generator gen(pUni);
    EXPECT_NO_THROW({ auto employee = gen.generateEmployee(); });
    auto employee = gen.generateEmployee();
    EXPECT_NE(employee, nullptr);
    EXPECT_NO_THROW({ employee->setName("Test"); });
    EXPECT_NO_THROW({ employee->setSurname("Testowy"); });
    EXPECT_NO_THROW({ employee->setSalary(9999.90f); });
    EXPECT_EQ(employee->getName(), "Test");
    EXPECT_EQ(employee->getSurname(), "Testowy");
    EXPECT_FLOAT_EQ(employee->getSalary(), 9999.90f);
}

TEST(GeneratorTests, generateStudentShouldWork) {
    auto pUni = std::make_shared<University>();
    Generator gen(pUni);
    EXPECT_NO_THROW({ auto student = gen.generateStudent(); });
    auto student = gen.generateStudent();
    EXPECT_NE(student, nullptr);
    EXPECT_NO_THROW({ student->setName("Test"); });
    EXPECT_NO_THROW({ student->setSurname("Testowy"); });
    EXPECT_NO_THROW({ student->setIndex("000001"); });
    EXPECT_EQ(student->getName(), "Test");
    EXPECT_EQ(student->getSurname(), "Testowy");
    EXPECT_EQ(student->getIndex(), "000001");
}

TEST(UniversityTests, addPersonShouldWork) {
    auto pUni = std::make_shared<University>();
    auto student = createStudent();
    auto employee = createEmployee();
    auto person = createAdam();
    EXPECT_NO_THROW({ pUni->addPerson(std::make_shared<Student>(student)); });
    EXPECT_NO_THROW({ pUni->addPerson(std::make_shared<Employee>(employee)); });
    EXPECT_NO_THROW({ pUni->addPerson(std::make_shared<Person>(person)); });
}