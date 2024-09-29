#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria // abstract base class
{
    protected:
        std::string _type;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria &copy);
        AMateria &operator=(const AMateria &other);

        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};