#include "WrongCat.hpp"

WrongCat::WrongCat() { 
    this->_type = "WrongCat";
    std::cout << "WrongAnimal (" << _type << ") created.\n";
}

WrongCat::~WrongCat() { std::cout << "-(" << _type << ") destroyed.\n"; }

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    *this = copy;
    this->_type = "WrongCat";
    std::cout << "WrongAnimal (" << _type << ") copy created.\n";
}

void WrongCat::makeSound() const { std::cout << "Meow! (but wrong).\n"; }

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    this->_type = other._type;
    return *this;
}
