#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = 0;
    this->index_total = 0;
}

bool isNumeric(const std::string& str) {
    for (std::size_t i = 0; i < str.length(); i++)
    {
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

    if (!str.empty() && str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }

    for (; i < str.size(); ++i)
    {
        result = result * 10 + (str[i] - '0');
    }

    return isNegative ? -result : result;
}

int Phonebook::check_index(std::string selected_num_str, int *selected_num)
{
    *selected_num = stringToInt(selected_num_str);
    if(!isNumeric(selected_num_str) || selected_num_str.length() < 1)
        return 1;
    if(this->index_total > 8)
    {
        if(*selected_num > 8)
            return 1;
    }
    else
    {
        if(*selected_num > this->index_total - 1)
            return 1;
    }
    if(this->index_total == 0)
        return 1;
    if(*selected_num >= 8 && *selected_num <= 0)
        return 1;
    return 0;
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

    while(1)
    {
        long unsigned int i = 0;
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
            while(1)
            {
                if(!std::isdigit(phone_number[i]))
                {
                    std::cout << "Please enter number only" << std::endl;
                    break ;
                }
                else
                    i++;
                if(i == phone_number.length())
                {
                    err = 1;
                    break ;
                }
            }
            if(err)
                break;
        }
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
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "name" << "|";
    std::cout << std::setw(10) << "surname" << "|";
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    int print;
    if(this->index_total > 8)
        print = 8;
    else
        print = index_total;
    for(int i = 0; i < print; i++)
    {
        std::cout << std::setw(10) << i << "|"; 
        if(this->contacts[i].getName().length() > 9)
            std::cout << std::setw(10) << this->contacts[i].getName().substr(0,9) + "." << "|";
        else
            std::cout << std::setw(10) << this->contacts[i].getName() << "|";
        if(this->contacts[i].getSurname().length() > 9)
            std::cout << std::setw(10) << this->contacts[i].getSurname().substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << this->contacts[i].getSurname() << "|";
        if(this->contacts[i].getNickName().length() > 9)
            std::cout << std::setw(10) << this->contacts[i].getNickName().substr(0, 9) + "." << "|" << std::endl;
        else
            std::cout << std::setw(10) << this->contacts[i].getNickName() << "|" << std::endl;
        this->contacts[i].index = i;
    }
    std::cout << "Please enter an index: ";
    int selected_num = 0;
    std::string selected_num_str;
    std::cin >> selected_num_str;
    if(check_index(selected_num_str, &selected_num))
    {
        if(this->index_total == 0 && this->index == 0)
            return ;
        std::cout << "Please enter valid index :";
        std::cin >> selected_num_str;
        while(check_index(selected_num_str, &selected_num))
        {
            std::cout << "Please enter valid index :";
            std::cin >> selected_num_str;
        }
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Name : " << this->contacts[selected_num].getName() << std::endl;
    std::cout << "Surname : " << this->contacts[selected_num].getSurname() << std::endl;
    std::cout << "Nickname : " << this->contacts[selected_num].getNickName() << std::endl;
    std::cout << "Phone Number : " << this->contacts[selected_num].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret : " << this->contacts[selected_num].getDarkestSecret() << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
