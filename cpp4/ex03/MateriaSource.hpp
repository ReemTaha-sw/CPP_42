#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource // Concrete Class implementing IMateriaSource Interface
{
    private:
        AMateria *_templates[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &copy);
        MateriaSource &operator=(MateriaSource const &copy);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria *createMateria(std::string const &type);
};