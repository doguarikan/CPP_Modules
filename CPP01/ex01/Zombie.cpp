#include "Zombie.hpp"

void Zombie::setName(std::string name) {
    this->name = name;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
}