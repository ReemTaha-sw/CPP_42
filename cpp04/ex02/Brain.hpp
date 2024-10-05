#pragma once

#include <iostream>

class Brain
{
    protected:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &other);
        virtual ~Brain();
        
        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
        void printIdeas() const;
};