#pragma once

#include "AMateria.hpp"

class Cure : public AMateria // concrete subclasses of AMateria
{
    public:
        Cure();
        Cure(Cure const &copy);
        ~Cure();
        Cure &operator=(Cure const &copy);
        
        AMateria *clone() const; //implement the virtual functions defined in AMateria
        void use(ICharacter &target); //implement the virtual functions defined in AMateria
};