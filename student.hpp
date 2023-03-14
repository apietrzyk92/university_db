#pragma once
#include <array>
#include <string>

enum class sex {
    male,
    female
};

class student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::array<size_t, 11> PESEL_;
    sex sex_;
    std::array<size_t, 6> index_;

public:
    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::array<size_t, 11> getPESEL() const;
    std::array<size_t, 6> getIndex() const;
    sex getSex() const;

    void setName(std::string name);
    void setSurname(std::string surname);
    void setAddress(std::string address);
    void setPESEL(std::array<size_t, 11> PESEL);
    void setIndex(std::array<size_t, 6> index);
    void setSex(sex sex);
};