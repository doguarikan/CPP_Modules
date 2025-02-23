#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog *i = new Dog();
	i->setIdea("Stick");

	Dog meta = *i;
	Dog *a = i;

	i->setIdea("Bone");
	std::cout << "\n<--DeepCopy-->" << std::endl;

	i->printBrainAddress();
	meta.printBrainAddress();
	i->printNidea(1);
	meta.printNidea(1);

	std::cout << "\n<--ShallowCopy-->" << std::endl;

	a->printBrainAddress();
	i->printBrainAddress();
	a->printNidea(1);
	i->printNidea(1);
	

	std::cout << "\n<---------->\n" << std::endl;

	delete i;

	std::cout << "\n<---------->\n" << std::endl;

	const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

	return 0;
}