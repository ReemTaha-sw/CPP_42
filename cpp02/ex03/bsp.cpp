/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:13:43 by rosman            #+#    #+#             */
/*   Updated: 2024/09/10 20:02:23 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed step1 = p1.getX() * (p2.getY() - p3.getY());
    Fixed step2 = p2.getX() * (p3.getY() - p1.getY());
    Fixed step3 = p3.getX() * (p1.getY() - p2.getY());
    Fixed total = step1 + step2 + step3;
    // absolute value
    total = ((total < Fixed(0)) ? Fixed(-total.toFloat()) : total);
    
    return total / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c); // Full triangle area
    Fixed areaPAB = area(point, a, b); // Triangle area with point and 2 vertices
    Fixed areaPBC = area(point, b, c); // Triangle area with point and 2 vertices
    Fixed areaPCA = area(point, c, a); // Triangle area with point and 2 vertices
    
    // If areas are equal, the point is inside
    return (areaABC == areaPAB + areaPBC + areaPCA);
}