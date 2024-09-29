/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:07 by rosman            #+#    #+#             */
/*   Updated: 2024/09/10 16:05:55 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float flo);
        Fixed(const Fixed &copy);
        ~Fixed();
        
        Fixed& operator=(const Fixed &other);
        
        // comparacion
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        
        // aritmeticos
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;

        // Pre-increment/decrement
        Fixed& operator++(); // Return by reference
        Fixed& operator--(); // Return by reference

        // Post-increment/decrement
        Fixed operator++(int); // Return by value
        Fixed operator--(int); // Return by value

        // min/max
        static const Fixed& min(const Fixed& first, const Fixed& second);
        static const Fixed& max(const Fixed& first, const Fixed& second);
        static const Fixed& min(Fixed& first, Fixed& second);
        static const Fixed& max(Fixed& first, Fixed& second);
 
        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);