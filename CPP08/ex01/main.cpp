#include <iostream>
#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span big(10000);
        std::vector<int> data;
        
		for (int i = 0; i < 10000; ++i) 
            data.push_back(i);

        big.addRange(data.begin(), data.end());
        std::cout << big.shortestSpan() << std::endl;
        std::cout << big.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
