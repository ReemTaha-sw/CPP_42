#include "Dog.hpp"

Dog::Dog() { 
    this->_type = "Dog";
    std::cout << "Animal (" << _type << ") created.\n";
}

Dog::~Dog() { std::cout << "-(" << _type << ") destroyed.\n"; }

Dog::Dog(const Dog &copy) : Animal(copy) {
    *this = copy;
    this->_type = "Dog";
    std::cout << "Animal (" << _type << ") copy created.\n";
}

void Dog::makeSound() const { std::cout << "Dog says " << GREEN << BOLD << "'Woof!'\n" << RESET; }

Dog& Dog::operator=(const Dog &other)
{
    this->_type = other._type;
    return *this;
}
