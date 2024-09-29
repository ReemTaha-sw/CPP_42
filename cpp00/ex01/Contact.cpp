/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:32:17 by rosman            #+#    #+#             */
/*   Updated: 2024/09/02 17:02:11 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret):
 first_name(first_name), last_name(last_name), nick_name(nick_name), phone_number(phone_number), darkest_secret(darkest_secret) {}

std::string Contact::get_f_name()
{
    return this->first_name;
}
std::string Contact::get_l_name()
{
    return this->last_name;
}
std::string Contact::get_n_name()
{
    return this->nick_name;
}
std::string Contact::get_secret()
{
    return this->darkest_secret;
}

std::string Contact::get_phone()
{
    return this->phone_number;
}