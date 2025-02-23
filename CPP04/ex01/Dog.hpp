#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    Brain* brain;
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        Dog& operator=(const Dog& other);

        void makeSound() const;
        void setIdea(const std::string& idea);
        std::string getIdea(int index) const;
        void printBrainAddress();
        void printNidea(int i);
};

#endif
