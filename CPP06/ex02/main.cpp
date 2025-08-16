#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    int random = rand() % 3;
    
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return new A();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}

int main() {
    std::srand(std::time(0));
    
    std::cout << "Testing pointer identification:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        std::cout << "Generated object " << i + 1 << " type: ";
        identify(ptr);
        delete ptr;
    }
    
    std::cout << "\nTesting reference identification:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        std::cout << "Generated object " << i + 1 << " type: ";
        identify(*ptr);
        delete ptr;
    }
    
    return 0;
}
