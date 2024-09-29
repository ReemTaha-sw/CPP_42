/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:52:35 by rosman            #+#    #+#             */
/*   Updated: 2024/09/04 14:38:59 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    (void)av;
    if(ac > 1)
    {
        for(int j = 1; j < ac; j++)
            for(int i = 0; av[j][i]; i++)
                std::cout<< (char)toupper(av[j][i]);
    }
    else
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout<< "\n";
    return (0);
}