/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:30 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 14:10:28 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Creation Phase ===\n" << std::endl;
    
    std::cout << RED << "\nNew Object\n\n" << RESET;
    FragTrap st1;
    std::cout << RED << "\n\nNew Object\n\n" << RESET;
    FragTrap st2("Warrior");
    std::cout << RED << "\n\nNew Object\n\n" << RESET;
    FragTrap st3(st2);

    std::cout << "\n=== Battle Begins ===\n" << std::endl;

    st1.attack("p1");
    st2.attack("P2");
    st2.attack("P3");
    
    std::cout << std::endl;

    st2.takeDamage(10);
    st3.takeDamage(40);
    
    std::cout << "\n=== Battle Begins ===\n" << std::endl;

    st1.beRepaired(10);

    std::cout << "\n=== High Fives Guys ===\n" << std::endl;

    st3.highFivesGuys();
    st2.highFivesGuys();
    
    std::cout << "\n=== Destruction Phase ===\n" << std::endl;

    return 0;

}

