#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    for (int i = 0; i < 4; i++)
        if (copy._templates[i] != NULL)
            this->_templates[i] = copy._templates[i]->clone();
        else
            this->_templates[i] = NULL;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_templates[i] != NULL)
                delete this->_templates[i];
            if (other._templates[i] != NULL)
                this->_templates[i] = other._templates[i]->clone();
        }
    }
        return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_templates[i] != NULL)
        {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] == NULL)
        {
            this->_templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
            return this->_templates[i]->clone();
    }
    return NULL;
}