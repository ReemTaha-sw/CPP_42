#pragma once

#include <iostream>

// color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal(); // dynamic (runtime) polymorphism
        Animal(const Animal &copy);
        Animal &operator=(const Animal &other);

        virtual void makeSound() const;
        std::string getType() const;
};