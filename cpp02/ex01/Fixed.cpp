/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:04 by rosman            #+#    #+#             */
/*   Updated: 2024/09/11 14:08:54 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) : _fixedPointValue(num << _fractionalBits)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float flo) : _fixedPointValue(roundf(flo * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called\n";
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
    this->_fixedPointValue = raw;
}

int Fixed::getRawBits() const
{
    return this->_fixedPointValue;
}

float Fixed::toFloat() const
{
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &Fixed)
{
    return (out << Fixed.toFloat());
}