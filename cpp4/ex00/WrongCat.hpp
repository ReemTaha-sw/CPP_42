#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        virtual ~WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &other);

        void makeSound() const;
};