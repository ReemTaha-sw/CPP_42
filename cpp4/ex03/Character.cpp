#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        this->_materia[i] = NULL;
}

Character::Character(Character const &copy) : _name(copy._name)
{
    for (int i = 0; i < 4; ++i) {
        if (copy._materia[i] != NULL) 
            this->_materia[i] = copy._materia[i]->clone();
        else 
            this->_materia[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

Character &Character::operator=(Character const &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i])
                delete this->_materia[i];
            if (copy._materia[i])
                this->_materia[i] = copy._materia[i]->clone();
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_materia[idx])
        this->_materia[idx]->use(target);
}