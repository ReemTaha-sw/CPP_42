#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Intern someRandomIntern;
        std::cout << "\n";
        Bureaucrat alice("Alice", 1);

        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        alice.signForm(*form1);
        std::cout << "\n";
        alice.executeForm(*form1);
        delete form1;
        std::cout << "\n";

        AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Home");
        alice.signForm(*form2);
        std::cout << "\n";
        alice.executeForm(*form2);
        delete form2;
        std::cout << "\n";

        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        alice.signForm(*form3);
        std::cout << "\n";
        alice.executeForm(*form3);
        delete form3;
        std::cout << "\n";

        // This will throw an exception
        AForm* form4 = someRandomIntern.makeForm("unknown form", "Target");
        delete form4;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
