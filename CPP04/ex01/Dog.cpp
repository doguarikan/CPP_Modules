#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!! Woof!!" << std::endl;
}

void Dog::setIdea(const std::string& idea) {
    brain->setAllIdeas(idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}

void Dog::printBrainAddress() {
	std::cout << this->brain << std::endl;
}

void Dog::printNidea(int i) {
	this->brain->printNidea(i);
}