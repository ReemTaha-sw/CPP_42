#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Creating Animals ===\n";
    const Animal* meta = new Animal();
    std::cout << "\n";
    const Animal* dog = new Dog();
    std::cout << "\n";
    const Animal* cat = new Cat();

    std::cout << "\n=== getType() ===\n";
    std::cout << "dog->getType() : " << GREEN << dog->getType() << "\n" << RESET;
    std::cout << "cat->getType() : " << YELLOW << cat->getType() << "\n" << RESET;

    std::cout << "\n=== makeSound() ===\n";
    cat->makeSound();
    dog->makeSound();

    std::cout << "\n=== Creating Wrong Animal ===\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << "\n";
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n=== getType() ===\n";
    std::cout << "wrongCat->getType() : " << RED << wrongCat->getType() << "\n" << RESET;
    std::cout << "\n=== makeSound() ===\n";
    std::cout << "WrongCat::makeSound() const { std::cout << 'Meow! (but wrong)'; } but no virtual so:\n";
    wrongCat->makeSound();

    std::cout << "\n=== deleting ===\n";
    delete dog;
    std::cout << "\n";
    delete cat;
    std::cout << "\n";
    delete meta;
    std::cout << "\n";
    delete wrongCat;
    std::cout << "\n";
    delete wrongMeta;

    return 0;
}
