/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:27:48 by rosman            #+#    #+#             */
/*   Updated: 2024/09/07 21:27:36 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name) , weapon(weapon){}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
