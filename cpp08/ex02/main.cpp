#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin(); // last in the stack
    MutantStack<int>::iterator ite = mstack.end(); // top of the stack

    ++it;
    --it;

    std::cout << std::endl << "MutantStack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test reverse iterator
    std::cout << std::endl << "MutantStack reverse elements:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin(); // top of the stack
    MutantStack<int>::reverse_iterator rite = mstack.rend(); // last of stack

    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Test copy constructor
    std::stack<int> s(mstack);
    
    std::cout << std::endl << "Stack 's(mstack)' elements:" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}
