#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base::~Base()
{
	std::cout << "Base destructor called!\n";
}

Base* generate(void) {
    std::srand(static_cast<unsigned int>(time(0)));
    int randNum = rand() % 3;  // Random number between 0 and 2

    if (randNum == 0) {
        std::cout << "Generating A" << std::endl;
        return new A();
    } else if (randNum == 1) {
        std::cout << "Generating B" << std::endl;
        return new B();
    } else {
        std::cout << "Generating C" << std::endl;
        return new C();
    }
}

// Function to identify the type of object using a pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Function to identify the type of object using a reference
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}
