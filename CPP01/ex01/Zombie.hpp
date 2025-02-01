#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    std::string name;
    
    public:
        Zombie(std::string name); // destructor lazım mı!!!!!!!!!!!!!!!
        void announce();
        void setName(std::string name);
        Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif