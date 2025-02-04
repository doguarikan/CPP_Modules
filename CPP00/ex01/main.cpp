#include "PhoneBook.hpp"

std::string toupper_string(const std::string &str) {
    std::string result = str;
    for (std::size_t i = 0; i < result.length(); ++i) {
        result[i] = std::toupper(result[i]);
    }
    return result;
}

int main() {
    
    std::string input;
    PhoneBook book;

    while(true) {
        
        std::cout << "-ADD-" << std::endl;
        std::cout << "-SEARCH-" << std::endl;
        std::cout << "-EXIT-" << std::endl;
        
        std::cin >> input;
        input = toupper_string(input);

        if(input == "ADD")
            book.add();
        else if(input == "SEARCH")
            book.search();
        else if(input == "EXIT")
            return 0;
        else
            std::cout << "Please enter only commands" << std::endl;
    }
}