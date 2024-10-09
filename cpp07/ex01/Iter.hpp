#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, size_t sizeOfArray, typename Func>
void iter(T (&array)[sizeOfArray], size_t length, Func func)
{
    if (sizeOfArray >= length && length != 0)
        for (size_t i = 0; i < length; i++)
            func(array[i]);
    else
        std::cout << "\033[31mOut Of The Array Range!\033[0m";
}

#endif
