#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { 
    this->_type = "WrongAnimal";
    std::cout << "WrongAnimal (" << _type << ") created.\n";
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destroyed.\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    *this = copy;
    this->_type = "WrongAnimal";
    std::cout << "WrongAnimal (" << _type << ") copy created.\n";
}

void WrongAnimal::makeSound() const { std::cout << RED << BOLD << "WrongAnimal noise ?!?!.\n"<< RESET; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    this->_type = other._type;
    return *this;
}

std::string WrongAnimal::getType() const { return _type; }
