/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:04 by rosman            #+#    #+#             */
/*   Updated: 2024/09/11 15:16:25 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int num) : _fixedPointValue(num << _fractionalBits) {}

Fixed::Fixed(const float flo) : _fixedPointValue(roundf(flo * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &copy) { *this = copy; }

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

int Fixed::getRawBits() const { return this->_fixedPointValue; }

float Fixed::toFloat() const { return (float)_fixedPointValue / (1 << _fractionalBits); }

int Fixed::toInt() const { return _fixedPointValue >> _fractionalBits; }

// comparacion -----------------------------------------------------------------

bool Fixed::operator>(const Fixed &other) const // >
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const // <
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const // <=
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const // >=
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const // ==
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const // !=
{
    return this->_fixedPointValue != other._fixedPointValue;
}

// aritmeticos ------------------------------------------------------------

Fixed Fixed::operator+(const Fixed &other) const // +
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue  + other._fixedPointValue);
    return result;
}
Fixed Fixed::operator-(const Fixed &other) const // -
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue  - other._fixedPointValue);
    return result;
}
Fixed Fixed::operator/(const Fixed &other) const // /
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits)  / other._fixedPointValue);
    return result;
}
Fixed Fixed::operator*(const Fixed &other) const // *
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

// Increment/Decrement operators ------------------------------------------------

Fixed& Fixed::operator++() // Pre-increment
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() // Pre-decrement
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

// min/max---------------------------------------------------------------

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) { return (first < second) ? first : second; }
const Fixed& Fixed::min(Fixed& first, Fixed& second) { return (first < second) ? first : second; }
const Fixed& Fixed::max(const Fixed& first, const Fixed& second) { return (first > second) ? first : second; }
const Fixed& Fixed::max(Fixed& first, Fixed& second) { return (first > second) ? first : second; }

std::ostream& operator<<(std::ostream &out, const Fixed &Fixed) { return (out << Fixed.toFloat(), out); }