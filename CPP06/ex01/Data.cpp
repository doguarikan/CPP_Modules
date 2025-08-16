#include "Data.hpp"

Data::Data() : name(""), age(0), salary(0.0) {}

Data::Data(const std::string& n, int a, double s) : name(n), age(a), salary(s) {}

Data::Data(const Data& other) : name(other.name), age(other.age), salary(other.salary) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        salary = other.salary;
    }
    return *this;
}

Data::~Data() {}

void Data::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}
