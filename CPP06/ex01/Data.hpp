#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    std::string name;
    int age;
    double salary;
    
    Data();
    Data(const std::string& n, int a, double s);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
    
    void display() const;
};

#endif
