#include "B.hpp"
#include <iostream>

B::B() {
    std::cout << "B constructor called" << std::endl;
}

B::B(const B& other) {
    (void)other;
    std::cout << "B copy constructor called" << std::endl;
}

B& B::operator=(const B& other) {
    (void)other;
    std::cout << "B assignment operator called" << std::endl;
    return *this;
}

B::~B() {
    std::cout << "B destructor called" << std::endl;
}
