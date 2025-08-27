#include "Span.hpp"

Span::Span() : max(0), nums() {}

Span::Span(unsigned int max) : max(max), nums() {}

Span::Span(const Span &other) : max(other.max), nums(other.nums) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        max = other.max;
        nums = other.nums;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (nums.size() >= max)
        throw std::runtime_error("Span: capacity exceeded!");
    nums.push_back(value);
}

int Span::longestSpan() {
    if (nums.size() < 2)
        throw std::runtime_error("Span: not enough elements for longestSpan!");
    std::vector<int>::iterator minIt = std::min_element(nums.begin(), nums.end());
    std::vector<int>::iterator maxIt = std::max_element(nums.begin(), nums.end());
    return *maxIt - *minIt;
}

int Span::shortestSpan() {
    if (nums.size() < 2)
        throw std::runtime_error("Span: not enough elements for shortestSpan!");
    std::vector<int> tmp(nums);
    std::sort(tmp.begin(), tmp.end());
    int minDiff = INT_MAX;
    for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minDiff) 
            minDiff = diff;
    }
    return minDiff;
}
