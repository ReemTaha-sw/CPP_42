/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:25:19 by rosman            #+#    #+#             */
/*   Updated: 2024/09/08 14:04:40 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
    {
        std::cout << "\033[32mThis are the complains\033[0m:\n";
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("UNKNOWN");
    }
    else
        harl.complain(av[1]);
    return 0;
}