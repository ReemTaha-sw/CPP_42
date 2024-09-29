/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:04 by rosman            #+#    #+#             */
/*   Updated: 2024/09/09 16:54:46 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->_fixedPointValue = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointValue;
}