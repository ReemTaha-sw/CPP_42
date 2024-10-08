#include "AMateria.hpp"

AMateria::AMateria() : _type("Default AMateria") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) { *this = copy; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other)
        this->_type = other._type;
    return *this;  
}

std::string const &AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << this->_type << " on " << target.getName() << " *\n";
}