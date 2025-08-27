#include "MutantStack.hpp"

int main() {
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    MutantStack<int> test;
    std::cout << "Empty size: " << test.size() << std::endl;
    
    test.push(10);
    test.push(20);
    std::cout << "Size after push: " << test.size() << std::endl;
    std::cout << "Top element: " << test.top() << std::endl;
    
    test.pop();
    std::cout << "Size after pop: " << test.size() << std::endl;

    return 0;
}