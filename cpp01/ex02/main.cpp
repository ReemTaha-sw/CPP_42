/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:12:38 by rosman            #+#    #+#             */
/*   Updated: 2024/09/06 14:49:30 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of the string variable ( &str ):           " << &str << "\n";
    std::cout << "Memory address held by string pointer ( stringPTR ):      " << stringPTR << "\n";
    std::cout << "Memory address held by string reference ( &stringREF ):   " << &stringREF << "\n";
    
    std::cout << "\nValue of the string variable (str):                   " << str << "\n";
    std::cout << "Value pointed to by string pointer (*stringPTR):      " << *stringPTR << "\n";
    std::cout << "Value pointed to by string reference (stringREF):     " << stringREF << "\n";
    return 0;
}