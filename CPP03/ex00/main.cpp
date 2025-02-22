#include "ClapTrap.hpp"

int main() {
	std::cout << "<--- Creating a ClapTrap --->" << std::endl;
	ClapTrap knight("Knight");

	knight.attack("Enemy");
	knight.takeDamage(3);
	knight.beRepaired(5);
	knight.takeDamage(4);
	knight.beRepaired(10);
	knight.attack("Zombie");

	std::cout << "<--- Destruction begins --->" << std::endl;
	return 0;
}
