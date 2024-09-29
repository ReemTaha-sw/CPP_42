/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:30 by rosman            #+#    #+#             */
/*   Updated: 2024/09/13 16:11:13 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap1("CT_1");
    ClapTrap clapTrap2("CT_2");

    std::cout << "\n=== Battle Begins ===\n" << std::endl;

    clapTrap1.attack("CT_2");
    clapTrap2.takeDamage(3);

    clapTrap2.attack("CT_1");
    clapTrap1.takeDamage(2);

    std::cout << "\n=== Repair Phase ===\n" << std::endl;

    clapTrap1.beRepaired(5);
    clapTrap2.beRepaired(4);

    std::cout << "\n=== Energy Drain ===\n" << std::endl;

    for (int i = 0; i < 8; ++i) {
        clapTrap1.attack("CT_2");
        clapTrap2.attack("CT_1");
    }

    std::cout << "\n=== Out of Energy ===\n" << std::endl;

    clapTrap1.attack("CT_2");
    clapTrap2.attack("CT_1");

    std::cout << "\n=== End Battle ===\n" << std::endl;

    return 0;
}
