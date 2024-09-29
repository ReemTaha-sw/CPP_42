#include "Brain.hpp"

void Brain::printIdeas() const {
    for (int i = 0; i < 5; i++) {
        std::cout << "Idea " << i + 1 << ": " << _ideas[i] << "\n";
    }
}

Brain::Brain() { 
    std::cout << "🧠 Brain Constructor created as :\n";
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "Default IDEA";
    printIdeas();
}

Brain& Brain::operator=(const Brain &copy) {
    std::cout << "🧠 Brain assigned as :\n";
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = copy._ideas[i];
        }
        // *(this->_ideas) = *(copy)._ideas;
        
    }
    printIdeas();
    return *this;
}

Brain::Brain(const Brain &copy) {
    *this = copy;
}

Brain::~Brain() { std::cout << "Brain destroyed.\n"; }

void Brain::setIdea(int index, const std::string &idea)
{
     if (index >= 0 && index < 100) 
        this->_ideas[index] = idea;
    else 
        std::cout << "Invalid index!\n";
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index <= 100)
        return this->_ideas[index];
    return"There is no IDEA with this index!\n";
}