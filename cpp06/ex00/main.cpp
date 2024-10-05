#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::string testCases[] = {
            "A", "42", "3.14",
            "2.71828", "nan", "+inff",
            "-inf", "255", "32", "invalid_input", "42.0f", 
        };

        const int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

        for (int i = 0; i < numTestCases; i++) {
            std::cout << "\nTesting case: " << testCases[i] << std::endl;
            ScalarConverter::convert(testCases[i]);
        }

        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
