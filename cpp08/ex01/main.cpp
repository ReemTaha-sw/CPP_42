#include "Span.hpp"
#include <list>
#include <ctime>  // Include for std::time

int main() {
    try {
        // Seed the random number generator with the current time
        std::srand(std::time(NULL));

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(3);

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
        Span bigNewSpan(10000);
        bigSpan.addNumbers(vec.begin(), vec.end());
        bigNewSpan.addNumbers(lit.begin(), lit.end());
        std::cout << "Big span shortest: " << bigSpan.shortestSpan() << "\n";
        std::cout << "Big span longest: " << bigSpan.longestSpan() << "\n";
        std::cout << "\nBig New span shortest: " << bigNewSpan.shortestSpan() << "\n";
        std::cout << "Big New span longest: " << bigNewSpan.longestSpan() << "\n";

        const std::vector<int>& numbers = bigSpan.getNumbers();
        std::cout << "Contents of bigSpan:" << std::endl;
        for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
