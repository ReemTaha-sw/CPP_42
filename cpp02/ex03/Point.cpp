/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:17:39 by rosman            #+#    #+#             */
/*   Updated: 2024/09/10 20:13:55 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(Point &point) { *this = point; }

Point& Point::operator=(const Point &copy)
{
    if (this != &copy)
    {
        const_cast<Fixed&>(_x) = copy._x;
        const_cast<Fixed&>(_y) = copy._y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return this->_x;}
Fixed Point::getY() const { return this->_y;}
