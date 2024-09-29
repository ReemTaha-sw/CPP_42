/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:18:59 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 20:38:57 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CYAN << MAGENTA << "🤖 FragTrap ("<< _name << ")  created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CYAN << MAGENTA << "🤖 FragTrap (" << _name << ") created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << CYAN << MAGENTA << "🤖 FragTrap (" << _name << ") copied! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::string name = (_name.empty()) ? "Defualt Name" : _name;
    std::cout << CYAN << MAGENTA << "💥 FragTrap Destructor (" << name << ") destroyed.\n" << RESET;
}

void FragTrap::highFivesGuys(void) {
    std::string name = (_name.empty()) ? "Defualt Name" : _name;
    std::cout << CYAN << MAGENTA << "FragTrap (" << name << ") requests high fives! 🖐\n" << RESET;
}