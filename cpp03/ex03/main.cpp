/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:30 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 20:34:48 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Creation Phase ===\n" << std::endl;
    
    std::cout << RED << "\nNew Object\n\n" << RESET;
    
    DiamondTrap diamond1("D_1");
    
    std::cout << RED << "\nNew Object\n\n" << RESET;
    DiamondTrap diamond2(diamond1);
    std::cout << RED << "\nNew Object\n\n" << RESET;
    DiamondTrap diamond3("D_3");

    std::cout << "\n=== Battle Begins ===\n" << std::endl;
    
    diamond1.attack("target1");
    diamond2.beRepaired(1);
    diamond3.takeDamage(5);

    std::cout << "\n=== Who Am I ===\n" << std::endl;
    
    diamond1.whoAmI();

    diamond2.whoAmI();
    diamond3.whoAmI();

    std::cout << "\n===  Destructing  ===\n" << std::endl;
    return 0;

}

