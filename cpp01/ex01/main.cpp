/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:40:48 by rosman            #+#    #+#             */
/*   Updated: 2024/09/08 13:46:40 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <climits>


bool isNumber(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool isWithinIntRange(const std::string &str) {
    const std::string int_max_str = "2147483647";

    if (str.length() > int_max_str.length()) {
        return false;
    }
    if (str.length() == int_max_str.length() && str > int_max_str) {
        return false;
    }
    return true;
}

bool isAlphabetic(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (!std::isalpha(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    Zombie* zombies;
    double N = 5;
    std::string name = "Default Name";
    if (ac == 3)
    {
        if (!isNumber(av[1]) || !isAlphabetic(av[2]) || !isWithinIntRange(av[1]))
            return (std::cout << "\033[31mError\033[0m: The first argument must be an +(int) and the second argument must be alphabetic.\n", 1);
        N = atoi(av[1]);
        name = av[2]? av[2] : "Default Name";
    }
    zombies = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
    return 0;
}