#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = 0;
}

void Phonebook::add() {
    std::string name;
    std::string surname;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    int err = 0;
    if(this->index == 8)
        this->index = 0;

    while(1) {
        long unsigned int i = 0; // ????!!!!!! .length compare
        std::cout << "Name: " << std::endl;
        std::cin >> name;
        std::cout << "Surname: " << std::endl;
        std::cin >> surname;
        std::cout << "Nickname: " << std::endl;
        std::cin >> nick_name;
        while(1)
        {   
            std::cout << "Phone number: " << std::endl;
            std::cin >> phone_number;
            while(1) {
                if(!std::isdigit(phone_number[i])) {
                    std::cout << "Please enter number only" << std::endl;
                    break ;
                }
                else
                    i++;
                if(i == phone_number.length()) {
                    err = 1;
                    break ;
                }
            }
            if(err)
                break;
        } // exceptions
        std::cout << "Darkest secret: " << std::endl;
        std::cin >> darkest_secret;
        break ;
    }
    Phonebook::contacts[this->index].setName(name);
    Phonebook::contacts[this->index].setSurname(surname);
    Phonebook::contacts[this->index].setNickName(nick_name);
    Phonebook::contacts[this->index].setPhoneNumber(phone_number);
    Phonebook::contacts[this->index].setDarkestSecret(darkest_secret);
    this->index++;
}

void Phonebook::search() {
    
}

void Phonebook::exit() {
    
}