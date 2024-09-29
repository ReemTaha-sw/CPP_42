/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:25:24 by rosman            #+#    #+#             */
/*   Updated: 2024/09/08 14:06:44 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    void (Harl::*complaints[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // array of pointers to class member function
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for(int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (this->*complaints[i])();
    }
    std::cout << "\033[31m" << level << "\033[0m: Not one of our levels 🤭.\nThe Levels are: \033[32mDEBUG, INFO, WARNING, ERROR\033[0m\n";
}