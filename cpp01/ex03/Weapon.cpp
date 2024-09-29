/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:09:25 by rosman            #+#    #+#             */
/*   Updated: 2024/09/06 17:05:25 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string name)
{
    type = name;
}

const std::string& Weapon::getType() {return type;}