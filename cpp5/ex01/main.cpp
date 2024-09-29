#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 3);
        Bureaucrat bob("Bob", 100);

        Form taxForm("TaxForm", 50, 100);

        std::cout << taxForm << std::endl;

        alice.signForm(taxForm);  // Alice should sign successfully
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);  // Bob's grade is too low, should throw exception
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
