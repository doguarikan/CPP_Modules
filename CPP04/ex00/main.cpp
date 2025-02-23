#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n<--Deleting-->\n" << std::endl;
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n<--WrongAnimal-->\n" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();
    
    std::cout << "\n<--Deleting-->\n" << std::endl;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
}