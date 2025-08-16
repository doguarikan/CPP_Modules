#include "A.hpp"
#include <iostream>

A::A() {
    std::cout << "A constructor called" << std::endl;
}

A::A(const A& other) {
    (void)other;
    std::cout << "A copy constructor called" << std::endl;
}

A& A::operator=(const A& other) {
    (void)other;
    std::cout << "A assignment operator called" << std::endl;
    return *this;
}

A::~A() {
    std::cout << "A destructor called" << std::endl;
}
