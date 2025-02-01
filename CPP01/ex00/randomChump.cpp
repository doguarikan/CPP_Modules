#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie *zzz = newZombie(name);
    zzz->announce();
}