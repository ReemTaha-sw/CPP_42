#pragma once

#include "AMateria.hpp"

class Ice : public AMateria // concrete subclasses of AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(Ice const &copy);
        Ice &operator=(Ice const &other);
        
        AMateria *clone() const; // implement the virtual functions defined in AMateria
        void use(ICharacter& target); // implement the virtual functions defined in AMateria
};