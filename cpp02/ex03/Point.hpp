/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:13:02 by rosman            #+#    #+#             */
/*   Updated: 2024/09/10 20:13:39 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"


class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(float x, float y);
        Point(Point &point);
        ~Point();
        Point &operator=(const Point &copy);
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);