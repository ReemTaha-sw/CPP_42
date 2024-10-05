#include "Animal.hpp"

Animal::Animal() : _type("Animal") { std::cout << "Parent Class :(" << _type << ") created.\n"; }
Animal::~Animal() { std::cout << "Parent Class : Animal destroyed.\n"; }
Animal::Animal(const Animal &copy) : _type(copy._type) { std::cout << "Parent Class : (" << _type << ") copy created.\n"; }
std::string Animal::getType() const { return _type; }
void Animal::makeSound() const { std::cout << MAGENTA << "Parent Class : Animal noise ?!?!\n" << RESET; }
Animal& Animal::operator=(const Animal &other)
{
    this->_type = other._type;
    return *this;
}