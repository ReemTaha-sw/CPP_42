#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error.\n";
        return 1;
    }

    int result = RPN::evaluate(argv[1]);
    if (result == -1)
        return 1;
    return 0;
}