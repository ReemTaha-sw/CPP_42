/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:52:36 by rosman            #+#    #+#             */
/*   Updated: 2024/09/05 17:52:04 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie( std::string name );
        ~Zombie();
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );