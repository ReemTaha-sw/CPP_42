#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 3);
        Bureaucrat bob("Bob", 100);

        Form formA("FormA", 50, 100);
        Form formB("FormB", 50, 100);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        alice.signForm(formA);  // Alice should sign successfully
        std::cout << "\n" << formA << std::endl;

        bob.signForm(formB);  // Bob's grade is too low, should throw exception
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
