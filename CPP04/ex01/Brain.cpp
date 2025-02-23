#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

void Brain::setAllIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}

void Brain::printNidea(int i) {
	if (i < 0 || i > 99)
		return;
	for (int j = 0; j < i; j++)
		std::cout << j + 1 << " Idea : " << this->ideas[j] << std::endl;
}
