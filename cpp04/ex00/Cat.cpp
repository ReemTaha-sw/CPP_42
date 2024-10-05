#include "Cat.hpp"

Cat::Cat() { 
    this->_type = "Cat";
    std::cout << "Animal (" << _type << ") created.\n";
}

Cat::~Cat() { std::cout << "-(" << _type << ") destroyed.\n"; }

Cat::Cat(const Cat &copy): Animal(copy) {
    *this = copy;
    this->_type = "Cat";
    std::cout << "Animal (" << _type << ") copy created.\n";
}

void Cat::makeSound() const { std::cout <<_type << " says " << YELLOW << BOLD <<"'Meow!'\n" << RESET; }

Cat& Cat::operator=(const Cat &other)
{
    this->_type = other._type;
    return *this;
}
