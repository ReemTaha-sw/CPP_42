/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:30 by rosman            #+#    #+#             */
/*   Updated: 2024/09/14 20:02:15 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== Creation Phase ===\n" << std::endl;
    
    std::cout << RED << "\nNew Object\n\n" << RESET;
    ScavTrap st1;
    std::cout << RED << "\n\nNew Object\n\n" << RESET;
    ScavTrap st2("Warrior");
    std::cout << RED << "\n\nNew Object\n\n" << RESET;
    ScavTrap st3(st2);

    std::cout << "\n=== Battle Begins ===\n" << std::endl;

    st1.attack("p1");
    st2.attack("P2");
    st2.attack("P3");
    
    std::cout << std::endl;

    st2.takeDamage(10);
    st3.takeDamage(40);

    std::cout << "\n=== Repair Phase ===\n" << std::endl;

    st2.beRepaired(5);
    st3.beRepaired(4);

    std::cout << "\n=== Gate Keeper Mode ===\n" << std::endl;

    st1.guardGate();
    st2.guardGate();

    std::cout << "\n=== Destruction Phase ===\n" << std::endl;

    return 0;

}

