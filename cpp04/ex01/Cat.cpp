#include "Cat.hpp"

Cat::Cat() { 
    this->_type = "Cat";
    std::cout << "Animal (" << _type << ") created.\n";
    this->_brain = new Brain();
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "-(" << _type << ") destroyed.\n"; }

Cat::Cat(const Cat &copy): Animal(copy) {
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Animal (" << _type << ") copy created.\n";
}

void Cat::makeSound() const { std::cout <<_type << " says " << YELLOW << BOLD <<"'Meow!'\n" << RESET; }

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
        delete _brain;
        this->_brain = new Brain(*(other._brain)); // deep copying
    }
    return *this;
}

Brain *Cat::getBrain() const {
    return this->_brain;
}

void Cat::showIdeas() const { this->_brain->printIdeas(); }