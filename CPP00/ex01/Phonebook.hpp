#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

	Contact contacts[8];
	int index;
	public:
		void add();
		void search();
		void exit();
		Phonebook();

};

#endif