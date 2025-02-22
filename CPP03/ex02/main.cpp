#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "<--- Creating a ClapTrap --->" << std::endl;
    ClapTrap spiderman("Spiderman");
    spiderman.attack("Doctor Octopus");
    spiderman.takeDamage(3);
    spiderman.beRepaired(5);

    std::cout << "<--- Creating a ScavTrap --->" << std::endl;
    ScavTrap yoda("Yoda");
    yoda.attack("Vader");
    yoda.takeDamage(40);
    yoda.beRepaired(20);
    yoda.guardGate();

    std::cout << "<--- Creating a FragTrap --->" << std::endl;
    FragTrap ash("Ash");
    ash.attack("Jessie and James");
    ash.takeDamage(50);
    ash.beRepaired(30);
    ash.highFivesGuys();


    std::cout << "<--- Creating more tests --->" << std::endl;

    ClapTrap *clap1 = new ScavTrap("Scav-Clap");
    ClapTrap *clap2 = new FragTrap("Frag-Clap");


    clap1->attack("Enemy A");
    clap2->attack("Enemy B");

    clap1->takeDamage(10);
    clap2->takeDamage(15);

    clap1->beRepaired(5);
    clap2->beRepaired(8);

    std::cout << "<--- Destruction begins --->" << std::endl;

    delete clap1;
    delete clap2;
    return 0;
}
