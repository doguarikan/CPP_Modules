#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

	Contact contacts[8];
	int index;
	int index_total;
	public:
		void add();
		void search();
		int check_index(std::string selected_num_str, int *selected_num);
		Phonebook();
};

#endif