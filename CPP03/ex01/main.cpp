#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "<--- Creating a ClapTrap --->" << std::endl;
    
    ClapTrap knight("Knight");
    knight.attack("Archer");
    knight.takeDamage(3);
    knight.beRepaired(5);

    std::cout << "<--- Creating a ScavTrap --->" << std::endl;
    
    ScavTrap samurai("Samurai Jack");
    samurai.attack("Aku");
    samurai.takeDamage(40);
    samurai.beRepaired(20);
    samurai.guardGate();

    std::cout << "<--- Destruction begins --->" << std::endl;
    return 0;
}
