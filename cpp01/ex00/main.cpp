/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:50:25 by rosman            #+#    #+#             */
/*   Updated: 2024/09/05 17:25:44 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie my_zombie("My Zombie");
    my_zombie.announce();
    Zombie *new_zombie = newZombie("New Zombie");
    new_zombie->announce();
    randomChump("Random Chump");
    delete new_zombie;
    return 0;
}