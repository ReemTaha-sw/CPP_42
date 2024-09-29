/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:17:33 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 20:36:12 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(const std::string &name) 
    : ClapTrap(name + "_clap_name"), _name(name) {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "\n🤖 DiamondTrap (" << _name << ") created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << "\n\n";

}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) 
    : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name) {
    std::cout << "\n🤖 DiamondTrap (" << _name << ") copied! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap " << _name << " assigned.\n";
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed.\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << " and ClapTrap name is " 
              << ClapTrap::_name << "\n";
}