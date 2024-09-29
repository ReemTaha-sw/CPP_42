/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:25:19 by rosman            #+#    #+#             */
/*   Updated: 2024/09/08 14:15:26 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cerr << "\033[31mUsage: ./harlFilter <logLevel>\033[0m\n";
        return 1;
    }

    Harl harl;
    harl.filter(av[1]);

    return 0;
}
