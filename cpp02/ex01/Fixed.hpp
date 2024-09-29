/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:07 by rosman            #+#    #+#             */
/*   Updated: 2024/09/09 19:16:58 by rosman           ###   ########.fr       */
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

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);