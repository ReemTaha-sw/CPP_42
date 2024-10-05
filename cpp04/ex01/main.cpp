#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << GREEN << "===== Test 1: Create Dog and set Ideas =====\n" << RESET;
    const Animal *dog1 = new Dog();
    std::cout << "\n";
    dynamic_cast<const Dog*>(dog1)->getBrain()->setIdea(0, "Chase the cat!");
    dynamic_cast<const Dog*>(dog1)->getBrain()->setIdea(1, "Eat the bone!");
    std::cout << "Dog1 Idea 1: " << dynamic_cast<const Dog*>(dog1)->getBrain()->getIdea(0) << "\n";
    std::cout << "Dog1 Idea 2: " << dynamic_cast<const Dog*>(dog1)->getBrain()->getIdea(1) << "\n";

    std::cout << GREEN << "\n===== Test 2: Copy dog2(dog1) =====\n" << RESET;
    const Animal *dog2 = new Dog(*dynamic_cast<const Dog*>(dog1));
    dynamic_cast<const Dog*>(dog2)->getBrain()->setIdea(2, "Sleep all day!");
    std::cout << "\nAfter modification on the idea[2]:\n";
    std::cout << "Dog2 Idea 3: " << dynamic_cast<const Dog*>(dog2)->getBrain()->getIdea(2) << "\n";

    std::cout << GREEN << "\n===== Test 3: Assign Dog3 = Dog2 =====\n" << RESET;
    const Animal *dog3 = new Dog();
    *dynamic_cast<Dog*>(const_cast<Animal*>(dog3)) = *dynamic_cast<const Dog*>(dog2);

    std::cout << YELLOW << "\n===== Test 4: Create Cat and set Ideas =====\n" << RESET;
    Cat *cat1 = new Cat();
    cat1->getBrain()->setIdea(0, "Catch the mouse!");
    std::cout << "\nCat1 Idea 1: " << cat1->getBrain()->getIdea(0) << "\n";

    std::cout << YELLOW << "\n===== Test 5: Copy Cat2(Cat1) =====\n" << RESET;
    Cat *cat2 = new Cat(*cat1);
    std::cout << "\nAfter modification on the idea[1]: to 'Drink milk!'\n";
    cat2->getBrain()->setIdea(1, "Drink milk!");

    std::cout << YELLOW << "\n===== Test 6: Assign Cat3 = Cat2 =====\n" << RESET;
    Cat *cat3 = new Cat();
    *cat3 = *cat2;

    std::cout << YELLOW << "\n===== Test 7: Animal Sounds =====\n" << RESET;
    dog1->makeSound();
    cat1->makeSound();

    std::cout << "\n===== All tests completed =====\n" << RESET;

    delete dog1;
    delete dog2;
    delete dog3;
    delete cat1;
    delete cat2;
    delete cat3;

    return 0;
}
