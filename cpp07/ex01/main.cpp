#include "Iter.hpp"

void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

void increment(int &x) {
    x += 1;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Original integer array: ";
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Incremented integer array: ";
    iter(intArr, 5, increment);
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::string strArr[] = {"hello", "world", "templates", "are", "cool"};
    std::cout << "String array: ";
    iter(strArr, 5, printString);
    std::cout << std::endl;

    return 0;
}
