/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:25 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 20:49:41 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << CYAN << BOLD << "🤖 ClapTrap (DEFAULT Constructor with no name) created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << CYAN << BOLD << "🤖 ClapTrap (" << _name << ") created! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
    std::cout << CYAN << BOLD << "🤖 ClapTrap (" << _name << ") copied! 💚" 
              << _hitPoints << " ⚡" << _energyPoints << " 🔪" << _attackDamage << RESET << "\n";
}


ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    if (!_name.empty())
        std::cout << MAGENTA << "💥 ClapTrap (" << _name << ") has been scrapped. RIP ⚰️" << RESET << "\n";
    else    
        std::cout << MAGENTA << "💥 ClapTrap (Default) has been scrapped. RIP ⚰️" << RESET << "\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << BOLD << "⚔️ " << _name << " attacks " << target << " for " 
                  << _attackDamage << " damage! ⚡(Energy left: " << --_energyPoints << ")\n" << RESET;
    }
    else
    {
        std::cout << RED << "😵 " << _name << " is out of energy! ⚡(Energy left: " << _energyPoints << ")\n" << RESET;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints = (_hitPoints < 0) ? 0 : _hitPoints - amount;
    std::cout << RED << "💥 " << _name << " takes " << amount << " damage! 💚(HP left: " << _hitPoints << ")\n" << RESET;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        std::cout << GREEN << "🔧 " << _name << " repairs for " << amount << " HP! 💚(HP: " << _hitPoints 
                  << ") ⚡(Energy left: " << --_energyPoints << ")\n" << RESET;
    } else {
        std::cout << YELLOW << "😖 " << _name << " is too broken to repair! 💔\n" << RESET;
    }
}
