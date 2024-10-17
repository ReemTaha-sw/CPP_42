#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
   std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);


    try {
        std::vector<int>::iterator result = easyfind(vec, 30);
        int index = std::distance(vec.begin(), result);
        std::cout << "Found value in vector: " << *result << " at index: " << index << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }

    std::list<int> lst;
    lst.push_back(25);
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(35);
    lst.push_back(25);

    try {
        std::list<int>::iterator result = easyfind(lst, 25);
        int index = std::distance(lst.begin(), result);
        std::cout << "Found value in vector: " << *result << " at index: " << index << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }

    try {
        std::vector<int>::iterator result = easyfind(vec, 100);
        int index = std::distance(vec.begin(), result);
        std::cout << "Found value in vector: " << *result << " at index: " << index << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }

    return 0;
}
