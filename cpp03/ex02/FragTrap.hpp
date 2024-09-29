/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:19:03 by rosman            #+#    #+#             */
/*   Updated: 2024/09/15 14:03:33 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
      FragTrap();
      FragTrap(const std::string &name);
      FragTrap(const FragTrap &copy);
      FragTrap &operator=(const FragTrap &other);
      ~FragTrap();
      void highFivesGuys(void);
};