#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
int main() {
    // Seed the random number generator once
    srand(time(NULL));

    try {
        // Creating Bureaucrats
        Bureaucrat alice("Alice", 1);      // Highest grade
        Bureaucrat bob("Bob", 50);          // Mid-grade
        Bureaucrat charlie("Charlie", 150); // Lowest grade
        Bureaucrat dave("Dave", 45);        // Grade sufficient for RobotomyRequestForm

        // Creating Forms
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Ford Prefect");

        // Display Forms
        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;

        // Signing Forms
        alice.signForm(shrubForm);       // Should succeed
        bob.signForm(robotForm);         // Should succeed
        charlie.signForm(pardonForm);    // Should fail (grade too low)

        // Executing Forms
        alice.executeForm(shrubForm);    // Should succeed (creates home_shrubbery)
        bob.executeForm(robotForm);       // Should fail (grade too low)
        charlie.executeForm(pardonForm);  // Should fail (not signed and grade too low)
        dave.executeForm(robotForm);       // Should succeed

        // Attempt to sign and execute pardonForm with a high-grade bureaucrat
        alice.signForm(pardonForm);       // Should succeed
        alice.executeForm(pardonForm);    // Should succeed

    }
    catch (std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
