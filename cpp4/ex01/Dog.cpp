#include "Dog.hpp"

Dog::Dog() {
    this->_type = "Dog";
    std::cout << "Animal (" << _type << ") created.\n";
    this->_brain = new Brain();
}

Dog::~Dog() {
    delete _brain;
    std::cout << "-(" << _type << ") destroyed.\n"; }

Dog::Dog(const Dog &copy) : Animal(copy) {
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Animal (" << _type << ") copy created.\n";
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->_type = other._type;
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const { std::cout << "Dog says " << GREEN << BOLD << "'Woof!'\n" << RESET; }


Brain *Dog::getBrain() const {
    return this->_brain;
}

void Dog::showIdeas() const { this->_brain->printIdeas(); }