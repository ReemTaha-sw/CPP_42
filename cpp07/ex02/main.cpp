// #include "Array.hpp"

// void testDefaultConstructor() {
//     Array<int> intArray;
//     std::cout << "Default constructed array size: " << intArray.size() << std::endl;
// }

// void testParameterizedConstructor() {
//     Array<int> intArray(5);
//     std::cout << "Parameterized constructed array size: " << intArray.size() << std::endl;

//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         intArray[i] = i * 10;
//     }

//     std::cout << "Array contents: ";
//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         std::cout << intArray[i] << " ";
//     }
//     std::cout << std::endl;
// }

// void testCopyConstructor() {
//     Array<int> intArray(5);
//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         intArray[i] = i * 10;
//     }

//     Array<int> copyArray(intArray);
//     std::cout << "Copied array contents: ";
//     for (unsigned int i = 0; i < copyArray.size(); ++i) {
//         std::cout << copyArray[i] << " ";
//     }
//     std::cout << std::endl;

//     // Modify the original array and check if the copy remains unaffected
//     intArray[0] = 100;
//     std::cout << "Modified original array contents: ";
//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         std::cout << intArray[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "Copy array contents after modification of original: ";
//     for (unsigned int i = 0; i < copyArray.size(); ++i) {
//         std::cout << copyArray[i] << " ";
//     }
//     std::cout << std::endl;
// }

// void testAssignmentOperator() {
//     Array<int> intArray(5);
//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         intArray[i] = i * 10;
//     }

//     Array<int> assignedArray;
//     assignedArray = intArray;
//     std::cout << "Assigned array contents: ";
//     for (unsigned int i = 0; i < assignedArray.size(); ++i) {
//         std::cout << assignedArray[i] << " ";
//     }
//     std::cout << std::endl;

//     intArray[0] = 100;
//     std::cout << "Modified original array contents: ";
//     for (unsigned int i = 0; i < intArray.size(); ++i) {
//         std::cout << intArray[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "Assigned array contents after modification of original: ";
//     for (unsigned int i = 0; i < assignedArray.size(); ++i) {
//         std::cout << assignedArray[i] << " ";
//     }
//     std::cout << std::endl;
// }

// void testOutOfBoundsAccess() {
//     Array<int> intArray(5);
//     try {
//         intArray[5] = 100;
//     } catch (const std::out_of_range& e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

// void testEmptyArray() {
//     Array<int> emptyArray;
//     std::cout << "Empty array size: " << emptyArray.size() << std::endl;
// }

// int main() {
//     std::cout << "testDefaultConstructor -----------------\n";
//     testDefaultConstructor();
//     std::cout << "\ntestParameterizedConstructor -----------------\n";
//     testParameterizedConstructor();
//     std::cout << "\ntestCopyConstructor -----------------\n";
//     testCopyConstructor();
//     std::cout << "\ntestAssignmentOperator -----------------\n";
//     testAssignmentOperator();
//     std::cout << "\ntestOutOfBoundsAccess -----------------\n";
//     testOutOfBoundsAccess();
//     std::cout << "\ntestEmptyArray -----------------\n";
//     testEmptyArray();

//     return 0;
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}