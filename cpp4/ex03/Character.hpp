#pragma once

#include <iostream>

#include "ICharacter.hpp"

class Character : public ICharacter // Concrete Class implementing ICharacter Interface
{
    private:
        std::string _name;
        AMateria *_materia[4];

    public:
        Character(std::string const &name);
        Character(Character const &copy);
        Character &operator=(Character const &copy);
        ~Character();
        
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter&target);
};