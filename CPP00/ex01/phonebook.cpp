#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = 0;
    this->index_total = 0;
}

bool isNumeric(const std::string& str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int stringToInt(const std::string& str) {
    int result = 0;
    bool isNegative = false;
    size_t i = 0;

    if (!str.empty() && str[0] == '-') {
        isNegative = true;
        i = 1;
    }

    for (; i < str.size(); ++i) {
        result = result * 10 + (str[i] - '0');
    }

    return isNegative ? -result : result;
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
    this->index_total++;
    this->index++;
}

void Phonebook::search() {
    std::cout << std::right << std::setw(10) << "index" << "|";
    std::cout << std::right << std::setw(10) << "name" << "|";
    std::cout << std::right << std::setw(10) << "surname" << "|";
    std::cout << std::right << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    //int index_search;
    //if(this->index >= 8)
    //    index_search = 8;
    for(int i = 0; i < this->index_total; i++)
    {
        std::cout << std::right << std::setw(10) << i << "|"; 
        if(this->contacts[i].getName().length() > 9)
            std::cout << std::right << std::setw(10) << this->contacts[i].getName().substr(0, 9) << "." << "|"; // noktalı olduğunda kayma oluyor
        else
            std::cout << std::right << std::setw(10) << this->contacts[i].getName() << "|";
        if(this->contacts[i].getSurname().length() > 9)
            std::cout << std::right << std::setw(10) << this->contacts[i].getSurname().substr(0, 9) << "." << "|";
        else
            std::cout << std::right << std::setw(10) << this->contacts[i].getSurname() << "|";
        if(this->contacts[i].getNickName().length() > 9)
            std::cout << std::right << std::setw(10) << this->contacts[i].getNickName().substr(0, 9) << "." << "|" << std::endl;
        else
            std::cout << std::right << std::setw(10) << this->contacts[i].getNickName() << "|" << std::endl;
        this->contacts[i].index = i;
    }
    std::cout << "Please enter an index: ";
    std::string index_selected;
    int selected_num = 0;
    std::cin >> index_selected;
    selected_num = stringToInt(index_selected);
    while((!isNumeric(index_selected) || index_selected.length() < 1) && selected_num <= this->index_total) // girilen aranmak istenen sayı olamanyan bir index ise bos basıyor
    {
        std::cout << "Please enter valid index" << std::endl;
        std::cin >> index_selected;
        selected_num = stringToInt(index_selected);
    }
    if(selected_num >= 8)
    {
        while(selected_num >= 8)
        {
            std::cout << "Please enter lower index than 8" << std::endl;
            std::cin >> index_selected;
            selected_num = stringToInt(index_selected);
        }
    }
    else
    {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Name : " << this->contacts[selected_num].getName() << std::endl;
        std::cout << "Surname : " << this->contacts[selected_num].getSurname() << std::endl;
        std::cout << "Nickname : " << this->contacts[selected_num].getNickName() << std::endl;
        std::cout << "Phone Number : " << this->contacts[selected_num].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret : " << this->contacts[selected_num].getDarkestSecret() << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
}

void Phonebook::exit() {
    
}