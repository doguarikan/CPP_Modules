#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
    void debug();
    void info();
    void warning();
    void error();

    public:
        Harl();
        void complain(std::string level);
} ;

#endif