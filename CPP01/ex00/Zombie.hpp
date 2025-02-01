#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    std::string name;
    
    public:
        Zombie(std::string name); // destructor lazım mı!!!!!!!!!!!!!!!
        void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif