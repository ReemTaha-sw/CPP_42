#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1("Alice", 2);
        std::cout << bureaucrat1;

        bureaucrat1.incrementGrade();
        std::cout << "After increment: " << bureaucrat1;

        Bureaucrat bureaucrat2("Bob", 149);
        std::cout << bureaucrat2;

        bureaucrat2.decrementGrade();
        std::cout << "After decrement: " << bureaucrat2;

        std::cout << "\n";

        Bureaucrat bureaucrat3("Charlie", 151);  // Should throw an exception
        Bureaucrat bureaucrat4("Charlie", 0);  // Should throw an exception
    }
    catch (std::exception &e) {
        std::cerr << "\nException caught: " << e.what();
    }

    try {
        Bureaucrat bureaucrat1("Zuha", 0);
    }
    catch (std::exception &error){
        std::cerr << "\nException caught: " << error.what();
    }

    return 0;
}
