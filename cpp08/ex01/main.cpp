#include "Span.hpp"
#include <list>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(3);
        // sp.addNumber(3);
        // sp.addNumber(6);
        // sp.addNumber(9);
        // sp.addNumber(10);
        // sp.addNumber(17);

        std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
        std::cout << "Longest span: " << sp.longestSpan() << "\n";

        std::vector<int> vec;
        for (int i = 0; i < 10000; ++i) {
            vec.push_back(std::rand() % 10000);
        }
        std::list<int> lit;
        for (int i = 0; i < 10000; ++i) {
            lit.push_back(std::rand() % 10000);
        }

        Span bigSpan(10000);
        bigSpan.addNumbers(vec.begin(), vec.end());
        bigSpan.addNumbers(lit.begin(), lit.end());
        std::cout << "Big span shortest: " << bigSpan.shortestSpan() << "\n";
        std::cout << "Big span longest: " << bigSpan.longestSpan() << "\n";

    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
