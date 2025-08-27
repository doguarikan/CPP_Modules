#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iterator>

class Span {
    unsigned int max;
    std::vector<int> nums;

    public:
        Span();
        Span(unsigned int maxSize);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        template <typename InputIt>
        void addRange(InputIt first, InputIt last) {
            size_t distance = std::distance(first, last);
            if (nums.size() + distance > max)
                throw std::runtime_error("Span: capacity exceeded in addRange");
            
            for (InputIt it = first; it != last; ++it)
                nums.push_back(*it);
        }
        
        void addNumber(int value);
        int shortestSpan();
        int longestSpan();
};

#endif
