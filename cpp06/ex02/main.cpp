#include "Base.hpp"

int main() {
    Base* base = generate();

    std::cout << "Identifying via pointer: ";
    identify(base);

    std::cout << "Identifying via reference: ";
    identify(*base);

    delete base;
    return 0;
}
