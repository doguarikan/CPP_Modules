#include "Phonebook.hpp"

int main() {
    
    std::string input;
    Phonebook book;

    while(true) {
        
        std::cout << "-ADD-" << std::endl;
        std::cout << "-SEARCH-" << std::endl;
        std::cout << "-EXIT-" << std::endl;
        
        std::cin >> input;

        if(input == "ADD")
            book.add();
        else if(input == "SEARCH")
            book.search();
        else if(input == "EXIT")
            book.exit();
        else
            std::cout << "Please enter only commands" << std::endl;
    }
}