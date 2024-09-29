/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:12:22 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 20:39:07 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CYAN << YELLOW << "🤖 ScavTrap ("<< _name << ")  created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CYAN << YELLOW << "🤖 ScavTrap (" << _name << ") created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << CYAN << YELLOW << "🤖 ScavTrap (" << _name << ") copied! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::string name = (_name.empty()) ? "Defualt Name" : _name;
    std::cout << YELLOW << "💥 ScavTrap Destructor (" << name << ") destroyed.\n";
}

void ScavTrap::attack(const std::string &target) {
    std::string name = (_name.empty()) ? "Defualt Name" : _name;
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << CYAN << YELLOW << "ScavTrap : ⚔️ " << name << " attacks " << target 
                  << " for " << _attackDamage << " damage! ⚡(Energy left: " 
                  << --_energyPoints << ")\n" << RESET;
    } else {
        std::cout << CYAN << RED << "😵 ScavTrap " << name << " is out of energy! ⚡(Energy left: " 
                  << _energyPoints << ")\n" << RESET;
    }
}

void ScavTrap::guardGate() {
    std::string name = (_name.empty()) ? "Defualt Name" : _name;
    std::cout << CYAN << GREEN << "ScavTrap " << name << " : is now in Gate keeper mode.\n"<< RESET;
}
