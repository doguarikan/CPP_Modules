#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream> 
#include <string>
#include <iomanip>

class Contact {

	std::string name;
	std::string surname;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
	

	public:
		void setName(const std::string name);
		void setSurname(const std::string surname);
		void setNickName(const std::string nick_name);
		void setPhoneNumber(const std::string phone_number);
		void setDarkestSecret(const std::string darkest_secret);
		std::string getName();
		std::string getSurname();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		int index;
};

#endif
