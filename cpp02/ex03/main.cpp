/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:10 by rosman            #+#    #+#             */
/*   Updated: 2024/09/10 20:19:32 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    // Define triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test point inside the triangle
    Point point1(5.0f, 5.0f);
    if (bsp(a, b, c, point1)) {
        std::cout << "Point (5, 5) is inside the triangle." << std::endl;
    } else {
        std::cout << "Point (5, 5) is outside the triangle." << std::endl;
    }

    // Test point outside the triangle
    Point point2(15.0f, 5.0f);
    if (bsp(a, b, c, point2)) {
        std::cout << "Point (15, 5) is inside the triangle." << std::endl;
    } else {
        std::cout << "Point (15, 5) is outside the triangle." << std::endl;
    }

    // Test point on the edge of the triangle (should return false)
    Point point3(5.0f, 0.0f);
    if (bsp(a, b, c, point3)) {
        std::cout << "Point (5, 0) is inside the triangle." << std::endl;
    } else {
        std::cout << "Point (5, 0) is outside the triangle." << std::endl;
    }

    return 0;
}

// int main(void)
// {
// 	Point a(-4, -3);
// 	Point b(0, 1);
// 	Point c(1, -3);
// 	Point p(0,0);
// 	if (bsp(a, b, c, p))
// 		std::cout << "inside!!\n";
// 	else
// 		std::cout << "outside!!\n";
// }

// //0,-2 -> inside
// //0,-3 -> outside
// //-4,0 -> outside
// //4, 1 -> outside
// //0, 0 -> inside