#include "C.hpp"
#include <iostream>

C::C() {
    std::cout << "C constructor called" << std::endl;
}

C::C(const C& other) {
    (void)other;
    std::cout << "C copy constructor called" << std::endl;
}

C& C::operator=(const C& other) {
    (void)other;
    std::cout << "C assignment operator called" << std::endl;
    return *this;
}

C::~C() {
    std::cout << "C destructor called" << std::endl;
}
