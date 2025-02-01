#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie *zzz = new Zombie(name);
    return zzz;
}